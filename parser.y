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
%token <str> TID TFLOAT_CONST TINTEGER_CONST TCOMENTARIO_LINEA
/* %token TCOMENTARIO_MULTILINEA  */

// ==,<,<=,>,>=
%token <str> TIGUALQUE TMENOR TMENOROIGUAL TMAYOR TMAYOROIGUAL TDIFERENTEA

// +, -, *, /
%token <str> TSUMA TRESTA TMULTIPLICACION TDIVISION

// := TASSIG
%token <str> TASSIG


/*	Estos tokens no tienen atributos:   */

//Parentesis abrir, parentesis cerra, coma
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

%type <sentc> statement
%type <sentc> statements
%type <list> id_list
%type <list> id_list_rem
%type <list> arguments */

%type <str> expression
%type <str> variable
%type <str> type 

%type <number> M

%type <list> id_list
%type <list> id_list_rem

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
                  codigo.anadirDeclaraciones( $2 , $4 ) ;
                   delete $2; delete $4 ;
                }
            declarations 
             | %empty /* vacío */
             ;
id_list : TID id_list_rem { $$ = $2; 
                            $$.push_back( $1 ); }
        ;
id_list_rem : TCOMA TID id_list_rem  { $$ = codigo.anadirStr( $3 , $2 ); }
            | %empty { $$ = new vector<string>; } /* vacío */ 
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
            arguments procs_block TLBRACE statements TRBRACE {codigo.anadirInstruccion("endproc");}
            ;
main_subprog : RPROCEDURE RMAIN {codigo.anadirInstruccion("proc main");}
            procs_block TLBRACE statements TRBRACE 
            ;
arguments : TPARENTESIS_ABRIR param_list TPARENTESIS_CERRAR
            | %empty /* vacío */ 
            ;
param_list : id_list TDOSPUNTOS par_class type {}
            param_list_rem
            ;
par_class : RIN {}
            |ROUT {}
            |RIN ROUT {}
            ;
param_list_rem : TSEMIC id_list TDOSPUNTOS par_class type {}
               param_list_rem
               | %empty /* vacío */
               ;
statements : statements statement { }
            | %empty /* vacío */
            ;
statement : variable TASSIG expression TSEMIC 
            { }

            | RIF expression TDOSPUNTOS TLBRACE M statements M TRBRACE TSEMIC
            {}

            | RWHILE RFOREVER TDOSPUNTOS TLBRACE M statements M TRBRACE TSEMIC
            {}

            | RWHILE M expression TDOSPUNTOS TLBRACE M statements M TRBRACE 
            {}
            
            RFINALLY TDOSPUNTOS TLBRACE M statements TRBRACE TSEMIC M
            {}

            | RBREAK TSEMIC M
            {}

            | RCONTINUE RIF M expression TSEMIC
            {}

            | RREAD TPARENTESIS_ABRIR variable TPARENTESIS_CERRAR TSEMIC
            {}


            | RPRINTLN TPARENTESIS_ABRIR expression TPARENTESIS_CERRAR TSEMIC
            {}

            ;

variable : TID { $$ = $1 ; }
         ;
expression : expression TIGUALQUE expression
            {}

            | expression TMENOR expression
            {}


            | expression TMAYOR expression
            {}


            | expression TMAYOROIGUAL expression
            {}

            | expression TMENOROIGUAL expression
            {}

            | expression TDIFERENTEA expression
            {}

            | expression TSUMA expression
            {}

            | expression TRESTA expression
            {}

            | expression TMULTIPLICACION expression
            {}

            | expression TDIVISION expression
            {}

            | TID
            {}

            | TINTEGER_CONST
            {}


            | TFLOAT_CONST
            {}


            | TPARENTESIS_ABRIR expression TPARENTESIS_CERRAR
            {}


            ;

M:  %empty { $$ = codigo.obtenRef() ; }
	;

%%

expresionstruct makecomparison(std::string s1, std::string s2, std::string s3) {
  expresionstruct tmp ; 
  tmp.trues.push_back(codigo.obtenRef()) ;
  tmp.falses.push_back(codigo.obtenRef()+1) ;
  codigo.anadirInstruccion("if " + s1 + s2 + s3 + " goto") ;
  codigo.anadirInstruccion("goto") ;
  return tmp ;
}


expresionstruct makearithmetic(std::string s1, std::string s2, std::string s3) {
  expresionstruct tmp ; 
  tmp.str = codigo.nuevoId() ;
  codigo.anadirInstruccion(tmp.str + ":=" + s1 + s2 + s3 + ";") ;     
  return tmp ;
}


