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

   void yyerror (const char *msg) {
     cout << "line " << yylineno <<": " << msg << " at token " << yytext << endl ;
     yyerrornum++;
   }


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
   vector<string> *list ;
   expresionstruct *expr ;
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

variable : TID { $$ = $1 ;}

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

M:  %empty { $$ = Codigo.obtenRef() ; }
	;

%%