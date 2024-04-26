%option yylineno 
%option nounput

%{
 #include <string>
 using namespace std;
 #include <iostream>
 #include "parser.hpp" 

 #define TOKEN(t) yylval.str = new string(yytext, yyleng) ; return t 

 extern "C" int yywrap() { return(1) ; }  
 extern int yyerror(const char *); 

%}

%%
program                 TOKEN(RPROGRAM) ;
procedure		        TOKEN(RPROCEDURE) ;
main			        TOKEN(RMAIN) ;
var			            TOKEN(RVAR) ;
integer                 TOKEN(RINTEGER); 
float                   TOKEN(RFLOAT);
in                      TOKEN(RIN); 
out                     TOKEN(ROUT); 
if                      TOKEN(RIF); 
while                   TOKEN(RWHILE); 
continue                TOKEN(RCONTINUE); 
finally                 TOKEN(RFINALLY); 
forever                 TOKEN(RFOREVER); 
break                   TOKEN(RBREAK); 
read                    TOKEN(RREAD); 
println                 TOKEN(RPRINTLN); 


"="                      TOKEN(TASSIG);
";"                      TOKEN(TSEMIC);

"{"                      TOKEN(TLBRACE);
"}"                      TOKEN(TRBRACE);
":"                      TOKEN(TDOSPUNTOS);
","                      TOKEN(TCOMA);
"("                      TOKEN(TPARENTESIS_ABRIR);
")"                      TOKEN(TPARENTESIS_CERRAR);
"+"                      TOKEN(TSUMA);
"-"                      TOKEN(TRESTA);
"*"                      TOKEN(TMULTIPLICACION);
"/"                      TOKEN(TDIVISION);
"<"                      TOKEN(TMENOR);
">"                      TOKEN(TMAYOR);
"<""="                   TOKEN(TMENOROIGUAL);
">""="                   TOKEN(TMAYOROIGUAL);
"/""="                   TOKEN(TDIFERENTEA);
"=""="                   TOKEN(TIGUALQUE);


[ \t\n]                 ;


[a-zA-Z](_?[a-zA-Z0-9$])*_?                                     TOKEN(TID); 
(([1-9][0-9]*)|0)\.[0-9]+([Ee][+-]?(([1-9][0-9]*)|0))?          TOKEN(TFLOAT_CONST); 
(([1-9][0-9]*)|0)                                               TOKEN(TINTEGER_CONST); 
\/\/([^\/]|\/[^\/])*\/\/                                        TOKEN(TCOMENTARIO_MULTILINEA);
#!.*\n                                                          TOKEN(TCOMENTARIO_LINEA);

.                        { yyerror("Token desconocido: ");}    
%%