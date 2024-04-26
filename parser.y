%{
   #include <stdio.h>
   #include <iostream>
   #include <string>
   using namespace std; 

   extern int yylex();
   extern int yylineno;
   extern char *yytext;
   extern int yyerrornum;
  void yyerror (const char *msg) {
     printf("line %d: %s at '%s'\n", yylineno, msg, yytext) ;
     yyerrornum++;
   }

%}

/* 
   qué atributos tienen los tokens 
*/
%union {
    string *str ; 
    vector<string> *list ;
    expresionstruct *expr ;
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

%%
start : RPROGRAM TID {codigo.anadirInstruccion("prog" + $2->str);} 
         block  {
               codigo.anadirInstruccion("halt");
		         //codigo.escribir() ; 
               }
      ;
block : declarations {codigo.anadirInstruccion("call main");}
         subprogs
      ;
procs_block : declarations
               procs
            ;
declarations : RVAR id_list TDOSPUNTOS type TSEMIC declarations
             | /* vacío */
             ;
id_list : TID id_list_rem
        ;
id_list_rem : TCOMA TID id_list_rem
            | /* vacío */
            ;
type : RINTEGER
      | RFLOAT
      ;
subprogs : subprogram subprogs
            | main_subprog
            ;
procs : procs subprogram
            | /* vacío */
            ;
subprogram : RPROCEDURE TID arguments procs_block TLBRACE statements TRBRACE
            ;
main_subprog : RPROCEDURE RMAIN procs_block TLBRACE statements TRBRACE
            ;
arguments : TPARENTESIS_ABRIR param_list TPARENTESIS_CERRAR
            | /* vacío */
            ;
param_list : id_list TDOSPUNTOS par_class type param_list_rem
            ;
par_class : RIN
            |ROUT
            |RIN ROUT
            ;
param_list_rem : TSEMIC id_list TDOSPUNTOS par_class type param_list_rem
               | /* vacío */
               ;
statements : statements statement
            | /* vacío */
            ;
statement : variable TASSIG expression TSEMIC
            | RIF expression TDOSPUNTOS TLBRACE statements TRBRACE TSEMIC
            | RWHILE RFOREVER TDOSPUNTOS TLBRACE statements TRBRACE TSEMIC
            | RWHILE expression TDOSPUNTOS TLBRACE statements TRBRACE RFINALLY TDOSPUNTOS TLBRACE statements TRBRACE TSEMIC
            | RBREAK TSEMIC
            | RCONTINUE RIF expression TSEMIC
            | RREAD TPARENTESIS_ABRIR variable TPARENTESIS_CERRAR TSEMIC
            | RPRINTLN TPARENTESIS_ABRIR expression TPARENTESIS_CERRAR TSEMIC
            ;
variable : TID
         ;
expression : expression TIGUALQUE expression
            | expression TMENOR expression
            | expression TMAYOR expression
            | expression TMAYOROIGUAL expression
            | expression TMENOROIGUAL expression
            | expression TDIFERENTEA expression
            | expression TSUMA expression
            | expression TRESTA expression
            | expression TMULTIPLICACION expression
            | expression TDIVISION expression
            | TID
            | TINTEGER_CONST
            | TFLOAT_CONST
            | TPARENTESIS_ABRIR expression TPARENTESIS_CERRAR
            ;

