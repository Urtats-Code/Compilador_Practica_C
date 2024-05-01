%define parse.error verbose

%{

   #include <stdio.h>
   #include <iostream>
   #include <vector>
   #include <string>

   using namespace std; 

   extern int yylex();
   extern int yylineno;
   extern string *yytext;
   extern int yyerrornum;


   #include "Codigo.hpp"
   #include "Exp.hpp"

   expresionstruct makecomparison(std::string s1, std::string s2, std::string s3) ;
   expresionstruct makearithmetic(std::string s1, std::string s2, std::string s3) ;
   
   
   // Añado la declaración de la función unir. Si la hacéis diferente, debéis cambiar esta declaración.
   vector<int> *unir(vector<int> lis1, vector<int> lis2);


   Codigo Codigo;

%}

/* 
   qué atributos tienen los tokens 
*/

%union {
   string *str ; 
   vector<string> *list ; expresionstruct *expr ;
   sentences *sentc ;
   int number ;
   vector<int> *numlist; 
}

/* 
   declaración de tokens. Esto debe coincidir con tokens.l 
*/
/*PALABRAS RESERVADAS*/
%token <str> RPROGRAM RPROCEDURE RMAIN
%token <str> RVAR RINTEGER RFLOAT   
%token <str> RIN ROUT
%token <str> RIF RWHILE RCONTINUE RFINALLY RFOREVER RBREAK
%token <str> RREAD RPRINTLN

/*PARENTISIS, BRACKETS, ASIGNACIONES, DOS PUNTOS, LA COMA, COMPARACIONES, OPERADORES...*/
%token <str> TSEMIC TASSIG TDOSPUNTOS TCOMA
%token <str> TLBRACE TRBRACE 
%token <str> TPARENTESIS_ABRIR TPARENTESIS_CERRAR
%token <str> TSUMA TRESTA TMULTIPLICACION TDIVISION
%token <str> TMENOR TMAYOR TMENOROIGUAL TMAYOROIGUAL TDIFERENTEA TIGUALQUE

/*DEFINICIONES*/

%token <str> TID TINTEGER_CONST TFLOAT_CONST TCOMENTARIO_MULTILINEA TCOMENTARIO_LINEA

%start start

/*** Aquí se indica la prioridad y asociatividad de los operadores:
****  %nonassoc OP si OP no es asociativo, si solo puede aparecer una vez en la expresión
****  %left OP si OP es asociativo por la izda.
****  %right OP si OP es asociativo por la dcha.
****/
%nonassoc TDOSPUNTOS TCOMA
%nonassoc TMENOR TMAYOR TMENOROIGUAL TMAYOROIGUAL TDIFERENTEA TIGUALQUE
%left TSUMA TRESTA 
%left TMULTIPLICACION TDIVISION

/* declaración de símbolos no terminales con atributos */
%type <str> par_class
%type <str> variable
%type <str> type 
%type <expr> expression
%type <number> M
%type <sentc> statement
%type <sentc> statements
%type <list> id_list
%type <list> id_list_rem
%type <list> arguments

%%
start : RPROGRAM TID {Codigo.anadirInstruccion("prog" + $2->str);} 
         block  {
               Codigo.anadirInstruccion("halt");
		         Codigo.escribir() ; 
               }
      ;
      
block : declarations {Codigo.anadirInstruccion("call main");}
         subprogs
      ;
procs_block : declarations
               procs
            ;
declarations : RVAR id_list TDOSPUNTOS type TSEMIC {Codigo.anadirDeclaraciones($2,$4);}
            declarations
             | %empty /* vacío */
             ;
id_list : TID id_list_rem {$$ = Codigo.anadirStr($$,$1);}
        ;
id_list_rem : TCOMA TID id_list_rem {$$ = Codigo.anadirStr($$->list,$2->str); $$ = Codigo.unir($$,$3)}
            | %empty /* vacío */ {$$ = Codigo.inilista();}
            ;
type : RINTEGER {$$ = "int";}
      | RFLOAT {$$= "real";}
      ;
subprogs : subprogram subprogs
            | main_subprog
            ;
procs : procs subprogram
            | %empty /* vacío */
            ;
subprogram : RPROCEDURE TID {Codigo.anadirInstruccion("proc" + $2->str);}
            arguments procs_block TLBRACE statements TRBRACE {Codigo.anadirInstruccion("endproc" + $2->str);}
            ;
main_subprog : RPROCEDURE RMAIN {Codigo.anadirInstruccion("proc main");}
            procs_block TLBRACE statements TRBRACE 
            ;
arguments : TPARENTESIS_ABRIR param_list TPARENTESIS_CERRAR
            | %empty /* vacío */ /*{$$ = inilista();}*/
            ;
param_list : id_list TDOSPUNTOS par_class type {Codigo.anadir_argumentos($1, $3, $4);}
            param_list_rem
            ;
par_class : RIN {$$ = "val";}
            |ROUT {$$ = "ref";}
            |RIN ROUT {$$ = "ref";}
            ;
param_list_rem : TSEMIC id_list TDOSPUNTOS par_class type {Codigo.anadir_argumentos($2, $4, $5);}
               param_list_rem
               | %empty /* vacío */
               ;
statements : statements statement {$$->exits = Codigo.unir($1->exits, $2->exits);
                                    $$->continues = Codigo.unir($1->continues, $2->continues);}
            | %empty /* vacío */
            ;
statement : variable TASSIG expression TSEMIC 
            {Codigo.anadirInstruccion($1 + " = " + $3->str);
            $$->exits = inilista();
            $$->continues = Codigo.inilistaNumEmpty();}

            | RIF expression TDOSPUNTOS TLBRACE M statements M TRBRACE TSEMIC
            {Codigo.completarInstrucciones($2->trues, $5);
            Codigo.completarInstrucciones($2->falses, $7);
            $$->exits = Codigo.unir($$->exits, $5->exits);
            $$->continues = Codigo.unir($$->continues, $5->continues);}

            | RWHILE RFOREVER TDOSPUNTOS TLBRACE M statements M TRBRACE TSEMIC
            {Codigo.completarInstrucciones($6->continues, $5);
            Codigo.completarInstrucciones($6->exits, $7 + 1);
            Codigo.anadirInstruccion("goto" + to_string($5));}

            | RWHILE M expression TDOSPUNTOS TLBRACE M statements M TRBRACE 
            {Codigo.anadirInstruccion("goto" + to_string($2));
            Codigo.completarInstrucciones($7->continues, $2);
            Codigo.completarInstrucciones($3->trues, $6);
            Codigo.completarInstrucciones($3->falses, $8 + 1);}
            
            RFINALLY TDOSPUNTOS TLBRACE M statements TRBRACE TSEMIC M
            {Codigo.completarInstrucciones($7->exits, $17);
            Codigo.completarInstrucciones($14->exits, $17);
            Codigo.completarInstrucciones($14->continues, $17);}

            | RBREAK TSEMIC M
            {$$->exits = Codigo.inilistaNum($3);
            Codigo.anadirInstruccion("goto");}

            | RCONTINUE RIF M expression TSEMIC
            {Codigo.completarInstrucciones($4->falses,$3);
            Codigo.anadir($$->continues, $3);}

            | RREAD TPARENTESIS_ABRIR variable TPARENTESIS_CERRAR TSEMIC
            {Codigo.anadirInstruccion("read" + $3);
               $$->continues = Codigo.inilistaNumEmpty();
               $$->exits = Codigo.inilistaNumEmpty();}


            | RPRINTLN TPARENTESIS_ABRIR expression TPARENTESIS_CERRAR TSEMIC
            {Codigo.anadirInstruccion("read" + $3->str);
               $$->continues = Codigo.inilistaNumEmpty();
               $$->exits = Codigo.inilistaNumEmpty();}

            ;
variable : TID {$$ = $1 ;}
         ;
expression : expression TIGUALQUE expression
            {$$->str = Codigo.nuevoId();
            $$->trues = Codigo.inilistaNum( Codigo.obtenRef());
            $$->falses = Codigo.inilistaNum( Codigo.obtenRef()+1);
            Codigo.anadirInstruccion("if" + $1->str + "="+"=" + "goto");
            Codigo.anadirInstruccion("goto");}

            | expression TMENOR expression
            {$$->str = Codigo.nuevoId();
            $$->trues = Codigo.inilistaNum( Codigo.obtenRef() );
            $$->falses = Codigo.inilistaNum( Codigo.obtenRef()+1 );
            Codigo.anadirInstruccion("if" + $1->str + ">" + "goto");
            Codigo.anadirInstruccion("goto");}


            | expression TMAYOR expression
            {$$->str = Codigo.nuevoId();
            $$->trues = Codigo.inilistaNum( Codigo.obtenRef());
            $$->falses = Codigo.inilistaNum( Codigo.obtenRef()+1);
            Codigo.anadirInstruccion("if" + $1->str + "<"+"+"+" goto");
            Codigo.anadirInstruccion("goto"); }


            | expression TMAYOROIGUAL expression
            {$$->str = Codigo.nuevoId();
            $$->trues = Codigo.inilistaNum( Codigo.obtenRef() );
            $$->falses = Codigo.inilistaNum( Codigo.obtenRef()+1 );
            Codigo.anadirInstruccion("if" + $1->str + ">"+"=" + "goto");
            Codigo.anadirInstruccion("goto");}

            | expression TMENOROIGUAL expression
            {$$->str = Codigo.nuevoId();
            $$->trues = Codigo.inilistaNum( Codigo.obtenRef() );
            $$->falses = Codigo.inilistaNum( Codigo.obtenRef()+1 );
            Codigo.anadirInstruccion("if" + $1->str + "<"+"=" + "goto");
            Codigo.anadirInstruccion("goto");}

            | expression TDIFERENTEA expression
            {$$->str = Codigo.nuevoId();
            $$->trues = Codigo.inilistaNum( Codigo.obtenRef() );
            $$->falses = Codigo.inilistaNum( Codigo.obtenRef()+1 );
            Codigo.anadirInstruccion("if" + $1->str + "/"+"=" + "goto");
            Codigo.anadirInstruccion("goto");}

            | expression TSUMA expression
            {$$->str = Codigo.nuevoId();
            $$->trues = Codigo.inilistaNumEmpty();
            $$->falses = Codigo.inilistaNumEmpty();
            Codigo.anadirInstruccion($$->str + "=" + $1->str + "+" + $3->str);}

            | expression TRESTA expression
            {$$->str = Codigo.nuevoId();
            $$->trues = Codigo.inilistaNumEmpty();
            $$->falses = Codigo.inilistaNumEmpty();
            Codigo.anadirInstruccion($$->str + "=" + $1->str + "-" + $3->str);}

            | expression TMULTIPLICACION expression
            {$$->str = Codigo.nuevoId();
            $$->trues = Codigo.inilistaNumEmpty();
            $$->falses = Codigo.inilistaNumEmpty();
            Codigo.anadirInstruccion($$->str + "=" + $1->str + "*" + $3->str);}

            | expression TDIVISION expression
            {$$->str = Codigo.nuevoId();
            $$->trues = Codigo.inilistaNumEmpty();
            $$->falses = Codigo.inilistaNumEmpty();
            Codigo.anadirInstruccion($$->str + "=" + $1->str + "/" + $3->str);}

            | TID
            {$$->str = $1 -> str ;
            $$->trues = Codigo.inilistaNumEmpty();
            $$->falses = Codigo.inilistaNumEmpty();}

            | TINTEGER_CONST
            {$$->str = $1 -> str ;
            $$->trues = Codigo.inilistaNumEmpty();
            $$->falses = Codigo.inilistaNumEmpty();}


            | TFLOAT_CONST
            { $$  = $1 ;
            $$->trues =  Codigo.inilistaNumEmpty();
            $$->falses = Codigo.inilistaNumEmpty() ;}


            | TPARENTESIS_ABRIR expression TPARENTESIS_CERRAR
            {$$->str = Codigo.nuevoId();
            $$->trues = $2->trues;
            $$->falses = $2->falses;}


            ;

M:  %empty { $$ = Codigo.obtenRef() ; }
	;

%%