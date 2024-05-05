/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser.y"

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


#line 96 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TID = 3,                        /* TID  */
  YYSYMBOL_TFLOAT_CONST = 4,               /* TFLOAT_CONST  */
  YYSYMBOL_TINTEGER_CONST = 5,             /* TINTEGER_CONST  */
  YYSYMBOL_TCOMENTARIO_LINEA = 6,          /* TCOMENTARIO_LINEA  */
  YYSYMBOL_TIGUALQUE = 7,                  /* TIGUALQUE  */
  YYSYMBOL_TMENOR = 8,                     /* TMENOR  */
  YYSYMBOL_TMENOROIGUAL = 9,               /* TMENOROIGUAL  */
  YYSYMBOL_TMAYOR = 10,                    /* TMAYOR  */
  YYSYMBOL_TMAYOROIGUAL = 11,              /* TMAYOROIGUAL  */
  YYSYMBOL_TDIFERENTEA = 12,               /* TDIFERENTEA  */
  YYSYMBOL_TSUMA = 13,                     /* TSUMA  */
  YYSYMBOL_TRESTA = 14,                    /* TRESTA  */
  YYSYMBOL_TMULTIPLICACION = 15,           /* TMULTIPLICACION  */
  YYSYMBOL_TDIVISION = 16,                 /* TDIVISION  */
  YYSYMBOL_TASSIG = 17,                    /* TASSIG  */
  YYSYMBOL_TPARENTESIS_ABRIR = 18,         /* TPARENTESIS_ABRIR  */
  YYSYMBOL_TPARENTESIS_CERRAR = 19,        /* TPARENTESIS_CERRAR  */
  YYSYMBOL_TLBRACE = 20,                   /* TLBRACE  */
  YYSYMBOL_TRBRACE = 21,                   /* TRBRACE  */
  YYSYMBOL_TDOSPUNTOS = 22,                /* TDOSPUNTOS  */
  YYSYMBOL_TSEMIC = 23,                    /* TSEMIC  */
  YYSYMBOL_TCOMA = 24,                     /* TCOMA  */
  YYSYMBOL_RPROGRAM = 25,                  /* RPROGRAM  */
  YYSYMBOL_RPROCEDURE = 26,                /* RPROCEDURE  */
  YYSYMBOL_RMAIN = 27,                     /* RMAIN  */
  YYSYMBOL_RVAR = 28,                      /* RVAR  */
  YYSYMBOL_RINTEGER = 29,                  /* RINTEGER  */
  YYSYMBOL_RFLOAT = 30,                    /* RFLOAT  */
  YYSYMBOL_RIN = 31,                       /* RIN  */
  YYSYMBOL_ROUT = 32,                      /* ROUT  */
  YYSYMBOL_RIF = 33,                       /* RIF  */
  YYSYMBOL_RWHILE = 34,                    /* RWHILE  */
  YYSYMBOL_RCONTINUE = 35,                 /* RCONTINUE  */
  YYSYMBOL_RFINALLY = 36,                  /* RFINALLY  */
  YYSYMBOL_RFOREVER = 37,                  /* RFOREVER  */
  YYSYMBOL_RBREAK = 38,                    /* RBREAK  */
  YYSYMBOL_RREAD = 39,                     /* RREAD  */
  YYSYMBOL_RPRINTLN = 40,                  /* RPRINTLN  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_start = 42,                     /* start  */
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_block = 44,                     /* block  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_procs_block = 46,               /* procs_block  */
  YYSYMBOL_declarations = 47,              /* declarations  */
  YYSYMBOL_48_3 = 48,                      /* $@3  */
  YYSYMBOL_id_list = 49,                   /* id_list  */
  YYSYMBOL_id_list_rem = 50,               /* id_list_rem  */
  YYSYMBOL_type = 51,                      /* type  */
  YYSYMBOL_subprogs = 52,                  /* subprogs  */
  YYSYMBOL_procs = 53,                     /* procs  */
  YYSYMBOL_subprogram = 54,                /* subprogram  */
  YYSYMBOL_main_subprog = 55,              /* main_subprog  */
  YYSYMBOL_56_4 = 56,                      /* $@4  */
  YYSYMBOL_arguments = 57,                 /* arguments  */
  YYSYMBOL_param_list = 58,                /* param_list  */
  YYSYMBOL_59_5 = 59,                      /* $@5  */
  YYSYMBOL_par_class = 60,                 /* par_class  */
  YYSYMBOL_param_list_rem = 61,            /* param_list_rem  */
  YYSYMBOL_62_6 = 62,                      /* $@6  */
  YYSYMBOL_statements = 63,                /* statements  */
  YYSYMBOL_statement = 64,                 /* statement  */
  YYSYMBOL_65_7 = 65,                      /* $@7  */
  YYSYMBOL_variable = 66,                  /* variable  */
  YYSYMBOL_expression = 67,                /* expression  */
  YYSYMBOL_M = 68                          /* M  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   226

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   112,   112,   112,   119,   119,   122,   125,   125,   130,
     132,   136,   140,   142,   143,   145,   146,   148,   149,   151,
     153,   153,   156,   157,   159,   159,   162,   163,   164,   166,
     166,   168,   170,   176,   181,   186,   194,   203,   202,   217,
     226,   235,   241,   248,   250,   257,   265,   273,   280,   287,
     294,   301,   308,   316,   323,   329,   336,   343,   352
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TID", "TFLOAT_CONST",
  "TINTEGER_CONST", "TCOMENTARIO_LINEA", "TIGUALQUE", "TMENOR",
  "TMENOROIGUAL", "TMAYOR", "TMAYOROIGUAL", "TDIFERENTEA", "TSUMA",
  "TRESTA", "TMULTIPLICACION", "TDIVISION", "TASSIG", "TPARENTESIS_ABRIR",
  "TPARENTESIS_CERRAR", "TLBRACE", "TRBRACE", "TDOSPUNTOS", "TSEMIC",
  "TCOMA", "RPROGRAM", "RPROCEDURE", "RMAIN", "RVAR", "RINTEGER", "RFLOAT",
  "RIN", "ROUT", "RIF", "RWHILE", "RCONTINUE", "RFINALLY", "RFOREVER",
  "RBREAK", "RREAD", "RPRINTLN", "$accept", "start", "$@1", "block", "$@2",
  "procs_block", "declarations", "$@3", "id_list", "id_list_rem", "type",
  "subprogs", "procs", "subprogram", "main_subprog", "$@4", "arguments",
  "param_list", "$@5", "par_class", "param_list_rem", "$@6", "statements",
  "statement", "$@7", "variable", "expression", "M", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,    18,    22,   -65,   -65,    -2,    20,   -65,   -65,     5,
       8,     1,    25,   -65,   -16,     9,   -65,     1,   -65,     5,
     -65,   -65,    17,    13,   -65,   -65,   -65,   -65,    20,    -2,
      -2,    -2,    10,    31,    21,   -65,    37,   -65,   -13,   -65,
      56,    32,    56,    34,   -65,   -16,   -65,     6,    40,    29,
      51,    60,    62,     4,   -65,    64,    79,   -65,    14,   -65,
     -65,   -65,   -65,   -65,     6,   152,    61,     6,   -65,   -65,
      83,     6,   -65,   -65,     6,   -65,    65,   184,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,    67,    72,
     168,     6,   -65,    80,   197,   118,    20,   -65,   -65,   210,
     210,   210,   210,   210,   210,     0,     0,   -65,   -65,   -65,
     -65,    78,   135,    82,    85,   -65,    81,    56,    56,   -65,
     -65,   -65,   -65,   -13,    56,    56,    56,   -65,   -16,    88,
      89,    56,   -65,    98,    99,   102,    65,   -65,   -65,   -65,
     -65,    70,   113,   116,    56,    30,   114,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     1,     9,     0,     3,     4,    12,
       0,     0,     0,    10,     0,     0,     5,     0,    16,    12,
      13,    14,     0,    23,    20,    15,    11,     7,     0,     9,
       9,     9,     0,     0,     0,    18,     0,     8,     0,    22,
       0,     6,     0,    26,    27,     0,    43,     0,    58,     0,
       0,     0,     0,     0,    33,     0,     0,    17,     0,    28,
      24,    54,    56,    55,     0,     0,     0,     0,    58,    58,
       0,     0,    19,    32,     0,    21,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,     0,     0,     0,     0,    25,    57,    44,
      45,    48,    46,    47,    49,    50,    51,    52,    53,    58,
      58,     0,     0,     0,     0,    34,     0,     0,     0,    58,
      58,    41,    42,     0,    58,    58,     0,    40,     0,     0,
       0,    58,    29,     0,     0,     0,    31,    35,    36,    37,
      30,     0,     0,     0,     0,     0,     0,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -65,   -65,   -65,    71,     3,   -65,   -25,   119,
     -43,   122,   -65,   111,   -65,   -65,   -65,   -65,   -65,    46,
      19,   -65,   -42,   -52,   -65,    84,    33,   -64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     5,     7,    11,    34,    35,    31,    10,    13,
      22,    16,    41,    17,    18,    30,    29,    33,    76,    45,
      97,   136,    53,    54,   141,    55,    65,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    73,    60,    32,    91,    92,    73,    46,     8,    61,
      62,    63,    23,    20,    21,    86,    87,    46,    43,    44,
       1,     3,     4,     9,    64,    72,     6,    15,    19,    12,
      14,    28,    38,    46,    37,    75,    24,    47,    48,    49,
      27,    40,    50,    51,    52,   117,   118,    47,    48,    49,
      39,   146,    50,    51,    52,   126,   127,    42,    56,    46,
     129,   130,    68,    47,    48,    49,    59,   135,    50,    51,
      52,   116,    73,    73,    69,   124,   125,    66,    70,    73,
      71,    74,    23,    89,   131,   132,    46,   109,    96,    47,
      48,    49,   110,    73,    50,    51,    52,    77,   119,   113,
      90,    36,   145,   123,    94,   121,   142,    95,   122,   133,
     134,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   137,   138,   139,   112,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,   143,   144,   147,    26,    25,
       0,   115,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    57,     0,    93,   140,     0,     0,   120,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   128,
       0,     0,     0,     0,    88,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
     111,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,    98,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
      42,    53,    45,    28,    68,    69,    58,     3,     5,     3,
       4,     5,     3,    29,    30,    15,    16,     3,    31,    32,
      25,     3,     0,     3,    18,    21,    28,    26,     3,    24,
      22,    18,    22,     3,    31,    21,    27,    33,    34,    35,
      23,    20,    38,    39,    40,   109,   110,    33,    34,    35,
      19,    21,    38,    39,    40,   119,   120,    20,    26,     3,
     124,   125,    33,    33,    34,    35,    32,   131,    38,    39,
      40,    96,   124,   125,    23,   117,   118,    37,    18,   131,
      18,    17,     3,    22,   126,   128,     3,    20,    23,    33,
      34,    35,    20,   145,    38,    39,    40,    64,    20,    19,
      67,    30,   144,    22,    71,    23,    36,    74,    23,    21,
      21,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    23,    23,    21,    91,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    22,    20,    23,    19,    17,
      -1,    23,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    41,    -1,    70,   136,    -1,    -1,    23,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   123,
      -1,    -1,    -1,    -1,    22,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      22,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    19,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    19,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    42,     3,     0,    43,    28,    44,    47,     3,
      49,    45,    24,    50,    22,    26,    52,    54,    55,     3,
      29,    30,    51,     3,    27,    52,    50,    23,    18,    57,
      56,    48,    49,    58,    46,    47,    46,    47,    22,    19,
      20,    53,    20,    31,    32,    60,     3,    33,    34,    35,
      38,    39,    40,    63,    64,    66,    26,    54,    63,    32,
      51,     3,     4,     5,    18,    67,    37,    68,    33,    23,
      18,    18,    21,    64,    17,    21,    59,    67,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    22,    22,
      67,    68,    68,    66,    67,    67,    23,    61,    19,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    20,
      20,    22,    67,    19,    19,    23,    49,    68,    68,    20,
      23,    23,    23,    22,    63,    63,    68,    68,    60,    68,
      68,    63,    51,    21,    21,    68,    62,    23,    23,    21,
      61,    65,    36,    22,    20,    63,    21,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    43,    42,    45,    44,    46,    48,    47,    47,
      49,    50,    50,    51,    51,    52,    52,    53,    53,    54,
      56,    55,    57,    57,    59,    58,    60,    60,    60,    62,
      61,    61,    63,    63,    64,    64,    64,    65,    64,    64,
      64,    64,    64,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     3,     2,     0,     7,     0,
       2,     3,     0,     1,     1,     2,     1,     2,     0,     7,
       0,     7,     3,     0,     0,     6,     1,     1,     2,     0,
       7,     0,     2,     1,     4,     9,     9,     0,    16,     3,
       6,     5,     5,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     3,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 112 "parser.y"
                     { codigo.anadirInstruccion(  "prog "  + codigo.dollar_to_string( (yyvsp[0].str) )  ); }
#line 1526 "parser.cpp"
    break;

  case 3: /* start: RPROGRAM TID $@1 block  */
#line 113 "parser.y"
                {
               codigo.anadirInstruccion("halt");
		           codigo.escribir() ; 
            }
#line 1535 "parser.cpp"
    break;

  case 4: /* $@2: %empty  */
#line 119 "parser.y"
                     {codigo.anadirInstruccion("call main");}
#line 1541 "parser.cpp"
    break;

  case 7: /* $@3: %empty  */
#line 125 "parser.y"
                                                   { 
                  codigo.anadirDeclaraciones( *(yyvsp[-3].list) , *(yyvsp[-1].str) ) ;
                   delete (yyvsp[-3].list); delete (yyvsp[-1].str) ;
                }
#line 1550 "parser.cpp"
    break;

  case 10: /* id_list: TID id_list_rem  */
#line 132 "parser.y"
                          { (yyval.list) = new vector<string>; 
                            (yyval.list) -> push_back( *(yyvsp[-1].str) ); 
                            }
#line 1558 "parser.cpp"
    break;

  case 11: /* id_list_rem: TCOMA TID id_list_rem  */
#line 136 "parser.y"
                                     {  
                              (yyval.list) = (yyvsp[0].list) ;
                              (yyval.list) -> push_back( *(yyvsp[-1].str) ); 
                          }
#line 1567 "parser.cpp"
    break;

  case 12: /* id_list_rem: %empty  */
#line 140 "parser.y"
                     { (yyval.list) = new vector<string>; }
#line 1573 "parser.cpp"
    break;

  case 13: /* type: RINTEGER  */
#line 142 "parser.y"
                { (yyval.str) = new string("int");    }
#line 1579 "parser.cpp"
    break;

  case 14: /* type: RFLOAT  */
#line 143 "parser.y"
               {  (yyval.str) = new string("real");   }
#line 1585 "parser.cpp"
    break;

  case 19: /* subprogram: RPROCEDURE TID arguments procs_block TLBRACE statements TRBRACE  */
#line 151 "parser.y"
                                                                             { codigo.anadirInstruccion("endproc" + codigo.dollar_to_string( (yyvsp[-5].str) ) ); }
#line 1591 "parser.cpp"
    break;

  case 20: /* $@4: %empty  */
#line 153 "parser.y"
                                { codigo.anadirInstruccion("proc main"); }
#line 1597 "parser.cpp"
    break;

  case 24: /* $@5: %empty  */
#line 159 "parser.y"
                                               {}
#line 1603 "parser.cpp"
    break;

  case 26: /* par_class: RIN  */
#line 162 "parser.y"
                {}
#line 1609 "parser.cpp"
    break;

  case 27: /* par_class: ROUT  */
#line 163 "parser.y"
                  {}
#line 1615 "parser.cpp"
    break;

  case 28: /* par_class: RIN ROUT  */
#line 164 "parser.y"
                      {}
#line 1621 "parser.cpp"
    break;

  case 29: /* $@6: %empty  */
#line 166 "parser.y"
                                                          {}
#line 1627 "parser.cpp"
    break;

  case 32: /* statements: statements statement  */
#line 171 "parser.y"
               { 
               (yyval.sentc) = new sentences;
               (yyval.sentc)->exits = codigo.unirInt((yyvsp[-1].sentc)->exits , (yyvsp[0].sentc)->exits);
               (yyval.sentc)->continues = codigo.unirInt((yyvsp[-1].sentc)->continues , (yyvsp[0].sentc)->continues);
               }
#line 1637 "parser.cpp"
    break;

  case 33: /* statements: statement  */
#line 177 "parser.y"
               { 
               (yyval.sentc) = (yyvsp[0].sentc);
               }
#line 1645 "parser.cpp"
    break;

  case 34: /* statement: variable TASSIG expression TSEMIC  */
#line 182 "parser.y"
            { codigo.anadirInstruccion( *(yyvsp[-3].str) + *(yyvsp[-2].str) + (yyvsp[-1].expr) -> str + ";" )  ; 
            (yyval.sentc) = new sentences;              
            }
#line 1653 "parser.cpp"
    break;

  case 35: /* statement: RIF expression TDOSPUNTOS TLBRACE M statements M TRBRACE TSEMIC  */
#line 187 "parser.y"
            { 
              codigo.completarInstrucciones( (yyvsp[-7].expr) -> trues, (yyvsp[-4].number) ); 
              codigo.completarInstrucciones( (yyvsp[-7].expr) -> falses, (yyvsp[-2].number) );
              // $$->exits = codigo.unirInt($$->exits , $6->exits);
              // $$->continues = codigo.unirInt($$->continues , $6->continues);
            }
#line 1664 "parser.cpp"
    break;

  case 36: /* statement: RWHILE RFOREVER TDOSPUNTOS TLBRACE M statements M TRBRACE TSEMIC  */
#line 195 "parser.y"
            {
            codigo.completarInstrucciones( (yyvsp[-3].sentc) -> continues, (yyvsp[-4].number) );
            codigo.completarInstrucciones( (yyvsp[-3].sentc) -> exits, (yyvsp[-2].number) + 1 );
            codigo.anadirInstruccion("goto " + to_string((yyvsp[-4].number)));
            (yyval.sentc) = new sentences;
            }
#line 1675 "parser.cpp"
    break;

  case 37: /* $@7: %empty  */
#line 203 "parser.y"
           {
            codigo.anadirInstruccion("goto " + to_string((yyvsp[-7].number)));
            // codigo.completarInstrucciones( $7 -> continues, $2 );
            codigo.completarInstrucciones( (yyvsp[-6].expr) -> trues, (yyvsp[-3].number) );
            codigo.completarInstrucciones( (yyvsp[-6].expr) -> falses, (yyvsp[-1].number) + 1 );
           }
#line 1686 "parser.cpp"
    break;

  case 38: /* statement: RWHILE M expression TDOSPUNTOS TLBRACE M statements M TRBRACE $@7 RFINALLY TDOSPUNTOS TLBRACE statements TRBRACE TSEMIC  */
#line 210 "parser.y"
            {
              // int referencia = codigo.obtenRef();
              // codigo.completarInstrucciones($7->exits, referencia);
              // // codigo.completarInstrucciones($13->exits, referencia);
              // // codigo.completarInstrucciones($13->continues, referencia);
            }
#line 1697 "parser.cpp"
    break;

  case 39: /* statement: RBREAK TSEMIC M  */
#line 218 "parser.y"
            { 
            (yyval.sentc) = new sentences;
            printf("VALOR BREAK");
            printf("%d, " ,(yyvsp[0].number)); 
            (yyval.sentc)->exits.push_back((yyvsp[0].number));
            codigo.anadirInstruccion("goto ");
            }
#line 1709 "parser.cpp"
    break;

  case 40: /* statement: RCONTINUE RIF M expression TSEMIC M  */
#line 227 "parser.y"
            {
              (yyval.sentc) = new sentences;
              printf("VALOR CONTINUE");
              printf("%d, " ,(yyvsp[-3].number)); 
              codigo.completarInstrucciones((yyvsp[-2].expr) -> falses, (yyvsp[0].number));
              (yyval.sentc)->continues.push_back((yyvsp[-3].number));
            }
#line 1721 "parser.cpp"
    break;

  case 41: /* statement: RREAD TPARENTESIS_ABRIR variable TPARENTESIS_CERRAR TSEMIC  */
#line 236 "parser.y"
            { codigo.anadirInstruccion( "read " + *(yyvsp[-2].str) ) ;
            (yyval.sentc) = new sentences;
            }
#line 1729 "parser.cpp"
    break;

  case 42: /* statement: RPRINTLN TPARENTESIS_ABRIR expression TPARENTESIS_CERRAR TSEMIC  */
#line 242 "parser.y"
            { codigo.anadirInstruccion( "println " + (yyvsp[-2].expr) -> str ) ;
            (yyval.sentc) = new sentences;
            }
#line 1737 "parser.cpp"
    break;

  case 43: /* variable: TID  */
#line 248 "parser.y"
               { (yyval.str) = (yyvsp[0].str);  }
#line 1743 "parser.cpp"
    break;

  case 44: /* expression: expression TIGUALQUE expression  */
#line 251 "parser.y"
            { 
              (yyval.expr) = new expresionstruct; 
              *(yyval.expr) = makecomparison((yyvsp[-2].expr) -> str, *(yyvsp[-1].str) , (yyvsp[0].expr) -> str) ; 
              delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
            }
#line 1753 "parser.cpp"
    break;

  case 45: /* expression: expression TMENOR expression  */
#line 258 "parser.y"
            { 
              (yyval.expr) = new expresionstruct; 
              *(yyval.expr) = makecomparison((yyvsp[-2].expr) -> str, *(yyvsp[-1].str) , (yyvsp[0].expr) -> str) ; 
              delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
            }
#line 1763 "parser.cpp"
    break;

  case 46: /* expression: expression TMAYOR expression  */
#line 266 "parser.y"
            { 
              (yyval.expr) = new expresionstruct; 
              *(yyval.expr) = makecomparison((yyvsp[-2].expr) -> str, *(yyvsp[-1].str) , (yyvsp[0].expr) -> str) ; 
              delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
            }
#line 1773 "parser.cpp"
    break;

  case 47: /* expression: expression TMAYOROIGUAL expression  */
#line 274 "parser.y"
            { 
              (yyval.expr) = new expresionstruct; 
              *(yyval.expr) = makecomparison((yyvsp[-2].expr) -> str, *(yyvsp[-1].str) , (yyvsp[0].expr) -> str) ; 
              delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
            }
#line 1783 "parser.cpp"
    break;

  case 48: /* expression: expression TMENOROIGUAL expression  */
#line 281 "parser.y"
            { 
              (yyval.expr) = new expresionstruct; 
              *(yyval.expr) = makecomparison((yyvsp[-2].expr) -> str, *(yyvsp[-1].str) , (yyvsp[0].expr) -> str) ; 
              delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
            }
#line 1793 "parser.cpp"
    break;

  case 49: /* expression: expression TDIFERENTEA expression  */
#line 288 "parser.y"
            { 
              (yyval.expr) = new expresionstruct; 
              *(yyval.expr) = makecomparison((yyvsp[-2].expr) -> str, *(yyvsp[-1].str) , (yyvsp[0].expr) -> str) ; 
              delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
            }
#line 1803 "parser.cpp"
    break;

  case 50: /* expression: expression TSUMA expression  */
#line 295 "parser.y"
            { 
              (yyval.expr) = new expresionstruct; 
              *(yyval.expr) = makearithmetic((yyvsp[-2].expr) -> str, *(yyvsp[-1].str) , (yyvsp[0].expr) -> str) ; 
              delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
            }
#line 1813 "parser.cpp"
    break;

  case 51: /* expression: expression TRESTA expression  */
#line 302 "parser.y"
            { 
              (yyval.expr) = new expresionstruct; 
              *(yyval.expr) = makearithmetic((yyvsp[-2].expr) -> str, *(yyvsp[-1].str) , (yyvsp[0].expr) -> str) ; 
              delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
            }
#line 1823 "parser.cpp"
    break;

  case 52: /* expression: expression TMULTIPLICACION expression  */
#line 309 "parser.y"
            { 
              (yyval.expr) = new expresionstruct; 
              *(yyval.expr) = makearithmetic((yyvsp[-2].expr) -> str, *(yyvsp[-1].str) , (yyvsp[0].expr) -> str) ; 
              delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
            }
#line 1833 "parser.cpp"
    break;

  case 53: /* expression: expression TDIVISION expression  */
#line 317 "parser.y"
            { 
              (yyval.expr) = new expresionstruct; 
              *(yyval.expr) = makearithmetic((yyvsp[-2].expr) -> str, *(yyvsp[-1].str) , (yyvsp[0].expr) -> str) ; 
              delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
            }
#line 1843 "parser.cpp"
    break;

  case 54: /* expression: TID  */
#line 324 "parser.y"
            { 
              (yyval.expr) = new expresionstruct; 
              (yyval.expr) -> str = *(yyvsp[0].str) ; 
            }
#line 1852 "parser.cpp"
    break;

  case 55: /* expression: TINTEGER_CONST  */
#line 330 "parser.y"
            { 
              (yyval.expr) = new expresionstruct; 
              (yyval.expr) -> str = *(yyvsp[0].str); 
            }
#line 1861 "parser.cpp"
    break;

  case 56: /* expression: TFLOAT_CONST  */
#line 337 "parser.y"
            { 
              (yyval.expr) = new expresionstruct; 
              (yyval.expr) -> str = *(yyvsp[0].str); 
            }
#line 1870 "parser.cpp"
    break;

  case 57: /* expression: TPARENTESIS_ABRIR expression TPARENTESIS_CERRAR  */
#line 344 "parser.y"
            { 
              (yyval.expr) = new expresionstruct; 
              (yyval.expr) = (yyvsp[-1].expr); 
            }
#line 1879 "parser.cpp"
    break;

  case 58: /* M: %empty  */
#line 352 "parser.y"
           { (yyval.number) = codigo.obtenRef() ; }
#line 1885 "parser.cpp"
    break;


#line 1889 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 355 "parser.y"


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


