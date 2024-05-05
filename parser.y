%define parse.error verbose

%{
   #include <stdio.h>
   #include <iostream>
   #include <vector>
   #include <string>
   using namespace std; 

   extern int yylex();
   extern int yylineno;
   extern char *yytext;
   void yyerror (const char *msg) {
     printf("line %d: %s at '%s'\n", yylineno, msg, yytext) ;
   }

   #include "Codigo.hpp"
   #include "Exp.hpp"


   expresionstruct makecomparison(std::string s1, std::string s2, std::string s3) ;
   expresionstruct makearithmetic(std::string s1, std::string s2, std::string s3) ;

   Codigo codigo;

%}

/* 
   qué atributos tienen los símbolos 
*/
%union {
    string *str ; 
    vector<string> *list ;
    expresionstruct *expr ;
    sentences *sentc ;
    int number ;
    vector<int> *numlist ;
}
 
/*   declaración de tokens. Esto debe coincidir con tokens.l */

//Tokens definidos: id, integer, float/double...
%token <str> TID TFLOAT_CONST TINTEGER_CONST TCOMENTARIO_LINEA TCOMENTARIO_MULTILINEA

// ==,<,<=,>,>=
%token <str> TIGUALQUE TMENOR TMENOROIGUAL TMAYOR TMAYOROIGUAL TDIFERENTEA

// +, -, *, /
%token <str> TSUMA TRESTA TMULTIPLICACION TDIVISION

// = TASSIG
%token <str> TASSIG


/*	Estos tokens no tienen atributos:   */

//Parentesis abrir, parentesis cerrar, coma
%token  TPARENTESIS_ABRIR TPARENTESIS_CERRAR

//Llaves abrir, llaves cerrar
%token  TLBRACE TRBRACE

//Dos puntos, punto coma, coma
%token  TDOSPUNTOS TSEMIC TCOMA

//Palabras reservadas
%token RPROGRAM RPROCEDURE RMAIN
%token RVAR RINTEGER RFLOAT   
%token RIN ROUT
%token RIF RWHILE RCONTINUE RFINALLY RFOREVER RBREAK
%token RREAD RPRINTLN

/* 	Declaración de símbolos no terminales con atributos 	*/
/* %type <str> par_class
%type <str> type 
%type <expr> expression


%type <list> id_list
%type <list> id_list_rem
%type <list> arguments */

%type <expr> expression

%type <str> variable
%type <str> type 
%type <str> par_class 


%type <number> M

%type <list> id_list
%type <list> id_list_rem

%type <sentc> statement
%type <sentc> statements

/*Aquí falta poner la asociatividad y precedencia de los operadores*/
/*** Aquí se indica la prioridad y asociatividad de los operadores:
****  %nonassoc OP si OP no es asociativo, si solo puede aparecer una vez en la expresión
****  %left OP si OP es asociativo por la izda.
****  %right OP si OP es asociativo por la dcha.
****/
%nonassoc TDOSPUNTOS TCOMA
%nonassoc TMENOR TMAYOR TMENOROIGUAL TMAYOROIGUAL TDIFERENTEA TIGUALQUE
%left TSUMA TRESTA 
%left TMULTIPLICACION TDIVISION

%start start

%%

start : RPROGRAM TID { codigo.anadirInstruccion(  "prog "  + codigo.dollar_to_string( $2 )  ); } 
         block  {
               codigo.anadirInstruccion("halt");
		           codigo.escribir() ; 
            }
      ;
      
block : declarations {codigo.anadirInstruccion("call main");}
         subprogs
      ;
procs_block : declarations
               procs
            ;
declarations : RVAR id_list TDOSPUNTOS type TSEMIC { 
                  codigo.anadirDeclaraciones( *$2 , *$4 ) ;
                   delete $2; delete $4 ;
                }
            declarations 
             | %empty /* vacío */ 
             ;
id_list : TID id_list_rem { $$ = $2 ;
                            string tid_string= codigo.dollar_to_string( $1 ) ;
                            $$ -> push_back( tid_string );                           
                            }
        ;
id_list_rem : TCOMA TID id_list_rem  {  
                              $$ = $3 ;
                              string tid_string= codigo.dollar_to_string( $2 ) ;
                              $$ -> push_back( tid_string ); 
                            }
            | %empty /* vacío */ 
            { 
              $$ = new vector<string>; 
            } 
            ;
type : RINTEGER { $$ = new string("int");    }
      | RFLOAT {  $$ = new string("real");   }
      ;
subprogs : subprogram subprogs
            | main_subprog
            ;
procs : procs subprogram
            | %empty /* vacío */
            ;
subprogram : RPROCEDURE TID 
            {
              codigo.anadirInstruccion("proc " + codigo.dollar_to_string( $2 ) ); 
            }
            arguments procs_block TLBRACE statements TRBRACE 
            { 
              codigo.anadirInstruccion("endproc " + codigo.dollar_to_string( $2 ) ); 
            }
            ;
main_subprog : RPROCEDURE RMAIN { codigo.anadirInstruccion("proc main"); }
            procs_block TLBRACE statements TRBRACE 
            ;
arguments : TPARENTESIS_ABRIR param_list TPARENTESIS_CERRAR
            | %empty /* vacío */ 
            ;
param_list : id_list TDOSPUNTOS par_class type {codigo.anadir_argumentos(*$1,*$3,*$4);}
            param_list_rem
            ;
par_class : RIN { $$ = new string("val");  }
            |ROUT {$$ = new string("ref"); }
            |RIN ROUT {$$ = new string("ref"); }
            ;
param_list_rem : TSEMIC id_list TDOSPUNTOS par_class type {codigo.anadir_argumentos(*$2,*$4,*$5);}
               param_list_rem
               | %empty /* vacío */
               ;
statements : statements statement 
               { 
               $$ = new sentences;
               $$->exits = codigo.unirInt($1->exits , $2->exits);
               $$->continues = codigo.unirInt($1->continues , $2->continues);
               }
            | statement 
               { 
               $$ = $1;
               }
            ;
statement : variable TASSIG expression TSEMIC  
            { codigo.anadirInstruccion( *$1 + ":=" + $3 -> str + ";" )  ; 
            $$ = new sentences;              
            }

            | RIF expression TDOSPUNTOS TLBRACE M statements M TRBRACE TSEMIC
            { 
              codigo.completarInstrucciones( $2 -> trues, $5 ); 
              codigo.completarInstrucciones( $2 -> falses, $7 );
              $$ = $6;
            }

            | RWHILE RFOREVER TDOSPUNTOS TLBRACE M statements M TRBRACE TSEMIC
            {
            codigo.completarInstrucciones( $6 -> continues, $5 );
            codigo.completarInstrucciones( $6 -> exits, $7 + 1 );
            codigo.anadirInstruccion("goto " + to_string($5));
            $$ = new sentences;
            }

            | RWHILE M expression TDOSPUNTOS TLBRACE M statements M TRBRACE
           {
            codigo.anadirInstruccion("goto " + to_string($2));
            codigo.completarInstrucciones( $7 -> continues, $2 );
            codigo.completarInstrucciones( $3 -> trues, $6 );
            codigo.completarInstrucciones( $3 -> falses, $8 + 1 );
           } 
            RFINALLY TDOSPUNTOS TLBRACE statements TRBRACE TSEMIC 
            {
              int referencia = codigo.obtenRef();
              codigo.completarInstrucciones($7->exits, referencia);
              $$ = new sentences;
            }

            | RBREAK TSEMIC M
            { 
            $$ = new sentences;
            $$->exits.push_back($3);
            codigo.anadirInstruccion("goto ");
            }

            | RCONTINUE RIF M expression TSEMIC M
            {
              $$ = new sentences;
              codigo.completarInstrucciones($4 -> falses, $6);
              $$->continues.push_back($3);
            }

            | RREAD TPARENTESIS_ABRIR variable TPARENTESIS_CERRAR TSEMIC
            { codigo.anadirInstruccion( "read " + *$3 ) ;
            $$ = new sentences;
            }


            | RPRINTLN TPARENTESIS_ABRIR expression TPARENTESIS_CERRAR TSEMIC
            { 
            codigo.anadirInstruccion( "write " + $3 -> str ) ;
            codigo.anadirInstruccion( "writeln " ) ;
            $$ = new sentences;
            }
 
            ;

variable : TID { $$ = $1;  }
         ;
expression : expression TIGUALQUE expression
            { 
              $$ = new expresionstruct; 
              *$$ = makecomparison($1 -> str, *$2 , $3 -> str) ; 
              delete $1; delete $3;
            } 

            | expression TMENOR expression
            { 
              $$ = new expresionstruct; 
              *$$ = makecomparison($1 -> str, *$2 , $3 -> str) ; 
              delete $1; delete $3;
            } 


            | expression TMAYOR expression
            { 
              $$ = new expresionstruct; 
              *$$ = makecomparison($1 -> str, *$2 , $3 -> str) ; 
              delete $1; delete $3;
            } 


            | expression TMAYOROIGUAL expression
            { 
              $$ = new expresionstruct; 
              *$$ = makecomparison($1 -> str, *$2 , $3 -> str) ; 
              delete $1; delete $3;
            } 

            | expression TMENOROIGUAL expression
            { 
              $$ = new expresionstruct; 
              *$$ = makecomparison($1 -> str, *$2 , $3 -> str) ; 
              delete $1; delete $3;
            } 

            | expression TDIFERENTEA expression
            { 
              $$ = new expresionstruct; 
              *$$ = makecomparison($1 -> str, *$2 , $3 -> str) ; 
              delete $1; delete $3;
            } 

            | expression TSUMA expression
            { 
              $$ = new expresionstruct; 
              *$$ = makearithmetic($1 -> str, *$2 , $3 -> str) ; 
              delete $1; delete $3;
            } 

            | expression TRESTA expression
            { 
              $$ = new expresionstruct; 
              *$$ = makearithmetic($1 -> str, *$2 , $3 -> str) ; 
              delete $1; delete $3;
            } 

            | expression TMULTIPLICACION expression
            { 
              $$ = new expresionstruct; 
              *$$ = makearithmetic($1 -> str, *$2 , $3 -> str) ; 
              delete $1; delete $3;
            } 


            | expression TDIVISION expression
            { 
              $$ = new expresionstruct; 
              *$$ = makearithmetic($1 -> str, *$2 , $3 -> str) ; 
              delete $1; delete $3;
            } 

            | TID
            { 
              $$ = new expresionstruct; 
              $$ -> str = *$1 ; 
            }

            | TINTEGER_CONST
            { 
              $$ = new expresionstruct; 
              $$ -> str = *$1; 
            }


            | TFLOAT_CONST
            { 
              $$ = new expresionstruct; 
              $$ -> str = *$1; 
            }


            | TPARENTESIS_ABRIR expression TPARENTESIS_CERRAR
            { 
              $$ = new expresionstruct; 
              $$ = $2; 
            }


            ;

M:  %empty { $$ = codigo.obtenRef() ; }
	;

%%

expresionstruct makecomparison(std::string s1, std::string s2, std::string s3) {
  expresionstruct tmp ; 
  tmp.trues.push_back(codigo.obtenRef()) ;
  tmp.falses.push_back(codigo.obtenRef()+1) ;
  codigo.anadirInstruccion("if " + s1 + s2 + s3 + " goto") ;
  codigo.anadirInstruccion("goto ") ;
  return tmp ;
}


expresionstruct makearithmetic(std::string s1, std::string s2, std::string s3) {
  expresionstruct tmp ; 
  tmp.str = codigo.nuevoId() ;
  tmp.trues.push_back(codigo.obtenRef()) ;
  tmp.falses.push_back(codigo.obtenRef()+1) ;
  codigo.anadirInstruccion(tmp.str + ":=" + s1 + s2 + s3 + ";") ;     
  return tmp ;
}


