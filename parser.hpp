/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TID = 258,                     /* TID  */
    TFLOAT_CONST = 259,            /* TFLOAT_CONST  */
    TINTEGER_CONST = 260,          /* TINTEGER_CONST  */
    TCOMENTARIO_LINEA = 261,       /* TCOMENTARIO_LINEA  */
    TIGUALQUE = 262,               /* TIGUALQUE  */
    TMENOR = 263,                  /* TMENOR  */
    TMENOROIGUAL = 264,            /* TMENOROIGUAL  */
    TMAYOR = 265,                  /* TMAYOR  */
    TMAYOROIGUAL = 266,            /* TMAYOROIGUAL  */
    TDIFERENTEA = 267,             /* TDIFERENTEA  */
    TSUMA = 268,                   /* TSUMA  */
    TRESTA = 269,                  /* TRESTA  */
    TMULTIPLICACION = 270,         /* TMULTIPLICACION  */
    TDIVISION = 271,               /* TDIVISION  */
    TASSIG = 272,                  /* TASSIG  */
    TPARENTESIS_ABRIR = 273,       /* TPARENTESIS_ABRIR  */
    TPARENTESIS_CERRAR = 274,      /* TPARENTESIS_CERRAR  */
    TLBRACE = 275,                 /* TLBRACE  */
    TRBRACE = 276,                 /* TRBRACE  */
    TDOSPUNTOS = 277,              /* TDOSPUNTOS  */
    TSEMIC = 278,                  /* TSEMIC  */
    TCOMA = 279,                   /* TCOMA  */
    RPROGRAM = 280,                /* RPROGRAM  */
    RPROCEDURE = 281,              /* RPROCEDURE  */
    RMAIN = 282,                   /* RMAIN  */
    RVAR = 283,                    /* RVAR  */
    RINTEGER = 284,                /* RINTEGER  */
    RFLOAT = 285,                  /* RFLOAT  */
    RIN = 286,                     /* RIN  */
    ROUT = 287,                    /* ROUT  */
    RIF = 288,                     /* RIF  */
    RWHILE = 289,                  /* RWHILE  */
    RCONTINUE = 290,               /* RCONTINUE  */
    RFINALLY = 291,                /* RFINALLY  */
    RFOREVER = 292,                /* RFOREVER  */
    RBREAK = 293,                  /* RBREAK  */
    RREAD = 294,                   /* RREAD  */
    RPRINTLN = 295                 /* RPRINTLN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "parser.y"

    string *str ; 
    vector<string> *list ;
    expresionstruct *expr ;
    sentences *sentc ;
    int number ;
    vector<int> *numlist ;

#line 113 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
