/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "quick.y" /* yacc.c:339  */

#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

#include <string>
using namespace std;
	    stack < string > S;
	    //stack <  pair <  pair<string , string > , double >  >;


//               name  			type/return type        is function/macro/array , limit/number of argument 
map   <   		   string , pair   <  string   ,   pair < string , double > > > Table ;

set < string > variables;
#include "header.h"


extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" int yylineno ;
void yyerror(const char *  error_message ); 
bool Table_check(string name);
void Table_insert(string name,string type ,string what_is_this, double limit);
void check_array_declaration_recursive(string type, Syntax_Tree * p);
void check_declaration_recursive(string type, Syntax_Tree * p);
string TAC(Syntax_Tree * p);
int sizeof_array(map   <  string , pair   <  string   ,   pair < string , double > > > Table ,string array_name);
//int arguments ;
Syntax_Tree * dummy;
Syntax_Tree * dummy2;
Syntax_Tree * dummy3,*dummy56;
Syntax_Tree * root;


#line 104 "quick.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "quick.tab.h".  */
#ifndef YY_YY_QUICK_TAB_H_INCLUDED
# define YY_YY_QUICK_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MACRO = 258,
    BOOL = 259,
    INT = 260,
    CHAR = 261,
    PLUS_PLUS = 262,
    MINUS_MINUS = 263,
    NULL1 = 264,
    FORWARD = 265,
    BACKWARD = 266,
    HEY = 267,
    IF = 268,
    ELSE = 269,
    FOR = 270,
    ASD = 271,
    EQUAL_EQUAL = 272,
    NOT_EQUAL = 273,
    LESS_THAN_EQUAL = 274,
    GREATER_THAN_EQUAL = 275,
    TRUE = 276,
    FALSE = 277,
    RETURN = 278,
    AND_AND = 279,
    OR_OR = 280,
    COMMA = 281,
    QUICKIN = 282,
    QUICKOUT = 283,
    MAIN = 284,
    H = 285,
    N = 286,
    POINTER = 287,
    STRING = 288,
    INCLUDE = 289,
    VALUE = 290,
    DATA_TYPE_INT = 291,
    DATA_TYPE_STRING = 292,
    CB = 293,
    OB = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 40 "quick.y" /* yacc.c:355  */

	double NUMBERR;
	char CHARACTER;
	char *  STRINGG;
	struct Syntax_Tree * parag;
	//class Tree * node;
	//bool BOOLL;

#line 193 "quick.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_QUICK_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 208 "quick.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   451

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  261

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    56,    60,     2,    65,     2,
      44,    45,    37,    38,    50,    39,    63,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,    55,
      52,    51,    53,    64,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,    61,     2,    58,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,    57,     2,     2,     2,
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
      35,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,   115,   124,   130,   139,   152,   164,   177,
     211,   223,   236,   246,   263,   273,   293,   304,   323,   334,
     352,   359,   368,   375,   384,   391,   400,   413,   422,   438,
     449,   461,   469,   476,   483,   490,   500,   512,   522,   528,
     539,   556,   581,   633,   668,   674,   681,   688,   698,   704,
     716,   724,   733,   739,   751,   759,   770,   782,   806,   833,
     843,   850,   861,   872,   887,   906,   925,   944,   963,   982,
    1000,  1016,  1025,  1037,  1066,  1115,  1127,  1142,  1148,  1161,
    1168,  1179,  1190,  1206,  1213,  1220,  1227,  1234,  1241,  1248,
    1255,  1262,  1269,  1276,  1283,  1290,  1297,  1304,  1311,  1318,
    1325,  1332,  1339,  1346,  1353,  1360,  1367,  1374,  1381,  1388,
    1395,  1402,  1412,  1422,  1462,  1468,  1479,  1495,  1520,  1549,
    1568,  1574,  1582,  1587,  1601,  1613,  1629,  1637,  1653,  1670,
    1687,  1704,  1723,  1746,  1774,  1805,  1815,  1848,  1853,  1863,
    1868,  1875
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MACRO", "BOOL", "INT", "CHAR",
  "PLUS_PLUS", "MINUS_MINUS", "NULL1", "FORWARD", "BACKWARD", "HEY", "IF",
  "ELSE", "FOR", "ASD", "EQUAL_EQUAL", "NOT_EQUAL", "LESS_THAN_EQUAL",
  "GREATER_THAN_EQUAL", "TRUE", "FALSE", "RETURN", "AND_AND", "OR_OR",
  "COMMA", "QUICKIN", "QUICKOUT", "MAIN", "H", "N", "POINTER", "STRING",
  "INCLUDE", "VALUE", "'/'", "'*'", "'+'", "'-'", "DATA_TYPE_INT",
  "DATA_TYPE_STRING", "CB", "OB", "'('", "')'", "'{'", "'}'", "'['", "']'",
  "','", "'='", "'<'", "'>'", "'!'", "';'", "'#'", "'~'", "'`'", "'@'",
  "'$'", "'^'", "':'", "'.'", "'?'", "'&'", "$accept", "program",
  "header_by_user", "macro_statement", "function_declaration",
  "function_name", "function_arguments", "return_type", "data_type",
  "main_function", "function_statements", "array_statement",
  "array_declaration_recursive", "array_initialisation", "loop_statement",
  "loop_initialisation", "loop_condition", "loop_update", "loop_content",
  "conditional_statement", "if_expression", "inside_if_expression",
  "inside_content", "function_calling_newline", "input_output_statement",
  "remaining_statement_in", "remaining_statement_out", "quote",
  "assignment_statement", "increment_operator", "declaration_statement",
  "declaration_expression", "declaration_assignment_expression",
  "expression", "variable_or_value_or_function_call",
  "function_call_variables", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    47,    42,    43,    45,
     291,   292,   293,   294,    40,    41,   123,   125,    91,    93,
      44,    61,    60,    62,    33,    59,    35,   126,    96,    64,
      36,    94,    58,    46,    63,    38
};
# endif

#define YYPACT_NINF -135

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-135)))

#define YYTABLE_NINF -73

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     186,  -135,    22,   -19,    26,    71,  -135,    20,    50,    10,
    -135,  -135,    58,    77,  -135,    59,   137,  -135,  -135,    56,
      45,    85,   119,   142,   330,  -135,    35,   100,  -135,   146,
    -135,  -135,  -135,   164,   188,   202,    12,   244,   263,   117,
    -135,   222,   250,  -135,  -135,  -135,  -135,  -135,   251,  -135,
     252,   238,   178,   255,   237,   241,   -21,   246,  -135,   -20,
    -135,   260,  -135,   264,    -8,  -135,  -135,   144,    74,     7,
     112,   257,   258,  -135,  -135,  -135,  -135,  -135,   205,  -135,
     261,   275,   245,    74,   268,   224,   398,  -135,  -135,    27,
     281,   301,  -135,  -135,   144,   200,  -135,  -135,     0,    74,
    -135,    15,   346,   302,   346,    36,   185,  -135,   108,  -135,
     346,    74,   118,   307,   308,   366,   309,   285,   295,  -135,
     305,   394,   346,   304,   245,   245,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    70,   303,     8,    63,
     306,   310,   318,  -135,   383,    84,   134,  -135,  -135,   321,
     196,   311,   144,   147,   256,  -135,   346,   317,   303,  -135,
      12,  -135,   334,  -135,  -135,  -135,  -135,  -135,  -135,   346,
     346,   346,   346,  -135,  -135,  -135,  -135,   346,   346,  -135,
     -12,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,   346,  -135,   335,
     346,    74,   121,  -135,  -135,   206,    74,   341,   326,   333,
     340,    54,   -21,   265,  -135,   346,   337,  -135,   300,   348,
    -135,   374,  -135,   180,  -135,  -135,  -135,  -135,  -135,  -135,
     351,   352,   367,  -135,  -135,  -135,   354,   363,   355,  -135,
    -135
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     8,    12,     0,     1,     0,     0,     0,
      24,    25,     0,     0,     2,     0,     0,    27,    36,     0,
      13,     0,     0,     0,     0,    21,     0,     0,    10,     0,
       3,     6,     7,    59,     0,     0,     0,     0,     0,     0,
      26,     0,     0,    38,    34,    33,    32,    31,     0,   114,
       0,     0,     0,     0,    14,     0,     0,     0,    23,   132,
     135,     0,    22,     0,     0,   117,   118,   141,     0,     0,
     120,    37,   119,   122,    35,    30,    29,    36,     0,    16,
       0,     0,     0,     0,     0,    60,    71,   126,    47,     0,
       0,     0,    45,    44,   141,     0,    28,    77,     0,     0,
     112,     0,    79,     0,   137,     0,     0,   116,   132,   112,
     113,     0,     0,     0,     0,     0,     0,    15,     0,    11,
       0,    71,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,     0,     0,
       0,     0,     0,    75,     0,     0,     0,    76,   139,     0,
       0,     0,   141,     0,     0,   112,   124,     0,   121,   123,
       0,    17,     0,    18,    63,   131,    36,    61,    62,    64,
      65,    66,    67,   127,   128,   129,   130,    68,    69,    51,
       0,    48,   136,   134,   133,    78,   108,   109,   110,   111,
      83,    84,   104,    95,   100,    98,    96,    97,   101,   102,
     107,    99,   106,   105,    93,   103,    81,    85,    86,    87,
      88,    89,    90,    91,    92,    94,   112,    80,    73,     0,
     138,     0,     0,   115,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   140,    42,   136,   125,     0,    28,
      19,    57,    55,     0,    52,    49,    82,    74,    41,     9,
       0,     0,     0,    36,    36,    53,     0,     0,     0,    58,
      43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,  -135,  -135,  -135,  -135,   248,    25,  -135,
     -18,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -134,   -64,   152,  -135,  -135,  -135,  -135,  -101,   -56,  -135,
     368,  -135,   312,   -62,   -33,   -77
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    12,    26,    61,    41,    14,
     229,    42,    71,    43,    44,    91,   180,   243,   258,    45,
      84,    85,   230,    46,    47,    98,   101,   145,    48,    49,
      50,    72,    73,    86,    87,   105
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    92,   102,    62,   181,   104,   106,   110,   153,   179,
     142,    17,    59,    58,    60,     7,   107,   139,   120,   231,
     121,   122,     6,    82,    94,    59,   146,    60,    95,     8,
      13,   143,   104,    83,    65,    66,    99,   144,   232,   -50,
     108,    59,    60,    60,    27,    59,   147,    60,   100,   154,
     156,    99,    82,    15,   225,   242,    18,    25,   -50,   115,
     167,   168,    83,   109,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   110,   222,    28,    78,   136,   107,
      51,   149,    90,    16,   217,    52,   150,    89,   220,    21,
     104,   186,   187,    29,   188,   189,    10,    11,   245,   -54,
       9,   -20,    19,    59,   -54,    60,   -20,    59,   182,    60,
      20,    10,    11,   150,    99,   233,    30,   190,    99,   191,
     192,   193,   194,   195,    65,    66,   109,    62,   196,   197,
     198,   199,    53,    54,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      31,    59,   152,    60,   186,   187,    95,   188,   189,   235,
     111,    67,    99,   112,   238,    68,   236,    59,    69,    60,
      22,   150,    23,    32,   155,   244,   103,    59,    99,    60,
     190,    55,   191,   192,   193,   194,   195,     1,    99,    -4,
     216,   196,   197,   198,   199,   -39,   255,   200,   201,   202,
     203,   204,   205,   223,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   186,   187,    -4,   188,   189,    10,    11,
      -4,   130,   131,   132,   133,   251,    -4,    -4,   219,    59,
     252,    60,    56,   140,   151,   141,   257,   116,   117,   190,
      99,   191,   192,   193,   194,   195,    57,    88,   124,   125,
     196,   197,   198,   199,    63,    70,   200,   201,   202,   203,
     204,   205,   237,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   186,   187,    64,   188,   189,   -46,    59,    89,
      60,    74,    75,    76,    77,    80,    10,    11,    79,    99,
      81,    96,   130,   131,   132,   133,   118,    97,   190,    83,
     191,   192,   193,   194,   195,   224,   119,   113,   114,   196,
     197,   198,   199,   123,   137,   200,   201,   202,   203,   204,
     205,   246,   207,   208,   209,   210,   211,   212,   213,   214,
     215,    33,   138,   162,    33,   148,   130,   131,   132,   133,
     157,   158,   161,    34,   163,    35,    34,   164,    35,   248,
     166,   185,   218,    36,   112,   183,    36,    37,    38,   184,
      37,    38,   221,    39,    33,   226,    39,    33,   234,   228,
      10,    11,   239,    10,    11,   240,    34,    40,    35,    34,
     -72,    35,   130,   131,   132,   133,    36,   241,   250,   160,
      37,    38,   247,    37,    38,   249,    39,   253,   254,    39,
      89,   259,   260,    10,    11,   256,    10,    11,   227,     0,
     -56,   126,   127,   128,   129,   126,   127,   128,   129,   130,
     131,   132,   133,     0,     0,    93,   159,     0,   165,     0,
     130,   131,   132,   133,   130,   131,   132,   133,     0,   165,
       0,     0,     0,     0,     0,     0,   134,   135,     0,     0,
     134,   135
};

static const yytype_int16 yycheck[] =
{
      18,    57,    64,    36,   138,    67,    68,    69,   109,     1,
      10,     1,    33,     1,    35,    34,     9,    94,    82,    31,
      82,    83,     0,    44,    44,    33,    11,    35,    48,     3,
       5,    31,    94,    54,     7,     8,    44,    99,    50,    31,
      33,    33,    35,    35,    19,    33,    31,    35,    56,   111,
     112,    44,    44,    33,   155,     1,    46,     1,    50,    77,
     124,   125,    54,    56,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   152,    31,    52,    51,     9,
      45,    45,    57,    33,   146,    50,    50,    33,   150,    30,
     152,     7,     8,    48,    10,    11,    40,    41,   232,    45,
      29,    45,    44,    33,    50,    35,    50,    33,    45,    35,
      33,    40,    41,    50,    44,   216,    31,    33,    44,    35,
      36,    37,    38,    39,     7,     8,    56,   160,    44,    45,
      46,    47,    32,    33,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      31,    33,    44,    35,     7,     8,    48,    10,    11,   221,
      48,    44,    44,    51,   226,    48,    45,    33,    51,    35,
      33,    50,    35,    31,    56,   231,    32,    33,    44,    35,
      33,    35,    35,    36,    37,    38,    39,     1,    44,     3,
      56,    44,    45,    46,    47,    31,   252,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     7,     8,    29,    10,    11,    40,    41,
      34,    36,    37,    38,    39,    45,    40,    41,    32,    33,
      50,    35,    44,    33,    49,    35,   254,    32,    33,    33,
      44,    35,    36,    37,    38,    39,    44,     1,    24,    25,
      44,    45,    46,    47,    10,    33,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     7,     8,    11,    10,    11,    31,    33,    33,
      35,    31,    31,    31,    46,    48,    40,    41,    33,    44,
      49,    31,    36,    37,    38,    39,    35,    33,    33,    54,
      35,    36,    37,    38,    39,    49,    31,    50,    50,    44,
      45,    46,    47,    45,    33,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     1,    31,    48,     1,    33,    36,    37,    38,    39,
      33,    33,    33,    13,    49,    15,    13,    42,    15,    49,
      46,    33,    31,    23,    51,    49,    23,    27,    28,    49,
      27,    28,    51,    33,     1,    48,    33,     1,    33,    35,
      40,    41,    31,    40,    41,    49,    13,    47,    15,    13,
      47,    15,    36,    37,    38,    39,    23,    47,    14,    23,
      27,    28,    55,    27,    28,    47,    33,    46,    46,    33,
      33,    47,    47,    40,    41,   253,    40,    41,   160,    -1,
      47,    17,    18,    19,    20,    17,    18,    19,    20,    36,
      37,    38,    39,    -1,    -1,    57,   114,    -1,    45,    -1,
      36,    37,    38,    39,    36,    37,    38,    39,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,
      52,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    67,    68,    69,    70,     0,    34,     3,    29,
      40,    41,    71,    74,    75,    33,    33,     1,    46,    44,
      33,    30,    33,    35,    76,     1,    72,    74,    31,    48,
      31,    31,    31,     1,    13,    15,    23,    27,    28,    33,
      47,    74,    77,    79,    80,    85,    89,    90,    94,    95,
      96,    45,    50,    32,    33,    35,    44,    44,     1,    33,
      35,    73,   100,    10,    11,     7,     8,    44,    48,    51,
      33,    78,    97,    98,    31,    31,    31,    46,    74,    33,
      48,    49,    44,    54,    86,    87,    99,   100,     1,    33,
      74,    81,    94,    96,    44,    48,    31,    33,    91,    44,
      56,    92,    99,    32,    99,   101,    99,     9,    33,    56,
      99,    48,    51,    50,    50,    76,    32,    33,    35,    31,
      87,    99,    99,    45,    24,    25,    17,    18,    19,    20,
      36,    37,    38,    39,    52,    53,    51,    33,    31,   101,
      33,    35,    10,    31,    99,    93,    11,    31,    33,    45,
      50,    49,    44,    93,    99,    56,    99,    33,    33,    98,
      23,    33,    48,    49,    42,    45,    46,    87,    87,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,     1,
      82,    86,    45,    49,    49,    33,     7,     8,    10,    11,
      33,    35,    36,    37,    38,    39,    44,    45,    46,    47,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    56,    99,    31,    32,
      99,    51,   101,    56,    49,    93,    48,    73,    35,    76,
      88,    31,    50,    93,    33,    99,    45,    56,    99,    31,
      49,    47,     1,    83,    94,    86,    56,    55,    49,    47,
      14,    45,    50,    46,    46,    94,    88,    76,    84,    47,
      47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    68,    69,    69,    69,    70,
      70,    70,    70,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    77,    77,
      78,    78,    79,    80,    81,    81,    81,    81,    82,    82,
      82,    82,    83,    83,    83,    83,    84,    85,    85,    85,
      86,    86,    86,    86,    87,    87,    87,    87,    87,    87,
      87,    87,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    92,    92,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    94,    94,    94,    94,    95,    95,    96,
      97,    97,    97,    97,    98,    98,    99,    99,    99,    99,
      99,    99,   100,   100,   100,   100,   100,   101,   101,   101,
     101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     5,     0,     1,     5,     5,     1,    11,
       4,     7,     1,     2,     2,     4,     3,     5,     5,     7,
       0,     1,     1,     1,     1,     1,     4,     2,     4,     3,
       3,     2,     2,     2,     2,     3,     0,     2,     1,     1,
       4,     6,     6,    11,     1,     1,     0,     1,     1,     3,
       0,     1,     1,     3,     0,     1,     1,     7,    11,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     5,     7,     4,     4,     1,     3,     1,
       3,     3,     5,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     0,     3,     1,     5,     3,     2,     2,     2,
       1,     3,     1,     3,     3,     5,     1,     3,     3,     3,
       3,     3,     1,     4,     4,     1,     4,     1,     3,     2,
       4,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 95 "quick.y" /* yacc.c:1646  */
    {
		(yyval.parag) = make_node_parent("program -> function_declaration main_function");
		//cout<<"sdjghosdhglad";
		(yyval.parag)->child = (yyvsp[-1].parag);
		(yyvsp[-1].parag)->last = 0;
		(yyvsp[-1].parag)->next = (yyvsp[0].parag);
		(yyvsp[0].parag)->last = 1;
		//PreOrderTraversal($$);
		cout<<endl;
		root = (yyval.parag);

		//TAC($$);
		//PreOrderTraversalSimulate($$);
	}
#line 1531 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 116 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("header_by_user -> header_by_user INCLUDE STRING H N"); 
						Syntax_Tree * p2 = make_terminal_node(" include ",(yyvsp[-2].STRINGG)," .h "," ; ",NULL,4);
						(yyvsp[-4].parag)->last = 0;
						(yyvsp[-4].parag)->next = p2;
						(yyval.parag)->child = (yyvsp[-4].parag);
			}
#line 1543 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 124 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("header_by_user");
								//$$->last = 0 ;
								Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = parent;
							}
#line 1554 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 130 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("header_by_user");
								//$$->last = 0 ;
								Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = parent;
							}
#line 1565 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 140 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("macro_statement -> macro_statement MACRO STRING STRING N"); 
						Syntax_Tree * p2 = make_terminal_node(" Macro ",(yyvsp[-2].STRINGG),(yyvsp[-1].STRINGG)," ; ",NULL,4);
						(yyvsp[-4].parag)->last = 0;
						(yyvsp[-4].parag)->next = p2;
						(yyval.parag)->child = (yyvsp[-4].parag);

						if(Table_check((yyvsp[-2].STRINGG))){cout<<"Found duplicate : "<<(yyvsp[-2].STRINGG)<<endl;}
							else {Table_insert((yyvsp[-2].STRINGG),"string","macro",0);}
							//cout<<$3<<"int\n";

			}
#line 1582 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 153 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("macro_statement ->"); 
						Syntax_Tree * p2 = make_terminal_node(" Macro ",(yyvsp[-2].STRINGG)," value "," ; ",NULL,4);
						(yyvsp[-4].parag)->last = 0;
						(yyvsp[-4].parag)->next = p2;
						(yyval.parag)->child = (yyvsp[-4].parag);
						if(Table_check((yyvsp[-2].STRINGG))){cout<<"Found duplicate : "<<(yyvsp[-2].STRINGG)<<endl;}
							else {Table_insert((yyvsp[-2].STRINGG),"int","macro",0);
									//cout<<$3<<"int\n";
						}
			}
#line 1598 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 165 "quick.y" /* yacc.c:1646  */
    {//cout<<"macro to header    ";
				    	(yyval.parag) = make_node_parent("macro_statement->"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;//cout<<"macro to header    ";
    				}
#line 1609 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 178 "quick.y" /* yacc.c:1646  */
    {//cout<<"declaration    ";
			(yyval.parag) = make_node_parent("function_declaration -> function_declaration function_name ( function_arguments ) { function_statements RETURN return_type N }");
			
			//$$->last = 0 ;
			Syntax_Tree * p1 = make_terminal_node(" ( ",NULL,NULL,NULL,NULL,1);
			Syntax_Tree * p2 = make_terminal_node(" ) "," { ",NULL,NULL,NULL,2);
			Syntax_Tree * p3 = make_terminal_node("return",NULL,NULL,NULL,NULL,1);
			Syntax_Tree * p4 = make_terminal_node(" ; "," } ",NULL,NULL,NULL,2);

			(yyvsp[-10].parag)->last = 0;
			(yyvsp[-10].parag)->next = (yyvsp[-9].parag);

			(yyvsp[-9].parag)->last = 0;
			(yyvsp[-9].parag)->next = p1;

			p1->last = 0;
			p1->next = (yyvsp[-7].parag);
			
			(yyvsp[-7].parag)->last = 0;
			(yyvsp[-7].parag)->next = p2;
			
			p2->next->last = 0;
			p2->next->next = (yyvsp[-4].parag);
			
			(yyvsp[-4].parag)->last = 0;
			(yyvsp[-4].parag)->next = p3;
			p3->last = 0;
			p3->next = (yyvsp[-2].parag);			
			(yyvsp[-2].parag)->last = 0;
			(yyvsp[-2].parag)->next = p4;
			(yyval.parag)->child = (yyvsp[-10].parag);
			
		}
#line 1647 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 212 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("function_declaration -> function_declaration data_type  STRING N"); 
						Syntax_Tree * p2 = make_terminal_node((yyvsp[-1].STRINGG)," ; ",NULL,NULL,NULL,2);
						(yyvsp[-3].parag)->last = 0;
						(yyvsp[-3].parag)->next = (yyvsp[-2].parag);
						(yyvsp[-2].parag)->last = 0;
						(yyvsp[-2].parag)->next = p2;
						(yyval.parag)->child = (yyvsp[-3].parag);
						if(Table_check((yyvsp[-1].STRINGG))){cout<<"Found duplicate : "<<(yyvsp[-1].STRINGG)<<endl;}
							else {Table_insert((yyvsp[-1].STRINGG),Print_data((yyvsp[-2].parag)),"normal",0);}
			}
#line 1663 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 224 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("function_declaration -> function_declaration data_type  STRING '[' VALUE ']' N"); 
						Syntax_Tree * p2 = make_terminal_node((yyvsp[-4].STRINGG)," [ "," value "," ] "," ; ",5);
						(yyvsp[-6].parag)->last = 0;
						(yyvsp[-6].parag)->next = (yyvsp[-5].parag);
						(yyvsp[-5].parag)->last = 0;
						(yyvsp[-5].parag)->next = p2;
						(yyval.parag)->child = (yyvsp[-6].parag);
							//cout<<"bbbbbbbbbbbb"<<$5<<"aaaaaaaaaaaaa";
						if(Table_check((yyvsp[-4].STRINGG))){cout<<"Found duplicate : "<<(yyvsp[-4].STRINGG)<<endl;}
							else {Table_insert((yyvsp[-4].STRINGG),Print_data((yyvsp[-5].parag)),"array",(yyvsp[-2].NUMBERR));}
			}
#line 1680 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 237 "quick.y" /* yacc.c:1646  */
    {//cout<<"macro    ";
				    	(yyval.parag) = make_node_parent("function_declaration->"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;//cout<<"macro    ";
    				}
#line 1691 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 247 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("function_name -> data_type STRING"); 
						Syntax_Tree * p1 = make_terminal_node((yyvsp[0].STRINGG),NULL,NULL,NULL,NULL,1);

						(yyvsp[-1].parag)->last = 0;
						(yyvsp[-1].parag)->next = p1;

						(yyval.parag)->child = (yyvsp[-1].parag);

						if(Table_check((yyvsp[0].STRINGG))){cout<<"Found duplicate : "<<(yyvsp[0].STRINGG)<<endl;}
							else {Table_insert((yyvsp[0].STRINGG),Print_data((yyvsp[-1].parag)),"func",0);}
					}
#line 1708 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 264 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("function_arguments -> data_type STRING"); 
								Syntax_Tree * p1 = make_terminal_node((yyvsp[0].STRINGG),  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
								if(Table_check((yyvsp[0].STRINGG))){cout<<"Found duplicate : "<<(yyvsp[0].STRINGG)<<endl;}
									else {Table_insert((yyvsp[0].STRINGG),Print_data((yyvsp[-1].parag)),"normal",0);}
			}
#line 1722 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 274 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("function_arguments -> function_arguments ',' data_type STRING"); 
						(yyval.parag)->child = (yyvsp[-3].parag);
						(yyvsp[-3].parag)->last = 0;

						Syntax_Tree * p1 = make_terminal_node(" , ",NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p2 = make_terminal_node((yyvsp[0].STRINGG), NULL, NULL,NULL,NULL,1);
						(yyvsp[-3].parag)->next = p1;
						p1->last = 0;
						p1->next = (yyvsp[-1].parag);
						(yyvsp[-1].parag)->last = 0 ;
						
						(yyvsp[-1].parag)->next = p2;

								if(Table_check((yyvsp[0].STRINGG))){cout<<"Found duplicate : "<<(yyvsp[0].STRINGG)<<endl;}
									else {Table_insert((yyvsp[0].STRINGG),Print_data((yyvsp[-1].parag)),"normal",0);}


					}
#line 1746 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 294 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("function_arguments -> data_type POINTER STRING"); 
						Syntax_Tree * p1 = make_terminal_node(" pointer(->) ",(yyvsp[0].STRINGG),NULL,NULL,NULL,2);
						(yyvsp[-2].parag)->last = 0;
						(yyvsp[-2].parag)->next = p1;
						(yyval.parag)->child = (yyvsp[-2].parag);

								if(Table_check((yyvsp[0].STRINGG))){cout<<"Found duplicate : "<<(yyvsp[0].STRINGG)<<endl;}
									else {Table_insert((yyvsp[0].STRINGG),Print_data((yyvsp[-2].parag)),"point",0);}
		}
#line 1761 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 305 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("function_arguments -> function_arguments ',' data_type POINTER STRING"); 
						(yyval.parag)->child = (yyvsp[-4].parag);
						(yyvsp[-4].parag)->last = 0;

						Syntax_Tree * p1 = make_terminal_node(" , ",NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p2 = make_terminal_node(" -> ", (yyvsp[0].STRINGG), NULL,NULL,NULL,2);
						(yyvsp[-4].parag)->next = p1;
						p1->last = 0;
						p1->next = (yyvsp[-2].parag);
						(yyvsp[-2].parag)->last = 0 ;
						
						(yyvsp[-2].parag)->next = p2;


						if(Table_check((yyvsp[0].STRINGG))){cout<<"Found duplicate : "<<(yyvsp[0].STRINGG)<<endl;}
									else {Table_insert((yyvsp[0].STRINGG),Print_data((yyvsp[-2].parag)),"point",0);}
					}
#line 1784 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 324 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("function_arguments -> data_type STRING '[' VALUE ']'"); 
						Syntax_Tree * p1 = make_terminal_node((yyvsp[-3].STRINGG)," [ "," value "," ] ",NULL,4);
						(yyvsp[-4].parag)->last = 0;
						(yyvsp[-4].parag)->next = p1;
						(yyval.parag)->child = (yyvsp[-4].parag);

						if(Table_check((yyvsp[-3].STRINGG))){cout<<"Found duplicate : "<<(yyvsp[-3].STRINGG)<<endl;}
									else {Table_insert((yyvsp[-3].STRINGG),Print_data((yyvsp[-4].parag)),"array",(yyvsp[-1].NUMBERR));}
			}
#line 1799 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 335 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("function_arguments -> function_arguments ',' data_type STRING '[' VALUE ']'"); 
						(yyval.parag)->child = (yyvsp[-6].parag);
						(yyvsp[-6].parag)->last = 0;

						Syntax_Tree * p1 = make_terminal_node(" , ",NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p2 = make_terminal_node( (yyvsp[-3].STRINGG), " [ "," value "," ] ",NULL,4);
						(yyvsp[-6].parag)->next = p1;
						p1->last = 0;
						p1->next = (yyvsp[-4].parag);
						(yyvsp[-4].parag)->last = 0 ;
						(yyvsp[-4].parag)->next = p2;

						if(Table_check((yyvsp[-3].STRINGG))){cout<<"Found duplicate : "<<(yyvsp[-3].STRINGG)<<endl;}
									else {Table_insert((yyvsp[-3].STRINGG),Print_data((yyvsp[-4].parag)),"array",(yyvsp[-1].NUMBERR));}
					}
#line 1820 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 352 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("function_arguments ->");
								//$$->last = 0 ;
								Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = parent;
							}
#line 1831 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 359 "quick.y" /* yacc.c:1646  */
    {
	                     (yyval.parag) = make_node_parent("function_arguments");
								                      //$$->last = 0 ;
								Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = parent;
					  }
#line 1842 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 369 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("return_type -> variable_or_value_or_function_call"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
    				}
#line 1853 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 375 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("return_type");
						//$$->last = 0 ;
						Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = parent;
					             }
#line 1864 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 385 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("data_type ->"); 
						(yyvsp[0].parag) = make_terminal_node("int",NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[0].parag);

			}
#line 1875 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 392 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("data_type ->"); 
						(yyvsp[0].parag) = make_terminal_node("string",NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[0].parag);
			}
#line 1885 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 401 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("main_function -> MAIN { function_statements }"); 
								Syntax_Tree * p1 = make_terminal_node("Main"," { ",NULL,NULL,NULL,2);
								p1->next->last = 0;
								Syntax_Tree * p2 = make_terminal_node(" } ",  NULL,NULL,NULL,NULL,1);
								p1->next->next = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p2;

								(yyval.parag)->child = p1;
								dummy3 = (yyvsp[-1].parag);
							}
#line 1902 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 413 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("main_function");
						//$$->last = 0 ;
						Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = parent;
					             }
#line 1913 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 423 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("function_statement -> function_statements RETURN return_type N");
								(yyval.parag)->child = (yyvsp[-3].parag);

								(yyvsp[-3].parag)->last = 0;

								Syntax_Tree * p1 = make_terminal_node (" RETURN ",NULL,NULL,NULL,NULL,1);
								(yyvsp[-3].parag)->next = p1;
								p1->last = 0;
								p1->next = (yyvsp[-1].parag);
								Syntax_Tree * p2 = make_terminal_node (" ; ",NULL,NULL,NULL,NULL,1);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p2;

							}
#line 1933 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 439 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("function_statement -> function_statements declaration_statement N");
								(yyval.parag)->child = (yyvsp[-2].parag);
								(yyvsp[-2].parag)->last = 0;
								(yyvsp[-2].parag)->next = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								
								Syntax_Tree * p1 = make_terminal_node (" ; ",NULL,NULL,NULL,NULL,1);
								(yyvsp[-1].parag)->next = p1;
							}
#line 1948 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 450 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("function_statement -> function_statements assignment_statement N");
								(yyval.parag)->child = (yyvsp[-2].parag);
								(yyvsp[-2].parag)->last = 0;
								(yyvsp[-2].parag)->next = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								
								Syntax_Tree * p1 = make_terminal_node (" ; ",NULL,NULL,NULL,NULL,1);
								(yyvsp[-1].parag)->next = p1;

							}
#line 1964 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 462 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("function_statement -> function_statements input_output_statement");
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = (yyvsp[0].parag);
								(yyvsp[0].parag)->last = 1;
							}
#line 1976 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 469 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("function_statement -> function_statements function_calling_newline");
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = (yyvsp[0].parag);
								(yyvsp[0].parag)->last = 1;
							}
#line 1988 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 476 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("function_statement -> function_statements conditional_statement");
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = (yyvsp[0].parag);
								(yyvsp[0].parag)->last = 1;
							}
#line 2000 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 483 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("function_statement -> function_statements loop_statement");
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = (yyvsp[0].parag);
								(yyvsp[0].parag)->last = 1;
							}
#line 2012 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 490 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("function_statement -> function_statements array_statement N");
								(yyval.parag)->child = (yyvsp[-2].parag);
								(yyvsp[-2].parag)->last = 0;
								(yyvsp[-2].parag)->next = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								
								Syntax_Tree * p1 = make_terminal_node (" ; ",NULL,NULL,NULL,NULL,1);
								(yyvsp[-1].parag)->next = p1;
							}
#line 2027 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 500 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("function_statement ->");
								//$$->last = 0 ;
								Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = parent;
							}
#line 2038 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 512 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("array_statement -> data_type array_declaration_recursive");
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = (yyvsp[0].parag);
								(yyvsp[0].parag)->last = 1;
								check_array_declaration_recursive(Print_data((yyvsp[-1].parag)), (yyvsp[0].parag));
								//if(Table_check(Print_data($2))){cout<<"Found duplicate : "<<Print_data($2)<<endl;}
									//else {Table_insert(Print_data($1),Print_data($2),"array",0);}
							}
#line 2053 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 522 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("array_statement -> array_initialisation"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
    				}
#line 2064 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 528 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("array_statement");
						//$$->last = 0 ;
						Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = parent;
					             }
#line 2075 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 540 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("array_declaration_recursive -> STRING [ expression ]"); 
						Syntax_Tree * p1 = make_terminal_node((yyvsp[-3].STRINGG)," [ ",NULL,NULL,NULL,2);
						p1->next->last = 0;
						Syntax_Tree * p2 = make_terminal_node(" ] ",  NULL,NULL,NULL,NULL,1);
						p1->next->next = (yyvsp[-1].parag);
						(yyvsp[-1].parag)->last = 0;
						(yyvsp[-1].parag)->next = p2;
						(yyval.parag)->child = p1;
									if ((yyvsp[-1].parag)->type == 0)
									{}
									else 
									{
										cout<<"require integer index for array \n";
									}
					}
#line 2096 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 557 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("array_declaration_recursive -> array_declaration_recursive , STRING [ expression ]"); 
						(yyval.parag)->child = (yyvsp[-5].parag);
						(yyvsp[-5].parag)->last = 0;

						Syntax_Tree * p1 = make_terminal_node(" , ", (yyvsp[-3].STRINGG), " [ ",NULL,NULL,3);
						(yyvsp[-5].parag)->next = p1;
						p1->next->next->last = 0;
						p1->next->next->next = (yyvsp[-1].parag);
						(yyvsp[-1].parag)->last = 0 ;
						Syntax_Tree * p2 = make_terminal_node(" ] ",NULL,NULL,NULL,NULL,1);
						(yyvsp[-1].parag)->next = p2;
									if ((yyvsp[-1].parag)->type == 0)
										{}
									else 
									{
										cout<<"require integer index for array \n";
									}
					}
#line 2120 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 582 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("array_initialisation -> STRING [ expression ] = expression"); 
						Syntax_Tree * p1 = make_terminal_node((yyvsp[-5].STRINGG)," [ ",NULL,NULL,NULL,2);
						p1->next->last = 0;
						Syntax_Tree * p2 = make_terminal_node(" ] ",  " = ",NULL,NULL,NULL,2);
						p2->next->last = 0;
						p2->next->next = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
						p1->next->next = (yyvsp[-3].parag);
						(yyvsp[-3].parag)->last = 0;
						(yyvsp[-3].parag)->next = p2;
						(yyval.parag)->child = p1;
							if ((yyvsp[-3].parag)->type == 0)
										{}
									else 
									{
										cout<<"require integer index for array \n";
									}
							int t;
							if(Table_check((yyvsp[-5].STRINGG)))
							{
								if (strcmp (Table[(yyvsp[-5].STRINGG)].second.first.c_str() , "array")== 0  )
								{
									if (strcmp (Table[(yyvsp[-5].STRINGG)].first.c_str() , "int")== 0  )
										{t  = 0;}
									else 
									{
										t=1;
										//cout<<"Invalid operation \n";
									}
									if (t==(yyvsp[0].parag)->type)
									{}
									else
									{cout<<"Invalid operation \n";}
								}
								else
								{
									cout<<"its not an array ,invalid access\n";
									(yyval.parag)->type = -1;
								}
							}
							else
							{
								cout<<"Variable undefined \n";
							}
			}
#line 2171 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 634 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("loop_statement -> FOR ( loop_initialisation N loop_condition N loop_update ) { loop_content }"); 
						Syntax_Tree * p1 = make_terminal_node(" for "," ( ",NULL,NULL,NULL,2);
						p1->next->last = 0;
						p1->next->next = (yyvsp[-8].parag);
						
						Syntax_Tree * p2 = make_terminal_node(" ; ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p3 = make_terminal_node(" ; ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p4 = make_terminal_node(" ) ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p5 = make_terminal_node(" { ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p6 = make_terminal_node(" } ", NULL,NULL,NULL,NULL,1);
						p2->last = 0;p3->last = 0;p4->last = 0;p5->last = 0;

						(yyvsp[-8].parag)->last = 0;
						(yyvsp[-8].parag)->next = p2;
						p2->next = (yyvsp[-6].parag);
						(yyvsp[-6].parag)->last = 0;
						(yyvsp[-6].parag)->next = p3;
						p3->next = (yyvsp[-4].parag);

						(yyvsp[-4].parag)->last = 0;
						(yyvsp[-4].parag)->next = p4;
						p4->next = p5;

						p5->next = (yyvsp[-1].parag);
						(yyvsp[-1].parag)->last = 0;
						(yyvsp[-1].parag)->next = p6;

						(yyval.parag)->child = p1;
						dummy56 = (yyval.parag);
					}
#line 2207 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 668 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("loop_initialisation -> declaration_statement"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
    				}
#line 2218 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 674 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("loop_initialisation -> assignment_statement"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
    				}
#line 2229 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 681 "quick.y" /* yacc.c:1646  */
    {
		(yyval.parag) = make_node_parent("loop_initialisation ->");
		//$$->last = 0 ;
		Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
		(yyval.parag)->child = parent;
		
	}
#line 2241 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 688 "quick.y" /* yacc.c:1646  */
    {
						       (yyval.parag) = make_node_parent("loop_intialisation");
						          //$$->last = 0 ;
						            Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
						            (yyval.parag)->child = parent;
					             }
#line 2252 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 698 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("loop_condition -> if_expression"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
    				}
#line 2263 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 705 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("loop_condition -> loop_condition , if_expression"); 
									(yyval.parag)->child = (yyvsp[-2].parag);
									(yyvsp[-2].parag)->last = 0;
									Syntax_Tree * p1 = make_terminal_node(" , ",NULL,NULL,NULL,NULL,1);
									(yyvsp[-2].parag)->next = p1;
									p1->last = 0;
									p1->next = (yyvsp[0].parag);
									(yyvsp[0].parag)->last = 1;
								 }
#line 2278 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 716 "quick.y" /* yacc.c:1646  */
    {
		(yyval.parag) = make_node_parent("loop_condition ->");
		//$$->last = 0 ;
		Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
		(yyval.parag)->child = parent;
		
	}
#line 2290 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 724 "quick.y" /* yacc.c:1646  */
    {
						       (yyval.parag) = make_node_parent("loop_condition");
						          //$$->last = 0 ;
						            Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
						            (yyval.parag)->child = parent;
					             }
#line 2301 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 733 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("loop_update -> assignment_statement"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
    				}
#line 2312 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 740 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("loop_update -> loop_update , assignment_statement"); 
									(yyval.parag)->child = (yyvsp[-2].parag);
									(yyvsp[-2].parag)->last = 0;
									Syntax_Tree * p1 = make_terminal_node(" , ",NULL,NULL,NULL,NULL,1);
									(yyvsp[-2].parag)->next = p1;
									p1->last = 0;
									p1->next = (yyvsp[0].parag);
									(yyvsp[0].parag)->last = 1;
								 }
#line 2327 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 751 "quick.y" /* yacc.c:1646  */
    {
		(yyval.parag) = make_node_parent("loop_condition ->");
		//$$->last = 0 ;
		Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
		(yyval.parag)->child = parent;
		
	}
#line 2339 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 760 "quick.y" /* yacc.c:1646  */
    {
						       (yyval.parag) = make_node_parent("loop_update");
						          //$$->last = 0 ;
						            Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
						            (yyval.parag)->child = parent;
					             }
#line 2350 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 770 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("loop_content -> function_statements"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
    				}
#line 2361 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 783 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("conditional_statement -> IF ( if_expression ) { inside_content }"); 
						Syntax_Tree * p1 = make_terminal_node(" if "," ( ",NULL,NULL,NULL,2);
						p1->next->last = 0;
						p1->next->next = (yyvsp[-4].parag);
						
						Syntax_Tree * p2 = make_terminal_node(" ) ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p3 = make_terminal_node(" { ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p6 = make_terminal_node(" } ", NULL,NULL,NULL,NULL,1);
						p2->last = 0;p3->last = 0;

						(yyvsp[-4].parag)->last = 0;
						(yyvsp[-4].parag)->next = p2;
						p2->next = p3;
						p3->next = (yyvsp[-1].parag);
						(yyvsp[-1].parag)->last = 0;
						(yyvsp[-1].parag)->next = p6;
						

						(yyval.parag)->child = p1;
						dummy = (yyval.parag);
					}
#line 2388 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 807 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("conditional_statement -> IF ( if_expression ) { inside_content } ELSE { inside_content }"); 
						Syntax_Tree * p1 = make_terminal_node(" if "," ( ",NULL,NULL,NULL,2);
						p1->next->last = 0;
						p1->next->next = (yyvsp[-8].parag);
						
						Syntax_Tree * p2 = make_terminal_node(" ) ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p3 = make_terminal_node(" { ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p4 = make_terminal_node(" } ", " else "," { ",NULL,NULL,3);
						Syntax_Tree * p6 = make_terminal_node(" } ", NULL,NULL,NULL,NULL,1);
						p2->last = 0;p3->last = 0;p4->next->next->last = 0;

						(yyvsp[-8].parag)->last = 0;
						(yyvsp[-8].parag)->next = p2;
						p2->next = p3;
						p3->next = (yyvsp[-5].parag);
						(yyvsp[-5].parag)->last = 0;
						(yyvsp[-5].parag)->next = p4;
						p4->next->next->next = (yyvsp[-1].parag);

						(yyvsp[-1].parag)->last = 0;
						(yyvsp[-1].parag)->next = p6;
						
						(yyval.parag)->child = p1;
						dummy2 = (yyval.parag);
					}
#line 2419 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 833 "quick.y" /* yacc.c:1646  */
    {
						       (yyval.parag) = make_node_parent("conditional_statement");
						          //$$->last = 0 ;
						            Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
						            (yyval.parag)->child = parent;
					            }
#line 2430 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 844 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("if_expression -> inside_if_expression"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
    	}
#line 2441 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 851 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("if_expression -> inside_if_expression  AND_AND  inside_if_expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" && ",NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[-2].parag);
						(yyvsp[-2].parag)->last = 0;
						(yyvsp[-2].parag)->next = p1;
						p1->last = 0;
						p1->next = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
    				}
#line 2456 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 862 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("if_expression -> inside_if_expression  OR_OR  inside_if_expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" || ",NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[-2].parag);
						(yyvsp[-2].parag)->last = 0;
						(yyvsp[-2].parag)->next = p1;
						p1->last = 0;
						p1->next = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
    				}
#line 2471 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 873 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("if_expression -> ( inside_if_expression CB"); 
									Syntax_Tree * p1 = make_terminal_node(" ( ",NULL,NULL,NULL,NULL,1);
									Syntax_Tree * p2 = make_terminal_node(" ) ",NULL,NULL,NULL,NULL,1);
									(yyval.parag)->child = p1;
									p1->last = 0;
									p1->next = (yyvsp[-1].parag);
									(yyvsp[-1].parag)->last = 0 ;
									(yyvsp[-1].parag)->next = p2;
									p2->last = 1;
								 }
#line 2487 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 888 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("inside_if_expression -> expression EQUAL_EQUAL expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" == ",NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[-2].parag);
						(yyvsp[-2].parag)->last = 0;
						(yyvsp[-2].parag)->next = p1;
						p1->last = 0;
						p1->next = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;

							int t;
						if ((yyvsp[-2].parag)->type == (yyvsp[0].parag)->type)
								{t  = 0;}
							else 
							{
								t=1;
								cout<<"Invalid operation \n";
							}    				}
#line 2510 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 907 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("inside_if_expression -> expression NOT_EQUAL expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" != ",NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[-2].parag);
						(yyvsp[-2].parag)->last = 0;
						(yyvsp[-2].parag)->next = p1;
						p1->last = 0;
						p1->next = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
						int t;
						if ((yyvsp[-2].parag)->type == (yyvsp[0].parag)->type)
								{t  = 0;}
							else 
							{
								t=1;
								cout<<"Invalid operation \n";
							}
    				}
#line 2533 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 926 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("inside_if_expression -> expression LESS_THAN_EQUAL expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" <= ",NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[-2].parag);
						(yyvsp[-2].parag)->last = 0;
						(yyvsp[-2].parag)->next = p1;
						p1->last = 0;
						p1->next = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
						int t;
						if ((yyvsp[-2].parag)->type == (yyvsp[0].parag)->type)
								{t  = 0;}
							else 
							{
								t=1;
								cout<<"Invalid operation \n";
							}
    				}
#line 2556 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 945 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("expression GREATER_THAN_EQUAL expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" >= ",NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[-2].parag);
						(yyvsp[-2].parag)->last = 0;
						(yyvsp[-2].parag)->next = p1;
						p1->last = 0;
						p1->next = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
						int t;
						if ((yyvsp[-2].parag)->type == (yyvsp[0].parag)->type)
								{t  = 0;}
							else 
							{
								t=1;
								cout<<"Invalid operation \n";
							}
    				}
#line 2579 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 964 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("inside_if_expression -> expression < expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" < ",NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[-2].parag);
						(yyvsp[-2].parag)->last = 0;
						(yyvsp[-2].parag)->next = p1;
						p1->last = 0;
						p1->next = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
						int t;
						if ((yyvsp[-2].parag)->type == (yyvsp[0].parag)->type)
								{t  = 0;}
							else 
							{
								t=1;
								cout<<"Invalid operation \n";
							}
    				}
#line 2602 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 983 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("inside_if_expression -> expression > expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" > ",NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[-2].parag);
						(yyvsp[-2].parag)->last = 0;
						(yyvsp[-2].parag)->next = p1;
						p1->last = 0;
						p1->next = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;int t;
						if ((yyvsp[-2].parag)->type == (yyvsp[0].parag)->type)
								{t  = 0;}
							else 
							{
								t=1;
								cout<<"Invalid operation \n";
							}
    				}
#line 2624 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1000 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("inside_if_expression -> ! expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" ! ",NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = p1;
						p1->last = 0;
						p1->next = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
						int t;
						if ((yyvsp[0].parag)->type == 0  )
								{t  = 0;}
							else 
							{
								t=1;
								cout<<"Invalid operation \n";
							}
    				}
#line 2645 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1016 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("inside_if_expression -> expression"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
    				}
#line 2656 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1026 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("inside_content -> function_statements"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
    				}
#line 2667 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1038 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("function_calling_newline -> STRING '(' function_call_variables ')' N"); 
						Syntax_Tree * p1 = make_terminal_node((yyvsp[-4].STRINGG)," ( ",NULL,NULL,NULL,2);
						p1->next->last = 0;
						Syntax_Tree * p2 = make_terminal_node(" ) ",  " ; ",NULL,NULL,NULL,2);
						p1->next->next = (yyvsp[-2].parag);
						(yyvsp[-2].parag)->last = 0;
						(yyvsp[-2].parag)->next = p2;
						(yyval.parag)->child = p1;

						if(Table_check((yyvsp[-4].STRINGG)))// && Table_check($3)) 
									{

											if(strcmp (Table[(yyvsp[-4].STRINGG)].second.first.c_str() , "func")!= 0  )
											{	
												cout<<"its not an function ,invalid access\n";
												(yyval.parag)->type = -1;
											}
										else{

											}
									}
									else
										{
											cout<<"Variable undefined \n";
										}

		}
#line 2700 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1067 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("function_calling_newline -> STRING '=' STRING '(' function_call_variables ')' ';'"); 
						Syntax_Tree * p1 = make_terminal_node((yyvsp[-6].STRINGG)," = ",(yyvsp[-4].STRINGG)," ( ",NULL,4);
						p1->next->next->next->last = 0;
						Syntax_Tree * p2 = make_terminal_node(" ) ",  " ; ",NULL,NULL,NULL,2);
						p1->next->next->next->next = (yyvsp[-2].parag);
						(yyvsp[-2].parag)->last = 0;
						(yyvsp[-2].parag)->next = p2;
						int t;
						(yyval.parag)->child = p1;

							if(Table_check((yyvsp[-4].STRINGG)))
							{}
							else
							{
								cout<<"Variable undefined \n";
							}
							if(Table_check((yyvsp[-6].STRINGG)))
							{}
							else
							{
								cout<<"Variable undefined \n";
							}
							if ((strcmp (Table[(yyvsp[-6].STRINGG)].second.first.c_str() , "normal")== 0  ) && (strcmp (Table[(yyvsp[-4].STRINGG)].second.first.c_str() , "func")== 0  ))
								{
									if (strcmp (Table[(yyvsp[-6].STRINGG)].first.c_str() , Table[(yyvsp[-4].STRINGG)].first.c_str())== 0  )
										{t  = 0;}
									else 
									{
										t=1;
										cout<<"type mismatch \n";
									}
								}
								else
								{
									cout<<"invalid operation\n";
									(yyval.parag)->type = -1;
								}
							
		}
#line 2745 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1116 "quick.y" /* yacc.c:1646  */
    {
				(yyval.parag) = make_node_parent("I/O statement ->"); 
				Syntax_Tree * p1 = make_terminal_node("quickIn"," >> ",NULL,NULL,NULL,2);
				p1->next->last = 0;
				Syntax_Tree * p2 = make_terminal_node(" ; ",  NULL,NULL,NULL,NULL,1);
				p1->next->next = (yyvsp[-1].parag);
				(yyvsp[-1].parag)->last = 0;
				(yyvsp[-1].parag)->next = p2;

				(yyval.parag)->child = p1;
			}
#line 2761 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1128 "quick.y" /* yacc.c:1646  */
    {
				(yyval.parag) = make_node_parent("input_output_statement -> QUICKOUT BACKWARD remaining_statement_out N"); 
				Syntax_Tree * p1 = make_terminal_node("quickOut"," << ",NULL,NULL,NULL,2);
				p1->next->last = 0;
				Syntax_Tree * p2 = make_terminal_node(" ; ",  NULL,NULL,NULL,NULL,1);
				p1->next->next = (yyvsp[-1].parag);
				(yyvsp[-1].parag)->last = 0;
				(yyvsp[-1].parag)->next = p2;

				(yyval.parag)->child = p1;
			}
#line 2777 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1143 "quick.y" /* yacc.c:1646  */
    {
    	(yyval.parag) = make_node_parent("remaining_statement -> string"); 
    	Syntax_Tree * p1 = make_terminal_node((yyvsp[0].STRINGG),NULL,NULL,NULL,NULL,1);
		(yyval.parag)->child = p1;
    }
#line 2787 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1149 "quick.y" /* yacc.c:1646  */
    {
		(yyval.parag) = make_node_parent("remaining_statement_in ->"); 
		Syntax_Tree * p1 = make_terminal_node(" >> ",(yyvsp[0].STRINGG),NULL,NULL,NULL,2);
		(yyvsp[-2].parag)->last = 0;
		(yyvsp[-2].parag)->next = p1;
		(yyval.parag)->child = (yyvsp[-2].parag);
	}
#line 2799 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1162 "quick.y" /* yacc.c:1646  */
    {
				    	(yyval.parag) = make_node_parent("remaining_statement_out -> expression"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						(yyval.parag)->child = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1;
    				}
#line 2810 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1169 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("remaining_statement_out -> remaining_statement_out  BACKWARD expression"); 
						(yyval.parag)->child = (yyvsp[-2].parag);
						Syntax_Tree * p1 = make_terminal_node(" << ",NULL,NULL,NULL,NULL,1);
						(yyvsp[-2].parag)->next = p1;
						p1->last = 0;
						p1->next = (yyvsp[0].parag);
						(yyvsp[0].parag)->last = 1 ;
					}
#line 2824 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1180 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("remaining_statement_out ->"); 
						Syntax_Tree * p1 = make_terminal_node(" # ",NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p2 = make_terminal_node(" # ",NULL,NULL,NULL,NULL,1);
						p1->last = 0;
						p1->next = (yyvsp[-1].parag);
						(yyvsp[-1].parag)->last = 0;
						(yyvsp[-1].parag)->next = p2;
						(yyval.parag)->child = p1;
					}
#line 2839 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1191 "quick.y" /* yacc.c:1646  */
    {
						(yyval.parag) = make_node_parent("remaining_statement_out ->"); 
						(yyval.parag)->child = (yyvsp[-4].parag);
						Syntax_Tree * p1 = make_terminal_node(" << "," # ",NULL,NULL,NULL,2);
						(yyvsp[-4].parag)->next = p1;
						p1->next->last = 0;
						p1->next->next = (yyvsp[-1].parag);
						(yyvsp[-1].parag)->last = 0 ;
						Syntax_Tree * p2 = make_terminal_node(" # ",NULL,NULL,NULL,NULL,1);
						(yyvsp[-1].parag)->next = p2;
				}
#line 2855 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1206 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node((yyvsp[0].STRINGG),  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 2867 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1213 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node("value",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 2879 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1220 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ~ ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 2891 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1227 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ` ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 2903 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1234 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" @ ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 2915 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1241 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" $ ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 2927 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1248 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ^ ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 2939 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1255 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" : ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 2951 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1262 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" . ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 2963 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1269 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ? ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 2975 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1276 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ! ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 2987 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1283 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" & ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 2999 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1290 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" * ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3011 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1297 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ( ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3023 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1304 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ) ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3035 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1311 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" - ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3047 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1318 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" = ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3059 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1325 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" + ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3071 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1332 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" { ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3083 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1339 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" } ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3095 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1346 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ; ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3107 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1353 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" / ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3119 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1360 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" > ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3131 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1367 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" < ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3143 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1374 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" , ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3155 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1381 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ++ " ,  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3167 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1388 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" -- ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3179 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1395 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" >> ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3191 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1402 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" << ",  NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = (yyvsp[-1].parag);
								(yyvsp[-1].parag)->last = 0;
								(yyvsp[-1].parag)->next = p1;
			}
#line 3203 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1412 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("quote ->");
								//$$->last = 0 ;
								Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
								(yyval.parag)->child = parent;
						}
#line 3214 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1422 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("assignment_statement -> string = expression"); 
								Syntax_Tree * p1 = make_terminal_node_new((yyvsp[-2].STRINGG)," = ",NULL,NULL,NULL,2,"string",NULL,NULL,NULL,NULL,0);
								p1->next->last = 0;
								p1->next->next = (yyvsp[0].parag);
								(yyvsp[0].parag)->last = 1;
								(yyval.parag)->child = p1;


									int t;
									if(Table_check((yyvsp[-2].STRINGG)))
									{
										if (strcmp (Table[(yyvsp[-2].STRINGG)].second.first.c_str() , "normal")== 0  )
										{
											if (strcmp (Table[(yyvsp[-2].STRINGG)].first.c_str() , "int")== 0  )
												{t  = 0;}
											else 
											{
												t=1;
											}
											if ((yyvsp[0].parag)->type == t)
											{}
											else
											{
												cout<<"Invalid operation \n";
											}
										}
										else
										{
											cout<<"its not an array ,invalid access\n";
											(yyval.parag)->type = -1;
										}
									}
									else
									{
										cout<<"Variable undefined \n";
									}

									//dummy = $$;
							}
#line 3259 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1462 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("assignment_statement -> increment_operator"); 
								//$1 = make_terminal_node_new("increment_operator",NULL,NULL,NULL,NULL,1,"increment_operator",NULL,NULL,NULL,NULL,0);
								(yyval.parag)->child = (yyvsp[0].parag);
								(yyvsp[0].parag)->last = 1;
							}
#line 3270 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1468 "quick.y" /* yacc.c:1646  */
    { //not done
									(yyval.parag) = make_node_parent("assignment_statement ->"); 
									Syntax_Tree * p1 = make_terminal_node((yyvsp[-4].STRINGG)," = "," # ",NULL,NULL,3);
									p1->next->next->last = 0;
									Syntax_Tree * p2 = make_terminal_node(" # ",  NULL,NULL,NULL,NULL,1);
									p1->next->next->next = (yyvsp[-1].parag);
									(yyvsp[-1].parag)->last = 0;
									(yyvsp[-1].parag)->next = p2;

									(yyval.parag)->child = p1;
								}
#line 3286 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1479 "quick.y" /* yacc.c:1646  */
    { //not done
							    	(yyval.parag) = make_node_parent("assignment_statement ->"); 
							    	Syntax_Tree * p1 = make_terminal_node((yyvsp[-2].STRINGG)," = "," NULL ",NULL,NULL,3);
									(yyval.parag)->child = p1;
									if (strcmp (Table[(yyvsp[-2].STRINGG)].second.first.c_str() , "normal")== 0  )
										{}
									else 
										{cout<<"Invalid operation \n";}
									if (strcmp (Table[(yyvsp[-2].STRINGG)].first.c_str() , "int")== 0  )
										{cout<<"Invalid operation \n";}
									else 
										{}
							    }
#line 3304 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1495 "quick.y" /* yacc.c:1646  */
    {
							    	(yyval.parag) = make_node_parent("increment_operator -> STRING PLUS_PLUS"); 
							    	Syntax_Tree * p1 = make_terminal_node((yyvsp[-1].STRINGG)," ++ ",NULL,NULL,NULL,2);
									(yyval.parag)->child = p1;

									int t;
									if(Table_check((yyvsp[-1].STRINGG)))
									{
										if (strcmp (Table[(yyvsp[-1].STRINGG)].second.first.c_str() , "array")== 0  )
										{
												cout<<"its not an array ,invalid access\n";
												(yyval.parag)->type = -1;
										}
										else{
										if (strcmp (Table[(yyvsp[-1].STRINGG)].first.c_str() , "int")== 0  ){t  = 0;}
										else 
											{
												cout<<"Invalid operation \n";
											}}
									}
									else
									{
										cout<<"Variable undefined \n";
									}
							    }
#line 3334 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1520 "quick.y" /* yacc.c:1646  */
    {
							    	(yyval.parag) = make_node_parent("increment_operator -> STRING MINUS_MINUS"); 
							    	Syntax_Tree * p1 = make_terminal_node((yyvsp[-1].STRINGG)," -- ",NULL,NULL,NULL,2);
									(yyval.parag)->child = p1;
									int t;
									if(Table_check((yyvsp[-1].STRINGG)))
									{

										if (strcmp (Table[(yyvsp[-1].STRINGG)].second.first.c_str() , "array")== 0  )
										{
												cout<<"its not an array ,invalid access\n";
												(yyval.parag)->type = -1;
										}
										else{
										if (strcmp (Table[(yyvsp[-1].STRINGG)].first.c_str() , "int")== 0  ){t  = 0;}
										else 
											{
												cout<<"Invalid operation \n";
											}}
									}
									else
									{
										cout<<"Variable undefined \n";
									}
							    }
#line 3364 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1550 "quick.y" /* yacc.c:1646  */
    {
										(yyval.parag) = make_node_parent("declaration_statement -> data_type declaration_expression");
										(yyval.parag)->child = (yyvsp[-1].parag);
										(yyvsp[-1].parag)->last = 0;
										(yyvsp[-1].parag)->next = (yyvsp[0].parag);
										(yyvsp[0].parag)->last = 1;
										//Syntax_Tree * p1 = make_terminal_node (" ; ",NULL,NULL,NULL,NULL,1);
										//$2->next = p1;
										//cout<<$1->data<<endl;
										//cout<<Print_data($1)<<endl;
										//cout<<$2->data<<endl;

										check_declaration_recursive(Print_data((yyvsp[-1].parag)), (yyvsp[0].parag));
			}
#line 3383 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1569 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("declaration_expression -> STRING"); 
							    	Syntax_Tree * p1 = make_terminal_node((yyvsp[0].STRINGG),NULL,NULL,NULL,NULL,1);
									(yyval.parag)->child = p1;
								}
#line 3393 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1575 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("declaration_expression -> declaration_expression , STRING"); 
							    	Syntax_Tree * p1 = make_terminal_node(" , ",(yyvsp[0].STRINGG),NULL,NULL,NULL,2);
									(yyval.parag)->child = (yyvsp[-2].parag);
									(yyvsp[-2].parag)->last = 0;
									(yyvsp[-2].parag)->next = p1;
								}
#line 3405 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1582 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("declaration_expression -> declaration_assignment_expression"); 
							    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
									(yyval.parag)->child = (yyvsp[0].parag);
								}
#line 3415 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1588 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("declaration_expression -> declaration_expression , declaration_assignment_expression"); 
							    	Syntax_Tree * p1 = make_terminal_node(" , ",NULL,NULL,NULL,NULL,1);
									(yyval.parag)->child = (yyvsp[-2].parag);
									(yyvsp[-2].parag)->last = 0;
									(yyvsp[-2].parag)->next = p1;
									p1->last = 0;
									p1->next = (yyvsp[0].parag);
								}
#line 3429 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1602 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("declaration_assignment_expression -> STRING = expression"); 
							    	Syntax_Tree * p1 = make_terminal_node((yyvsp[-2].STRINGG)," = ",NULL,NULL,NULL,2);
							    	(yyval.parag)->child = p1;
									p1->next->last = 0;
									p1->next->next = (yyvsp[0].parag);
									(yyvsp[0].parag)->last = 1;


									
								}
#line 3445 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1614 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("declaration_assignment_expression -> STRING = # quote #"); 
									Syntax_Tree * p1 = make_terminal_node((yyvsp[-4].STRINGG)," = "," # ",NULL,NULL,3);
									p1->next->next->last = 0;
									Syntax_Tree * p2 = make_terminal_node(" # ",  NULL,NULL,NULL,NULL,1);
									p1->next->next->next = (yyvsp[-1].parag);
									(yyvsp[-1].parag)->last = 0;
									(yyvsp[-1].parag)->next = p2;

									(yyval.parag)->child = p1;
				}
#line 3461 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1630 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("expression -> variable_or_value_or_function_call"); 
									(yyval.parag)->child = (yyvsp[0].parag);
									(yyvsp[0].parag)->last = 1;
									(yyval.parag)->type  = (yyvsp[0].parag)->type;
									
			}
#line 3473 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1638 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("expression -> expression / expression"); 
									(yyval.parag)->child = (yyvsp[-2].parag);
									(yyvsp[-2].parag)->last = 0;
									Syntax_Tree * p1 = make_terminal_node_new(" / ",NULL,NULL,NULL,NULL,1," / ",NULL,NULL,NULL,NULL,0);
									(yyvsp[-2].parag)->next = p1;
									p1->last = 0;
									p1->next = (yyvsp[0].parag);
									(yyvsp[0].parag)->last = 1;
									if((yyvsp[-2].parag)->type == (yyvsp[0].parag)->type){(yyval.parag)->type  = (yyvsp[-2].parag)->type;}
									else
									{
										cout<<"Syntax errro : type mismatch \n";
									}
								 }
#line 3493 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1653 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("expression -> expression * expression"); 
									(yyval.parag)->child = (yyvsp[-2].parag);
									(yyvsp[-2].parag)->last = 0;
									Syntax_Tree * p1 = make_terminal_node_new(" * ",NULL,NULL,NULL,NULL,1," * ",NULL,NULL,NULL,NULL,0);
									(yyvsp[-2].parag)->next = p1;
									p1->last = 0;
									p1->next = (yyvsp[0].parag);
									(yyvsp[0].parag)->last = 1;


									if((yyvsp[-2].parag)->type == (yyvsp[0].parag)->type){(yyval.parag)->type  = (yyvsp[-2].parag)->type;}
									else
									{
										cout<<"Syntax errro : type mismatch \n";
									}
								 }
#line 3515 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1670 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("expression -> expression + expression"); 
									(yyval.parag)->child = (yyvsp[-2].parag);
									(yyvsp[-2].parag)->last = 0;
									Syntax_Tree * p1 = make_terminal_node_new(" + ",NULL,NULL,NULL,NULL,1," + ",NULL,NULL,NULL,NULL,0);
									(yyvsp[-2].parag)->next = p1;
									p1->last = 0;
									p1->next = (yyvsp[0].parag);
									(yyvsp[0].parag)->last = 1;


									if((yyvsp[-2].parag)->type == (yyvsp[0].parag)->type){(yyval.parag)->type  = (yyvsp[-2].parag)->type;}
									else
									{
										cout<<"Syntax errro : type mismatch \n";
									}
								 }
#line 3537 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1688 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("expression -> expression - expression"); 
									(yyval.parag)->child = (yyvsp[-2].parag);
									(yyvsp[-2].parag)->last = 0;
									Syntax_Tree * p1 = make_terminal_node_new(" - ",NULL,NULL,NULL,NULL,1," - ",NULL,NULL,NULL,NULL,0);
									(yyvsp[-2].parag)->next = p1;
									p1->last = 0;
									p1->next = (yyvsp[0].parag);
									(yyvsp[0].parag)->last = 1;

									if((yyvsp[-2].parag)->type == (yyvsp[0].parag)->type){(yyval.parag)->type  = (yyvsp[-2].parag)->type;}
									else
									{
										cout<<"Syntax errro : type mismatch \n";
									}
								 }
#line 3558 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1704 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("expression -> ( expression )"); 
									Syntax_Tree * p1 = make_terminal_node_new(" ( ",NULL,NULL,NULL,NULL,1," ( ",NULL,NULL,NULL,NULL,0);
									Syntax_Tree * p2 = make_terminal_node_new(" ) ",NULL,NULL,NULL,NULL,1," ) ",NULL,NULL,NULL,NULL,0);
									(yyval.parag)->child = p1;
									p1->last = 0;
									p1->next = (yyvsp[-1].parag);
									(yyvsp[-1].parag)->last = 0 ;
									(yyvsp[-1].parag)->next = p2;
									p2->last = 1;



									(yyval.parag)->type  = (yyvsp[-1].parag)->type;
								 }
#line 3578 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1723 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("variable_or_value_or_function_call -> STRING"); 
							    	Syntax_Tree * p1 = make_terminal_node_new((yyvsp[0].STRINGG),NULL,NULL,NULL,NULL,1,"string",NULL,NULL,NULL,NULL,0);
									(yyval.parag)->child = p1;

									//$$->type  = 

									if(Table_check((yyvsp[0].STRINGG)))
									{
											if(strcmp (Table[(yyvsp[0].STRINGG)].second.first.c_str() , "array")== 0  )
											{	
												cout<<"its a array ,invalid access\n";
												(yyval.parag)->type = -1;
											}
											else{
											if (strcmp (Table[(yyvsp[0].STRINGG)].first.c_str() , "int")== 0  ){(yyval.parag)->type  = 0;}
											else {(yyval.parag)->type  = 1;}}
									}
									else
									{
										cout<<"Variable undefined \n";
									}
								}
#line 3606 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1746 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("variable_or_value_or_function_call -> STRING [ VALUE ]"); 
							    	Syntax_Tree * p1 = make_terminal_node_new((yyvsp[-3].STRINGG)," [ ","value"," ] ",NULL,4,"STRING","[","VALUE","]",NULL,(yyvsp[-1].NUMBERR));
									(yyval.parag)->child = p1;

									if(Table_check((yyvsp[-3].STRINGG)))
									{

											if(strcmp (Table[(yyvsp[-3].STRINGG)].second.first.c_str() , "array")!= 0  )
											{	
												cout<<"its not an array ,invalid access\n";
												(yyval.parag)->type = -1;
											}
										else{
										if (strcmp (Table[(yyvsp[-3].STRINGG)].first.c_str() , "int")== 0  )
											{
												(yyval.parag)->type  = 0;
											}
										else 
											{
												(yyval.parag)->type  = 1;
											}}
									}
									else
										{
											cout<<"Variable undefined \n";
										}
								}
#line 3639 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1774 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("variable_or_value_or_function_call -> STRING [ STRING ]"); 
							    	Syntax_Tree * p1 = make_terminal_node_new((yyvsp[-3].STRINGG)," [ ",(yyvsp[-1].STRINGG)," ] ",NULL,4,"STRING","[","STRING","]",NULL,0);
									(yyval.parag)->child = p1;


									if(Table_check((yyvsp[-3].STRINGG)) && Table_check((yyvsp[-1].STRINGG))) 
									{

											if(strcmp (Table[(yyvsp[-3].STRINGG)].second.first.c_str() , "array")!= 0  )
											{	
												cout<<"its not an array ,invalid access\n";
												(yyval.parag)->type = -1;
											}
										else{

												if (strcmp (Table[(yyvsp[-3].STRINGG)].first.c_str() , "int")== 0  )
													{
														(yyval.parag)->type  = 0;
													}
												else 
													{
														(yyval.parag)->type  = 1;
													}
											}
									}
									else
										{
											cout<<"Variable undefined \n";
										}
								}
#line 3675 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1805 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("variable_or_value_or_function_call -> VALUE"); 
							    	Syntax_Tree * p1 = make_terminal_node_new("VALUE",NULL,NULL,NULL,NULL,1,"VALUE",NULL,NULL,NULL,NULL,(yyvsp[0].NUMBERR));
									(yyval.parag)->child = p1;

									(yyval.parag)->type  = 0;

									//dummy = p1;
								}
#line 3689 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1815 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("variable_or_value_or_function_call -> STRING '(' function_call_variables ')'"); 
							    	Syntax_Tree * p1 = make_terminal_node((yyvsp[-3].STRINGG)," ( ",NULL,NULL,NULL,2);
							    	(yyval.parag)->child = p1;
									p1->next->last = 0;
									p1->next->next = (yyvsp[-1].parag);
									(yyvsp[-1].parag)->last = 0;
									Syntax_Tree * p2 = make_terminal_node(" ) ",NULL,NULL,NULL,NULL,1);
									(yyvsp[-1].parag)->next = p2;
									(yyvsp[-1].parag)->last = 1;


									if(Table_check((yyvsp[-3].STRINGG)))// && Table_check($3)) 
									{

											if(strcmp (Table[(yyvsp[-3].STRINGG)].second.first.c_str() , "func")!= 0  )
											{	
												cout<<"its not an function ,invalid access\n";
												(yyval.parag)->type = -1;
											}
										else{

											}
									}
									else
										{
											cout<<"Variable  undefined \n";
										}

								}
#line 3724 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1848 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("function_call_variable -> expression"); 
									(yyval.parag)->child = (yyvsp[0].parag);
									(yyvsp[0].parag)->last = 1;
								}
#line 3734 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1853 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("function_call_variable -> function_call_variables , expression"); 
									(yyval.parag)->child = (yyvsp[-2].parag);
									(yyvsp[-2].parag)->last = 0;
									Syntax_Tree * p1 = make_terminal_node(" , ",NULL,NULL,NULL,NULL,1);
									(yyvsp[-2].parag)->next = p1;
									p1->last = 0;
									p1->next = (yyvsp[0].parag);
									(yyvsp[0].parag)->last = 1;
								 }
#line 3749 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1863 "quick.y" /* yacc.c:1646  */
    {
									(yyval.parag) = make_node_parent("function_call_variable ->pointer string"); 
							    	Syntax_Tree * p1 = make_terminal_node(" pointer (->)",(yyvsp[0].STRINGG),NULL,NULL,NULL,2);
									(yyval.parag)->child = p1;
								}
#line 3759 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1868 "quick.y" /* yacc.c:1646  */
    {
								(yyval.parag) = make_node_parent("function_call_variable ->"); 
								(yyval.parag)->child = (yyvsp[-3].parag);
								(yyvsp[-3].parag)->last = 0;
								Syntax_Tree * p1 = make_terminal_node(" , "," pointer (->)",(yyvsp[0].STRINGG),NULL,NULL,3);
								(yyvsp[-3].parag)->next = p1;
								 }
#line 3771 "quick.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1875 "quick.y" /* yacc.c:1646  */
    {
		(yyval.parag) = make_node_parent("function_call_varialbe ->");
		//$$->last = 0 ;
		Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
		(yyval.parag)->child = parent;
		
	}
#line 3783 "quick.tab.c" /* yacc.c:1646  */
    break;


#line 3787 "quick.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1884 "quick.y" /* yacc.c:1906  */




int main()
{

	FILE *myfile = fopen("input.txt", "r");
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;


	do {
		yyparse();
	} while (!feof(yyin));


freopen("/home/parag/Videos/mips/input_mips.txt","w",stdout);
//cout<<"here";
//cout<<"space: .asciiz \" \\n \" \n";
	//TAC(dummy56);
	//cout<<"sss"  <<endl;
	TAC(root);
	//cout<<endl<<sizeof_array(Table,"ab");

freopen("/home/parag/Videos/mips/variables.txt","w",stdout);
//cout<<"here";

	for(string i : variables)
	{
		cout<<i<<endl;	
	}
}


void yyerror(const char *  error_message)
{
	//cout<<"Oops we ran into an Error"<<endl;
	cout<<"The Error : "<<error_message<<"error on line  "<<yylineno<<endl;
	//exit(-1);


}

