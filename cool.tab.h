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

#ifndef YY_YY_COOL_TAB_H_INCLUDED
# define YY_YY_COOL_TAB_H_INCLUDED
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
    TYPEID = 258,                  /* TYPEID  */
    OBJECTID = 259,                /* OBJECTID  */
    INT_CONST = 260,               /* INT_CONST  */
    STR_CONST = 261,               /* STR_CONST  */
    CLASS = 262,                   /* CLASS  */
    INHERITS = 263,                /* INHERITS  */
    IF = 264,                      /* IF  */
    THEN = 265,                    /* THEN  */
    ELSE = 266,                    /* ELSE  */
    FI = 267,                      /* FI  */
    WHILE = 268,                   /* WHILE  */
    LOOP = 269,                    /* LOOP  */
    POOL = 270,                    /* POOL  */
    LET = 271,                     /* LET  */
    IN = 272,                      /* IN  */
    CASE = 273,                    /* CASE  */
    OF = 274,                      /* OF  */
    ESAC = 275,                    /* ESAC  */
    NEW = 276,                     /* NEW  */
    ISVOID = 277,                  /* ISVOID  */
    NOT = 278,                     /* NOT  */
    TRUE_CONST = 279,              /* TRUE_CONST  */
    FALSE_CONST = 280,             /* FALSE_CONST  */
    ASSIGN = 281,                  /* ASSIGN  */
    LE = 282,                      /* LE  */
    DARROW = 283                   /* DARROW  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "cool.y"

    char* texto;
    No* no_arvore;

#line 97 "cool.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_COOL_TAB_H_INCLUDED  */
