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

/* declaración de símbolos no terminales con atributos */
%type <str> par_class
%type <str> variable
%type <str> type 
%type <expr> expression
%type <number> M
%type <expr> statement
%type <expr> statements
%type <list> id_list
%type <list> id_list_rem

%%
start : RPROGRAM TID {codigo.anadirInstruccion("prog" + $2->str);} 
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
declarations : RVAR id_list TDOSPUNTOS type TSEMIC {codigo.anadirDeclaraciones($2->str,$4);}
            declarations
             | %empty /* vacío */
             ;
id_list : TID id_list_rem {$$ = codigo.anadirStr($$,$1->str);}
        ;
id_list_rem : TCOMA TID id_list_rem {$$ = codigo.anadirStr($$-list,$2->str);}
            | %empty /* vacío */ {$$ = codigo.inilista();}
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
subprogram : RPROCEDURE TID {codigo.anadirInstruccion("proc" + $2->str);}
            arguments procs_block TLBRACE statements TRBRACE {codigo.anadirInstruccion("endproc" + $2->str);}
            ;
main_subprog : RPROCEDURE RMAIN {codigo.anadirInstruccion("proc main");}
            procs_block TLBRACE statements TRBRACE 
            ;
arguments : TPARENTESIS_ABRIR param_list TPARENTESIS_CERRAR
            | %empty /* vacío */ {$1 = inilista();}
            ;
param_list : id_list TDOSPUNTOS par_class type {codigo.anadirargumentos($1, $3, $4);}
            param_list_rem
            ;
par_class : RIN {$$ = "val";}
            |ROUT {$$ = "ref";}
            |RIN ROUT {$$ = "ref";}
            ;
param_list_rem : TSEMIC id_list TDOSPUNTOS par_class type {codigo.anadirargumentos($2, $4, $5);}
               param_list_rem
               | %empty /* vacío */
               ;
statements : statements statement {$$->exits = codigo.unir($1->exits, $2->exits);
                                    $$->continues = codigo.unir($1->continues, $2->continues);}
            | %empty /* vacío */
            ;
statement : variable TASSIG expression TSEMIC 
            {codigo.anadirInstruccion($1 + " = " + $3->str);
            $$->exits = inilista();
            $$->continues = inilista();}

            | RIF expression TDOSPUNTOS TLBRACE M statements M TRBRACE TSEMIC
            {codigo.completar($2->trues, $5);
            codigo.completar($2->falses, $7);
            $$->exits = codigo.unir($$->exits, $5->exits);
            $$->continues = codigo.unir($$->continues, $5->continues);}

            | RWHILE RFOREVER TDOSPUNTOS TLBRACE M statements M TRBRACE TSEMIC
            {codigo.completar($6->continues, $5);
            codigo.completar($6->exits, $7 + 1);
            codigo.anadirInstruccion("goto" + to_string($5));}

            | RWHILE M expression TDOSPUNTOS TLBRACE M statements M TRBRACE 
            {codigo.anadirInstruccion("goto" + to_string($2));
            codigo.completar($7->continues, $2);
            codigo.completar($3->trues, $6);
            codigo.completar($3->falses, $8 + 1);}
            
            RFINALLY TDOSPUNTOS TLBRACE M statements TRBRACE TSEMIC M
            {codigo.completar($7->exits, $17);
            codigo.completar($14->exits, $17);
            codigo.completar($14->continues, $17);}

            | RBREAK TSEMIC M
            {$$->exits = codigo.inilistaNum($3);
            codigo.anadirInstruccion("goto");}

            | RCONTINUE RIF M expression TSEMIC
            {codigo.completar($4->falses,$3);
            codigo.anadir($$->continues, $3);}

            | RREAD TPARENTESIS_ABRIR variable TPARENTESIS_CERRAR TSEMIC
            {codigo.anadirInstruccion("read" + $3);
               $$->continues = inilista();
               $$->exits = inilista();}


            | RPRINTLN TPARENTESIS_ABRIR expression TPARENTESIS_CERRAR TSEMIC
            {codigo.anadirInstruccion("read" + $3->str);
               $$->continues = inilista();
               $$->exits = inilista();}

            ;
variable : TID {$$ = $1->str;}
         ;
expression : expression TIGUALQUE expression
            {$$->str = codigo.nuevoId();
            $$->trues = codigo.inilistaNum(codigo.obtenRef());
            $$->falses = codigo.inilistaNum(codigo.obtenRef()+1);
            codigo.anadirInstruccion("if" + $1->str + "==" + "goto");
            codigo.anadirInstruccion("goto");}

            | expression TMENOR expression
            {$$->str = codigo.nuevoId();
            $$->trues = codigo.inilistaNum(codigo.obtenRef());
            $$->falses = codigo.inilistaNum(codigo.obtenRef()+1);
            codigo.anadirInstruccion("if" + $1->str + ">" + "goto");
            codigo.anadirInstruccion("goto");}


            | expression TMAYOR expression
            {$$->str = codigo.nuevoId();
            $$->trues = codigo.inilistaNum(codigo.obtenRef());
            $$->falses = codigo.inilistaNum(codigo.obtenRef()+1);
            codigo.anadirInstruccion("if" + $1->str + "<" + "goto");
            codigo.anadirInstruccion("goto");}


            | expression TMAYOROIGUAL expression
            {$$->str = codigo.nuevoId();
            $$->trues = codigo.inilistaNum(codigo.obtenRef());
            $$->falses = codigo.inilistaNum(codigo.obtenRef()+1);
            codigo.anadirInstruccion("if" + $1->str + ">=" + "goto");
            codigo.anadirInstruccion("goto");}

            | expression TMENOROIGUAL expression
            {$$->str = codigo.nuevoId();
            $$->trues = codigo.inilistaNum(codigo.obtenRef());
            $$->falses = codigo.inilistaNum(codigo.obtenRef()+1);
            codigo.anadirInstruccion("if" + $1->str + "<=" + "goto");
            codigo.anadirInstruccion("goto");}

            | expression TDIFERENTEA expression
            {$$->str = codigo.nuevoId();
            $$->trues = codigo.inilistaNum(codigo.obtenRef());
            $$->falses = codigo.inilistaNum(codigo.obtenRef()+1);
            codigo.anadirInstruccion("if" + $1->str + "/=" + "goto");
            codigo.anadirInstruccion("goto");}

            | expression TSUMA expression
            {$$->str = codigo.nuevoId();
            $$->trues = codigo.inilista();
            $$->falses = codigo.inilista();
            codigo.anadirInstruccion($$->str + "=" + $1>str + "+" + $3->str);}

            | expression TRESTA expression
            {$$->str = codigo.nuevoId();
            $$->trues = codigo.inilista();
            $$->falses = codigo.inilista();
            codigo.anadirInstruccion($$->str + "=" + $1>str + "-" + $3->str);}

            | expression TMULTIPLICACION expression
            {$$->str = codigo.nuevoId();
            $$->trues = codigo.inilista();
            $$->falses = codigo.inilista();
            codigo.anadirInstruccion($$->str + "=" + $1>str + "*" + $3->str);}

            | expression TDIVISION expression
            {$$->str = codigo.nuevoId();
            $$->trues = codigo.inilista();
            $$->falses = codigo.inilista();
            codigo.anadirInstruccion($$->str + "=" + $1>str + "/" + $3->str);}

            | TID
            {$$->str = $1->str;
            $$->trues = codigo.inilista();
            $$->falses = codigo.inilista();}

            | TINTEGER_CONST
            {$$->str = $1->str;
            $$->trues = codigo.inilista();
            $$->falses = codigo.inilista();}


            | TFLOAT_CONST
            {$$->str = $1->str;
            $$->trues = codigo.inilista();
            $$->falses = codigo.inilista();}


            | TPARENTESIS_ABRIR expression TPARENTESIS_CERRAR
            {$$->str = codigo.nuevoId();
            $$->trues = $2->trues;
            $$->falses = $2->falses;}


            ;

M:  %empty { $$ = codigo.obtenRef() ; }
	;
