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
   extern int yyerrornum;
   void yyerror (const char *msg) {
     cout << "line " << yylineno <<": " << msg << " at token " << yytext << endl ;
     yyerrornum++;
   }

   #include "Codigo.hpp"
   #include "Exp.hpp"

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


%%