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
#line 1 "cool.y"

    /* bibliotecas, função de erro*/
    #include <stdio.h>
    #include <stdlib.h>
    #include <string>
    #include "arv.h"
    #include "semantico.h"

    int yylex(); 
    void yyerror(const char *s); 

    Programa* raiz_arv = nullptr; /* ponteiro para a raiz da arvore de sintaxe abstrata */

#line 85 "cool.tab.c"

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

#include "cool.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TYPEID = 3,                     /* TYPEID  */
  YYSYMBOL_OBJECTID = 4,                   /* OBJECTID  */
  YYSYMBOL_INT_CONST = 5,                  /* INT_CONST  */
  YYSYMBOL_STR_CONST = 6,                  /* STR_CONST  */
  YYSYMBOL_CLASS = 7,                      /* CLASS  */
  YYSYMBOL_INHERITS = 8,                   /* INHERITS  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_THEN = 10,                      /* THEN  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_FI = 12,                        /* FI  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_LOOP = 14,                      /* LOOP  */
  YYSYMBOL_POOL = 15,                      /* POOL  */
  YYSYMBOL_LET = 16,                       /* LET  */
  YYSYMBOL_IN = 17,                        /* IN  */
  YYSYMBOL_CASE = 18,                      /* CASE  */
  YYSYMBOL_OF = 19,                        /* OF  */
  YYSYMBOL_ESAC = 20,                      /* ESAC  */
  YYSYMBOL_NEW = 21,                       /* NEW  */
  YYSYMBOL_ISVOID = 22,                    /* ISVOID  */
  YYSYMBOL_NOT = 23,                       /* NOT  */
  YYSYMBOL_TRUE_CONST = 24,                /* TRUE_CONST  */
  YYSYMBOL_FALSE_CONST = 25,               /* FALSE_CONST  */
  YYSYMBOL_ASSIGN = 26,                    /* ASSIGN  */
  YYSYMBOL_LE = 27,                        /* LE  */
  YYSYMBOL_DARROW = 28,                    /* DARROW  */
  YYSYMBOL_29_ = 29,                       /* '<'  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '-'  */
  YYSYMBOL_33_ = 33,                       /* '*'  */
  YYSYMBOL_34_ = 34,                       /* '/'  */
  YYSYMBOL_35_ = 35,                       /* '~'  */
  YYSYMBOL_36_ = 36,                       /* '@'  */
  YYSYMBOL_37_ = 37,                       /* '.'  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* ':'  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_programa = 46,                  /* programa  */
  YYSYMBOL_lista_classes = 47,             /* lista_classes  */
  YYSYMBOL_classe = 48,                    /* classe  */
  YYSYMBOL_features = 49,                  /* features  */
  YYSYMBOL_lista_features = 50,            /* lista_features  */
  YYSYMBOL_feature = 51,                   /* feature  */
  YYSYMBOL_formals = 52,                   /* formals  */
  YYSYMBOL_lista_formals = 53,             /* lista_formals  */
  YYSYMBOL_formal = 54,                    /* formal  */
  YYSYMBOL_expr = 55,                      /* expr  */
  YYSYMBOL_exprs = 56,                     /* exprs  */
  YYSYMBOL_lista_exprs = 57,               /* lista_exprs  */
  YYSYMBOL_bloco_exprs = 58,               /* bloco_exprs  */
  YYSYMBOL_lista_let = 59,                 /* lista_let  */
  YYSYMBOL_lista_cases = 60,               /* lista_cases  */
  YYSYMBOL_item_case = 61                  /* item_case  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   289

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
      42,    43,    33,    31,    44,    32,    37,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    38,
      29,    30,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,    35,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    39,    39,    47,    54,    63,    68,    77,    81,    88,
      95,   104,   108,   112,   121,   124,   131,   138,   147,   154,
     157,   161,   165,   169,   172,   175,   178,   181,   184,   187,
     190,   193,   196,   199,   202,   205,   208,   211,   214,   217,
     220,   223,   226,   229,   232,   238,   241,   248,   255,   264,
     271,   280,   287,   294,   300,   308,   315,   324
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TYPEID", "OBJECTID",
  "INT_CONST", "STR_CONST", "CLASS", "INHERITS", "IF", "THEN", "ELSE",
  "FI", "WHILE", "LOOP", "POOL", "LET", "IN", "CASE", "OF", "ESAC", "NEW",
  "ISVOID", "NOT", "TRUE_CONST", "FALSE_CONST", "ASSIGN", "LE", "DARROW",
  "'<'", "'='", "'+'", "'-'", "'*'", "'/'", "'~'", "'@'", "'.'", "';'",
  "'{'", "'}'", "':'", "'('", "')'", "','", "$accept", "programa",
  "lista_classes", "classe", "features", "lista_features", "feature",
  "formals", "lista_formals", "formal", "expr", "exprs", "lista_exprs",
  "bloco_exprs", "lista_let", "lista_cases", "item_case", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-112)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,     6,    11,    -3,   -19,    -7,  -112,   -12,  -112,    30,
      32,  -112,    -5,   -27,     7,    32,    10,    32,    47,    51,
    -112,    19,  -112,    20,    33,    25,    24,    27,  -112,  -112,
    -112,    89,    65,    28,    51,   -21,  -112,  -112,    89,    89,
      69,    89,    71,    89,    89,  -112,  -112,    89,    89,    89,
     241,  -112,    73,  -112,    89,    89,   105,   140,    36,   -15,
     167,  -112,    -6,   241,    -6,   205,    40,   178,    89,    89,
      89,    89,    89,    89,    89,    75,    77,    44,   241,   241,
      41,    43,    89,    89,    82,    89,    85,    86,  -112,  -112,
     217,  -112,   252,   252,   252,    -9,    -9,    -6,    -6,    54,
      50,    89,  -112,    89,   116,   151,    70,   241,    56,    58,
       2,  -112,  -112,    96,    89,   193,   241,    89,  -112,    89,
      98,   103,  -112,  -112,    66,    74,  -112,   128,   241,    83,
      88,    89,  -112,  -112,    89,    89,    76,   241,   229,  -112,
    -112
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     0,     1,     0,     3,     0,
       7,     4,     0,     0,     0,     8,     0,     7,     0,    14,
       5,     0,     9,     0,    11,     0,     0,    15,    16,    10,
       6,     0,     0,     0,     0,    40,    41,    42,     0,     0,
       0,     0,     0,     0,     0,    43,    44,     0,     0,     0,
      12,    18,     0,    17,     0,    45,     0,     0,     0,     0,
       0,    28,    29,    38,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    47,
       0,    46,     0,     0,     0,     0,     0,     0,    49,    25,
       0,    39,    36,    35,    37,    30,    31,    32,    33,     0,
       0,     0,    22,     0,     0,     0,    51,    26,     0,     0,
       0,    55,    50,     0,    45,     0,    48,     0,    24,     0,
       0,     0,    27,    56,     0,     0,    13,     0,    52,    53,
       0,    45,    20,    23,     0,     0,     0,    54,     0,    21,
      57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -112,  -112,  -112,   115,   104,  -112,   107,  -112,  -112,    91,
     -31,  -111,  -112,  -112,  -112,  -112,    13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    14,    15,    16,    26,    27,    28,
      79,    80,    81,    66,    59,   110,   111
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,     9,    85,   125,     1,    54,   109,    56,    57,     5,
      60,     6,    62,    63,    18,    19,    64,    65,    67,     8,
     136,    55,   122,    78,    73,    74,    11,    75,    76,    86,
      75,    76,    10,    12,    17,    90,    13,    92,    93,    94,
      95,    96,    97,    98,    35,    36,    37,    20,    22,    38,
      24,   104,   105,    39,   107,    25,    40,    29,    41,    31,
      30,    42,    43,    44,    45,    46,    32,    33,    51,    52,
     115,    34,   116,    58,    61,    47,    77,    84,    99,    48,
      89,   100,    49,   101,   102,   106,   127,   103,   128,   108,
     109,   113,   114,    35,    36,    37,   119,   120,    38,   121,
     124,   129,    39,   137,   138,    40,   130,    41,   131,   134,
      42,    43,    44,    45,    46,    82,   135,   132,     7,   139,
       0,    23,    21,   123,    47,    53,     0,   117,    48,     0,
       0,    49,    68,     0,    69,    70,    71,    72,    73,    74,
     133,    75,    76,    68,     0,    69,    70,    71,    72,    73,
      74,     0,    75,    76,    83,    68,     0,    69,    70,    71,
      72,    73,    74,     0,    75,    76,   118,    68,     0,    69,
      70,    71,    72,    73,    74,     0,    75,    76,    68,     0,
      69,    70,    71,    72,    73,    74,    87,    75,    76,     0,
       0,     0,     0,     0,    68,     0,    69,    70,    71,    72,
      73,    74,     0,    75,    76,    68,     0,    69,    70,    71,
      72,    73,    74,     0,    75,    76,     0,     0,     0,     0,
      68,    91,    69,    70,    71,    72,    73,    74,     0,    75,
      76,     0,    68,   126,    69,    70,    71,    72,    73,    74,
       0,    75,    76,    88,    68,     0,    69,    70,    71,    72,
      73,    74,     0,    75,    76,   112,    68,     0,    69,    70,
      71,    72,    73,    74,     0,    75,    76,   140,    68,     0,
      69,    70,    71,    72,    73,    74,     0,    75,    76,    -1,
       0,    -1,    -1,    71,    72,    73,    74,     0,    75,    76
};

static const yytype_int16 yycheck[] =
{
      31,     8,    17,   114,     7,    26,     4,    38,    39,     3,
      41,     0,    43,    44,    41,    42,    47,    48,    49,    38,
     131,    42,    20,    54,    33,    34,    38,    36,    37,    44,
      36,    37,    39,     3,    39,    66,     4,    68,    69,    70,
      71,    72,    73,    74,     4,     5,     6,    40,    38,     9,
       3,    82,    83,    13,    85,     4,    16,    38,    18,    26,
      40,    21,    22,    23,    24,    25,    41,    43,     3,    41,
     101,    44,   103,     4,     3,    35,     3,    41,     3,    39,
      40,     4,    42,    39,    43,     3,   117,    44,   119,     4,
       4,    37,    42,     4,     5,     6,    26,    41,     9,    41,
       4,     3,    13,   134,   135,    16,     3,    18,    42,    26,
      21,    22,    23,    24,    25,    10,    28,    43,     3,    43,
      -1,    17,    15,   110,    35,    34,    -1,    11,    39,    -1,
      -1,    42,    27,    -1,    29,    30,    31,    32,    33,    34,
      12,    36,    37,    27,    -1,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    14,    27,    -1,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    15,    27,    -1,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    27,    -1,
      29,    30,    31,    32,    33,    34,    19,    36,    37,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    27,    -1,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,
      27,    43,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    -1,    27,    40,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    38,    27,    -1,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    38,    27,    -1,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    27,    -1,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    27,
      -1,    29,    30,    31,    32,    33,    34,    -1,    36,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    46,    47,    48,     3,     0,    48,    38,     8,
      39,    38,     3,     4,    49,    50,    51,    39,    41,    42,
      40,    51,    38,    49,     3,     4,    52,    53,    54,    38,
      40,    26,    41,    43,    44,     4,     5,     6,     9,    13,
      16,    18,    21,    22,    23,    24,    25,    35,    39,    42,
      55,     3,    41,    54,    26,    42,    55,    55,     4,    59,
      55,     3,    55,    55,    55,    55,    58,    55,    27,    29,
      30,    31,    32,    33,    34,    36,    37,     3,    55,    55,
      56,    57,    10,    14,    41,    17,    44,    19,    38,    40,
      55,    43,    55,    55,    55,    55,    55,    55,    55,     3,
       4,    39,    43,    44,    55,    55,     3,    55,     4,     4,
      60,    61,    38,    37,    42,    55,    55,    11,    15,    26,
      41,    41,    20,    61,     4,    56,    40,    55,    55,     3,
       3,    42,    43,    12,    26,    28,    56,    55,    55,    43,
      38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    51,    51,    52,    52,    53,    53,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    59,    59,    60,    60,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     5,     7,     0,     1,     2,
       3,     3,     5,     9,     0,     1,     1,     3,     3,     3,
       6,     8,     4,     7,     5,     3,     4,     5,     2,     2,
       3,     3,     3,     3,     2,     3,     3,     3,     2,     3,
       1,     1,     1,     1,     1,     0,     1,     1,     3,     2,
       3,     3,     5,     5,     7,     1,     2,     6
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
  case 2: /* programa: lista_classes  */
#line 40 "cool.y"
    {
        raiz_arv = new Programa((yyvsp[0].no_arvore));
        (yyval.no_arvore) = raiz_arv;
    }
#line 1247 "cool.tab.c"
    break;

  case 3: /* lista_classes: classe ';'  */
#line 48 "cool.y"
    {
        /* encontrou a primeira classe = cria uma nova lista vazia e adiciona ela */
        ListaClasses* l = new ListaClasses();
        l->adicionar((yyvsp[-1].no_arvore));
        (yyval.no_arvore) = l;
    }
#line 1258 "cool.tab.c"
    break;

  case 4: /* lista_classes: lista_classes classe ';'  */
#line 55 "cool.y"
    {
        /* ja tem uma lista $1 = só adiciona a nova classe $2 nela */
        ((ListaClasses*)(yyvsp[-2].no_arvore))->adicionar((yyvsp[-1].no_arvore));
        (yyval.no_arvore) = (yyvsp[-2].no_arvore);
    }
#line 1268 "cool.tab.c"
    break;

  case 5: /* classe: CLASS TYPEID '{' features '}'  */
#line 64 "cool.y"
    {
        /* $2 é o TYPEID (nome da classe) $4 são as features herda de object por padrao. */
        (yyval.no_arvore) = new Classe((yyvsp[-3].texto), "Object", (yyvsp[-1].no_arvore));
    }
#line 1277 "cool.tab.c"
    break;

  case 6: /* classe: CLASS TYPEID INHERITS TYPEID '{' features '}'  */
#line 69 "cool.y"
    {
        /* $2 é o TYPEID (nome da classe) $4 é o TYPEID da classe pai $6 são as features */
        (yyval.no_arvore) = new Classe((yyvsp[-5].texto), (yyvsp[-3].texto), (yyvsp[-1].no_arvore));
    }
#line 1286 "cool.tab.c"
    break;

  case 7: /* features: %empty  */
#line 77 "cool.y"
    {
        /* se a classe for vazia = retorna uma lista vazia */
        (yyval.no_arvore) = new ListaFeatures();
    }
#line 1295 "cool.tab.c"
    break;

  case 8: /* features: lista_features  */
#line 82 "cool.y"
    {
        (yyval.no_arvore) = (yyvsp[0].no_arvore);
    }
#line 1303 "cool.tab.c"
    break;

  case 9: /* lista_features: feature ';'  */
#line 89 "cool.y"
    {
        /* encontrou a primeira feature = cria uma nova lista vazia e adiciona ela */
        ListaFeatures* l = new ListaFeatures();
        l->adicionar((yyvsp[-1].no_arvore));
        (yyval.no_arvore) = l;
    }
#line 1314 "cool.tab.c"
    break;

  case 10: /* lista_features: lista_features feature ';'  */
#line 96 "cool.y"
    {
        /* ja tem uma lista $1 = só adiciona a nova feature $2 nela */
        ((ListaFeatures*)(yyvsp[-2].no_arvore))->adicionar((yyvsp[-1].no_arvore));
        (yyval.no_arvore) = (yyvsp[-2].no_arvore);
    }
#line 1324 "cool.tab.c"
    break;

  case 11: /* feature: OBJECTID ':' TYPEID  */
#line 105 "cool.y"
    {
        (yyval.no_arvore) = new Atributo((yyvsp[-2].texto), (yyvsp[0].texto), NULL);
    }
#line 1332 "cool.tab.c"
    break;

  case 12: /* feature: OBJECTID ':' TYPEID ASSIGN expr  */
#line 109 "cool.y"
    {
        (yyval.no_arvore) = new Atributo((yyvsp[-4].texto), (yyvsp[-2].texto), (yyvsp[0].no_arvore));
    }
#line 1340 "cool.tab.c"
    break;

  case 13: /* feature: OBJECTID '(' formals ')' ':' TYPEID '{' expr '}'  */
#line 113 "cool.y"
    {
        /* $1 nome do metodo, $3 parametros, $6 é o tipo de retorno, $8 é o corpo do metodo */
        (yyval.no_arvore) = new Metodo((yyvsp[-8].texto), (yyvsp[-6].no_arvore), (yyvsp[-3].texto), (yyvsp[-1].no_arvore));
    }
#line 1349 "cool.tab.c"
    break;

  case 14: /* formals: %empty  */
#line 121 "cool.y"
    {
        (yyval.no_arvore) = new ListaFormais();
    }
#line 1357 "cool.tab.c"
    break;

  case 15: /* formals: lista_formals  */
#line 125 "cool.y"
    {
        (yyval.no_arvore) = (yyvsp[0].no_arvore);
    }
#line 1365 "cool.tab.c"
    break;

  case 16: /* lista_formals: formal  */
#line 132 "cool.y"
    {
        /* encontrou o primeiro formal = cria uma nova lista vazia e adiciona ele */
        ListaFormais* l = new ListaFormais();
        l->adicionar((yyvsp[0].no_arvore));
        (yyval.no_arvore) = l;
    }
#line 1376 "cool.tab.c"
    break;

  case 17: /* lista_formals: lista_formals ',' formal  */
#line 139 "cool.y"
    {
        /* ja tem uma lista $1 = só adiciona o novo formal $3 nela */
        ((ListaFormais*)(yyvsp[-2].no_arvore))->adicionar((yyvsp[0].no_arvore));
        (yyval.no_arvore) = (yyvsp[-2].no_arvore);
    }
#line 1386 "cool.tab.c"
    break;

  case 18: /* formal: OBJECTID ':' TYPEID  */
#line 148 "cool.y"
    {
        (yyval.no_arvore) = new Formal((yyvsp[-2].texto), (yyvsp[0].texto));
    }
#line 1394 "cool.tab.c"
    break;

  case 19: /* expr: OBJECTID ASSIGN expr  */
#line 155 "cool.y"
    {    (yyval.no_arvore) = new Atribuicao((yyvsp[-2].texto), (yyvsp[0].no_arvore));  }
#line 1400 "cool.tab.c"
    break;

  case 20: /* expr: expr '.' OBJECTID '(' exprs ')'  */
#line 159 "cool.y"
    {    (yyval.no_arvore) = new Chamada((yyvsp[-5].no_arvore), (yyvsp[-3].texto), (yyvsp[-1].no_arvore));  }
#line 1406 "cool.tab.c"
    break;

  case 21: /* expr: expr '@' TYPEID '.' OBJECTID '(' exprs ')'  */
#line 163 "cool.y"
    {    (yyval.no_arvore) = new ChamadaEstatica((yyvsp[-7].no_arvore), (yyvsp[-5].texto), (yyvsp[-3].texto), (yyvsp[-1].no_arvore));  }
#line 1412 "cool.tab.c"
    break;

  case 22: /* expr: OBJECTID '(' exprs ')'  */
#line 167 "cool.y"
    {    (yyval.no_arvore) = new Chamada("self", (yyvsp[-3].texto), (yyvsp[-1].no_arvore));  }
#line 1418 "cool.tab.c"
    break;

  case 23: /* expr: IF expr THEN expr ELSE expr FI  */
#line 170 "cool.y"
    {    (yyval.no_arvore) = new If((yyvsp[-5].no_arvore), (yyvsp[-3].no_arvore), (yyvsp[-1].no_arvore));  }
#line 1424 "cool.tab.c"
    break;

  case 24: /* expr: WHILE expr LOOP expr POOL  */
#line 173 "cool.y"
    {    (yyval.no_arvore) = new While((yyvsp[-3].no_arvore), (yyvsp[-1].no_arvore));  }
#line 1430 "cool.tab.c"
    break;

  case 25: /* expr: '{' bloco_exprs '}'  */
#line 176 "cool.y"
    {    (yyval.no_arvore) = new Bloco((yyvsp[-1].no_arvore));  }
#line 1436 "cool.tab.c"
    break;

  case 26: /* expr: LET lista_let IN expr  */
#line 179 "cool.y"
    {    (yyval.no_arvore) = new Let((yyvsp[-2].no_arvore), (yyvsp[0].no_arvore));  }
#line 1442 "cool.tab.c"
    break;

  case 27: /* expr: CASE expr OF lista_cases ESAC  */
#line 182 "cool.y"
    {    (yyval.no_arvore) = new Case((yyvsp[-3].no_arvore), (yyvsp[-1].no_arvore));  }
#line 1448 "cool.tab.c"
    break;

  case 28: /* expr: NEW TYPEID  */
#line 185 "cool.y"
    {    (yyval.no_arvore) = new New((yyvsp[0].texto));  }
#line 1454 "cool.tab.c"
    break;

  case 29: /* expr: ISVOID expr  */
#line 188 "cool.y"
    {    (yyval.no_arvore) = new IsVoid((yyvsp[0].no_arvore));  }
#line 1460 "cool.tab.c"
    break;

  case 30: /* expr: expr '+' expr  */
#line 191 "cool.y"
    {    (yyval.no_arvore) = new Plus((yyvsp[-2].no_arvore), (yyvsp[0].no_arvore));  }
#line 1466 "cool.tab.c"
    break;

  case 31: /* expr: expr '-' expr  */
#line 194 "cool.y"
    {    (yyval.no_arvore) = new Minus((yyvsp[-2].no_arvore), (yyvsp[0].no_arvore));  }
#line 1472 "cool.tab.c"
    break;

  case 32: /* expr: expr '*' expr  */
#line 197 "cool.y"
    {    (yyval.no_arvore) = new Mult((yyvsp[-2].no_arvore), (yyvsp[0].no_arvore));  }
#line 1478 "cool.tab.c"
    break;

  case 33: /* expr: expr '/' expr  */
#line 200 "cool.y"
    {    (yyval.no_arvore) = new Divide((yyvsp[-2].no_arvore), (yyvsp[0].no_arvore));  }
#line 1484 "cool.tab.c"
    break;

  case 34: /* expr: '~' expr  */
#line 203 "cool.y"
    {    (yyval.no_arvore) = new Negacao((yyvsp[0].no_arvore));  }
#line 1490 "cool.tab.c"
    break;

  case 35: /* expr: expr '<' expr  */
#line 206 "cool.y"
    {    (yyval.no_arvore) = new MenorQue((yyvsp[-2].no_arvore), (yyvsp[0].no_arvore));  }
#line 1496 "cool.tab.c"
    break;

  case 36: /* expr: expr LE expr  */
#line 209 "cool.y"
    {    (yyval.no_arvore) = new MenorIgual((yyvsp[-2].no_arvore), (yyvsp[0].no_arvore));  }
#line 1502 "cool.tab.c"
    break;

  case 37: /* expr: expr '=' expr  */
#line 212 "cool.y"
    {    (yyval.no_arvore) = new Igual((yyvsp[-2].no_arvore), (yyvsp[0].no_arvore));  }
#line 1508 "cool.tab.c"
    break;

  case 38: /* expr: NOT expr  */
#line 215 "cool.y"
    {    (yyval.no_arvore) = new Not((yyvsp[0].no_arvore));  }
#line 1514 "cool.tab.c"
    break;

  case 39: /* expr: '(' expr ')'  */
#line 218 "cool.y"
    {    (yyval.no_arvore) = (yyvsp[-1].no_arvore);  }
#line 1520 "cool.tab.c"
    break;

  case 40: /* expr: OBJECTID  */
#line 221 "cool.y"
    {    (yyval.no_arvore) = new ObjectID((yyvsp[0].texto));  }
#line 1526 "cool.tab.c"
    break;

  case 41: /* expr: INT_CONST  */
#line 224 "cool.y"
    {    (yyval.no_arvore) = new Int(atoi((yyvsp[0].texto)));  }
#line 1532 "cool.tab.c"
    break;

  case 42: /* expr: STR_CONST  */
#line 227 "cool.y"
    {    (yyval.no_arvore) = new String((yyvsp[0].texto));  }
#line 1538 "cool.tab.c"
    break;

  case 43: /* expr: TRUE_CONST  */
#line 230 "cool.y"
    {    (yyval.no_arvore) = new Bool(true);  }
#line 1544 "cool.tab.c"
    break;

  case 44: /* expr: FALSE_CONST  */
#line 233 "cool.y"
    {    (yyval.no_arvore) = new Bool(false);  }
#line 1550 "cool.tab.c"
    break;

  case 45: /* exprs: %empty  */
#line 238 "cool.y"
    {
        (yyval.no_arvore) = new ListaExprs();
    }
#line 1558 "cool.tab.c"
    break;

  case 46: /* exprs: lista_exprs  */
#line 242 "cool.y"
    {
        (yyval.no_arvore) = (yyvsp[0].no_arvore);
    }
#line 1566 "cool.tab.c"
    break;

  case 47: /* lista_exprs: expr  */
#line 249 "cool.y"
    {
        /* encontrou a primeira expressao = cria uma nova lista vazia e adiciona ela */
        ListaExprs* l = new ListaExprs();
        l->adicionar((yyvsp[0].no_arvore));
        (yyval.no_arvore) = l;
    }
#line 1577 "cool.tab.c"
    break;

  case 48: /* lista_exprs: lista_exprs ',' expr  */
#line 256 "cool.y"
    {
        /* ja tem uma lista $1 = só adiciona a nova expressao $3 nela */
        ((ListaExprs*)(yyvsp[-2].no_arvore))->adicionar((yyvsp[0].no_arvore));
        (yyval.no_arvore) = (yyvsp[-2].no_arvore);
    }
#line 1587 "cool.tab.c"
    break;

  case 49: /* bloco_exprs: expr ';'  */
#line 265 "cool.y"
    {
        /* encontrou a primeira expressao = cria uma nova lista vazia e adiciona ela */
        BlocoExprs* l = new BlocoExprs();
        l->adicionar((yyvsp[-1].no_arvore));
        (yyval.no_arvore) = l;
    }
#line 1598 "cool.tab.c"
    break;

  case 50: /* bloco_exprs: bloco_exprs expr ';'  */
#line 272 "cool.y"
    {
        /* ja tem uma lista $1 = só adiciona a nova expressao $2 nela */
        ((BlocoExprs*)(yyvsp[-2].no_arvore))->adicionar((yyvsp[-1].no_arvore));
        (yyval.no_arvore) = (yyvsp[-2].no_arvore);
    }
#line 1608 "cool.tab.c"
    break;

  case 51: /* lista_let: OBJECTID ':' TYPEID  */
#line 281 "cool.y"
    {
        ListaLet* l = new ListaLet();
        l->adicionar(new LetItem((yyvsp[-2].texto), (yyvsp[0].texto), NULL));
        (yyval.no_arvore) = l;
    }
#line 1618 "cool.tab.c"
    break;

  case 52: /* lista_let: OBJECTID ':' TYPEID ASSIGN expr  */
#line 288 "cool.y"
    {
        ListaLet* l = new ListaLet();
        l->adicionar(new LetItem((yyvsp[-4].texto), (yyvsp[-2].texto), (yyvsp[0].no_arvore)));
        (yyval.no_arvore) = l;
    }
#line 1628 "cool.tab.c"
    break;

  case 53: /* lista_let: lista_let ',' OBJECTID ':' TYPEID  */
#line 295 "cool.y"
    {
        ((ListaLet*)(yyvsp[-4].no_arvore))->adicionar(new LetItem((yyvsp[-2].texto), (yyvsp[0].texto), NULL));
        (yyval.no_arvore) = (yyvsp[-4].no_arvore);
    }
#line 1637 "cool.tab.c"
    break;

  case 54: /* lista_let: lista_let ',' OBJECTID ':' TYPEID ASSIGN expr  */
#line 301 "cool.y"
    {
        ((ListaLet*)(yyvsp[-6].no_arvore))->adicionar(new LetItem((yyvsp[-4].texto), (yyvsp[-2].texto), (yyvsp[0].no_arvore)));
        (yyval.no_arvore) = (yyvsp[-6].no_arvore);
    }
#line 1646 "cool.tab.c"
    break;

  case 55: /* lista_cases: item_case  */
#line 309 "cool.y"
    {
        /* encontrou o primeiro case = cria uma nova lista vazia e adiciona ele */
        ListaCase* l = new ListaCase();
        l->adicionar((yyvsp[0].no_arvore));
        (yyval.no_arvore) = l;
    }
#line 1657 "cool.tab.c"
    break;

  case 56: /* lista_cases: lista_cases item_case  */
#line 316 "cool.y"
    {
        /* ja tem uma lista $1 = só adiciona o novo case $2 nela */
        ((ListaCase*)(yyvsp[-1].no_arvore))->adicionar((yyvsp[0].no_arvore));
        (yyval.no_arvore) = (yyvsp[-1].no_arvore);
    }
#line 1667 "cool.tab.c"
    break;

  case 57: /* item_case: OBJECTID ':' TYPEID DARROW expr ';'  */
#line 325 "cool.y"
    {
        /* $1 = id, $3 = tipo, $5 = corpo do case */
        (yyval.no_arvore) = new CaseItem((yyvsp[-5].texto), (yyvsp[-3].texto), (yyvsp[-1].no_arvore));
    }
#line 1676 "cool.tab.c"
    break;


#line 1680 "cool.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 331 "cool.y"


void yyerror(const char *s) {
    extern int yylineno;
    printf("Erro sintatico na linha %d: %s\n", yylineno, s);
}

int main(int argc, char **argv) {
    extern FILE *yyin;
    
    if (argc > 1) {
        FILE *arquivo = fopen(argv[1], "r");
        if (!arquivo) {
            printf("Erro ao abrir o arquivo\n");
            return 1;
        }
        yyin = arquivo;
    }

    printf("Iniciando analise sintatica...\n");

    if(yyparse() == 0) {
        printf("Analise sintatica concluida com sucesso!\n\n");
        printf("=== ARVORE SINTATICA ABSTRATA (AST) ===\n");
        if (raiz_arv){        
            raiz_arv->print(0);  // Imprime a árvore de sintaxe abstrata

            printf("\n=== ANALISE SEMANTICA ===\n");
            analisadorSemantico semantico;
            semantico.construir_grafo_classes(raiz_arv);
            semantico.verificar_classes(raiz_arv);

            if(semantico.erroSemantico) {
                printf("Erros semanticos encontrados.\n");
            } else {
                printf("Analise semantica concluida com sucesso!\n");
            }
        } else {
            printf("A arvore de sintaxe abstrata esta vazia.\n");
        }
    } else {
        printf("Erro na analise sintatica.\n");
    }

    return 0;
}
