%{

/******************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I. 
*****************************************************************************/

#include <stdio.h>   // for stderr, printf, etc.
#include <string.h>  // for strcmp
#include "ebnfClasses.hh" // for ebnf classes, declarations

#define YYERROR_VERBOSE
#define YYDEBUG 1
#define CLASSSIZE 400
#define NAMESIZE 256
#define LINESIZE 1024
#define LETTERSIZE 200

/********************************************************************/

/* PRELIMINARY NOTES

1. What sebnf2pars Does

The sebnf2pars parser builder reads an annotated EBNF file describing
the syntax of a STEP Part 21 file corresponding to a particular
EXPRESS schema(s). Then it writes several files: (1) a C++ header file
and a C++ code file defining and implementing a set of classes
providing an API for dealing with the items described by the EXPRESS
schema, and (2) a YACC file and a Lex file for a parser that reads and
stores STEP Part 21 files.  The parser builds a parse tree using the
C++ classes. The API includes printing functions that will print a
STEP Part 21 file back out. See below (and the documentation of main)
for more details.

2. TokenNames and TokenLexes

The tokenNames contain the names of tokens as given implicitly in the
EBNF file by using names in all upper case.  The tokenLexes correspond
one-to-one with the tokenNames and point to the same strings, except
where an explicit spelling of a token name is given in the EBNF file.
Explicit spellings in the EBNF file differ from the implicit spellings.
They are not required to differ, but there is no point in giving an
explicit spelling if it does not differ from the implicit spelling.
Differences occur when the spelling rules of EBNF (a name must start
with a letter and underscores may not be used) make an actual name illegal.

3. Expressions

The following tokens defined in the tokens section of this file may be
used as theType of an expression.
   KEYWORD
   NONTERMINAL
   ONECHAR
   TERMINAL
   TERMINALSTRING
   TWOCHAR

4. Commas

The YACC grammar below is very straightforward except in its handling of
commas. Because EBNF uses commas to separate terms, it becomes very hard
for humans to read when quoted commas are mixed with unquoted commas.
For example: "device , ',' , DMIS". It is convenient to use "c" instead
of ',' so the example becomes "device , c , DMIS", which is easy to read.

a. In the EBNF file, there is required to be a production
"c = ',' ;" that defines c to be a comma.

b. When the production defining c in the EBNF file is read, no production
is constructed internally for it, but the token C is recorded.

c. Everywhere else in the EBNF file that a comma in single quotes might
appear, either c or a comma in single quotes may be used.

d. Rather than creating a new expression every time a c is read
in the EBNF there is a special expression named commaExp that represents
a c.

e. In the YACC file that is generated, C is used rather than ',' , and
in the lex file that is generated, when a comma is read, C is returned.

f. The language for which a parser is being constructed may not use C
as a token.

5. Parse Tree

The parsers this writes include YACC actions that build a parse tree.
The toolkit also includes printing a parsed file back out again and
deleting a parse tree. To make that possible, sebnf2pars includes:

a. automatically generating a C++ header file (baseName.hh)
defining classes with which a parse tree can be constructed.

b. automatically generating a C++ code file (baseName.cc)
implementing for each class:
 - two constructors
 - a destructor
 - an identifying method (isA method)
 - a Part 21 file printer (printSelf method)
 - access functions if needed

c. writing YACC actions in the YACC file (baseName.y) that build a
parse tree using the classes.

6. Supertype/subtype Relationships Supported

sebnf2pars supports only a limited number of the supertype/subtype
relationships that are possible in EXPRESS.

Each supertype may (and must) be only one of its subtypes. This is
equivalent to allowing only a ONEOF statement for a supertype in
EXPRESS. This means, among other things, that a supertype cannot be
instantiated.

Multiple supertypes of a subtype are allowed. If a subtype has more
than one supertype with non-empty attNames, however, the attNames of
the production for the subtype must be given in the part of the EBNF
file that lists attribute names.

Almost all STEP AIM-type models use complex supertype/subtype
relationships, so sebnf2pars is not expected to be useful for handling
AIM-type models. Most STEP ARM-type models use no or very few complex
supertype/subtype relationships, so sebnf2pars is expected to be
useful for handling ARM-type models.

7. Select

A SELECT type in EXPRESS is handled like an EXPRESS ENTITY with
no attributes and two (or more) subtypes.

8. Enumeration

An enumeration in EXPRESS is handled like an EXPRESS ENTITY in which
each of the enumeration values is a subtype of EXPRESS ENTITY.

9. Access Functions

In orthodox object-oriented programming, the data members of an object
are private, so only the object has direct access to its data. Other
objects or the programmer can get or set the data only if a class
defines access functions that let the data be retrieved or set.  If
the data members of an object are public, direct access to the data is
available to all. sebnf2pars lets the user decide which of the two
types of access to use by requiring the user to give a second command
argument when calling sebnf2pars that is either "indirect" for
indirect (i.e., orthodox) access, or "direct" for direct access.
Indirect access is implemented by making all data members private and
defining a get_ function and a set_ function for every data member of
every class. Direct access is implemented by making all data members
public.

In this file, direct or indirect is implemented by passing either a
boolean argument "direct", or by passing (or having as local
variables) two character strings, "before" and "after", which are
"get_" and "()" for indirect and are "" and "" for direct.

Most of the examples given in this file assume indirect access.

*/

/********************************************************************/

extern FILE * yyin;
extern int yylex();

prodList productions;
expression * commaExp = new expression(0, "c", 0);
char buffer[NAMESIZE];
char * classNames[26][CLASSSIZE];
char * tokenNames[26][LETTERSIZE];
char * tokenLexes[26][LETTERSIZE];
char * terminalNames[LETTERSIZE];

/********************************************************************/

void checkExpressions();
void findAllAncestors();
void findAncestors(production * prod, prodList * ancesti);
void findAttNamesAll();
void findAttNamesOne(production * super, stringList * front);
void findBeInstance();
void findMixed();
void findMyAtts(FILE * inFile);
void findMyAttsNames(char * aLine, production * prod, int n, FILE * inFile);
void findMyExps();
void findOptProds();
production * findProd(char * itemName);
void findProdValueAll();
void findProdValueOne(production * prod);
void findSupertypes();
int findToken(char * text, int * n);
void findTransferName(production * parent, production * child);
char * findTypeName(expression * exp);
void printCppBaseClass(char * baseClassName, FILE * cppHFile, FILE * cppCFile);
void printCppClassAccess(char * className, expList * myExps,
			 stringList * myAtts, FILE * cppHFile, FILE * cppCFile);
void printCppClassConstructor(char * className, expList * exps,
			      prodList * subtypeOf, stringList * attNames,
			      stringList * myAtts, FILE * cppHFile,
			      FILE * cppCFile);
void printCppClassData(expList * myExps, stringList * myAtts,
		       FILE * cppHFile, bool direct);
void printCppClassDestructor(char * className, expList * exps,
			     stringList * attNames, stringList * myAttNames,
			     FILE * cppCFile, bool direct);
void printCppClassDestructorList(char * typeName, char * before,
				 char * attName, char * after, FILE * cppCFile);
void printCppClassDestructorListInstance(char * attName, FILE * cppCFile);
void printCppClassDoc(expList * exps, FILE * cppHFile);
void printCppClasses(char * baseFileName, bool direct);
void printCppClassIsA(production * prod, char * className,
		      FILE * cppHFile, FILE * cppCFile);
void printCppClassList(production * prod, char * className, char * eName,
		       char * baseClassName, stringList * attNames,
		       FILE * cppHFile, FILE * cppCFile, bool direct);
void printCppClassParent(production * prod, char * className, char * eName,
			 char * baseClassName, FILE * cppHFile,
			 FILE * cppCFile, bool direct);
void printCppClassPrinter(char * className, expList * exps,
			  stringList * attNames, stringList * myAttNames,
			  FILE * cppCFile, bool direct);
void printCppClassPrinterListNo(char * typeName, char * before, char * attName,
				char * after, char * ider, int spaces,
				FILE * cppCFile);
void printCppClassPrinterListYes(char * typeName, char * before, char * attName,
				 char * after, char * ider, int spaces,
				 FILE * cppCFile);
void printCppClassPrinterMixed(production * prod, FILE * cppCFile, bool direct);
void printCppClassStart(char * className, FILE * cppHFile);
void printCppClassTop (production * prod, char * className, char * eName,
		       char * baseClassName, definition * def,
		       stringList * attNames, FILE * cppHFile,
		       FILE * cppCFile, bool direct);
void printCppDocumentation(FILE * cppCFile, FILE * cppHFile, bool direct);
void printCppInstanceClass(char * baseClassName, FILE * cppHFile,
			   FILE * cppCFile, bool direct);
void printCppNames(char * eName, char * baseClassName, FILE * cppHFile);
void printCppPrintFunctions(FILE * cppCFile);
void printCppProductionClass(production * prod, char * eName,
			     char * baseClassName, FILE * cppHFile,
			     FILE * cppCFile, bool direct);
void printLex(char * baseFileName, bool direct);
void printLexEnd(FILE * lexFile);
void printLexMiddle(FILE * lexFile);
void printLexStart(char * baseFileName, FILE * lexFile, bool direct);
void printLexString(char * leader,char * lexString,
		    char * trailer, FILE * lexFile);
void printLexToken(char * theName, char * lexName, FILE * lexFile);
void printStarLine(FILE * someFile);
void printYacc(char * baseFileName, bool direct);
void printYaccAction(char * prodName, char * className, expList * exps,
		     stringList * attNames, FILE * yaccFile, bool direct);
void printYaccActionItem(expression * exp, int * commaFlag,
			 int n, FILE * yaccFile);
void printYaccExpression(expression * exp, FILE * yaccFile);
void printYaccFirstAction(char * className, expList * exps, FILE * yaccFile);
void printYaccFirstProduction(production * prod, FILE * yaccFile);
void printYaccForList(production * prod, char * listName,
		      defList * defins, FILE * yaccFile, bool direct);
void printYaccForListDefault(char * listName, char * listItemName,
			     char * listItemClass, int index,
			     const char * coma, FILE * yaccFile);
void printYaccForListInstance(char * listName, char * listItemName, int index,
			      const char * coma,FILE * yaccFile, bool direct);
void printYaccForListMixed(char * listName, production * listItemProd,
			   int index, const char * coma, FILE * yaccFile,
			   bool direct);
void printYaccForOptProd0(production * prod, FILE * yaccFile, bool direct);
void printYaccForOptProd1(char * transferName, FILE * yaccFile, bool direct);
void printYaccForOptProd2(char * transferName, FILE * yaccFile);
void printYaccForParenList(char * prodName, defList * defins, FILE * yaccFile);
void printYaccForPlain(char * prodName, defList * defs,
		       stringList * attNames, FILE * yaccFile, bool direct);
void printYaccForSupertype(char * prodName, defList * defins, FILE * yaccFile);
void printYaccGlobals(FILE * yaccFile);
void printYaccIncDefs(FILE * yaccFile, char * baseFileName, bool direct);
void printYaccLinkAll(FILE * yaccFile);
void printYaccLinkers(FILE * yaccFile);
void printYaccMain(FILE * yaccFile);
void printYaccMiddle(FILE * yaccFile);
void printYaccParseMany(FILE * yaccFile);
void printYaccParseOne(FILE * yaccFile);
void printYaccProduction(production * prod, FILE * yaccFile, bool direct);
void printYaccProductions(FILE * yaccFile, bool direct);
void printYaccRecordRefOpt(char * prodName, char * attName, int n,
			   FILE * yaccFile, char * before, char * after);
void printYaccRecordRefs(expList * exps, stringList * attNames,
			 FILE * yaccFile,  char * before,  char * after);
void printYaccRule(expList * exps, FILE * yaccFile);
void printYaccStart(FILE * yaccFile, char * baseFileName, bool direct);
void printYaccUnionAndTypes(FILE * yaccFile);
void printYaccYyerror(FILE * yaccFile);
void recordClass(char * className);
void recordClasses(prodList * toPrint);
void recordTerminal(char * terminalName);
void recordToken(char * tokenName);
void reviseSpelling();
void selectProductions(prodList * toPrint);
int yyerror(char * s);
int yyparse();

/********************************************************************/

%}

%union {
        double        dval;
        expression *  exal;
        definition *  fval;
        defList *     ldvl;
        expList *     levl;
        int           ival;
        production *  pval;
        char *        sval;
}

%type <ival> part21Grammar
%type <ival> productionList
%type <pval> production
%type <sval> leftSide
%type <ldvl> definitionList
%type <fval> definition
%type <levl> expressionList
%type <exal> expression

%token <ival> BAD
%token <ival> COMMA
%token <sval> KEYWORD
%token <ival> IS
%token <sval> NONTERMINAL
%token <sval> ONECHAR
%token <ival> OR
%token <ival> SEMICOLON
%token <sval> TERMINAL
%token <sval> TERMINALSTRING
%token <sval> TWOCHAR

%%

part21Grammar : productionList { $$ = 0;}
	;

productionList :
	  production
	  {$$ = 0;
	   if (strcmp($1->lhs, "c"))
	     productions.pushBack($1);
           else
	     recordToken("C");}
	| productionList production
	  {$$ = 0;
	   if (strcmp($2->lhs, "c"))
	     productions.pushBack($2);
	   else
	     recordToken("C");}
	;

production :
	  leftSide definitionList SEMICOLON
	  {$$ = new production($1, $2);
	  }
	;

leftSide :
	  NONTERMINAL IS
	  { $$ = $1; }
	| TERMINAL IS
	  { $$ = $1; }
	| KEYWORD IS
	  { $$ = $1; }
	;

definitionList :
	  definition
	  {$$ = new defList($1);}
	| definitionList OR definition
	  {$$ = $1;
	   $1->pushBack($3);}
	;

definition :
	  expressionList
	  {$$ = new definition($1); }
	;

expressionList :
	  /* empty */
	  {$$ = new expList();}
	| expression
	  {$$ = new expList($1);}
	| expressionList COMMA expression
	  {$$ = $1;
	   $1->pushBack($3);}
	;

expression :
	  KEYWORD
          {$$ = new expression(KEYWORD, $1, 0);
	   recordToken($1); }
	| NONTERMINAL
	  {if (strcmp($1, "c"))
	      $$ = new expression(NONTERMINAL, $1, 0);
	   else
	     $$ = commaExp;}
	| TERMINAL
	  {$$ = new expression(TERMINAL, $1, 0);
	   recordTerminal($1);}
	| TERMINALSTRING
	  {$$ = new expression(TERMINALSTRING, $1, 0);}
	| ONECHAR
	  {$$ = new expression(ONECHAR, $1, 0);}
	| TWOCHAR
	  {$$ = new expression(TWOCHAR, $1, 0);}
	;

%%

/********************************************************************/

/* checkExpressions

Returned Value: none

Called By: main

This goes through all the productions. For each production prod, this
goes through all the definitions. For each definition def, this goes
through all the expressions. For each expression exp whose type
is NONTERMINAL (meaning it should be a defined production), this checks
that the production whose name is the itemName of exp exists.

*/

void checkExpressions()
{
  prodListCell * prodCell;
  defListCell * defCell;
  expListCell * expCell;
  expression * exp;
  
  for (prodCell = productions.first; prodCell; prodCell = prodCell->next)
    {
      for (defCell = prodCell->data->defs->first;
	   defCell;
	   defCell = defCell->next)
	{
	  for (expCell = defCell->data->expressions->first;
	       expCell;
	       expCell = expCell->next)
	    {
	      exp = expCell->data;
	      if ((exp->theType == NONTERMINAL) &&
		  (findProd(exp->itemName) == 0))
		{
		  fprintf(stderr, 
			  "In a definition of %s, %s is not defined\n",
			  prodCell->data->lhs, exp->itemName);
		  exit(1);
		}
	    }
	}
    }
}


/********************************************************************/

/* findAllAncestors

Returned Value: none

Called By: main

This goes through all the productions. For each production prod, this
finds all the ancestors of prod excluding "instance" and optionals.

*/

void findAllAncestors() /* NO ARGUMENTS */
{
  prodListCell * prodCell;

  for (prodCell = productions.first; prodCell; prodCell = prodCell->next)
    {
      findAncestors(prodCell->data, &(prodCell->data->ancestors));
    }
}

/********************************************************************/

/* findAncestors

Returned Value: none

Called By: findAllAncestors

This goes through the subtypeOf list of prod. For each element that is
not an optional parent and is not already on the ancesti list, this
adds that production to the list and then calls itself recursively on
that element. Thus, it works its way up the tree of supertypes, adding
them all to the ancesti list.

*/

void findAncestors(  /* ARGUMENTS                              */
 production * prod,  /* production for which to find ancestors */
 prodList * ancesti) /* list of ancestors to be filled         */
{
  prodListCell * superCell;
  production * super;
  
  for (superCell = prod->subtypeOf.first;
       superCell;
       superCell = superCell->next)
    {
      super = superCell->data;
      if (super && (!(ancesti->member(super))) &&
	  (super->isOptional != 1) && (super->isOptional != 2))
	{
	  ancesti->pushBack(super);
	  findAncestors(super, ancesti);
	}
    }
}

/********************************************************************/

/* findAttNamesAll

Returned Value: none

Called By: main

This goes through the productions. For each one that is a supertype
and has no supertype itself, it calls findAttNamesOne, which calls
itself recursively to trace down through the supertype tree.  This
process results in the attNames of every production that has any
attNames being populated. See documentation of findAttNamesOne.

*/

void findAttNamesAll()
{
  prodListCell * prodCell;
  production * prod;
  stringListCell * stringCell;

  for (prodCell = productions.first; prodCell;  prodCell = prodCell->next)
    {
      prod = prodCell->data;
      if (strcmp(prod->lhs, "instance") == 0); // skip instance
      else if (prod->subtypeOf.first == 0)
	{
	  for (stringCell = prod->myAtts.first;
	       stringCell;
	       stringCell = stringCell->next)
	    {
	      prod->attNames.pushBack(stringCell->data);
	    }
	  if (prod->isSupertype)
	    findAttNamesOne(prod, &(prod->attNames));
	}
    }
}

/********************************************************************/

/* findAttNamesOne

Returned Value: none

Called By:
  findAttNamesAll
  findAttNamesOne (recursively)

For each subtype sub of supertype super, if the attNames of sub is
empty, this copies the attribute names in the "front" list onto the
beginning of the attNames of sub and copies the myAtts of sub onto the
end of the attNames of sub. Then, if sub is a supertype, calls itself
recursively on sub. Thus, it traces down through a supertype-subtype
tree, setting the attNames of every production in the tree.

It does not matter whether or not front is empty or whether or not the
myAtts of sub is empty.

For a supertype, each definition has one expression in which the
prodValue of the expression is a subtype.

If sub has more than one supertype with non-empty attNames (rapidMovement,
for example), the attNames of sub must be given in the EBNF file. This
will ensure that the attNames list is in the correct order.

If sub has more than one supertype, the part of the supertype-subtype
tree starting with sub will be traversed more than once. However,
after the first traversal, no change will be made to attNames since
none of the attNames of the productions lower in the tree will be
empty.

*/

void findAttNamesOne( /* ARGUMENTS                        */
 production * super,  /* production known to be supertype */
 stringList * front)  /* attNames of super                */
{
  defListCell * defCell;
  production * sub;
  stringListCell * stringCell;

  if (!super->defs)
    return;
  for (defCell = super->defs->first; defCell; defCell = defCell->next)
    {
      sub = defCell->data->expressions->first->data->prodValue;
      if (sub->attNames.first == 0)
	{
	  for (stringCell = front->first;
	       stringCell;
	       stringCell= stringCell->next)
	    {
	      sub->attNames.pushBack(stringCell->data);
	    }
	  for (stringCell = sub->myAtts.first;
	       stringCell;
	       stringCell= stringCell->next)
	    {
	      sub->attNames.pushBack(stringCell->data);
	    }
	}
      if (sub->isSupertype)
	findAttNamesOne(sub, &(sub->attNames));
    }
}

/********************************************************************/

/* findBeInstance

Returned Value: none

Called By: main

This goes through all the productions. If a production Q is an
instance, it looks at each ancestor P of Q and if beInstance of P is
zero sets the beInstance of P to Q. Note that the isInstance of an
ancestor of a production that is an instance must be false.

*/

void findBeInstance() /* NO ARGUMENTS */
{
  prodListCell * subCell;
  prodListCell * superCell;
  production * sub;

  for (subCell = productions.first; subCell; subCell = subCell->next)
    {
      sub = subCell->data;
      if (sub->isInstance)
	{
	  for (superCell = sub->ancestors.first;
	       superCell;
	       superCell = superCell->next)
	    {
	      if (superCell->data->beInstance == 0)
		superCell->data->beInstance = sub;
	    }
	}
    }
}

/********************************************************************/

/* findMixed

Returned Value: none

Called By: main

This looks through all the productions. If a production prod is a
supertype and has non-NULL beInstance (supertypes cannot have
isInstance be true), then the definitions of prod are examined.
Each definition must have only one expression. If that expression
does not have either isInstance or beInstance, then the isSupertype
of prod is set to 2, indicating its subtypes are a mixture of
instances and non-instances.

*/

void findMixed() /* NO ARGUMENTS */
{
  prodListCell * prodCell;   // place on productions list to work on
  production * prod;         // production to work on
  defListCell * defCell;
  production * sub;

  for (prodCell = productions.first; prodCell; prodCell = prodCell->next)
    {
      prod = prodCell->data;
      if (prod->isSupertype && prod->beInstance)
	{
	  for (defCell = prod->defs->first; defCell; defCell = defCell->next)
	    {
	      sub = defCell->data->expressions->first->data->prodValue;
	      if ((!sub->isInstance) && (!sub->beInstance))
		{
		  prod->isSupertype = 2;
		  break;
		}
	    }
	}
    }
}

/********************************************************************/

/* findMyAtts

Returned Value: none

Called By: main

This reads the part of EBNF file that gives the attribute names of
productions as comments. It sets the myAtts of each production
that is included in the section.

That part of the file has the following format:

(* Start attribute names *)
(* angleTaper : angle *)
(* approval : status level *)
...
(* rapidMovement : : itsSecplane itsToolpath itsToolDirection *)
...
(* workplan : itsElements itsChannel itsSetup itsEffect *)
(* End attributes *)

Each line is an EBNF comment; i.e. starts with (* and ends with *).

The "Start attribute names" line must be first.

The "End attributes" line must be last.

The other lines have the name of the production at the front followed
by a colon and the names of the attributes of the production. It is
suggested but not required that the attribute names be as given in
the EXPRESS for the production. In most cases, that is all there is on
the line, but in the case of productions that inherit attributes from
more than one chain of ancestors, there is another colon followed
by the names of all of the attributes of the production, in order
(i.e. the attNames). The names could be deduced but the order could
not be, since the subtypeOf list is not necessarily in the same order
as the SUBTYPE OF statement in the EXPRESS. That order must be used
since the expressions of an instance are in that order.

Blank lines are not allowed.
Newlines in a list of attribute names are not allowed.

Only those attributes that belong to a production should be listed.
Attributes inherited from supertypes should not be included.

That part of the EBNF file may be placed anywhere in the file.
At the end is a good place.

It might be nice to make the format a little more user-friendly by
allowing blank lines and allowing newlines in lists of attribute
names.

*/

void findMyAtts( /* ARGUMENTS                                 */
 FILE * inFile)  /* EBNF file with argument names as comments */
{
  char aName[NAMESIZE]; // a production name
  char aLine[LINESIZE]; // a line of EBNF text
  production * prod;    // production to modify
  int n;                // index in aLine
  int m;                // character counter

  for (;;)
    {
      if (fgets(aLine, LINESIZE, inFile) == 0)
	{
	  fprintf(stderr, "Did not find Start attribute names\n");
	  exit(1);
	}
      if (strcmp(aLine, "(* Start attribute names *)\n") == 0)
	break;
    }
  for (;;)
    {
      if (fgets(aLine, LINESIZE, inFile) == 0)
	{
	  fprintf(stderr, "Did not find End attributes\n");
	  exit(1);
	}
      if (strcmp(aLine, "(* End attributes *)\n") == 0)
	break;
      else
	{
	  if ((aLine[0] != '(') || (aLine[1] != '*'))
	    { 
	      fprintf(stderr, "(* missing at beginning of attribute line");
	      exit(1);
	    }
	  m = 0; // m is not set to 0 on next line if nothing is read
	  sscanf((aLine+2), "%*[ \t]%n", &m);  // read white space
	  n = (m+2);
	  sscanf ((aLine+n), "%[^: \t]%n", aName, &m); // read production name
	  prod = findProd(aName); // find the production
	  if (prod == 0)
	    { 
	      fprintf(stderr, 
		      "Did not find production %s listed in attributes\n",
		      aName);
	      exit(1);
	    }
	  n = (n+m);
	  m = 0; // m is not set to 0 on next line if nothing is read
	  sscanf((aLine+n), "%*[ \t]%n", &m); // read white space
	  n = (n+m);
	  if (aLine[n] != ':')
	    { 
	      fprintf(stderr, "Colon missing in attributes after %s\n", aName);
	      exit(1);
	    }
	  n++;
	  findMyAttsNames(aLine, prod, n, inFile);
	}
    }
}

/********************************************************************/

/* findMyAttsNames

Returned Value: none

Called By: findMyAtts

This reads the attribute names of prod starting after the first colon
on the first line of a line giving the attribute names of prod.
If the attributes are given on more than one line, this reads the
additional lines.

FIX to use same stuff as findMyAtts

*/

void findMyAttsNames( /* ARGUMENTS                                 */
 char * aLine,        /* initially, part of line after first colon */
 production * prod,   /* production being processed                */
 int n,               /* index in aLine at which to start          */
 FILE * inFile)       /* EBNF file with argument names as comments */
{
  char aName[NAMESIZE];  // an attribute name
  int m;                 // character counter
  
  for ( ; ; )
    { // read an attribute name
      m = 0;
      sscanf((aLine+n), "%*[ \t]%n", &m); // read white space
      n = (n+m);
      if (aLine[n] == ':') // found second colon
	break;
      else if (aLine[n] == '\n') // found end of line
	{ // end of line reached so read another line
	  if (fgets(aLine, LINESIZE, inFile) == 0)
	    {
	      fprintf(stderr, "Attribute line is missing *) at the end\n");
	      exit(1);
	    }
	  n = 0;
	}
      else if ((aLine[n] == '*') && (aLine[n+1] == ')'))
	return; // found end of attributes
      else
	{
	  m = 0;
	  sscanf ((aLine+n), "%[^* \t\n]%n", aName, &m); // read attribute name
	  n = (n+m);
	  if (m > 0)
	    prod->myAtts.pushBack(strdup(aName)); // add name to myAtts
	  else
	    {
	      fprintf(stderr, "bad attribute line: %s\n", aLine);
	      exit(1);
	    }
	}
    }
  if (aLine[n] == ':') // found second colon
    {
      n++;
      for ( ; ; )
	{ // read an attribute name
	  m = 0;
	  sscanf((aLine+n), "%*[ \t]%n", &m); // read white space
	  n = (n+m);
	  if (aLine[n] == '\n') // found end of line
	    { // end of line reached so read another line
	      if (fgets(aLine, LINESIZE, inFile) == 0)
		{
		  fprintf(stderr, "Attribute line is missing *) at the end\n");
		  exit(1);
		}
	      n = 0;
	    }
	  else if ((aLine[n] == '*') && (aLine[n+1] == ')'))
	    return; // found end of attributes
	  else
	    {
	      m = 0;
	      sscanf ((aLine+n), "%[^* \t\n]%n", aName, &m); // read att name
	      n = (n+m);
	      if (m > 0)
		prod->attNames.pushBack(strdup(aName)); // add to attNames
	      else
		{
		  fprintf(stderr, "bad attribute line: %s\n", aLine);
		  exit(1);
		}
	    }
	}
    }
}

/********************************************************************/

/* findMyExps

Returned Value: none

Called By: main

This sets the values of myExps in every production that has any
attNames. The myAtts are the attributes that are not inherited from a
supertype. The myExps are the expressions from the EBNF that
correspond to the myAtts. To select myExps for a production prod, a
production (called the "source") that contains all the expressions
belonging to P must first be identified.

If a prod is an instance, then prod is the source. Otherwise, if prod has a
beInstance, then that beInstance is the source. Otherwise, prod is the
source; this works if every production with attributes that is not an
instance or a supertype of an instance has no parent with attributes
and has no subtype with attributes. The EBNF input file must observe
those limitations.

If a production has no supertypes except instance, then it owns all of
its attributes as given in attNames.  If a production has a supertype
that is not instance, then the attributes of that supertype must be
removed from the attributes given in attNames in order to find the
myAtts of the production.

The myExps are selected from those expressions that are TERMINAL or
NONTERMINAL, since those are the only ones that correspond to attributes.

Conceptually, this works as follows. See the diagram below - in the diagram,
the Os are expressions that are not terminals or nonterminals (keywords and
punctuation, for example) and do not match an attribute.

 myAtts (of prod)               B C   D
 expressions of source  O O U O V W O X O Y Z
 attNames (of source)       A   B C   D   E F

1. Let myName be the first of the myAtts (B in the example). Go to step 2.

2. Starting at the first expression on the left in the expressions of source,
   go along the list until a non-O expression is found (U in the diagram),
   and set currentExp to that expression. Go to step 3.

3. Set currentName to the first of the attNames (A in the example).
   Go to step 4.

4. If currentName is myName, go to step 6. Otherwise, go to step 5.

5. Set currentName to the next of the attNames (B in the example) and
   set currentExp to the next non-O expression (V in the example).
   Go back to step 4.

6. Record currentExp as the next expression of myExps. Go to step 7.

7. As long as there are more myAtts
  a. Set myName to the next of myAtts.
  b. Set currentName to the next of attNames.
  c. Check that myName and currentName are the same.
  d. Set currentExp to the next non-O expression.
  e. Go back to step 6.

In the diagram above, the process will stop after D in myAtts is processed,
and the end result will be that myExps of prod will be set to (V W X).

*/

void findMyExps() /* NO ARGUMENTS */
{
  prodListCell * prodCell;   // place on productions list to work on
  production * prod;         // production to work on
  production * source;       // production with all the expressions
  expListCell * expCell;     // place on expression list to use
  stringListCell * attCell;  // cell in attNames
  stringListCell * myCell;   // cell in myAtts

  for (prodCell = productions.first; prodCell; prodCell = prodCell->next)
    {
      prod = prodCell->data;
      myCell = prod->myAtts.first;
      if (!myCell) // if there are no attributes, there are no myExps.
	continue;
      source = (prod->isInstance ? prod :
		prod->beInstance ? prod->beInstance : prod);
      if ((prod->isSupertype) && (source == prod))
	{
	  fprintf(stderr, 
		  "%s is supertype with attributes but no instance subtype\n",
		  prod->lhs);
	  exit(1);
	}
      for (expCell = source->defs->first->data->expressions->first;
           expCell;
	   expCell = expCell->next)
	{ // go to first expression matching an attribute
	  if ((expCell->data->theType == TERMINAL) ||
	      (expCell->data->theType == NONTERMINAL))
	    break;
	}
      if (!expCell)
	{
	  fprintf(stderr,
		  "Not enough expressions to match attributes for %s\n",
		  prod->lhs);
	  if (prod->isSupertype)
	    {
	      fprintf(stderr, 
		      "Instance may be missing an instance subtype of %s\n",
		      prod->lhs);
	    }
	  exit(1);
	}
      for (attCell = source->attNames.first; attCell; attCell = attCell->next)
	{ // find the source attName that is the same as the name in myCell
	  if (strcmp(attCell->data, myCell->data) == 0)
	    break;
	  if (!expCell)
	    {
	      fprintf(stderr,
		      "Not enough expressions to match attributes for %s\n",
		      prod->lhs);
	      if (prod->isSupertype)
		{
		  fprintf(stderr, 
			  "Instance may be missing an instance subtype of %s\n",
			  prod->lhs);
		}
	      exit(1);
	    }
	  for (expCell = expCell->next; expCell; expCell = expCell->next)
	    { // go to expression matching next attribute of attNames
	      if ((expCell->data->theType == TERMINAL) ||
		  (expCell->data->theType == NONTERMINAL))
		break;
	    }
	}
      for ( ; myCell; myCell = myCell->next, attCell = attCell->next)
	{
	  if (!expCell)
	    {
	      fprintf(stderr, 
		      "Not enough expressions to match attributes for %s\n",
		      prod->lhs);
	      exit(1);
	    }
	  else if (!attCell)
	    {
	      fprintf(stderr, "Not enough attNames to match myAtts for %s\n",
		      prod->lhs);
	      exit(1);
	    }
	  else if (strcmp(attCell->data, myCell->data))
	    {
	      fprintf(stderr,
		      "Matching attribute names %s and %s differ for %s\n",
		      attCell->data, myCell->data, prod->lhs);
	      exit(1);
	    }
	  prod->myExps.pushBack(expCell->data);
	  for (expCell = expCell->next; expCell; expCell = expCell->next)
	    { // go to expression matching next attribute of attNames
	      if ((expCell->data->theType == TERMINAL) ||
		  (expCell->data->theType == NONTERMINAL))
		break;
	    }
	}
    }
}

/********************************************************************/

/* production::findOptProds

Returned Value: none

Called By: main

An optional is a production with two definitions, each one expression
long in which the second definition is '$' and the first definition is
a production.

   P =
       C
     | '$'
     ;

P will be called an "optional parent" and C will be called an
"optional child".

The following paragraphs marked A, B, and C describe how YACC is
constructed from EBNF.  In the following paragraphs, confusion is
introduced by the fact that the same symbol is used for an EBNF
production, a YACC production, and a C++ class name. Hence, the symbol
names are preceded by (EBNF), (YACC), or (C++) to indicate which is
intended. Also, a YACC production is called a rule.

A. ------------------------------------
When a definition of production (EBNF)Q includes an expression that is
a production (EBNF)P that is an EBNF instance or is the supertype of
an EBNF instance, in the rule that is generated for (YACC)Q, where
(YACC)P would be expected to appear, "instanceId" appears
instead. This is done because what will actually appear in a Part 21
file is an instanceId. In the action for (YACC)Q, call the constructor
for a (C++)Q, and use NULL as a constructor argument wherever
instanceId appears in the rule for (YACC)Q. Record an association
between the value of the instanceId, the C++ type of the data member
of (C++)Q, and the memory location that should point to the instance
represented by the instanceId so that after the file is read, the
actual instance of (C++)P can be linked in.

In the example below, the "direction" in the EBNF production becomes
"instanceId" in the YACC rule. The first two lines starting with
"direction" are the action for "direction".

B. -----------------------------------
However, if (EBNF)P is an optional parent, using instanceId in the
YACC rule does not work since what will actually appear in a Part 21
file is either an instanceId or $.  Hence, some other method of
passing an instanceId in YACC is needed for an optional parent.
The method is:
 - Go through the productions looking for optional parents P (which is
   done by checking for the structure diagrammed above).
 - Have the type of the value of (YACC)P be a pointer to a (C++)C.
 - If the Part 21 file has a $, have the value of (YACC)P be NULL (which is
   a perfectly good pointer to a (C++)C.
 - If the Part 21 file has an instanceId, have the value of (YACC)P be a
   new (C++)C with its instanceId set to the instanceId that was found.
 - Use (YACC)P in the rule for (YACC)Q.
 - In the YACC action for Q that first constructs a (C++)Q, use the value
   of the (YACC)P. This may be either NULL or a pointer to a (C++)C.
 - If the (C++)P value of (YACC)P is not NULL:
   * set the pointer to the (C++)P in the (C++)Q to NULL.
   * record an association between the value of the instanceId stored in
     the (C++)P, the C++ type of the data member of (C++)Q, and the memory
     location that should point to the instance represented by the instanceId.
   * delete the (C++)P.

In the example below, the "optDirection" in the EBNF production is
still an "optDirection" in the YACC rule. The 7 lines starting with
"if ($9)" are the action for optDirection.

EXAMPLE: -------------------------------

The EBNF production for axis2placement3d shown
below becomes the first YACC rule and action shown below.
The second YACC rule and action are for optDirection.

  *****************************************

EBNF
axis2placement3d =
	  AXIS2PLACEMENT3D , '(' , CharString , c , 
          cartesianPoint , c , direction , c , optDirection , ')'

  *****************************************

YACC
axis2placement3d :
	  AXIS2PLACEMENT3D LPAREN CHARSTRING C
          instanceId C instanceId C optDirection RPAREN
	    { $$ = new axis2placement3d($3, 0, 0, $9);
	      cartesianPoint_refs.push_back(&($$->location));
	      cartesianPoint_nums.push_back($5->get_val());
	      direction_refs.push_back(&($$->axis));
	      direction_nums.push_back($7->get_val());
	      if ($9)
		{
		  $$->set_refDirection(0);
		  direction_refs.push_back(&($$->refDirection));
		  direction_nums.push_back($9->get_iId()->get_val());
		  delete $9;
		}
	    }
	;

optDirection :
	  instanceId
	    { $$ = new direction();
	      $$->set_iId($1);
	    }
	| DOLLAR
	    { $$ = 0; }

C. ------------------------------------

However, there is one further wrinkle. It may be that (EBNF)C is a supertype
of an instance, not an instance. In this case, (C++)C will not have an iId in
which to store the instanceId that was read. The findTransferName function
is called to find a subtype D of (EBNF)C that is an instance and the action
for (YACC)C makes a new (C++)D. It does not matter if D is not the actual
type of the instance because D gets deleted after it has transferred the
instanceId.

EXAMPLE:

The YACC action for optApproachRetractStrategy (which is not an instance)
builds a plungeHelix (which is a subtype of optApproachRetractStrategy
and is an instance).

optApproachRetractStrategy :
	  instanceId
	    { $$ = new plungeHelix();
	      $$->set_iId($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;



 ------------------------------------

findOptProds goes through all the productions, and for each production
P, decides if P is an optional parent.

If P is an optional parent and C is an instance:
  - the isOptional of P is set to 1
  - the optProd of P is set to C
  - the isOptional of C is set to 3
  - the optProd of C is set to P
  - the transferName of P is set to C->lhs

If P is an optional parent and C is the ancestor of an instance:
  - the isOptional of P is set to 1
  - the optProd of P is set to C
  - the isOptional of C is set to 3
  - the optProd of C is set to P
  - the transferName is set in findTransferName

If P is an optional parent and C is neither an instance nor the ancestor
of an instance:
  - the isOptional of P is set to 2
  - the optProd of P is set to C
  - the isOptional of C is set to 3
  - the optProd of C is set to P
  - the transferName is set to C->lhs

If P is not an optional, nothing is done, leaving the optProd of P at
0, the default value.

Since this is checking the isInstance value of each production, the
findSupertypes function, which sets the isInstance value must be run
before this function is run.

*/

void findOptProds() /* NO ARGUMENTS */
{
  prodListCell * prodCell;
  production * parent;
  production * child;
  expList * firstExps;
  expList * lastExps;

  for (prodCell = productions.first; prodCell; prodCell = prodCell->next)
    {
      parent = prodCell->data;
      if (parent->defs->findLength() == 2)
	{
	  firstExps = parent->defs->first->data->expressions;
	  lastExps = parent->defs->last->data->expressions;
	  if ((firstExps->findLength() == 1) &&
	      (lastExps->findLength() == 1) &&
	      (firstExps->first->data->prodValue) &&
	      (lastExps->first->data->theType == ONECHAR) &&
	      (strcmp(lastExps->first->data->itemName, "$") == 0))
	    {
	      child = firstExps->first->data->prodValue;
	      child->isOptional = 3;
	      child->optProd = parent;
	      parent->optProd = child;
	      if (child->isInstance)
		{
		  parent->isOptional = 1;
		  parent->transferName = child->lhs;
		}
	      else if (child->beInstance)
		{
		  parent->isOptional = 1;
		  findTransferName(parent, child);
		}
	      else
		{
		  parent->isOptional = 2;
		  parent->transferName = child->lhs;
		}
	    }
	}
    }
}

/********************************************************************/

/* findProd

Returned Value: production *
If a production with the given itemName exists in the productions list,
this returns that production. Otherwise, it returns NULL.

Called By:
  findMyAtts
  printCppClassDestructorList
  printCppClasses
  printCppClassPrinterListYes
  printYaccForList
  printYaccForOptProd1

*/

production * findProd( /* ARGUMENTS                  */
 char * itemName)      /* name of production to find */
{
  prodListCell * prodCell;

  for (prodCell = productions.first; prodCell; prodCell = prodCell->next)
    {
      if (strcmp(itemName, prodCell->data->lhs) == 0)
	{
	  return prodCell->data;
	}
    }
  return 0;
}

/********************************************************************/

/* findProdValueAll

Returned Value: none

Called By: main

This goes through all the productions and calls findProdValueOne for each.

*/

void findProdValueAll() /* NO ARGUMENTS */
{
  prodListCell * prodCell;

  for (prodCell = productions.first; prodCell; prodCell = prodCell->next)
    {
      findProdValueOne(prodCell->data);
    }
}

/********************************************************************/

/* findProdValueOne

Returned Value: none

Called By: findProdValueAll

This calls setProdValue on the expression list of each of the
definitions of every production except prod. This is done so that
each expression whose name is the same as the name of prod will
have its prodValue pointer set to prod.

*/

void findProdValueOne( /* ARGUMENTS                           */
 production * prod)    /* production to which to set pointers */
{
  prodListCell * userCell;
  defListCell * defCell;

  for (userCell = productions.first; userCell; userCell = userCell->next)
    {
      if (userCell->data == prod)
	continue; // don't check to see if a production uses itself
      for (defCell = userCell->data->defs->first;
	   defCell;
	   defCell = defCell->next)
	{
	  defCell->data->expressions->setProdValue(prod);
	}
    }
}

/********************************************************************/

/* findSupertypes

Returned Value: none

Called By:  main

This goes through all the productions. For each production P, this
checks whether every definition of P has only one expression and that
the expression is a production Q that is not a list. If so, this
changes the isSupertype of P to 1 and adds P to the subtypeOf list
of all the productions in the definitions.

If a production has non-zero isSupertype, a class will be generated for
it which has derived classes.

Note that it is expected that in the EBNF files input to sebnf2pars
if a production has more than one definition and the production is not
a list, each definition will have only one expression and that expression
will be a production.

EXAMPLE - If the EBNF is the following

two5DmillingStrategy =
	  contourParallel
	| bidirectionalMilling
	;

Then the isSupertype of two5DmillingStrategy is set to 1, and the
subtypeOf lists of contourParallel and bidirectionalMilling are made
to include two5DmillingStrategy.

isSupertype may be reset to 2 in findMixed.

*/

void findSupertypes() /* NO ARGUMENTS */
{
  prodListCell * prodCell;
  defListCell * defCell;
  expression * exp;
  production * prod;
  production * sub;

  for (prodCell = productions.first; prodCell; prodCell = prodCell->next)
    {
      prod = prodCell->data;
      for (defCell = prod->defs->first ; defCell; defCell = defCell->next)
	{
	  if (defCell->data->expressions->findLength() != 1)
	    break;
	  exp = defCell->data->expressions->first->data;
	  if ((exp->theType != NONTERMINAL) ||
	      (exp->prodValue == 0)      ||
	      (exp->prodValue->isList))
	    break;
	}
      if (defCell)
	continue;
      prod->isSupertype = 1;
      if (strcmp(prod->lhs, "instance") == 0)
	{
	  for (defCell = prod->defs->first ; defCell; defCell = defCell->next)
	    {
	      sub = defCell->data->expressions->first->data->prodValue;
	      sub->isInstance = true;
	    }
	}
      else
	{
	  for (defCell = prod->defs->first ; defCell; defCell = defCell->next)
	    {
	      sub = defCell->data->expressions->first->data->prodValue;
	      sub->subtypeOf.pushBack(prod);
	    }
	}
    }
}

/********************************************************************/

/* findToken

Returned Value: int
If the text is the name of a token, this returns 1. Otherwise, it returns 0.

Called By:
  printCppClassPrinter
  printYaccProductions
  printYaccUnionAndTypes
  reviseSpelling
  selectProductions

If the token is found in the tokenNames, this also sets *n to the
zero-based index of the position at which the token was found in the
sub-array of the tokenNames starting with the first letter of the
token.

*/

int findToken( /* ARGUMENTS                         */
 char * text,  /* text to look for                  */
 int * n)      /* position at which found, if found */
{
  char ** letterNames;
  int result;

  if ((text[0] < 'A') || (text[0] > 'Z'))
    return 0;
  letterNames = tokenNames[text[0] - 'A'];
  for (*n = 0; (*n < LETTERSIZE); *n = (*n + 1))
    {
      if (letterNames[*n] == 0)
	return 0;
      result = strcmp(text, letterNames[*n]);
      if (result == 0) // found it
	return 1;
      else if (result < 0) // text would come before letterNames[*n]
	return 0;
    }
  return 0;
}

/********************************************************************/

/* findTransferName

Returned Value: none

Called By: findOptProds

See the documentation of findOptProds.

The child is not an instance. The findTransferName function finds a
subtype of the child that is an instance and makes its name the value
of the transferName of the parent. Any subtype of the child that is an
instance will do, so this just picks the first one it finds.

*/

void findTransferName( /* ARGUMENTS                    */
 production * parent,  /* optional parent              */
 production * child)   /* optional child of the parent */
{
  prodListCell * prodCell;
  production * prod;

  for (prodCell = productions.first; prodCell; prodCell = prodCell->next)
    {
      prod = prodCell->data;
      if ((prod->ancestors.member(child)) &&
	  (prod->isInstance))
	{
	  parent->transferName = prod->lhs;
	  break;
	}
    }
  if (!prodCell)
    {
      fprintf(stderr, "did not find transferName for %s\n", parent->lhs);
      exit(1);
    }
}

/********************************************************************/

/* findTypeName

Returned Value: none

Called By:
  printCppClassConstructor
  printCppClassData
  printCppClassAccess

This picks the name to use for the data type of an expression.

For a list, the type name is the name of the list item, except that:
1. if the list item name is CHARSTRING, it is changed to char
2. if the list item name is REALSTRING, it is changed to double
3. if the list item name is instancePlus, it is changed to instance.

For an optional parent, the type name is the name of the optional child.

Otherwise, the type name is the item name of the expression.

*/

char * findTypeName( /* ARGUMENTS                                 */
 expression * exp)   /* expression for which to find a type name  */
{
  char * typeName;

  if (exp->prodValue->isList)
    {
      typeName =
	exp->prodValue->defs->first->data->expressions->last->data->itemName;
      if (strcmp(typeName, "CHARSTRING") == 0)
	typeName = "char";
      else if (strcmp(typeName, "REALSTRING") == 0)
	typeName = "double";
      else if(strcmp(typeName, "instancePlus") == 0)
	typeName = "instance";
    }
  else if ((exp->prodValue->isOptional == 1) ||
	   (exp->prodValue->isOptional == 2))
    typeName = exp->prodValue->optProd->lhs;
  else
    typeName = exp->itemName;
  return typeName;
}

/********************************************************************/

/* main

This is the main routine for the sebnf2yacc parser generator.
This:

1. checks that the executable has been called correctly.

2. opens the EBNF file for reading.

3. initializes arrays of token names, token lexes, and terminal names.

4. calls yyparse to parse in the EBNF file, causing a list of
   productions to be built and populating the three arrays of
   tokens. For each production, a list of definitions is built, and
   it is determined if the production represents a list.

5. closes the EBNF file.

6. calls reviseSpelling to modify the list of token lexes by changing
   the spelling of any token for which the list of productions contains
   a spelling different from the name of the token.

7. reopens the EBNF file.

8. calls findMyAtts to read the comments at the end of the
   EBNF file that contain the names of the attributes of those
   productions that have attributes and to set the attNames of
   those productions.

9. re-closes the EBNF file.

10. calls checkExpressions to check that for every NONTERMINAL expression
   that names a production, the production exists.   

11. calls findProdValueAll to examine every expression in every definition
   in every production and, if an expression represents a reference to a
   production; a pointer to the production is set in the expression.

12. calls findSupertypes to determines which productions are supertypes
   or subtypes of other productions and (1) set the isSupertype of
   those productions that are supertypes and (2) set the subtypeOf
   for those production that are subtypes. It also sets the
   isInstance of subtypes of instance to true.

13. calls findAllAncestors to find all the ancestors of each production.

14. calls findBeInstance to set beInstance for each production
   that is an ancestor of a production for which isInstance is true.

15. call findMixed to identify those supertypes that have some subtypes
   that are instanced and some that are not.

16. calls findOptProds to set the isOptional and optProd for each
   production that is an optional parent or an optional child.

17. calls findAttNamesAll to set attNames for each production that
   has attNames.

18. calls findMyExps to set myExps for each production that has
   attributes.

19. calls printCppClasses to print C++ classes to represent the
   productions in the EBNF file. If the user has given "indirect"
   as the second argument to the sebnf2pars command, get_ and set_
   functions that access the C++ class data will be written and the
   data will be private. If the user has given "direct", no get_ and
   set_ functions are written and the class data is public, so that
   it can be handled directly.  Each class also includes a printSelf
   method, an isA method, and a destructor. Class declarations are
   written into a header (.hh) file. Class definitions are written
   into a code (.cc) file.

20. calls printYacc to print a YACC file for a parser with the same
   productions as the EBNF file. Actions that build a parse tree are
   included with each YACC rule.

21. calls printLex to print a Lex file for the parser.

The name of the EBNF file to be processed should end in ".ebnf".
When this function is called, there should be two command arguments.
The first argument should be the EBNF file name without the suffix.
The second argument should be "direct" or "indirect" (without the
quotes).

The generator is not purely data driven. Many things specific to
STEP Part 21 files are hard-coded in the YACC and Lex files that are
generated.

*/

int main(       /* ARGUMENTS                                      */
 int argc,      /* one more than the number of command arguments  */
 char * argv[]) /* array of executable name and command arguments */
{
  int n;
  int m;
  char fileName[NAMESIZE]; // buffer for file name
  bool direct;

  if ((argc != 3) ||
      (strcmp(argv[2], "direct") && strcmp(argv[2], "indirect")))
    {
      fprintf(stderr, "Usage: %s <base file name> direct|indirect\n", argv[0]);
      fprintf(stderr, "direct = allow direct access, "
	      "e.g. x=foo.bar and foo.bar=x\n");
      fprintf(stderr, "indirect = use access functions, "
	      "e.g. x=foo.get_bar() and foo.set_bar(x)\n");
      exit(1);
    }
  direct = (strcmp(argv[2], "direct") ? false : true);
  sprintf(fileName, "%s.ebnf", argv[1]);
  yyin = fopen(fileName, "r");
  if (yyin == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n", fileName);
      exit(1);
    }
  for (n = 0; n < 26; n++)
    {
      for (m = 0; m < LETTERSIZE; m++)
	{
	  classNames[n][m] = 0;
	  tokenNames[n][m] = 0;
	  tokenLexes[n][m] = 0;
	}
    }
  yyparse();
  fclose(yyin);
  reviseSpelling();
  yyin = fopen(fileName, "r");
  findMyAtts(yyin);
  fclose(yyin);
  checkExpressions();
  findProdValueAll();
  findSupertypes();
  findAllAncestors();
  findBeInstance();
  findMixed();
  findOptProds();
  findAttNamesAll();
  findMyExps();
  printCppClasses(argv[1], direct);
  printYacc(argv[1], direct);
  printLex(argv[1], direct);
  return 0;
}

/********************************************************************/

/* printCppBaseClass

Returned Value: none

Called By: printCppClasses

This prints in the header file the base class for the other classes.
The base class has a virtual function "isA" that determines
if an instance of one class is also an instance of another (parent)
class. The base class also has a virtual printSelf function.

*/

void printCppBaseClass( /* ARGUMENTS                   */
 char * baseClassName,  /* name for base class         */
 FILE * cppHFile,       /* C++ header file to print in */
 FILE * cppCFile)       /* C++ code file to print in   */
{
  printCppClassStart(baseClassName, cppHFile);
  fprintf(cppHFile,
"This is the base class for all other classes. It has virtual\n"
"functions printSelf and isA.\n"
"\n"
"*/\n"
"\n"
"class %s\n", baseClassName);
  fprintf(cppHFile,
"{\n"
"public:\n"
"  %s();\n", baseClassName);
  fprintf(cppHFile,	  
"  virtual ~%s();\n", baseClassName);
  fprintf(cppHFile,	  
"  virtual void printSelf() = 0;\n"
"  virtual int isA(int aType) = 0;\n"
"};\n");
  printStarLine(cppCFile);
  fprintf(cppCFile,
"/* %s */\n", baseClassName);
  fprintf(cppCFile,
"\n"
"%s::%s(){}\n", baseClassName, baseClassName);
  fprintf(cppCFile,	  
"\n"
"%s::~%s(){}\n", baseClassName, baseClassName);
}

/********************************************************************/

/* printCppClassAccess

Returned Value: none

Called By:
  printCppClassList
  printCppClassParent
  printCppClassTop

This (1) prints in the header file the declarations of get and set
functions for each data member of a class and (2) prints in the code
file the definitions of those functions.  See the documentation of
printCppClassData for more details.

The name of each get function is the same as the name of the data member
but with the prefix "get_". A get function has no arguments and returns
the data member.

The name of each set function is the same as the name of the data member
but with the prefix "set_". A set function takes one argument, which is
an item of the same type as the data member. The set function sets the
data member to the value given by the argument. A set function does not
return anything.

This is checking that myExps and myAtts have the same number of elements.

This is not called if myExps is empty (although it could be called
in that case; it just would not print anything).

*/

void printCppClassAccess( /* ARGUMENTS                   */
 char * className,        /* name of class               */
 expList * myExps,        /* expressions to represent    */
 stringList * myAtts,     /* names of attributes         */
 FILE * cppHFile,         /* C++ header file to print in */
 FILE * cppCFile)         /* C++ code file to print in   */
{
  expListCell * expCell;
  stringListCell * attCell;
  expression * exp;
  char * typeName;

  if (myExps->first)
    fprintf(cppCFile, "\n");
  for (expCell = myExps->first, attCell = myAtts->first;
       (expCell || attCell);
       expCell = expCell->next, attCell = attCell->next)
    {
      if (!attCell)
	{
	  fprintf(stderr, "not enough attribute names\n");
	  exit(1);
	}
      if (!expCell)
	{
	  fprintf(stderr, "not enough expressions\n");
	  exit(1);
	}
      exp = expCell->data;
      if (exp->theType == NONTERMINAL)
	{
	  if (!(exp->prodValue))
	    {
	      fprintf(stderr, "Bug in printCppClassAccess\n");
	      exit(1);
	    }
	  typeName = findTypeName(exp);
	  if (exp->prodValue->isList)
	    {
	      fprintf(cppHFile, "  std::list<%s *> * get_%s();\n",
		      typeName, attCell->data);
	      fprintf(cppCFile, "std::list<%s *> * %s::get_%s()\n",
		      typeName, className, attCell->data);
	      fprintf(cppCFile, "  {return %s;}\n", attCell->data);
	      fprintf(cppHFile, "  void set_%s(std::list<%s *> * %sIn);\n",
		      attCell->data, typeName, attCell->data);
	      fprintf(cppCFile, "void %s::set_%s(std::list<%s *> * %sIn)\n",
		      className, attCell->data, typeName, attCell->data);
	      fprintf(cppCFile, "  {%s = %sIn;}\n",
		      attCell->data, attCell->data);
	    }
	  else
	    {
	      fprintf(cppHFile, "  %s * get_%s();\n",
		      typeName, attCell->data);
	      fprintf(cppCFile, "%s * %s::get_%s()\n",
		      typeName, className, attCell->data);
	      fprintf(cppCFile, "  {return %s;}\n", attCell->data);
	      fprintf(cppHFile, "  void set_%s(%s * %sIn);\n",
		      attCell->data, typeName, attCell->data);
	      fprintf(cppCFile, "void %s::set_%s(%s * %sIn)\n",
		      className, attCell->data, typeName, attCell->data);
	      fprintf(cppCFile, "  {%s = %sIn;}\n",
		      attCell->data, attCell->data);
	    }
	}
      else if (exp->theType == TERMINAL)
	{
	  if (strcmp(exp->itemName, "INTSTRING") == 0)
	    {
	      fprintf(cppHFile, "  int get_%s();\n", attCell->data);
	      fprintf(cppCFile, "int %s::get_%s()\n",
		      className, attCell->data);
	      fprintf(cppCFile, "  {return %s;}\n", attCell->data);
	      fprintf(cppHFile, "  void set_%s(int %sIn);\n",
		      attCell->data, attCell->data);
	      fprintf(cppCFile, "void %s::set_%s(int %sIn)\n",
		      className, attCell->data, attCell->data);
	      fprintf(cppCFile, "  {%s = %sIn;}\n",
		      attCell->data, attCell->data);
	    }
	  else if (strcmp(exp->itemName, "REALSTRING") == 0)
	    {
	      fprintf(cppHFile, "  double get_%s();\n", attCell->data);
	      fprintf(cppCFile, "double %s::get_%s()\n",
		      className, attCell->data);
	      fprintf(cppCFile, "  {return %s;}\n", attCell->data);
	      fprintf(cppHFile, "  void set_%s(double %sIn);\n",
		      attCell->data, attCell->data);
	      fprintf(cppCFile, "void %s::set_%s(double %sIn)\n",
		      className, attCell->data, attCell->data);
	      fprintf(cppCFile, "  {%s = %sIn;}\n",
		      attCell->data, attCell->data);
	    }
	  else
	    {
	      fprintf(cppHFile, "  char * get_%s();\n", attCell->data);
	      fprintf(cppCFile, "char * %s::get_%s()\n",
		      className, attCell->data);
	      fprintf(cppCFile, "  {return %s;}\n", attCell->data);
	      fprintf(cppHFile, "  void set_%s(char * %sIn);\n",
		      attCell->data, attCell->data);
	      fprintf(cppCFile, "void %s::set_%s(char * %sIn)\n",
		      className, attCell->data, attCell->data);
	      fprintf(cppCFile, "  {%s = %sIn;}\n",
		      attCell->data, attCell->data);
	    }
	}
    }
}

/********************************************************************/

/* printCppClassConstructor

Returned Value: none

Called By:
  printCppClassList
  printCppClassParent
  printCppClassTop

If the class has attNames, this prints a constructor that has an
argument for each of the attNames.

This will not handle diamonds in the supertype-subtype tree (but there
should not be any).

Getting the commas between parent type constructors right is a nuisance,
since only some of the parent types need a constructor. It is not known
until the next parent type with attributes is found whether a comma is
needed after the last call to a parent type constructor. The needComma
variable deals with that.

*/

void printCppClassConstructor( /* ARGUMENTS                          */
 char * className,             /* name of class being printed        */
 expList * exps,               /* expressions of this and supertypes */
 prodList * subtypeOf,         /* list of immediate supertypes       */
 stringList * attNames,        /* attributes of this and supertypes  */
 stringList * myAtts,          /* attributes of this class only      */
 FILE * cppHFile,              /* C++ header file to print in        */
 FILE * cppCFile)              /* C++ code file to print in          */
{
  expListCell * expCell;
  stringListCell * attCell;
  prodListCell * superCell;
  expression * exp;
  char * typeName;
  int needComma;

  printStarLine(cppCFile);
  fprintf(cppCFile, "/* %s */\n\n", className);
  fprintf(cppCFile, "%s::%s(){}\n\n", className, className); 
  if (attNames->first == 0)
    return; // no attributes, so no constructor
  needComma = 0;
  attCell = attNames->first;
  fprintf(cppHFile, "  %s(\n", className);
  for (expCell = exps->first; expCell; expCell = expCell->next)
    {
      exp = expCell->data;
      if ((exp->theType == NONTERMINAL) ||
	  (exp->theType == TERMINAL))
	{
	  if (!attCell) // may be more exps than attNames
	    break;
  	  if (exp->theType == NONTERMINAL)
	    {
	      if (!(exp->prodValue))
		{
		  fprintf(stderr, "%s is not defined\n", exp->itemName);
		  exit(1);
		}
	      typeName = findTypeName(exp);
	      if (exp->prodValue->isList)
		{
		  fprintf(cppHFile, "    std::list<%s *> * %sIn%s",
			  typeName, attCell->data,
			  ((attCell->next) ? ",\n" : ");\n"));
		}
	      else
		{
		  fprintf(cppHFile, "    %s * %sIn%s",
			  typeName, attCell->data,
			  ((attCell->next) ? ",\n" : ");\n"));
		}
	    }
	  else if (exp->theType == TERMINAL)
	    {
	      if (strcmp(exp->itemName, "INTSTRING") == 0)
		fprintf(cppHFile, "    int %sIn%s", attCell->data,
			((attCell->next) ? ",\n" : ");\n"));
	      else if (strcmp(exp->itemName, "REALSTRING") == 0)
		fprintf(cppHFile, "    double %sIn%s", attCell->data,
			((attCell->next) ? ",\n" : ");\n"));
	      else
		fprintf(cppHFile, "    char * %sIn%s", attCell->data,
			((attCell->next) ? ",\n" : ");\n"));
	    }
	  attCell = attCell->next;
	}
    }
  attCell = attNames->first;
  fprintf(cppCFile, "%s::%s(\n", className, className);
  for (expCell = exps->first; expCell; expCell = expCell->next)
    {
      exp = expCell->data;
      if ((exp->theType == NONTERMINAL) ||
	  (exp->theType == TERMINAL))
	{
	  if (!attCell) // may be more exps than attNames
	    break;
  	  if (exp->theType == NONTERMINAL)
	    {
	      typeName = findTypeName(exp);
	      if (exp->prodValue->isList)
		{
		  fprintf(cppCFile, " std::list<%s *> * %sIn%s",
			  typeName, attCell->data,
			  ((attCell->next) ? ",\n" : ")"));
		}
	      else
		{
		  fprintf(cppCFile, " %s * %sIn%s",
			  typeName, attCell->data,
			  ((attCell->next) ? ",\n" : ")"));
		}
	    }
	  else if (exp->theType == TERMINAL)
	    {
	      if (strcmp(exp->itemName, "INTSTRING") == 0)
		fprintf(cppCFile, " int %sIn%s", attCell->data,
			((attCell->next) ? ",\n" : ")"));
	      else if (strcmp(exp->itemName, "REALSTRING") == 0)
		fprintf(cppCFile, " double %sIn%s", attCell->data,
			((attCell->next) ? ",\n" : ")"));
	      else
		fprintf(cppCFile, " char * %sIn%s", attCell->data,
			((attCell->next) ? ",\n" : ")"));
	    }
	  attCell = attCell->next;
	}
    }
   if (myAtts->first == 0)
    { // only supertypes have attributes
      fprintf(cppCFile, " :\n");
      for (superCell = subtypeOf->first; superCell; superCell = superCell->next)
	{
	  if (superCell->data->attNames.first)
	    { // only print supertype constructor if supertype has attNames
	      if (needComma)
		fprintf(cppCFile, ",\n");
	      fprintf(cppCFile, "   %s(\n", superCell->data->lhs);
	      for (attCell = superCell->data->attNames.first;
		   attCell;
		   attCell = attCell->next)
		{
		  fprintf(cppCFile, "     %sIn%s", attCell->data,
			  (attCell->next ? ",\n" : ")")); 
		}
	      needComma = 1;
	    }
	}
      fprintf(cppCFile, "\n");
      fprintf(cppCFile, "    {}\n");
    }
  else if (strcmp(myAtts->first->data, attNames->first->data))
    { // subtype has attributes and supertypes might have attributes
      fprintf(cppCFile, " :\n");
      for (superCell = subtypeOf->first; superCell; superCell = superCell->next)
	{
	  if (superCell->data->attNames.first)
	    { // only print supertype constructor if supertype has attNames
	      if (needComma)
		fprintf(cppCFile, ",\n");
	      fprintf(cppCFile, "   %s(\n", superCell->data->lhs);
	      for (attCell = superCell->data->attNames.first;
		   attCell;
		   attCell = attCell->next)
		{
		  fprintf(cppCFile, "     %sIn%s", attCell->data,
			  (attCell->next ? ",\n" : ")")); 
		}
	      needComma = 1;
	    }
	}
      fprintf(cppCFile, "\n");
      fprintf(cppCFile, "{\n");
      for (attCell = myAtts->first; attCell; attCell = attCell->next)
	{
	  fprintf(cppCFile, "   %s = %sIn;\n", attCell->data, attCell->data);
	}
      fprintf(cppCFile, "}\n");
    }
  else
    { // only subtype has attributes
      fprintf(cppCFile, "\n");
      fprintf(cppCFile, "{\n");
      for (attCell = attNames->first; attCell; attCell = attCell->next)
	{
	  fprintf(cppCFile, "  %s = %sIn;\n", attCell->data, attCell->data);
	}      
      fprintf(cppCFile, "}\n");
    }
}

/********************************************************************/

/* printCppClassData

Returned Value: none

Called By:
  printCppClassList
  printCppClassParent
  printCppClassTop

This prints in the header file the data members of a class. Data
members for the class being printed are derived from the myExps and
myAtts lists of a production.

The name of each data member is the attribute name given in myAtts.

The name of the type of data for nonterminals is set in findTypeName.
For a list of nonterminals, a std::list<typeName *> is printed.

This is not called unless there is at least one expression in myExps.

*/

void printCppClassData( /* ARGUMENTS                        */
 expList * myExps,      /* expressions to represent         */
 stringList * myAtts,   /* names of attributes              */
 FILE * cppHFile,       /* C++ header file to print in      */
 bool direct)           /* true = use direct access to data */
{
  stringListCell * attCell;
  expListCell * expCell;
  expression * exp;
  char * typeName;

  if (!direct)
    fprintf(cppHFile, "private:\n");
  for (expCell = myExps->first, attCell = myAtts->first;
       (expCell || attCell);
       expCell = expCell->next, attCell = attCell->next)
    {
      if (!attCell)
	{
	  fprintf(stderr, "not enough attribute names\n");
	  exit(1);
	}
      if (!expCell)
	{
	  fprintf(stderr, "not enough expressions\n");
	  exit(1);
	}
      exp = expCell->data;
      if (exp->theType == NONTERMINAL)
	{
	  if (!(exp->prodValue))
	    {
	      fprintf(stderr, "Bug in printCppClassData\n");
	      exit(1);
	    }
	  typeName = findTypeName(exp);
	  if (exp->prodValue->isList)
	    {
	      fprintf(cppHFile, "  std::list<%s *> * %s;\n",
		      typeName, attCell->data);
	    }
	  else
	    {
	      fprintf(cppHFile, "  %s * %s;\n", typeName, attCell->data);
	    }
	}
      else if (exp->theType == TERMINAL)
	{
	  if (strcmp(exp->itemName, "INTSTRING") == 0)
	    fprintf(cppHFile, "  int %s;\n", attCell->data);
	  else if (strcmp(exp->itemName, "REALSTRING") == 0)
	    fprintf(cppHFile, "  double %s;\n", attCell->data);
	  else
	    fprintf(cppHFile, "  char * %s;\n", attCell->data);
	}
    }
}

/********************************************************************/

/* printCppClassDestructor

Returned Value: none

Called By:
  printCppClassList
  printCppClassTop

This is modeled after printCppClassPrinter, but where the printers
that are generated by that function print punctuation and keywords,
the destructors that are generated by this function do nothing,
and where the printers check for NULL pointers, the destructors do not.

EBNF lists of (1) subtypes of instance (isInstance) and (2) supertypes
of subtypes of instance (beInstance), which have the printed form of a
list of #N, should not have their elements deleted except when the
list is the dataSection of an inputFile. Each #N will be deleted when
the dataSection is deleted and must not be deleted more than once.

Only #N items are multiply referenced, so everything else that is a
pointer should be deleted and will not be deleted more than once.

The tree of destructor function calls will be the same as the tree of
printSelf function calls, starting at inputFile.

 */

void printCppClassDestructor( /* ARGUMENTS                        */
 char * className,            /* name for class                   */
 expList * exps,              /* expressions to print from        */
 stringList * attNames,       /* names of all attributes          */
 stringList * myAttNames,     /* names of class attributes        */
 FILE * cppCFile,             /* C++ code file to print in        */
 bool direct)                 /* true = use direct access to data */
{
  expListCell * expCell;
  stringListCell * attCell;
  expression * exp;
  char * elementType;
  char * attName; // attribute name
  char * before;
  char * after;

  fprintf(cppCFile, "\n");
  fprintf(cppCFile, "%s::~%s()\n", className, className);
  fprintf(cppCFile, "{\n");
  attCell = attNames->first;
  for (expCell = exps->first; expCell; expCell = expCell->next)
    {
      exp = expCell->data;

      if ((exp->theType == NONTERMINAL) || (exp->theType == TERMINAL))
	{
	  if (!attCell)
	    {
	      fprintf(stderr, "not enough attribute names\n");
	      exit(1);
	    }
	  attName = attCell->data;
	  if (direct || myAttNames->member(attName))
	    {
	      before = "";
	      after = "";
	    }
	  else
	    {
	      before = "get_";
	      after = "()";
	    }
  	  if (exp->theType == NONTERMINAL)
	    {
	      if (!(exp->prodValue))
		{
		  fprintf(stderr, "Bug in printCppClassDestructor\n");
		  exit(1);
		}
	      else if (exp->prodValue->isList == 2)
		{ // list has commas
		  elementType = exp->prodValue->defs->first->data->
		    expressions->first->data->itemName;
		  if (strcmp(elementType, "CHARSTRING") == 0)
		    elementType = "char";
		  else if (strcmp(elementType, "REALSTRING") == 0)
		    elementType = "double";
		  else if(strcmp(elementType, "instancePlus") == 0)
		    elementType = "instance";
		  printCppClassDestructorList(elementType, before, attName,
					      after, cppCFile);
		  fprintf(cppCFile, "  delete %s%s%s;\n",
			  before, attName, after);
		}
	      else if (exp->prodValue->isList == 1)
		{ // list has no commas
		  elementType = exp->prodValue->defs->first->data->
		    expressions->first->data->itemName;
		  if(strcmp(elementType, "instancePlus") == 0)
		    printCppClassDestructorListInstance(attName, cppCFile);
		  else
		    {
		      fprintf(stderr, 
			      "List without commas must be instance list\n");
		      exit(1);
		    }
		  fprintf(cppCFile, "  delete %s%s%s;\n",
			  before, attName, after);
		}
	      else if ((exp->prodValue->isOptional == 1) ||
		       (exp->prodValue->isOptional == 2))
		{ // an optional parent
		  if (exp->prodValue->isOptional == 2)
		    fprintf(cppCFile, "  delete %s%s%s;\n",
			    before, attName, after);
		  else if (exp->prodValue->optProd->isInstance);
		  else if (exp->prodValue->optProd->beInstance);
		  else
		    {
		      fprintf(stderr, "Bug 2 in printCppClassDestructor\n");
		      exit(1);
		    }
		}
	      else if (exp->prodValue->isInstance);
	      else if (exp->prodValue->beInstance);
	      else
		fprintf(cppCFile, "  delete %s%s%s;\n",
			before, attName, after);
	    }
	  else if (exp->theType == TERMINAL)
	    {
	      if (strcmp(exp->itemName, "INTSTRING") == 0);
	      else if (strcmp(exp->itemName, "REALSTRING") == 0);
	      else if (strcmp(exp->itemName, "CHARSTRING") == 0)
		fprintf(cppCFile, "  delete %s%s%s;\n",
			before, attName, after);
	      else
		{
		  fprintf(stderr, 
			  "unknown TERMINAL in printCppClassDestructor\n");
		  exit(1);
		}
	    }
	  attCell = attCell->next;
	}
    }
  fprintf(cppCFile, "}\n");
}

/********************************************************************/

/* printCppClassDestructorList

Returned Value: none

Called By: printCppClassDestructor

This prints the destructor for a list that is separated by commas.

*/

void printCppClassDestructorList( /* ARGUMENTS                          */
 char * typeName,                 /* name of type of data in list       */
 char * before,                   /* either "get_" or ""                */
 char * attName,                  /* attribute name                     */
 char * after,                    /* either "()" or ""                  */
 FILE * cppCFile)                 /* C++ code file to print in          */
{
  production * prod;

  if (strcmp(typeName, "char") && strcmp(typeName, "double"))
    {
      prod = findProd(typeName);
      if (!prod)
	{
	  fprintf(stderr, "Cannot handle list of %s\n", typeName);
	  exit(1);
	}
      if ((prod->isInstance) || prod->beInstance)
	return;
    }
  fprintf(cppCFile, "  {\n");
  fprintf(cppCFile, "    std::list<%s *>::iterator iter;\n", typeName);
  fprintf(cppCFile, "    for (iter = %s%s%s->begin();\n",
	  before, attName, after);
  fprintf(cppCFile, "         iter != %s%s%s->end();\n",
	  before, attName, after);
  fprintf(cppCFile, "         ++iter)\n");
  fprintf(cppCFile, "      {\n");
  fprintf(cppCFile, "        delete *iter;\n");
  fprintf(cppCFile, "      }\n");
  fprintf(cppCFile, "  }\n");
}

/********************************************************************/

/* printCppClassDestructorListInstance

Returned Value: none

Called By: printCppClassDestructor

This prints the destructor for a list of instances. This is normally
called only for deleting the data section of an input file.

*/

void printCppClassDestructorListInstance( /* ARGUMENTS                 */
 char * attName,                          /* attribute name            */
 FILE * cppCFile)                         /* C++ code file to print in */
{
  fprintf(cppCFile, 
"  {\n"
"    std::list<instance *>::iterator iter;\n" 
"    for (iter = %s->begin(); iter != %s->end(); ++iter)\n"
"      {\n"
"        delete *iter;\n"
"      }\n"
"  }\n", attName, attName);
}

/********************************************************************/

/* printCppClassDoc

Returned Value: none

Called By:
  printCppClassList
  printCppClassTop

This prints in the header file a list of EBNF expressions saying (in
EBNF terms) what the class represents. The printing is done
in the documentation of the class being printed.

This documentation is an essential feature because it is the only
source an applications programmer will have to understand what is
in each part of the parse tree.

For example, for plane, it prints:

PLANE '(' CHARSTRING ',' axis2placement3d ')'

*/

void printCppClassDoc( /* ARGUMENTS                    */
 expList * exps,       /* expressions to print         */
 FILE * cppHFile)      /* C++ header file to print in  */
{
  expListCell * expCell;
  expression * exp;

  for (expCell = exps->first; expCell; expCell = expCell->next)
    {
      exp = expCell->data;
      if (exp == commaExp)
	fprintf(cppHFile, "','");
      else if ((exp->theType == NONTERMINAL) || (exp->theType == TERMINAL))
	{
	  fprintf(cppHFile, "%s", exp->itemName);
	}
      else if (exp->theType == KEYWORD)
	{
	  fprintf(cppHFile, "%s", exp->itemName);
	}
      else if (exp->theType == ONECHAR)
	{
	  fprintf(cppHFile, "'%s'", exp->itemName);
	}
      else
	{
	  fprintf(stderr, "Bug in printCppClassDoc\n");
	  exit(1);
	}
      if (expCell->next)
	fprintf(cppHFile, " ");
    }
}

/********************************************************************/

/* printCppClasses

Returned Value: none

Called By: main

This:

1. opens the header file and the code file

2. calls selectProductions to select the productions for which classes should
   be printed and put them on the toPrint list

3. calls recordClasses to store the names of the productions on the toPrint
   list in alphabetical order in the classNames array.

4. calls printCppDocumentation to print documentation at the beginning of
   the code file and the header file.

5. prints two #includes at the beginning of the code file.

6. calls printCppPrintFunctions to print printDouble and printString
   functions in the code file.

7. prints a #include at the beginning of the header file.

8. calls printCppNames to print in the header file the declarations
of all classes and the enumeration of all class type ids.

9. calls printCppBaseClass to print in the header file the definition
of the base class.

10. goes through the toPrint list and calls printCppProductionClass to print
class definitions in the header file and printSelf functions and destructors
in the code file. See below regarding the order in which classes are printed.

11. prints a star line in the header file and in the code file.

12. closes the header file and the code file.

This prints C++ classes to represent all productions that are not for
lists, terminals or token names and are not optional parents. The
methods for deciding how to represent the productions with classes
were developed with one objective being to minimize the width and
depth of the class hierarchy. The identification and use of
supertypes, as described below, is the primary strategy used to
minimize the size of the class hierarchy.

An enumeration, eNames, is created with a name for every class in the
hierarchy.

A single base class is used at the top of the hierarchy. It has a
virtual function named printSelf.

Only leaf classes (those that are not the base for any derived class)
may be instantiated. Every leaf class is a derived class of instance.

Parent classes are needed to make it possible to reference by type
something that may be any of several derived types.
Each parent class has:
 a default constructor,
 a default destructor,
 a virtual printSelf function.

If every definition of a production P consists of a single expression
that is a nonterminal, then we say P is a supertype.

If P is a supertype, then a single class C with the same name as P is
printed to represent P, and C will be a base class for each of
the classes printed to represent the definitions of P.

If P is not a supertype or a list, P should have only one definition.
Only one class is printed, and the class name is the same as the name
of P. It is an error if there is more than one definition.

The class naming methods just described will produce class names that
are unique within the header file since production names are unique
within the productions.

Since C++ compilers will not allow a derived class to be defined in a
header file until all of its base classes have been defined (note that
this reticence prevents defining loops of class definitions), it is
necessary to ensure that the header file is printed that way. To
enable that, the production class has (1) a boolean wasPrinted data
member, originally set to false, and set to true when class(es) for
the production are printed, (2) an int isSupertype data member
originally set to 0 and reset after productions have been read but
before classes are printed, and (3) a subtypeOf data member whose
value is a list of productions that are supertypes of the production,
originally empty but possibly populated when the check for supertypes
is made.

When this function runs, it goes through the productions repeatedly
and prints classes for the productions whose supertypes have all been
printed. While it does that, it counts the number of productions for
which classes have been printed during each loop and the total number
of productions for which classes have been printed, stopping when
either classes have been printed for all productions or no classes
were printed the last time around the loop. If there is a
subtype/supertype loop in the productions, the total number of
productions for which classes have been printed will be less than
the number of productions, indicating an error, and the program exits.

All subclasses are public. All methods and functions in every class
are public. All data members in every class are private.

This uses the global buffer for file names.

*/

void printCppClasses( /* ARGUMENTS                        */
 char * baseFileName, /* base name of C++ file to print   */
 bool direct)         /* true = use direct access to data */
{
  FILE * cppHFile;
  FILE * cppCFile;
  prodList toPrint;
  production * prod;
  prodListCell * prodCell;
  prodListCell * superCell;
  production * instanceProd;
  static char baseClassName[NAMESIZE];
  static char eName[NAMESIZE];
  int n;
  int totalToPrint;  // total number of productions for which to print classes
  int numberPrinted; // number of productions for which classes printed in loop
  int totalPrinted;  // total number of productions for which classes printed
  
  sprintf(buffer, "%sclasses.hh", baseFileName);
  cppHFile = fopen(buffer, "w");
  if (cppHFile == 0)
    {
      fprintf(stderr, "Unable to open file %s for writing\n", buffer);
      exit(1);
    }
  sprintf(buffer, "%sclasses.cc", baseFileName);
  cppCFile = fopen(buffer, "w");
  if (cppCFile == 0)
    {
      fprintf(stderr, "Unable to open file %s for writing\n", buffer);
      exit(1);
    }
  instanceProd = findProd("instance");
  selectProductions(&toPrint);
  recordClasses(&toPrint);
  printCppDocumentation(cppCFile, cppHFile, direct);
  fprintf(cppCFile, "#include \"%sclasses%s.hh\"\n",
	  baseFileName, (direct ? "Direct" : ""));
  fprintf(cppCFile, "#include <stdio.h>   // for printf, etc.\n");
  printCppPrintFunctions(cppCFile);
  fprintf(cppHFile, "#include <list>\n\n");
  sprintf(eName, "%sClassEName", baseFileName);
  sprintf(baseClassName, "%sCppBase", baseFileName);
  printCppNames(eName, baseClassName, cppHFile);
  printCppBaseClass(baseClassName, cppHFile, cppCFile);
  totalToPrint = toPrint.findLength();
  totalPrinted = 0;
  for (n = 0; n < totalToPrint; n++)
    {
      numberPrinted = 0;
      for (prodCell = toPrint.first; prodCell; prodCell = prodCell->next)
	{
	  prod = prodCell->data;
	  if (prod->wasPrinted == false)
	    {
	      if ((prod->isInstance) &&
		  (instanceProd->wasPrinted == false))
		continue;
	      for (superCell = prod->subtypeOf.first;
		   superCell;
		   superCell = superCell->next)
		{
		  if (superCell->data->wasPrinted == false)
		    break;
		}
	      if (superCell)
		continue; // not all supertypes printed yet
	      printCppProductionClass(prod, eName, baseClassName,
				      cppHFile, cppCFile, direct);
	      prod->wasPrinted = true;
	      numberPrinted++;
	    }
	}
      if (numberPrinted == 0)
	break;
      totalPrinted = (totalPrinted + numberPrinted);
    }
  if (totalPrinted != totalToPrint)
    {
      fprintf(stderr, "loop found in productions\n");
      exit(1);
    }
  printStarLine(cppHFile);
  printStarLine(cppCFile);
  fclose(cppHFile);
  fclose(cppCFile);
}

/********************************************************************/

/* printCppClassIsA

Returned Value: none

Called By:
  printCppClassList
  printCppClassParent
  printCppClassTop

This prints the isA function for a class.

*/

void printCppClassIsA( /* ARGUMENTS                   */
 production * prod,    /* production to print from    */
 char * className,     /* name for class              */
 FILE * cppHFile,      /* C++ header file to print in */
 FILE * cppCFile)      /* C++ code file to print in   */
{ 
  prodListCell * superCell;
  char * superName;

  fprintf(cppHFile, "  int isA(int aType);\n");
  fprintf(cppCFile, "\n");
  fprintf(cppCFile, "int %s::isA(int aType)\n", className);
  fprintf(cppCFile, "    { return ");
  if (prod->ancestors.first)
    fprintf(cppCFile, "(");
  fprintf(cppCFile, "(aType == %s_E)", className);
  for (superCell = prod->ancestors.first; 
       superCell;
       superCell = superCell->next)
    {
      superName = superCell->data->lhs;
      if (strcmp(superName, "instance")) // omit instance
	{
	  fprintf(cppCFile, " ||\n");
	  fprintf(cppCFile, "\t      (aType == %s_E)", superName);
	}
    }
  if (prod->ancestors.first)
    {
      fprintf(cppCFile, ");\n");
      fprintf(cppCFile, "    }\n");
    }
  else
    fprintf(cppCFile, "; }\n");
}

/********************************************************************/

/* printCppClassList

Returned Value: none

Called By: printCppProductionClass

This prints in the header file the definition of a class when the
production being represented is not a supertype and has two
definitions. This happens only if the production represents an EBNF
parenthesized list.

The first definition must be three expressions long, the first
expression must be a left parenthesis, and the last expression must be
a right parenthesis.

The second definition must consist of a left parenthesis followed by
a right parenthesis.

The class is made a subclass of the base class.

By calling printCppClassPrinter, this also prints in the code file the
printSelf function for the class.

By calling printCppClassDestructor, this also prints in the code file the
destructor for the class.

*/

void printCppClassList( /* ARGUMENTS                        */
 production * prod,     /* production to print from         */
 char * className,      /* name for class                   */
 char * eName,          /* name for enumeration of classes  */
 char * baseClassName,  /* name of base class               */
 stringList * attNames, /* names of all attributes          */
 FILE * cppHFile,       /* C++ header file to print in      */
 FILE * cppCFile,       /* C++ code file to print in        */
 bool direct)           /* true = use direct access to data */
{
  expList * exps;
  
  exps = prod->defs->first->data->expressions;
  if ((exps->findLength() != 3) ||
      (strcmp(exps->first->data->itemName, "(")) ||
      (strcmp(exps->last->data->itemName, ")")))
    {
      fprintf(stderr, "%s with two definitions is not a paren list\n",
	      className);
      exit(1);
    }
  exps = prod->defs->last->data->expressions;
  if ((exps->findLength() != 2) ||
      (strcmp(exps->first->data->itemName, "(")) ||
      (strcmp(exps->last->data->itemName, ")")))
    {
      fprintf(stderr, "%s with two definitions is not a paren list\n",
	      className);
      exit(1);
    }
  printCppClassStart(className, cppHFile);
  fprintf(cppHFile,
	  "This is a class for the list %s.\n", className);
  fprintf(cppHFile, "It represents the following items:\n\n");
  printCppClassDoc(prod->defs->first->data->expressions, cppHFile);
  fprintf(cppHFile,"\n  or\n");
  printCppClassDoc(prod->defs->last->data->expressions, cppHFile);
  fprintf(cppHFile, "\n\n*/\n\n");
  fprintf(cppHFile, "class %s :\n", className);
  if (prod->isInstance)
    {
      fprintf(stderr, "list %s must not be an instance\n", className);
      exit(1);
    }
  else if (prod->subtypeOf.first)
    {
      fprintf(stderr, "list %s must not have a supertype\n", className);
      exit(1);
    }
  else
    {
      fprintf(cppHFile, "  public %s\n", baseClassName);
    }
  fprintf(cppHFile, "{\n");
  fprintf(cppHFile, "public:\n");
  fprintf(cppHFile, "  %s();\n", className);
  exps = prod->defs->first->data->expressions;
  printCppClassConstructor(className, exps, &(prod->subtypeOf),
			   attNames, &(prod->myAtts), cppHFile, cppCFile);
  fprintf(cppHFile, "  ~%s();\n", className);
  printCppClassIsA(prod, className, cppHFile, cppCFile);
  fprintf(cppHFile, "  void printSelf();\n");
  printCppClassPrinter(className, exps, attNames,
		       &(prod->myAtts), cppCFile, direct);
  printCppClassDestructor(className, exps, attNames,
			  &(prod->myAtts), cppCFile, direct);
  if (prod->myExps.first)
    {
      if (!direct)
	printCppClassAccess(className, &(prod->myExps), &(prod->myAtts),
			    cppHFile, cppCFile);
      printCppClassData(&(prod->myExps), &(prod->myAtts), cppHFile, direct);
    }
  fprintf(cppHFile, "};\n");
}

/********************************************************************/

/* printCppClassParent

Returned Value: none

Called By: printCppProductionClass

This prints in the header file a class that will be used as a parent
class. It represents a production that is a supertype. If the
supertype is mixed (some instances and some non-instances), it is
identified as mixed and the printSelf function does not have its
definition set to zero.  If it is not mixed, the printSelf function
does have its definition set to zero.

If prod is named "instance", this calls printCppInstanceClass.

*/

void printCppClassParent( /* ARGUMENTS                               */
 production * prod,       /* production for which a class is printed */
 char * className,        /* name for class                          */
 char * eName,            /* name of enumeration for classes         */
 char * baseClassName,    /* name of base class                      */
 FILE * cppHFile,         /* C++ header file to print in             */
 FILE * cppCFile,         /* C++ code file to print in               */
 bool direct)             /* true = use direct access to data        */
{
  prodListCell * superCell;
  expList * exps;
  expList emptyExps;

  printCppClassStart(className, cppHFile);
  if (strcmp(className, "instance") == 0)
    {
      printCppInstanceClass(baseClassName, cppHFile, cppCFile, direct);
      return;
    }
  fprintf(cppHFile, "This is a %sparent class.\n\n*/\n\n",
	  ((prod->isSupertype == 2) ? "mixed " : ""));
  fprintf(cppHFile, "class %s :\n", className);
  superCell = prod->subtypeOf.first;
  if (prod->isInstance)
    {
      fprintf(cppHFile, "  public instance%s\n", (superCell ? "," : ""));
      superCell = prod->subtypeOf.first;
      if (superCell)
	{
	  for ( ; superCell; superCell = superCell->next)
	    {
	      fprintf(cppHFile, "  public %s%s\n", superCell->data->lhs,
		      (superCell->next ? "," : ""));
	    }
	}
    }
  else if (superCell)
	{
	  for ( ; superCell; superCell = superCell->next)
	    {
	      fprintf(cppHFile, "  public %s%s\n", superCell->data->lhs,
		      (superCell->next ? "," : ""));
	    }
	}
  else
      fprintf(cppHFile, "  public %s\n", baseClassName);
  fprintf(cppHFile, "{\n");
  if ((!direct) && (prod->beInstance))
    fprintf(cppHFile, "  friend int yyparse();\n");
  fprintf(cppHFile, "public:\n");
  fprintf(cppHFile, "  %s();\n", className);
  if (prod->attNames.first)
    {
      if (!prod->beInstance)
	{
	  fprintf(stderr,
		  "Cannot handle %s since not a subtype of instance\n",
		  prod->lhs);
	  exit(1);
	}
      exps = prod->beInstance->defs->first->data->expressions;
    }
  else
    exps = &emptyExps;
  printCppClassConstructor(className, exps, &(prod->subtypeOf),
			   &(prod->attNames), &(prod->myAtts),
			   cppHFile, cppCFile);
  fprintf(cppHFile, "  ~%s();\n", className);
  fprintf(cppCFile, "\n%s::~%s(){}\n", className, className);
  printCppClassIsA(prod, className, cppHFile, cppCFile);
  fprintf(cppHFile, "  void printSelf()%s;\n",
	  ((prod->isSupertype == 2) ? "" : " = 0"));
  if (prod->myExps.first)
    {
      if (!direct)
	printCppClassAccess(className, &(prod->myExps), &(prod->myAtts),
			    cppHFile, cppCFile);
      printCppClassData(&(prod->myExps), &(prod->myAtts), cppHFile, direct);
    }
  fprintf(cppHFile, "};\n");
}

/********************************************************************/

/* printCppClassPrinter

Returned Value: none

Called By:
  printCppClassList
  printCppClassTop

This prints in the code file. It prints code for a pretty printer for
a class corresponding to a definition of a production. The pretty
printer that is written prints the following items:

1. a line of stars with a blank line before and after

2. the function type and name (on one line); the function takes no arguments.
   The function name is always printSelf.

3. {

4. one or more lines for each expression in exps, according to the type
   of the expression

   a. comma (check for comma must be first)
      printf(",");

   b. keyword
      printf("<keyword name>");

   c. ONECHAR
      printf("<the char>");
      If the ONECHAR is a semicolon, a newline is also printed, since
      that is the usual way of formatting a Part 21 file.

   d. TERMINALSTRING
      printf("<the string>");

   e. nonterminal that is a list with commas
      (see printCppClassPrinterListYes)

   f. nonterminal that is a list without commas
      (see printCppClassPrinterListNo)

   g. nonterminal that is an optional parent of a child that is not an instance
      if (<attName>)
        <attName>->printSelf();
      else
        printf("$");

   h. nonterminal that is an optional parent of a child with isInstance true
      if (<attName>)
        <attName>->get_iId()->printSelf();
      else
        printf("$");

   i. nonterminal that is an optional parent of a child with beInstance not NULL
      if (<attName>)
        ((instance *)<attName>)->get_iId()->printSelf();
      else
        printf("$");

   j. other nonterminal
      printf("<attName>->printSelf();\n")

   k. terminal INTSTRING
      printf("%d", <attName>);\n"

   l. terminal REALSTRING
      printDouble(<attName>);\n"

   m. terminal CHARSTRING
      printString(<attName>);\n"

5. }

This works from the expressions for the definition from which the
class is generated.

For those attributes of a class that are inherited, access functions
are used in the printSelf functions since the attributes are private
to the parent class. For those attributes that belong to the class,
the attribute is used directly. In the example below, axis and refDirection
belong to axis2placement3d, so they are used directly, while name and
location belong to parent classes, so get_name() and get_location()
are used.

EXAMPLE 1

void axis2placement3d::printSelf()
{
  printf("AXIS2_PLACEMENT_3D");
  printf("(");
  printString(get_name());
  printf(",");
  get_location()->get_iId()->printSelf();
  printf(",");
  axis->get_iId()->printSelf();
  printf(",");
  if (refDirection)
    refDirection->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

*/

void printCppClassPrinter( /* ARGUMENTS                        */
 char * className,         /* name for class                   */
 expList * exps,           /* expressions to print from        */
 stringList * attNames,    /* names of all attributes          */
 stringList * myAttNames,  /* names of class attributes        */
 FILE * cppCFile,          /* C++ code file to print in        */
 bool direct)              /* true = use direct access to data */
{
  int m;
  expListCell * expCell;
  stringListCell * attCell;
  expression * exp;
  production * prod;
  char * elementType;
  char * lexName; // name for keyword stored in tokenLexes
  char * attName; // attribute name
  char * before;
  char * after;
  char * ider;

  fprintf(cppCFile, "\n");
  fprintf(cppCFile, "void %s::printSelf()\n", className);
  fprintf(cppCFile, "{\n");
  attCell = attNames->first;
  for (expCell = exps->first; expCell; expCell = expCell->next)
    {
      exp = expCell->data;
      if (exp == commaExp)
	fprintf(cppCFile, "  printf(\",\");\n");
      else if (exp->theType == KEYWORD)
	{
	  if (!findToken(exp->itemName, &m))
	    {
	      fprintf(stderr, "Bug in printCppClassPrinter\n");
	      exit(1);
	    }
	  lexName = tokenLexes[exp->itemName[0] - 'A'][m];
	  fprintf(cppCFile, "  printf(\"%s\");\n", lexName);
	}
      else if ((exp->theType == ONECHAR) && (exp->itemName[0] == ';'))
	{
	  fprintf(cppCFile, "  printf(\";\\n\");\n");
	}
      else if ((exp->theType == ONECHAR) ||
	       (exp->theType == TERMINALSTRING))
	{
	  fprintf(cppCFile, "  printf(\"%s\");\n", exp->itemName);
	}
      else if ((exp->theType == NONTERMINAL) || (exp->theType == TERMINAL))
	{
	  if (!attCell)
	    {
	      fprintf(stderr, 
		      "not enough attribute names for %s\n", className);
	      exit(1);
	    }
	  attName = attCell->data;
	  if (direct || myAttNames->member(attName))
	    {
	      before = "";
	      after = "";
	    }
	  else
	    {
	      before = "get_";
	      after = "()";
	    }
	  if (direct)
	    ider = "iId";
	  else
	    ider = "get_iId()";
  	  if (exp->theType == NONTERMINAL)
	    {
	      prod = exp->prodValue;
	      if (!prod)
		{
		  fprintf(stderr, "Bug in printCppClassPrinter\n");
		  exit(1);
		}
	      else if (prod->isList == 2)
		{ // list has commas
		  elementType = prod->defs->first->data->
		    expressions->first->data->itemName;
		  if (strcmp(elementType, "CHARSTRING") == 0)
		    elementType = "char";
		  else if (strcmp(elementType, "REALSTRING") == 0)
		    elementType = "double";
		  else if(strcmp(elementType, "instancePlus") == 0)
		    elementType = "instance";
		  printCppClassPrinterListYes(elementType, before, attName,
					      after, ider, 2, cppCFile);
		}
	      else if (prod->isList == 1)
		{ // list has no commas
		  elementType = prod->defs->first->data->
		    expressions->first->data->itemName;
		  if (strcmp(elementType, "CHARSTRING") == 0)
		    elementType = "char";
		  else if (strcmp(elementType, "REALSTRING") == 0)
		    elementType = "double";
		  else if(strcmp(elementType, "instancePlus") == 0)
		    elementType = "instance";
		  printCppClassPrinterListNo(elementType, before, attName,
					     after, ider, 2, cppCFile);
		}
	      else if ((prod->isOptional == 1) || (prod->isOptional == 2))
		{ // an optional parent
		  fprintf(cppCFile, "  if (%s%s%s)\n", before, attName, after);
		  if (prod->isOptional == 2)
		    fprintf(cppCFile, "    %s%s%s->printSelf();\n",
			    before, attName, after);
		  else if (prod->optProd->isInstance)
		    fprintf(cppCFile, "    %s%s%s->%s->printSelf();\n",
			    before, attName, after, ider);
		  else if ((prod->optProd->beInstance) && 
			   (prod->optProd->isSupertype == 2))
		    fprintf(cppCFile, "    %s%s%s->printSelf();\n",
			    before, attName, after);
		  else if (prod->optProd->beInstance)
		    fprintf(cppCFile, 
			    "    (dynamic_cast<instance *>(%s%s%s))->%s"
			    "->printSelf();\n", before, attName, after, ider);
		  else
		    {
		      fprintf(stderr, "Bug 2 in printCppClassPrinter\n");
		      exit(1);
		    }
		  fprintf(cppCFile, "  else\n");
		  fprintf(cppCFile, "    printf(\"$\");\n");
		}
	      else if (prod->isInstance)
		{
		  fprintf(cppCFile, "  %s%s%s->%s->printSelf();\n",
			  before, attName, after, ider);
		}
	      else if (prod->beInstance)
		{
		  fprintf(cppCFile,
			  "  (dynamic_cast<instance *>(%s%s%s))->"
			  "%s->printSelf();\n",
			  before, attName, after, ider);
		}
	      else
		fprintf(cppCFile, "  %s%s%s->printSelf();\n",
			before, attName, after);
	    }
	  else if (exp->theType == TERMINAL)
	    {
	      if (strcmp(exp->itemName, "INTSTRING") == 0)
		fprintf(cppCFile, "  printf(\"%%d\", %s%s%s);\n",
			before, attName, after);
	      else if (strcmp(exp->itemName, "REALSTRING") == 0)
		fprintf(cppCFile, "  printDouble(%s%s%s);\n",
			before, attName, after);
	      else if (strcmp(exp->itemName, "CHARSTRING") == 0)
		fprintf(cppCFile, "  printString(%s%s%s);\n",
			before, attName, after);
	      else
		{
		  fprintf(stderr, "unknown TERMINAL in printCppClassPrinter\n");
		  exit(1);
		}
	    }
	  attCell = attCell->next;
	}
    }
  fprintf(cppCFile, "}\n");
}

/********************************************************************/

/* printCppClassPrinterListNo

Returned Value: none

Called By:
  printCppClassPrinter

This prints in the code file a printer for a list that is not separated
by commas.  The "if" that this prints at the beginning is needed in
case the list is empty, since in the "for" loop the address of iter is
assumed to point to something.

For a list of instances (for which this prints some special code),
this prints:

  if (items->begin() != items->end())
    {
      std::list<instance *>::iterator iter;
      for (iter = items->begin();
           iter != items->end();
           iter++)
        {
          (*iter)->get_iId()->printSelf();
          printf("=");
          (*iter)->printSelf();
          printf(";\n");
        }
    }

In Part 21 files, the only kind of list not separated by commas is a
list of instances, so some of the code here never runs.

*/

void printCppClassPrinterListNo( /* ARGUMENTS                          */
 char * typeName,                /* name of type of data in list       */
 char * before,                  /* either "get_" or ""                */
 char * attName,                 /* attribute name                     */
 char * after,                   /* either "()" or ""                  */
 char * ider,                    /* either "iId" or "get_iId()"        */
 int spaces,                     /* number of spaces before first line */
 FILE * cppCFile)                /* C++ code file to print in          */
{
  int n; // counter for spaces
  
  for (n=0; n<spaces; n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "if (%s%s%s->begin() != %s%s%s->end())\n",
	  before, attName, after, before, attName, after);
  for (n=0; n< (spaces+2); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "{\n");
  for (n=0; n<(spaces+4); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "std::list<%s *>::iterator iter;\n", typeName);
  for (n=0; n<(spaces+4); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "for (iter = %s%s%s->begin();\n", before, attName, after);
  for (n=0; n<(spaces+9); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "iter != %s%s%s->end();\n", before, attName, after);
  for (n=0; n<(spaces+9); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "iter++)\n");
  for (n=0; n<(spaces+6); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "{\n");
  if (strcmp(typeName, "instance") == 0)
    {
      for (n=0; n<(spaces+8); n++) fputc(' ', cppCFile);
      fprintf(cppCFile, "(*iter)->%s->printSelf();\n", ider);
      for (n=0; n<(spaces+8); n++) fputc(' ', cppCFile);
      fprintf(cppCFile, "printf(\"=\");\n");
      for (n=0; n<(spaces+8); n++) fputc(' ', cppCFile);
      fprintf(cppCFile, "(*iter)->printSelf();\n");
      for (n=0; n<(spaces+8); n++) fputc(' ', cppCFile);
      fprintf(cppCFile, "printf(\";\\n\");\n");
    }
  else
    {
      for (n=0; n<(spaces+8); n++) fputc(' ', cppCFile);
      fprintf(cppCFile, "(*iter)->printSelf();\n");
    }
  for (n=0; n<(spaces+6); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "}\n");
  for (n=0; n<(spaces+2); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "}\n");
}

/********************************************************************/

/* printCppClassPrinterListYes

Returned Value: none

Called By:
  printCppClassPrinter

This prints in the code file a printer for list that has commas
separating the list elements. The "if" that this prints at the
beginning is needed in case the list is empty, since in the "for" loop
the address of iter is assumed to point to something.

EXAMPLE 1 - For a list of strings with attribute name "theList", this prints:

  if (theList->begin() != theList->end())
    {
      std::list<char *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          printString(*iter);
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }

If theList were an attribute of a parent type rather than of the class for
which printSelf was being printed, this would print "get_theList()"
in the four places "theList" appears above.

EXAMPLE 2 - For a list of executables, this prints:

  if (theList->begin() != theList->end())
    {
      std::list<executable *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }

*/


void printCppClassPrinterListYes( /* ARGUMENTS                          */
 char * typeName,                 /* name of type of data in list       */
 char * before,                   /* either "get_" or ""                */
 char * attName,                  /* attribute name                     */
 char * after,                    /* either "()" or ""                  */
 char * ider,                     /* either "iId" or "get_iId()"        */
 int spaces,                      /* number of spaces before first line */
 FILE * cppCFile)                 /* C++ code file to print in          */
{
  int n; // counter for spaces
  production * prod;

  for (n=0; n<spaces; n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "if (%s%s%s->begin() != %s%s%s->end())\n",
	  before, attName, after, before, attName, after);
  for (n=0; n<(spaces+2); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "{\n");
  for (n=0; n<(spaces+4); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "std::list<%s *>::iterator iter;\n", typeName);
  for (n=0; n<(spaces+4); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "for (iter = %s%s%s->begin(); ; )\n",
	  before, attName, after);
  for (n=0; n<(spaces+6); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "{\n");
  for (n=0; n<(spaces+8); n++) fputc(' ', cppCFile);
  if (strcmp(typeName, "char") == 0)
    fprintf(cppCFile,"printString(*iter);\n");
  else if (strcmp(typeName, "double") == 0)
    fprintf(cppCFile,"printDouble(*iter);\n");
  else
    {
      prod = findProd(typeName);
      if (!prod)
	{
	  fprintf(stderr, "Cannot handle list of %s\n", typeName);
	  exit(1);
	}
      else if (prod->isInstance)
	fprintf(cppCFile,"(*iter)->%s->printSelf();\n", ider);
      else if ((prod->beInstance) && (prod->isSupertype != 2))
	fprintf(cppCFile,
		"(dynamic_cast<instance *>(*iter))->%s->printSelf();\n", ider);
      else
	fprintf(cppCFile,"(*iter)->printSelf();\n");
    }
  for (n=0; n<(spaces+8); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "if (++iter == %s%s%s->end())\n", before, attName, after);
  for (n=0; n<(spaces+10); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "break;\n");
  for (n=0; n<(spaces+8); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "printf(\",\");\n");
  for (n=0; n<(spaces+6); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "}\n");
  for (n=0; n<(spaces+2); n++) fputc(' ', cppCFile);
  fprintf(cppCFile, "}\n");
}

/********************************************************************/

/* printCppClassPrinterMixed

Returned Value: none

Called By: printCppProductionClass

This prints in the code file a printer for a production is a supertype
that is a mixture of instances and non-instances.

*/

void printCppClassPrinterMixed( /* ARGUMENTS                             */
 production * prod,             /* production for which to print printer */
 FILE * cppCFile,               /* C++ code file to print in             */
 bool direct)                   /* true = access to data is direct       */
{
  char * ider;
  defListCell * defCell;
  production * sub;
  bool started;

  if (direct)
    ider = "iId";
  else
    ider = "get_iId()";
  started = false;
  fprintf(cppCFile, "\n");
  fprintf(cppCFile, "void %s::printSelf()\n", prod->lhs);
  fprintf(cppCFile, "{\n");
  for (defCell = prod->defs->first; defCell; defCell = defCell->next)
    {
      sub = defCell->data->expressions->first->data->prodValue;
      fprintf(cppCFile, "  ");
      if (started)
	fprintf(cppCFile, "else ");
      else
	started = true;
      fprintf(cppCFile, "if (this->isA(%s_E))\n", sub->lhs);
      if (sub->isInstance || sub->beInstance)
	fprintf(cppCFile, 
		"    (dynamic_cast<instance *>(this))->%s->printSelf();\n",
		ider);
      else
	fprintf(cppCFile, "    (dynamic_cast<%s *>(this))->printSelf();\n",
		sub->lhs);
    }
  fprintf(cppCFile, "}\n"); 
}

/********************************************************************/

/* printCppClassStart

Returned Value: none

Called By:
  printCppBaseClass
  printCppClassList
  printCppClassParent
  printCppClassTop

This prints in the header file the first five lines of any class
definition. The first, third, and fifth lines are blank. The second
line is a line of stars.  The third line is the class name.

*/

void printCppClassStart( /* ARGUMENTS                    */
 char * className,       /* name for class               */
 FILE * cppHFile)        /* C++ header file to print in  */
{
  printStarLine(cppHFile);
  fprintf(cppHFile,
"/* %s\n"
"\n",
	  className);
}

/********************************************************************/

/* printCppClassTop

Returned Value: none

Called By: printCppProductionClass

This is called when the production being represented has only one
definition.  This (1) prints in the header file the declaration of a
class, and (2) prints in the code file the definintions of the class
functions and methods.

This:

1. calls printCppClassStart to print in the header file the beginning
   of the class declaration.

2. calls printCppClassDoc to print in the header file what EBNF the
   class represents.

3. prints in the header file the names of the parent classes.

4. makes yyparse a friend function of the class if necessary.

5. calls printCppClassConstructor (1) to print in the header file the
   declaration of two constructors and (2) to print in the code file
   the definitions of the constructors.

6. prints in the header file a declaration of the destructor.

7. calls printCppClassDestructor to print in the code file the
   definition of the destructor.

8. calls printCppClassIsA (1) to print in the header file the
   declaration of the isA method and (2) to print in the code file
   the definition of the isA method.

9. prints in the header file a declaration of the printSelf method.

10. calls printCppClassPrinter to print in the code file the definition of
    the printSelf method.

11. if the class has data members and data access is to be indirect,
    calls printCppClassAccess to print in the code file the
    access functions.

12. if the class has data members, calls printCppClassData to print in the
    header file declarations of the data members.


*/

void printCppClassTop(  /* ARGUMENTS                          */
 production * prod,     /* production to print from           */
 char * className,      /* name for class                     */
 char * eName,          /* name for enumeration of classes    */
 char * baseClassName,  /* name of base class                 */
 definition * def,      /* EBNF definition of class           */
 stringList * attNames, /* names of all attributes            */
 FILE * cppHFile,       /* C++ header file to print in        */
 FILE * cppCFile,       /* C++ code file to print in          */
 bool direct)           /* true = use direct access to data   */
{
  expList * exps;
  prodListCell * superCell;

  superCell = prod->subtypeOf.first;
  exps = def->expressions;
  printCppClassStart(className, cppHFile);
  fprintf(cppHFile,
	  "This is a class for the single definition of %s.\n", className);
  fprintf(cppHFile, "It represents the following items:\n\n");
  printCppClassDoc(def->expressions, cppHFile);
  fprintf(cppHFile, "\n\n*/\n\n");
  fprintf(cppHFile, "class %s :\n", className);
  if (prod->isInstance)
    {
      fprintf(cppHFile, "  public instance%s\n", (superCell ? "," : ""));
      if (superCell)
	{
	  for (;  superCell; superCell = superCell->next)
	    {
	      fprintf(cppHFile, "  public %s%s\n", superCell->data->lhs,
		      (superCell->next ? "," : ""));
	    }
	}
    }
  else if (superCell)
    {
      for (;  superCell; superCell = superCell->next)
	{
	  fprintf(cppHFile, "  public %s%s\n", superCell->data->lhs,
		  (superCell->next ? "," : ""));
	}
    }
  else
    {
      fprintf(cppHFile, "  public %s\n", baseClassName);
    }
  fprintf(cppHFile, "{\n");
  if ((!direct) && (prod->isInstance))
    fprintf(cppHFile, "  friend int yyparse();\n");
  fprintf(cppHFile, "public:\n");
  fprintf(cppHFile, "  %s();\n", className);
  printCppClassConstructor(className, exps, &(prod->subtypeOf),
			   attNames, &(prod->myAtts), cppHFile, cppCFile);
  fprintf(cppHFile, "  ~%s();\n", className);
  printCppClassDestructor(className, def->expressions,
			  attNames, &(prod->myAtts), cppCFile, direct);
  printCppClassIsA(prod, className, cppHFile, cppCFile);
  fprintf(cppHFile, "  void printSelf();\n");
  printCppClassPrinter(className, def->expressions,
		       attNames, &(prod->myAtts), cppCFile, direct);
  if (prod->myExps.first)
    {
      if (!direct)
	printCppClassAccess(className, &(prod->myExps), &(prod->myAtts),
			    cppHFile, cppCFile);
      printCppClassData(&(prod->myExps), &(prod->myAtts), cppHFile, direct);
    }
  fprintf(cppHFile, "};\n");
}

/********************************************************************/

/* printCppDocumentation

Returned Value: none

Called By: printCppClasses

This prints the NIST disclaimer at the beginning of the C++ code file
and prints the NIST disclaimer and documentation at the beginning of
the C++ header file.

It might be nice to improve this by:
  Explain "theList" attribute name.
  Explain that:
  1. non-optional ints and doubles are represented by int and double
  if they are given as IntString and RealString in the EBNF.
  2. non-optional ints and doubles are represented by classes integer and
  real if they are given as integer and real in the EBNF.
  3. optional ints and doubles are represented by classes integer and real.

*/

void printCppDocumentation( /* ARGUMENTS                        */
 FILE * cppCFile,           /* C++ code file to print in        */
 FILE * cppHFile,           /* C++ header file to print in      */
 bool direct)               /* true = use direct access to data */
{

  fprintf(cppCFile, 
"\n"
"/************************************************************************\n"
"  DISCLAIMER:\n"
"  This software was produced by the National Institute of Standards\n"
"  and Technology (NIST), an agency of the U.S. government, and by statute\n"
"  is not subject to copyright in the United States.  Recipients of this\n"
"  software assume all responsibility associated with its operation,\n"
"  modification, maintenance, and subsequent redistribution.\n"
"\n"
"  See NIST Administration Manual 4.09.07 b and Appendix I.\n"
"************************************************************************/\n"
"\n");

  fprintf(cppHFile, 
"\n"
"/************************************************************************\n"
"  DISCLAIMER:\n"
"  This software was produced by the National Institute of Standards\n"
"  and Technology (NIST), an agency of the U.S. government, and by statute\n"
"  is not subject to copyright in the United States.  Recipients of this\n"
"  software assume all responsibility associated with its operation,\n"
"  modification, maintenance, and subsequent redistribution.\n"
"\n"
"  See NIST Administration Manual 4.09.07 b and Appendix I.\n"
"************************************************************************/\n"
"\n"
"/*\n"
"\n"
"This file defines classes used to represent data in Part 21 files.\n"
"The meaning of each class definition is documented. In the\n"
"documentation, punctuation marks and special characters that should\n"
"appear in program files are enclosed in quotes.\n"
"\n"
"A class is defined for each production in the EBNF file that does not\n"
"define a list or give the spelling of a token and is not an optional\n"
"parent.\n"
"\n"
"Each expression from the EBNF definition for a production that\n"
"corresponds to an attribute in the EXPRESS model used by the EBNF file\n"
"is represented by a data member of the class. The name of the data\n"
"member is the EXPRESS attribute name given in the comments at the end\n"
"of the EBNF file. Each represented item is either a list or a class,\n"
"and they are represented as follows.\n"
"\n"
"   Each list data member is represented by a pointer to a C++ standard\n"
"   library list of pointers to the class for the item of which the list\n"
"   is composed. For example, std::list<cartesianPoint *> * theList\n"
"\n"
"   Every other data member is represented by a pointer to the class for\n"
"   that item. \n"
"\n"
"Classes are not defined for optional parents. If there is an optional\n"
"attribute, its value is a pointer to the optional child, but the\n"
"pointer may be NULL. No pointer to a non-optional attribute may be NULL.\n"
"\n");
  if (!direct)
    {
      fprintf(cppHFile,
"For each data member of a C++ class, there is a function to get the data\n"
"member, and a function to set it. The name of each function is the name of\n"
"the data member preceded by either \"get_\" or \"set_\". The get function\n"
"has no arguments and returns the type of data in the data member. The set\n"
"function has an argument whose type is the type of the data member and\n"
"returns nothing.\n"
"\n");
    }
  fprintf(cppHFile,
"Each class from which no other class is derived has two constructors\n"
"and a destructor. One of the constructors takes no arguments, and sets\n"
"nothing. The other constructor takes as many arguments as there are\n"
"data members and sets all the data members.\n"
"\n"
"*/\n"
"\n");
}

/********************************************************************/

/* printCppInstanceClass

Returned Value: none

Called By: printCppClassParent

This (1) prints in the header file the declaration of the instance class,
and (2) prints in the code file the definitions of the functions and
methods.

*/

void printCppInstanceClass( /* ARGUMENTS                        */
 char * baseClassName,      /* name of base class               */
 FILE * cppHFile,           /* C++ header file to print in      */
 FILE * cppCFile,           /* C++ code file to print in        */
 bool direct)               /* true = use direct access to data */
{
  fprintf(cppHFile, 
"This is the instance class.\n"
"\n"
"*/\n"
"\n"
"class instance :\n"
"  public %s\n", baseClassName);
  fprintf(cppHFile,
"{\n"
"public:\n"
"  instance();\n"
"  instance(instanceId * iIdIn);\n"
"  ~instance();\n"
"  int isA(int aType) = 0;\n"
"  void printSelf() = 0;\n");
  if (!direct)
    fprintf(cppHFile, 
"  instanceId * get_iId();\n"
"  void set_iId(instanceId * iIdIn);\n"
"private:\n");
  fprintf(cppHFile,
"  instanceId * iId;\n"
"};\n");
  printStarLine(cppCFile);
  fprintf(cppCFile, 
"/* instance */\n"
"\n"
"instance::instance(){}\n"
"\n"
"instance::instance(instanceId * iIdIn)\n"
"{\n"
"  iId = iIdIn;\n"
"}\n"
"\n"
"instance::~instance(){}\n");
  if (!direct)
    fprintf(cppCFile, 
"\n"
"instanceId * instance::get_iId(){return iId;}\n"
"void instance::set_iId(instanceId * iIdIn){iId = iIdIn;}\n");
}

/********************************************************************/

/* printCppNames

Returned Value: none

Called By: printCppClasses

This prints in the C++ header file the declaration of all the classes
followed by an enumeration of all the class names. The enumeration
name for a class is the name of the class followed by _E.

*/

void printCppNames(    /* ARGUMENTS                       */
 char * eName,         /* name for enumeration of classes */
 char * baseClassName, /* base class name                 */
 FILE * cppHFile)      /* C++ header file to print in     */
{
  int n;
  int k;
  
  for (n = 0; n < 26; n++)
    { // print declarations for all the classes
      for (k=0; classNames[n][k]; k++)
	{
	  fprintf(cppHFile, "class %s;\n", classNames[n][k]);
	}
    }
  fprintf(cppHFile, "class %s;\n", baseClassName);
  printStarLine(cppHFile);
  fprintf(cppHFile, "enum %s {\n", eName);
  for (n = 0; n < 26; n++)
    { // print enumeration names for all the classes
      for (k=0; classNames[n][k]; k++)
	{
	  fprintf(cppHFile, "%s_E,\n", classNames[n][k]);
	}
    }
  fprintf(cppHFile, "%s_E};\n", baseClassName);
}

/********************************************************************/

/* printCppPrintFunctions

Returned Value: none

Called By: printCppClasses

This prints in the C++ code file the printDouble and printString
functions.

The printDouble function this prints prints doubles with the default
number of decimal places (except that trailing zeros other than the
first one after a decimal point are removed) and no leading zeros
(except one zero immediately before a decimal point).

The printString functions this prints puts apostrophes before and
after the string and doubles up apostrophes inside the string (since
that is what Part 21 files require).

*/

void printCppPrintFunctions( /* ARGUMENTS                 */
 FILE * cppCFile)            /* C++ code file to print in */
{
  fprintf(cppCFile,
"\n"
"void printDouble(\n"
" double num)\n"
"{\n"
"  int n;\n"
"  int k;\n"
"  char buffer[50];\n"
"\n"
"  k = sprintf(buffer, \"%%f\", num);\n"
"  for (n = (k-1); ((buffer[n] == '0') && (buffer[n-1] != '.')); n--)\n"
"    buffer[n] = 0;\n"
"  printf(\"%%s\", buffer);\n"
"}\n"
"\n"
"void printString(\n"
" char * aString)\n"
"{\n"
"  int n;\n"
"  putchar('\\'');\n"
"  for (n=0; aString[n]; n++)\n"
"    {\n"
"      putchar(aString[n]);\n"
"      if (aString[n] == '\\'')\n"
"	putchar('\\''); // if apostrophe, print another apostrophe\n"
"    }\n"
"  putchar('\\'');\n""}\n"
"\n");
}

/********************************************************************/

/* printCppProductionClass

Returned Value: none

Called By: printCppClasses

This prints one C++ class to represent a single production.
It prints declarations in the header file and prints function and
method definitions in the code file.

This does not print anything if the production is an instancePlus, since
no use is made of that class.

This is not called if the production is an optional parent, since no
class is needed for optional parents. An instance of an optional parent
is either NULL or an instance of an optional child.

If a production that is not a supertype or a list has multiple definitions,
this prints an error message and exits.

*/

void printCppProductionClass( /* ARGUMENTS                             */
 production * prod,           /* production for which to print classes */
 char * eName,                /* name for enumeration of classes       */
 char * baseClassName,        /* name of base class                    */
 FILE * cppHFile,             /* C++ header file to print in           */
 FILE * cppCFile,             /* C++ code file to print in             */
 bool direct)                 /* true = use direct access to data      */
{
  char * prodName;        // name of production
  defListCell * defCell;
  
  prodName = prod->lhs;
  defCell = prod->defs->first;
  if (defCell == 0)
    { // no definitions
      fprintf(stderr, "Bug in printCppProductionClass\n");
      exit(1);
    }
  else if (prod->isSupertype)
    {
      printCppClassParent(prod, prodName, eName,
			  baseClassName, cppHFile, cppCFile, direct);
      if (prod->isSupertype == 2)
	printCppClassPrinterMixed(prod, cppCFile, direct);
    }
  else if (defCell->next == 0)
    { // only one definition
      printCppClassTop(prod, prodName, eName, baseClassName, defCell->data,
		       &(prod->attNames), cppHFile, cppCFile, direct);
    }
  else if (defCell->next->next == 0)
    { // two definitions - must be a list
      printCppClassList(prod, prodName, eName, baseClassName,
			&(prod->attNames), cppHFile, cppCFile, direct);
    }
  else
    { // more than two definitions
      fprintf(stderr, 
	      "%s has more than two definitions and is not a supertype\n",
	      prodName);
      exit(1);
    }
}

/********************************************************************/

/* printLex

Returned Value: none

Called By: main

This:
1. opens the lex file for printing
2. calls printLexStart to print the first few lines of the lex file.
3. calls printLexMiddle to print the middle of the lex file.
4. calls printLexToken repeatedly to print lex rules to handle all the
   keywords,
5. calls printLexEnd to print lex rules to handle all other token types.
6. closes the lex file

*/

void printLex(        /* ARGUMENTS                        */
 char * baseFileName, /* base name for Lex file name      */
 bool direct)         /* true = use direct access to data */
{
  int m;
  int n;
  char * lexFileName;
  FILE * lexFile;

  lexFileName = new char[strlen(baseFileName) + 5];
  sprintf(lexFileName, "%s.lex", baseFileName);
  lexFile = fopen(lexFileName, "w");
  if (lexFile == 0)
    {
      fprintf(stderr, "Unable to open file %s for writing\n", lexFileName);
      exit(1);
    }
  else
    {
      printLexStart(baseFileName, lexFile, direct);
      printLexMiddle(lexFile);
      for (n = 0; n < 26; n++)
	{
	  for (m = 0; ((m < LETTERSIZE) && (tokenNames[n][m])); m++)
	    {
	      printLexToken(tokenNames[n][m], tokenLexes[n][m], lexFile);
	    }
	}
      printLexEnd(lexFile);
    }
  fclose(lexFile);
  delete[] lexFileName;
}

/********************************************************************/

/* printLexEnd

Returned Value: none

Called By: printLex

This prints the end of the lex file. This includes all the rules for
reading character strings, comments, iId numbers, single characters,
integer strings, and real strings.

In the printed lex file, the right sides below line up correctly
since the backslashes on the left do not print.

*/

void printLexEnd( /* ARGUMENTS            */
 FILE * lexFile)  /* lex file to print in */
{
  fprintf(lexFile,
"{_}\"/*\"                                 {ECH; BEGIN(COMMENT);}\n"
"<COMMENT>.                              {ECH;}\n"
"<COMMENT>\\n                             {ECH;}\n"
"<COMMENT>\"*/\"{_}                        {ECH; BEGIN(INITIAL);}\n"
"{_}'                                    {ECH; j=0; BEGIN INSTRING;}\n" 
"<INSTRING>('')                          {ECH; stringText[j++] = '\\'';}\n" 
"<INSTRING>'{_}                          {ECH; BEGIN INITIAL;\n"
"                                         stringText[j] = 0;\n"
"                                         yylval.sval = strdup(stringText);\n"
"                                         return CHARSTRING;}\n"
"<INSTRING>[ -&(-~\\t]                    {ECH; stringText[j++]=yytext[0];}\n"
"<INSTRING>\\n                            {ECH;\n"
"                                         sprintf(lexMessage,\n"
"                                                 \"newline in string\");\n"
"                                         BEGIN INITIAL;\n"
"                                         return BAD;}\n"
"<INSTRING>.                             {ECH;\n"
"                                         sprintf(lexMessage,\n"
"                                              \"bad character in string\");\n"
"                                         BEGIN INITIAL;\n"
"                                         return BAD;}\n"
"<INID>[0-9]+{_}                         {ECH;\n"
"                                         sscanf(yytext, \"%%d\", &k);\n"
"                                         yylval.ival = k;\n"
"                                         BEGIN INITIAL;\n"
"                                         return INTSTRING;}\n"
"<INID>.                                 {ECH;\n"
"                                         sprintf(lexMessage,\n"
"                                              \"bad character in iId\");\n"
"                                         BEGIN INITIAL;\n"
"                                         return BAD;}\n"
"{_}\"$\"{_}                               {ECH; return DOLLAR;}\n"
"{_}\",\"{_}                               {ECH; return C;}\n"
"{_}\":\"{_}                               {ECH; return COLON;}\n"
"{_}\"=\"{_}                               {ECH; return EQUALS;}\n"
"{_}\"[\"{_}                               {ECH; return LBOX;}\n"
"{_}\"(\"{_}                               {ECH; return LPAREN;}\n"
"{_}\"]\"{_}                               {ECH; return RBOX;}\n"
"{_}\")\"{_}                               {ECH; return RPAREN;}\n"
"{_}\";\"{_}                               {ECH;\n"
"                                           lineTextIndex = 0;\n"
"                                           return SEMICOLON;}\n"
"{_}\"#\"                                  {ECH; BEGIN INID; return SHARP;}\n"
"{_}\"/\"{_}                               {ECH; return SLASH;}\n"
"{_}[0-9]+{_}                            {ECH;\n"
"                                         sscanf(yytext, \"%%d\", &k);\n"
"                                         yylval.ival = k;\n"
"                                         return INTSTRING;}\n"
"{_}(-?|\"+\")(([0-9]+\".\"[0-9]+)|(\".\"[0-9]+)){_} {ECH;\n"
"                                         sscanf(yytext, \"%%lf\", &num);\n"
"                                         yylval.rval = num;\n"
"                                         return REALSTRING;}\n"
"{_}(-?|\"+\")([0-9]+\".\")/[^a-zA-Z]{_}     {ECH;\n"
"                                         sscanf(yytext, \"%%lf\", &num);\n"
"                                         yylval.rval = num;\n"
"                                         return REALSTRING;}\n"
".                                 {ECH;\n"
"                                   sprintf(lexMessage, \"bad character\");\n"
"                                   BEGIN INITIAL;\n"
"                                   return BAD;}\n"
"\n"
"%%%%\n"
"\n"
"int yywrap()\n"
"{\n"
"  return 1;\n"
"}\n");
}

/********************************************************************/

/* printLexMiddle

Returned Value: none

Called By: printLex

This prints a few #defines and some declarations in the middle of the
lex file. It also prints lex definitions and states.

The lex this writes allows either upper or lower case letters in
keywords.

*/

void printLexMiddle( /* ARGUMENTS            */
 FILE * lexFile)     /* lex file to print in */
{
  fprintf(lexFile,
"\n"
"#define ECH  for (k=0; ((k < yyleng) && (lineTextIndex < 4095));)\\\n"
"    lineText[lineTextIndex++] = yytext[k++];\\\n"
"    lineText[lineTextIndex] = 0\n"
"\n"
"extern char lineText[];\n"
"extern char lexMessage[];\n"
"int lineTextIndex;\n"
"char stringText[4096];\n"
"int j;      // index for stringText\n"
"double num; // number to parse reals into\n"
"int k;      // utility index, used in ECH compiler macro\n"
"\n"
"void shiftUpcase(\n"
" char * text)\n"
"{\n"
"  int n;\n"
"  int first;\n"
"  char c;\n"
"\n"
"  for (first = 0; text[first] <= ' '; first++);\n"
"  for (n = first; text[n] > ' '; n++)\n"
"    {\n"
"      c = text[n];\n"
"      text[n - first] = (islower(c) ? toupper(c) : c);\n"
"    }\n"
"  text[n - first] = 0;\n"
"}\n"
"\n"
"%%}\n"
"\n"
"A [aA]\n"
"B [bB]\n"
"C [cC]\n"
"D [dD]\n"
"E [eE]\n"
"F [fF]\n"
"G [gG]\n"
"H [hH]\n"
"I [iI]\n"
"J [jJ]\n"
"K [kK]\n"
"L [lL]\n"
"M [mM]\n"
"N [nN]\n"
"O [oO]\n"
"P [pP]\n"
"Q [qQ]\n"
"R [rR]\n"
"S [sS]\n"
"T [tT]\n"
"U [uU]\n"
"V [vV]\n"
"W [wW]\n"
"X [xX]\n"
"Y [yY]\n"
"Z [zZ]\n"
"\n"
"_ [ \\t\\n\\r]*\n"
"\n"
"%%x COMMENT\n"
"%%x INSTRING\n"
"%%x INID\n"
"\n"
"%%%%\n"
"\n");
}

/********************************************************************/

/* printLexStart

Returned Value: none

Called By:
  printLex

This prints the beginning of the lex file for the parser. It
prints the standard NIST disclaimer and four #includes.

*/

void printLexStart(   /* ARGUMENTS                        */
 char * baseFileName, /* base name for Lex file name      */
 FILE * lexFile,      /* lex file to print in             */
 bool direct)         /* true = use direct access to data */
{
  fprintf(lexFile,
"%%{\n"
"\n"
"/************************************************************************\n"
"  DISCLAIMER:\n"
"  This software was produced by the National Institute of Standards\n"
"  and Technology (NIST), an agency of the U.S. government, and by statute\n"
"  is not subject to copyright in the United States.  Recipients of this\n"
"  software assume all responsibility associated with its operation,\n"
"  modification, maintenance, and subsequent redistribution.\n"
"\n"
"  See NIST Administration Manual 4.09.07 b and Appendix I.\n"
"************************************************************************/\n"
"\n"
"#include <string.h>          // for strdup, etc.\n"
"#include <ctype.h>           // for isalpha\n"
"#include \"%sclasses%s.hh\"\n", baseFileName, (direct ? "Direct" : ""));
  fprintf(lexFile,
"#include \"%sYACC%s.hh\"\n", baseFileName, (direct ? "Direct" : ""));
}

/********************************************************************/

/* printLexString

Returned Value: none

Called By:
  printLexToken

This prints the lex rule for a token name, plus the beginning of the
action for the rule. The rule is always of the form:
(optional white space) leader name trailer

When the parser that is built executes the "ECH" action written here, it
inserts the text that is read at the end of the parser's lineText array.
ECH is defined by the printLexMiddle function.

*/

void printLexString( /* ARGUMENTS                          */
 char * leader,      /* text to print before printing name */
 char * lexString,   /* lex regular expression to print    */
 char * trailer,     /* text to print after printing name  */
 FILE * lexFile)     /* lex file to print in               */
{
  int j;

  j = fprintf(lexFile, "{_}%s%s%s", leader, lexString, trailer);
  for (; j < 40; j++)
    fputc(' ', lexFile);
  fprintf(lexFile, "{ECH; ");
}

/********************************************************************/

/* printLexToken

Returned Value: none

Called By: printLex

This prints the lex rule and action for a token.

EXAMPLE - For ENDSEC, this prints:

{_}{E}{N}{D}{S}{E}{C}{_}                {ECH; return ENDSEC;}

An upper case C is used in the YACC output to stand for a comma, so
C must appear as a token in the YACC file. An upper case C in a Part
21 file, however should not be taken to mean the token C. Hence, when
theName is "C" in this function, nothing is printed.

*/

void printLexToken( /* ARGUMENTS            */
 char * theName,    /* token name to print  */
 char * lexName,    /* lex name to look for */
 FILE * lexFile)    /* lex file to print in */
{
  char lexString[NAMESIZE]; // lex regular expression to print
  int m;                    // index for lexName
  int n;                    // index for lexString

  if (strcmp(theName, "C") == 0)
    return;
  n = 0;
  for (m = 0; lexName[m]; m++)
    {
      if ((lexName[m] >= 'A') && (lexName[m] <= 'Z'))
	n = (n + sprintf((lexString + n), "{%c}", lexName[m]));
      else
	n = (n + sprintf((lexString + n), "\"%c\"", lexName[m]));
    }
  printLexString("", lexString, "{_} ", lexFile);
  fprintf(lexFile, "return %s;}\n", theName);
}

/********************************************************************/

/*  printStarLine

Returned Value: none

Called By:
  printCppBaseClass
  printCppClassConstructor
  printCppClasses
  printCppClassStart
  printCppInstanceClass
  printCppNames
  printYaccIncDefs
  printYaccStart

This prints a line of stars to separate sections of code visually.

*/

void printStarLine( /* ARGUMENTS        */
 FILE * someFile)   /* file to print in */
{
  fprintf(someFile,
"\n"
"/********************************************************************/\n"
"\n");
}

/********************************************************************/

/* printYacc

Returned Value: none

Called By: main

This prints the YACC file. If the file cannot be opened, this
prints an error message and exits. Otherwise, it:
1. opens the YACC file
2. calls printYaccStart
3. calls printYaccMiddle
4. calls printYaccProductions
5. prints %% at the end of the YACC file
6. closes the YACC file

*/

void printYacc(       /* ARGUMENTS                        */
 char * baseFileName, /* base name of YACC file to print  */
 bool direct)         /* true = use direct access to data */
{
  FILE * yaccFile;
  char fileName[NAMESIZE];

  sprintf(fileName, "%s.y", baseFileName);
  yaccFile = fopen(fileName, "w");
  if (yaccFile == 0)
    {
      fprintf(stderr, "Unable to open file %s for writing\n", fileName);
      exit(1);
    }
  printYaccStart(yaccFile, baseFileName, direct);
  printYaccMiddle(yaccFile);
  printYaccProductions(yaccFile, direct);
  fprintf(yaccFile, "%%%%\n");
  fclose(yaccFile);
}

/********************************************************************/

/* printYaccAction

Returned Value: none

Called By:  printYaccForPlain

This prints in the C++ code file the action to be taken when a YACC
rule is triggered.

EXAMPLE: 

The EBNF production for axis2placement3d is:

AXIS2PLACEMENT3D , '(' , CharString , c , 
          cartesianPoint , c , direction , c , optDirection , ')'

The YACC rule written by printYaccRule for axis2placement3d (with the
index for each expression written here above the expression) is:

  1       2       3      4     5      6     7      9      9         10
AXIS2  LPAREN CHARSTRING C instanceId C instanceId C optDirection RPAREN

Where AXIS2PLACEMENT3D has been abbreviated to AXIS2 so that the whole
rule will fit on on line.

For the action for axis2placement3d, this prints:

              $$ = new axis2placement3d($3, 0, 0, $9);
	      cartesianPoint_refs.push_back(&($$->location));
	      cartesianPoint_nums.push_back($5->get_val());
	      delete $5;
	      direction_refs.push_back(&($$->axis));
	      direction_nums.push_back($7->get_val());
	      delete $7;
	      if ($9)
		{
		  $$->refDirection = 0;
		  direction_refs.push_back(&($$->refDirection));
		  direction_nums.push_back($9->get_iId()->get_val());
		  delete $9->get_iId();
		  delete $9;
		}

If optDirection were replaced in the rule by optToolpathSpeedprofile,
which is an optional based on a mixed supertype, the block starting
with "if ($9)" would be replaced by the following. The check of
whether $9 is a toolpathSpeed is needed because $9 could also be a
real or a speedName, in which case it should not be modified.

              if (($9) && ($9->isA(toolpathSpeed_E)))
		{
		  toolpathSpeed * v;
		  v = dynamic_cast<toolpathSpeed *>($9);
		  $$->itsSpeed = 0;
		  toolpathSpeedprofile_refs.push_back(&($$->itsSpeed));
		  toolpathSpeedprofile_nums.push_back(v->get_iId()->get_val());
		  delete v->get_iId();
		  delete $9;
		}

The arguments to the constructor on the first line of the action are
printed by printYaccActionItem. Everything after the first line
except the closing brace is printed by printYaccRecordRefs.

*/

void printYaccAction(   /* ARGUMENTS                                   */
 char * prodName,       /* name of production for action               */
 char * className,      /* name of class to instantiate                */
 expList * exps,        /* expressions to use in making class instance */
 stringList * attNames, /* attribute names                             */
 FILE * yaccFile,       /* YACC file to print in                       */
 bool direct)           /* true = use direct access to data            */
{
  expListCell * expCell;
  int n;            // counter for exps
  int commaFlag;    // 1 means a comma and space are needed, 0 = not
  char * before;
  char * after;
  
  commaFlag = 0;
  if (direct)
    {
      before = "";
      after = "";
    }
  else
    {
      before = "get_";
      after = "()";
    }
  if (strcmp(className, "instancePlus") == 0)
    {
      fprintf(yaccFile,
"	    { int n;\n"
"	      $$ = $3;\n");
      if (direct)
	fprintf(yaccFile, "	      $3->iId = $1;\n");
      else
	fprintf(yaccFile, "	      $3->set_iId($1);\n");
      fprintf(yaccFile,
	      "	      n = $1->%sval%s;\n", before, after);
      fprintf(yaccFile,
"	      if (n < INSTANCEMAX)\n"
"		{\n"
"		  if (instances[n])\n"
"		    {\n"
"		      fprintf(report, \"instanceId %%d reused\\n\", n);\n"
"		      numErrors++;\n"
"		    }\n"
"		  else\n"
"		    instances[n] = $$;\n"
"		}\n"
"	      else\n"
"		{\n"
"		  fprintf(report, \"instanceId %%d is too large\\n\", n);\n"
"		  numErrors++;\n"
"		}\n"
"	    }\n");
    }
  else
    {
      fprintf(yaccFile, "\t    { $$ = new %s(", className);
      for (n = 1, expCell = exps->first ; expCell; n++, expCell = expCell->next)
	{
	  printYaccActionItem(expCell->data, &commaFlag, n, yaccFile);
	}
      fprintf(yaccFile, ");");
      printYaccRecordRefs(exps, attNames, yaccFile, before, after);
    }
}

/********************************************************************/

/* printYaccActionItem

Returned Value: none

Called By:
  printYaccAction
  printYaccFirstAction

This prints in the YACC file the arguments to the constructor called
on the first line of the YACC action.

This prints:
 $N for terminals.
 NULL for nonterminals that are productions with isInstance true
   or non-NULL beInstance.
 $N for other nonterminals.

Everything else is ignored.

See example in documentation of printYaccAction.

Commas must be printed between the arguments of a constructor.  The
caller will not know whether or not this function has printed an item,
so the commaFlag is used here and in the caller. The caller sets the
commaFlag to 0 before its first call to this function, and when this
function prints an item, this function resets the commaFlag to 1.

*/

void printYaccActionItem( /* ARGUMENTS                            */
 expression * exp,        /* expression to print from             */
 int * commaFlag,         /* 1 = print comma, 0=don't, reset here */
 int n,                   /* counter for arguments of rule        */
 FILE * yaccFile)         /* YACC file to print in                */
{
  if (exp->theType == TERMINAL)
    {
      if (*commaFlag) // printed arg, so print comma and newline
	fprintf(yaccFile, ", ");
      *commaFlag = 1;
      fprintf(yaccFile, "$%d", n);
    }
  else if (exp->theType == NONTERMINAL)
    {
      if (*commaFlag) // printed arg, so print comma and newline
	fprintf(yaccFile, ", ");
      *commaFlag = 1;
      if ((exp->prodValue) &&
	  ((exp->prodValue->isInstance) ||
	   (exp->prodValue->beInstance)))
	fprintf(yaccFile, "0");
      else
	fprintf(yaccFile, "$%d", n);
    }
}

/********************************************************************/

/* printYaccExpression

Returned Value: none

Called By: printYaccRule

This prints one expression into the YACC file.

*/

void printYaccExpression( /* ARGUMENTS             */
 expression * exp,        /* expression to print   */
 FILE * yaccFile)         /* YACC file to print in */
{
  if (exp == commaExp)
    fprintf(yaccFile, " C");
  else if ((exp->theType == KEYWORD)     ||
	   (exp->theType == NONTERMINAL) ||
	   (exp->theType == TERMINAL))
    fprintf(yaccFile, " %s", exp->itemName);
  else if (exp->theType == ONECHAR)
    {
      switch (exp->itemName[0])
	{
	case ',':
	  fprintf(yaccFile, " C");
	  break;
	case ';':
	  fprintf(yaccFile, " SEMICOLON");
	  break;
	case '/':
	  fprintf(yaccFile, " SLASH");
	  break;
	case '=':
	  fprintf(yaccFile, " EQUALS");
	  break;
	case ':':
	  fprintf(yaccFile, " COLON");
	  break;
	case '$':
	  fprintf(yaccFile, " DOLLAR");
	  break;
	case '[':
	  fprintf(yaccFile, " LBOX");
	  break;
	case ']':
	  fprintf(yaccFile, " RBOX");
	  break;
	case '(':
	  fprintf(yaccFile, " LPAREN");
	  break;
	case ')':
	  fprintf(yaccFile, " RPAREN");
	  break;
	case '#':
	  fprintf(yaccFile, " SHARP");
	  break;
	default:
	  fprintf(stderr, "Unknown onechar type in printYaccExpression\n");
	  exit(1);
	} 
    }
  else if (exp->theType == TERMINALSTRING)
    {
      fprintf(stderr, "Cannot handle terminal string in printYaccExpression\n");
      exit(1);
    }
  else if (exp->theType == TWOCHAR)
    {
      fprintf(stderr, "Bad expression type in printYaccExpression\n");
      exit(1);
    }
  else
    {
      fprintf(stderr, "Unknown expression type in printYaccExpression\n"); 
      exit(1);
    }
}

/********************************************************************/

/* printYaccFirstAction

Returned Value: none

Called By:  printYaccFirstProduction

This prints in the YACC file the action for the first production.
This is similar to printYaccAction, except that it writes a second
line of each action, which is "tree = $$;". The tree variable is
global, and the name "tree" is hard-coded.

*/

void printYaccFirstAction( /* ARGUMENTS                                   */
 char * className,         /* name of class to instantiate                */
 expList * exps,           /* expressions to use in making class instance */
 FILE * yaccFile)          /* YACC file to print in                       */
{
  expListCell * expCell;
  int n;            // counter for exps
  int commaFlag;    // 1 means a comma and space are needed, 0 = not
  
  commaFlag = 0;
  fprintf(yaccFile, "\t    { $$ = new %s(", className);
  for (n = 1, expCell = exps->first ; expCell; n++, expCell = expCell->next)
    {
      printYaccActionItem(expCell->data, &commaFlag, n, yaccFile);
    }
  fprintf(yaccFile, ");\n");
  fprintf(yaccFile, "\t      tree = $$; }\n");
}

/********************************************************************/

/* printYaccFirstProduction

Returned Value: none

Called By: printYaccProductions

This writes in the YACC file the rule and action for the first production.
The first production must not be a list or a supertype and must have exactly
one definition.

*/

void printYaccFirstProduction( /* ARGUMENTS                 */
 production * prod,            /* first production to print */
 FILE * yaccFile)              /* YACC file to print in     */
{
  expList * exps;

  if ((prod->isList) || (prod->isSupertype))
    {
      fprintf(stderr, "First production must not be a list or a supertype\n");
      exit(1);
    }
  if ((prod->defs->first == 0) || (prod->defs->first != prod->defs->last))
    {
      fprintf(stderr, "First production must have exactly one definition\n");
      exit(1);
    }
  fprintf(yaccFile, "%s :\n", prod->lhs);
  exps = prod->defs->first->data->expressions;
  printYaccRule(exps, yaccFile);
  printYaccFirstAction(prod->lhs, exps, yaccFile);
  fprintf(yaccFile, "\t;\n\n");
}

/********************************************************************/

/* printYaccForList

Returned Value: none

Called By: printYaccProduction

This prints in the YACC file the rule and action for a list.

It is determined whether the list is separated by commas by checking if
prod->isList is 2.

In three cases of listed thing the name of the thing is changed:
CHARSTRING -> char
REALSTRING -> double
instancePlus -> instance

*/

void printYaccForList( /* ARGUMENTS                           */
 production * prod,    /* list production from which to print */
 char * listName,      /* name of the list                    */
 defList * defins,     /* definitions of the production       */
 FILE * yaccFile,      /* YACC file to print in               */
 bool direct)          /* true = use direct access to data    */
{
  char * listItemName;
  int index;
  const char * coma;
  production * listItemProd;

  listItemName = defins->first->data->expressions->first->data->itemName;
  index = ((prod->isList == 2) ? 3 : 2);
  coma =  ((prod->isList == 2) ? "C " : "");
  listItemProd = findProd(listItemName);
  if (strcmp(listItemName, "CHARSTRING") == 0)
    printYaccForListDefault(listName, listItemName, "char",
			    index, coma, yaccFile);
  else if (strcmp(listItemName, "REALSTRING") == 0)
    printYaccForListDefault(listName, listItemName, "double",
			    index, coma, yaccFile);
  else if (strcmp(listItemName, "instancePlus") == 0)
    printYaccForListDefault(listName, listItemName, "instance",
			    index, coma, yaccFile);
  else if (listItemProd && 
	   ((listItemProd->isInstance) ||
	    ((listItemProd->beInstance) && (listItemProd->isSupertype != 2))))
    printYaccForListInstance(listName, listItemName,
			     index, coma, yaccFile, direct);
  else if (listItemProd &&
	   (listItemProd->beInstance) &&
	   (listItemProd->isSupertype == 2))
    printYaccForListMixed(listName, listItemProd,
			  index, coma, yaccFile, direct);
  else
    printYaccForListDefault(listName, listItemName, listItemName,
			    index, coma, yaccFile);
}

/********************************************************************/

/* printYaccForListDefault

Returned Value: none

Called By: printYaccForList

This prints in the YACC file the rule and action for a list when the
list item has isInstance false and NULL beInstance.

If the EBNF form does not use a comma separator, so that the form is:

thingList =
	  thing
        | thingList , thing
        ;

Then this prints

        	  thing
        	    { $$ = new std::list<thing *>;
                      $$->push_back($1); }
        	| thingList thing
	            { $$ = $1;
                      $$->push_back($2); }

If the EBNF form uses a comma separator, so that the form is:

thingList =
	  thing
        | thingList , c , thing
        ;

Then this prints

        	  thing
        	    { $$ = new std::list<thing *>;
                      $$->push_back($1); }
        	| thingList C thing
	            { $$ = $1;
                      $$->push_back($3); }

*/

void printYaccForListDefault( /* ARGUMENTS                         */
 char * listName,             /* name of the list                  */
 char * listItemName,         /* name of the item listed           */
 char * listItemClass,        /* name of class for the item listed */
 int index,                   /* 3 if comma used, 2 if not         */
 const char * coma,           /* "C " if comma used, "" if not     */
 FILE * yaccFile)             /* YACC file to print in             */
{
  fprintf(yaccFile, "\t  %s\n", listItemName);
  fprintf(yaccFile, "\t    { $$ = new std::list<%s *>;\n", listItemClass);
  fprintf(yaccFile, "\t      $$->push_back($1); }\n");
  fprintf(yaccFile, "\t| %s %s%s\n", listName, coma, listItemName);
  fprintf(yaccFile, "\t    { $$ = $1;\n"); 
  fprintf(yaccFile, "\t      $$->push_back($%d); }\n", index);
}

/********************************************************************/

/* printYaccForListInstance

Returned Value: none

Called By: printYaccForList

This prints in the YACC file the rule and action for a list when the
list item is not mixed and has isInstance true or non-NULL beInstance.

If the EBNF form does not use a comma separator, so that the form is:

thingList =
	  thing
        | thingList , thing
        ;

Then this prints

	  instanceId
	    { $$ = new std::list<thing *>;
	      $$->push_back(0);
	      thing_refs.push_back(&($$->back()));
	      thing_nums.push_back($1->get_val());
	    }
	| thingList instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      thing_refs.push_back(&($$->back()));
	      thing_nums.push_back($2->get_val());
	    }

If the EBNF form uses a comma separator, so that the form is:

thingList =
          thing
        | thingList , c , thing  
        ;

Then this prints

	  instanceId
	    { $$ = new std::list<thing *>;
	      $$->push_back(0);
	      thing_refs.push_back(&($$->back()));
	      thing_nums.push_back($1->get_val());
	    }
	| thingList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      thing_refs.push_back(&($$->back()));
	      thing_nums.push_back($3->get_val());
	    }

*/

void printYaccForListInstance( /* ARGUMENTS                        */
 char * listName,              /* name of the list                 */
 char * listItemName,          /* name of the item listed          */
 int index,                    /* 3 if comma used, 2 if not        */
 const char * coma,            /* "C " if comma used, "" if not    */
 FILE * yaccFile,              /* YACC file to print in            */
 bool direct)                  /* true = use direct access to data */
{
  fprintf(yaccFile, "\t  instanceId\n");
  fprintf(yaccFile, "\t    { $$ = new std::list<%s *>;\n", listItemName);
  fprintf(yaccFile, "\t      $$->push_back(0);\n");
  fprintf(yaccFile, "\t      %s_refs.push_back(&($$->back()));\n",
	  listItemName);
  if (direct)
    fprintf(yaccFile, "\t      %s_nums.push_back($1->val);\n",
	    listItemName);
  else
    fprintf(yaccFile, "\t      %s_nums.push_back($1->get_val());\n",
	    listItemName);
  fprintf(yaccFile, "\t    }\n");
  fprintf(yaccFile, "\t| %s %sinstanceId\n", listName, coma);
  fprintf(yaccFile, "\t    { $$ = $1;\n"); 
  fprintf(yaccFile, "\t      $$->push_back(0);\n");
  fprintf(yaccFile, "\t      %s_refs.push_back(&($$->back()));\n",
	  listItemName);
  if (direct)
    fprintf(yaccFile, "\t      %s_nums.push_back($%d->val);\n",
	    listItemName, index);
  else
    fprintf(yaccFile, "\t      %s_nums.push_back($%d->get_val());\n",
	    listItemName, index);
  fprintf(yaccFile, "\t    }\n");
}

/********************************************************************/

/* printYaccForListMixed

Returned Value: none

Called By: printYaccForList

This prints in the YACC file the rule and action for a list when the
list item is mixed.

For trimmingSelectList, whose list item is trimmingSelect (which is
a cartesianPoint or a real), this prints:

trimmingSelectList :
	  instanceId
	    { $$ = new std::list<trimmingSelect *>;
	      $$->push_back(0);
	      trimmingSelect_refs.push_back(&($$->back()));
	      trimmingSelect_nums.push_back($1->get_val());
	    }
	| real
	    { $$ = new std::list<trimmingSelect *>;
	      $$->push_back($1);
	    }
	| trimmingSelectList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      trimmingSelect_refs.push_back(&($$->back()));
	      trimmingSelect_nums.push_back($3->get_val());
	    }
	| trimmingSelectList C real
	    { $$ = $1;
	      $$->push_back($3);
	    }
	;

*/

void printYaccForListMixed( /* ARGUMENTS                        */
 char * listName,           /* name of the list                 */
 production * listItemProd, /* item being listed                */
 int index,                 /* 3 if comma used, 2 if not        */
 const char * coma,         /* "C " if comma used, "" if not    */
 FILE * yaccFile,           /* YACC file to print in            */
 bool direct)               /* true = use direct access to data */
{
  char * listItemName; 
  defListCell * defCell;
  production * sub;

  listItemName = listItemProd->lhs;
  fprintf(yaccFile, "\t  instanceId\n");
  fprintf(yaccFile, "\t    { $$ = new std::list<%s *>;\n", listItemName);
  fprintf(yaccFile, "\t      $$->push_back(0);\n");
  fprintf(yaccFile, "\t      %s_refs.push_back(&($$->back()));\n",
	  listItemName);
  if (direct)
    fprintf(yaccFile, "\t      %s_nums.push_back($1->val);\n",
	    listItemName);
  else
    fprintf(yaccFile, "\t      %s_nums.push_back($1->get_val());\n",
	    listItemName);
  fprintf(yaccFile, "\t    }\n");
  for (defCell = listItemProd->defs->first; defCell; defCell = defCell->next)
    {
      sub = defCell->data->expressions->first->data->prodValue;
      if (sub->isInstance || sub->beInstance)
	continue;
      fprintf(yaccFile, "\t| %s\n", sub->lhs);
      fprintf(yaccFile, "\t    { $$ = new std::list<%s *>;\n", listItemName);
      fprintf(yaccFile, "\t      $$->push_back($1);\n");
      fprintf(yaccFile, "\t    }\n");
    }
  fprintf(yaccFile, "\t| %s %sinstanceId\n", listName, coma);
  fprintf(yaccFile, "\t    { $$ = $1;\n"); 
  fprintf(yaccFile, "\t      $$->push_back(0);\n");
  fprintf(yaccFile, "\t      %s_refs.push_back(&($$->back()));\n",
	  listItemName);
  if (direct)
    fprintf(yaccFile, "\t      %s_nums.push_back($%d->val);\n",
	    listItemName, index);
  else
    fprintf(yaccFile, "\t      %s_nums.push_back($%d->get_val());\n",
	    listItemName, index);
  fprintf(yaccFile, "\t    }\n");
  for (defCell = listItemProd->defs->first; defCell; defCell = defCell->next)
    {
      sub = defCell->data->expressions->first->data->prodValue;
      if (sub->isInstance || sub->beInstance)
	continue;
      fprintf(yaccFile, "\t| %s %s%s\n", listName, coma, sub->lhs);
      fprintf(yaccFile, "\t    { $$ = $1;\n");
      fprintf(yaccFile, "\t      $$->push_back($%d);\n", index);
      fprintf(yaccFile, "\t    }\n");
    }
}

/********************************************************************/

/* printYaccForOptProd0

Returned Value: none

Called By: printYaccProduction

This prints in the YACC file the rules and actions for the
definitions of a production that is an optional parent with a child
that is a mix of isInstances (or beInstances) and non-instances.
For example, if the EBNF is the following (in which real and speedName
are not instances but toolpathSpeed is),

toolpathSpeedprofile =
	  real
	| speedName
	| toolpathSpeed
	;

optToolpathSpeedprofile =
	  toolpathSpeedprofile
	| $
	;

then this prints the following:

optToolpathSpeedprofile :
	  instanceId
	    { toolpathSpeed * v;
	      v = new toolpathSpeed(0);
	      v->set_iId($1);
	      $$ = v;
	    }
	| real
	    { $$ = $1; }
	| speedName
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

The first and last lines of the example are not printed by this function.

In the example, only toolpathSpeed is an instance subtype of
toolpathSpeedprofile. If there were more instance subtypes, only one
of them would be used to print the YACC, since the only reason for
building an instance is to transmit the instanceId. The new C++ object
that is built is an instance of the class corresponding to the
beInstance of the optional child of the optional production being
printed. Each of the non-instance definitions of the optional child
gets its own defintion in the YACC.

*/

void printYaccForOptProd0( /* ARGUMENTS                         */
 production * prod,        /* optional production to print for  */
 FILE * yaccFile,          /* YACC file to print in             */
 bool direct)              /* true = use direct access to data  */
{
  production * inst;
  production * child;
  production * sub;
  stringListCell * attCell;
  defListCell * defCell;

  child = prod->optProd;
  inst = child->beInstance;
  fprintf(yaccFile, "\t  instanceId\n");
  fprintf(yaccFile, "\t    { %s * v;\n", inst->lhs);
  fprintf(yaccFile, "\t      v = new %s(", inst->lhs);
  for (attCell = inst->attNames.first; attCell; attCell = attCell->next)
    {
      fprintf(yaccFile, "0");
      if (attCell->next)
	fprintf(yaccFile, ",");
    }
  fprintf(yaccFile, ");\n");
  if (direct)
    fprintf(yaccFile, "\t      v->iId = $1;\n");
  else
    fprintf(yaccFile, "\t      v->set_iId($1);\n");
  fprintf(yaccFile, "\t      $$ = v;\n");
  fprintf(yaccFile, "\t    }\n");
  for (defCell = child->defs->first; defCell; defCell = defCell->next)
    {
      sub = defCell->data->expressions->first->data->prodValue;
      if (sub->isInstance || sub->beInstance)
	continue;
      fprintf(yaccFile, "\t| %s\n", sub->lhs);
      fprintf(yaccFile, "\t    { $$ = $1; }\n");
    }
  fprintf(yaccFile, "\t| DOLLAR\n");
  fprintf(yaccFile, "\t    { $$ = 0; }\n");
}

/********************************************************************/

/* printYaccForOptProd1

Returned Value: none

Called By: printYaccProduction

This prints in the YACC file the rules and actions for the two
definitions of a production that is an optional parent with a child
that is an instance or is a supertype of an instance. For example:

optToolDirection :
	  instanceId
	    { $$ = new twoAxes();
	      $$->set_iId($1);
	    }
	| DOLLAR
	    { $$ = 0; }
	;

The first and last lines of the example are not printed by this function.

In this example, toolDirection is not an instance, so it cannot be
instantiated. However, twoAxes is an instance and is a subtype of
toolDirection, so the transferName has been set to twoAxes. The
only reason for instantiating anything here is so that the iId can
be transferred to the rule using the optional. It is necessary to make
a C++ class instance of the correct type in order to do this. Once
the iId is transferred, the C++ class instance created here is deleted.

The attributes of the C++ class instance created here that are pointers
must not be garbage or an error will occur when the destructor deletes
them. Hence, all the attributes are set to 0 in the constructor. Zero
works for all attributes of all classes, including those whose type is
int or double, the only non-pointer types used.

*/

void printYaccForOptProd1( /* ARGUMENTS                         */
 char * transferName,      /* name of production to instantiate */
 FILE * yaccFile,          /* YACC file to print in             */
 bool direct)              /* true = use direct access to data  */
{
  production * prod;
  stringListCell * aCell;

  prod = findProd(transferName);
  fprintf(yaccFile, "\t  instanceId\n");
  fprintf(yaccFile, "\t    { $$ = new %s(", transferName);
  for (aCell = prod->attNames.first; aCell; aCell = aCell->next)
    {
      fprintf(yaccFile, "0");
      if (aCell->next)
	fprintf(yaccFile, ",");
    }
  fprintf(yaccFile, ");\n");
  if (direct)
    fprintf(yaccFile, "\t      $$->iId = $1;\n");
  else
    fprintf(yaccFile, "\t      $$->set_iId($1);\n");
  fprintf(yaccFile, "\t    }\n");
  fprintf(yaccFile, "\t| DOLLAR\n");
  fprintf(yaccFile, "\t    { $$ = 0; }\n");
}

/********************************************************************/

/* printYaccForOptProd2

Returned Value: none

Called By: printYaccProduction

This prints in the YACC file the rules and actions for the two
definitions of a production that is an optional parent with a child
that is not an instance or a supertype of an instance. For example:

optBoolean :
	  boolean
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

The first and last lines of the example are not printed by this function.

*/

void printYaccForOptProd2( /* ARGUMENTS                 */
 char * transferName,      /* name of production to use */
 FILE * yaccFile)          /* YACC file to print in     */
{
  fprintf(yaccFile, "\t  %s\n", transferName);
  fprintf(yaccFile, "\t    { $$ = $1; }\n");
  fprintf(yaccFile, "\t| DOLLAR\n");
  fprintf(yaccFile, "\t    { $$ = 0; }\n");
}

/********************************************************************/

/* printYaccForParenList

Returned Value: none

Called By: printYaccProduction

This prints in the YACC file the rules and actions for the two
definitions of a paren list that may be empty.

A paren list that may be empty has the following format:

parenThingList =
	  '(' , thingList , ')'
	| '('  , ')'
	;

The format has been checked previously in printCppClassList, so it
is not rechecked here.

EXAMPLE: For a parenThingList, this would print:

	  LPAREN thingList RPAREN
	    { $$ = new parenThingList($2); }
	| LPAREN RPAREN
	    { $$ = new parenThingList(new std::list<thing *>); }

*/
void printYaccForParenList( /* ARGUMENTS                         */
 char * prodName,           /* name of the paren list production */
 defList * defins,          /* definitions of the production     */
 FILE * yaccFile)           /* YACC file to print in             */
{
  production * theList;
  char * listName;
  char * thingName;

  theList = defins->first->data->expressions->first->next->data->prodValue;
  listName = theList->lhs;
  thingName = theList->defs->first->data->expressions->first->data->itemName;
  fprintf(yaccFile, "\t  LPAREN %s RPAREN\n", listName);
  fprintf(yaccFile, "\t    { $$ = new %s($2); }\n", prodName);
  fprintf(yaccFile, "\t| LPAREN RPAREN\n");
  fprintf(yaccFile, "\t    { $$ = new %s(new std::list<%s *>); }\n",
	  prodName,
	  ((strcmp(thingName, "CHARSTRING") == 0) ? "char" : thingName)) ;
}

/********************************************************************/

/* printYaccForPlain

Returned Value: none

Called By:  printYaccProduction

This prints in the YACC file the rules and actions for a production.
The production name is printed in printYaccProduction before this
function is called.

The defs here are the defs of the production for which YACC is to be
printed.

*/

void printYaccForPlain( /* ARGUMENTS                        */
 char * prodName,       /* name of the production           */
 defList * defs,        /* definitions of the production    */
 stringList * attNames, /* attribute names                  */
 FILE * yaccFile,       /* YACC file to print in            */
 bool direct)           /* true = use direct access to data */
{
  expList * exps;

  if ((defs->first == 0) || (defs->first != defs->last))
    {
      fprintf(stderr, "Plain production must have exactly one definition\n");
      exit(1);
    }
  exps = defs->first->data->expressions;
  printYaccRule(exps, yaccFile);
  printYaccAction(prodName, prodName, exps, attNames, yaccFile, direct);
}

/********************************************************************/

/* printYaccForSupertype

Returned Value: none

Called By: printYaccProduction

This prints the rules and actions for all the definitions of a production
defining a supertype. For example:

leftOrRight :
	  leftOrRightLeft
	    { $$ = $1; }
	| leftOrRightRight
	    { $$ = $1; }
	;

*/

void printYaccForSupertype( /* ARGUMENTS                        */
 char * prodName,           /* name of production being printed */
 defList * defins,          /* definitions of the production    */
 FILE * yaccFile)           /* YACC file to print in            */
{
  char * subtypeName;
  defListCell * defCell;

  for (defCell = defins->first; defCell; defCell = defCell->next)
    {
      subtypeName = defCell->data->expressions->first->data->itemName;
      fprintf(yaccFile, "\t%c %s\n", (defCell->back ? '|' : ' '), subtypeName);
      fprintf(yaccFile, "\t    { $$ = $1; }\n");
    }
}

/********************************************************************/

/* printYaccGlobals

Returned Value: none

Called By: printYaccStart

This prints the extern declarations and global variables of the
YACC file.

The numErrors global variable, which is not shared with the lexer,
counts the number of errors. Whenever YACC detects an error, this is
increased by one.

*/

void printYaccGlobals( /* ARGUMENTS              */
 FILE * yaccFile)      /* YACC file to print in  */
{
  fprintf(yaccFile,
"/*\n"
"\n"
"The lineText array is used for saving everything on a line up to the end\n"
"of the line, 4096 characters, or an error, whichever comes first. The\n"
"lineText is used (printed by yyerror) only if there is an error. This \n"
"lets the user see the point in the Part 21 file at which an error occurred.\n"
"Lines longer than 4096 characters will not overflow the lineText array.\n"
"\n"
"*/\n"
"\n"
"extern FILE * yyin;\n"
"extern int yylex();\n"
"\n"
"int numErrors = 0;\n"
"char lineText[4096];\n"
"char lexMessage[80];\n"
"FILE * report;\n"
"%s * tree;\n", productions.first->data->lhs);
  fprintf(yaccFile,
"char errorMessage[256];\n"
"instance * instances[INSTANCEMAX] = {0};\n");
}

/********************************************************************/

/* printYaccIncDefs

Returned Value: none

Called By: printYaccStart

This prints the standard NIST disclaimer, #includes, and #defines in
the YACC file.

One of the #defines this writes into the YACC file is the WRITE_LINKER
macro that is called in printYaccLinkers for those classes for which
isInstance is true or beInstance is non-zero. The macro writes
declarations of two lists:

1. a list named <class>_refs of pointers to references to instances of
   a particular class.
2. a list named <class>_nums of iId numbers corresponding to the list of
   pointers.
The macro also defines a linking function named link_<class>.

The linking function for a class goes through the <class>_refs and
<class>_nums lists looking at the corresponding ref and num. The value
of the ref is set to instances[num], unless instances[num] is not
the right type, in which case an error is reported.

The instances array used in the macro is an array of pointers to
instances. The instances array is indexed by the value of instanceIds.
yyparse puts an entry in the instances array each time an instancePlus
is parsed, so the array is complete when linking starts.

*/

void printYaccIncDefs( /* ARGUMENTS                           */
 FILE * yaccFile,      /* YACC file to print in               */
 char * baseFileName,  /* base file name for including header */
 bool direct)          /* true = use direct access to data    */
{
  fprintf(yaccFile,
"/************************************************************************\n"
"  DISCLAIMER:\n"
"  This software was produced by the National Institute of Standards\n"
"  and Technology (NIST), an agency of the U.S. government, and by statute\n"
"  is not subject to copyright in the United States.  Recipients of this\n"
"  software assume all responsibility associated with its operation,\n"
"  modification, maintenance, and subsequent redistribution.\n"
"\n"
"  See NIST Administration Manual 4.09.07 b and Appendix I.\n"
"************************************************************************/\n"
"\n"
"#include <string.h>  // for strlen, strcpy, strcat\n"
"#include <stdio.h>   // for fopen, etc.\n"
"#include <stdlib.h>  // for exit\n"
"#include \"%sclasses%s.hh\"\n", baseFileName, (direct ? "Direct" : ""));
  fprintf(yaccFile,
"\n"
"#define YYERROR_VERBOSE\n"
"#define YYDEBUG 1\n"
"#define INSTANCEMAX 100000\n");
  printStarLine(yaccFile);
  fprintf(yaccFile,
"#define WRITE_LINKER(TYP) \\\n"
"std::list<TYP **> TYP ## _refs;\\\n"
"std::list<int> TYP ## _nums;\\\n"
"\\\n"
"void link_ ## TYP()\\\n"
"{\\\n"
"  std::list<TYP **>::iterator refIter;\\\n"
"  std::list<int>::iterator numIter;\\\n"
"  for (refIter = TYP ## _refs.begin(),\\\n"
"	 numIter = TYP ## _nums.begin();\\\n"
"       refIter != TYP ## _refs.end();\\\n"
"       refIter++, numIter++)\\\n"
"    {\\\n"
"      if (instances[*numIter] == 0)\\\n"
"	 {\\\n"
"	   fprintf(report,\\\n"
"		   \"Error: referenced instance #%%d does not exist\\n\",\\\n"
"		   *numIter);\\\n"
"	   numErrors++;\\\n"
"	 }\\\n"
"      else if (instances[*numIter]->isA(TYP ## _E))\\\n"
"	{\\\n"
"	  **refIter = dynamic_cast<TYP *>(instances[*numIter]);\\\n"
"	}\\\n"
"      else\\\n"
"	{\\\n"
"	  fprintf(report, \"Error: #%%d used incorrectly\\n\",\\\n");
  if (direct)
    fprintf(yaccFile,
"		  instances[*numIter]->iId->val);\\\n");
  else
    fprintf(yaccFile,
"		  instances[*numIter]->get_iId()->get_val());\\\n");
  fprintf(yaccFile,
"	  numErrors++;\\\n"
"	}\\\n"
"    }\\\n"
"  TYP ## _refs.clear();\\\n"
"  TYP ## _nums.clear();\\\n"
"}\n"
"\n");
}

/********************************************************************/

/* printYaccLinkAll

Returned Value: none

Called By: printYaccStart

This prints the linkAll function in the YACC file. The linkAll
function just calls all the link_<class> functions generated
automatically by the the calls (written by printYaccLinkers) to
the WRITE_LINKER macro (written by printYaccIncDefs).
  
*/

void printYaccLinkAll( /* ARGUMENTS             */
 FILE * yaccFile)      /* YACC file to print in */
{
  prodListCell * prodCell;
  production * prod;

  fprintf(yaccFile,
"/* linkAll\n"
"\n"
"The instances array, which is used by all the linking functions called\n"
"here, is not needed after linking is finished. That array needs to be\n"
"cleared in order to parse another file, so it is cleared at the\n"
"end of this function.\n"
"\n"
"*/\n"
"\n"
"void linkAll()\n"
"{\n"
"  int n;\n"
"\n");
  for (prodCell = productions.first; prodCell; prodCell = prodCell->next)
    {
      prod = prodCell->data;
      if ((prod->isInstance) || prod->beInstance)
	fprintf(yaccFile, "  link_%s();\n", prod->lhs);
    }
  fprintf(yaccFile,
"  for (n = 0; n < INSTANCEMAX; n++)\n"
"    {\n"
"      instances[n] = 0;\n"
"    }\n"
"}\n");
}

/********************************************************************/

/* printYaccLinkers

Returned Value: none

Called By: printYaccStart

In the YACC file:

This prints all the calls to WRITE_LINKER near the beginning of the YACC
file. Each call to WRITE_LINKER defines a linking function for a
class that is represented by an instance if it is used in a Part 21 file.

*/

void printYaccLinkers(
 FILE * yaccFile)
{
  prodListCell * prodCell;
  production * prod;

  for (prodCell = productions.first; prodCell; prodCell = prodCell->next)
    {
      prod = prodCell->data;
      if ((prod->isInstance) || prod->beInstance)
	fprintf(yaccFile, "WRITE_LINKER(%s)\n", prod->lhs);
    }
}

/********************************************************************/

/* printYaccMiddle

Returned Value: none

Called By: printYacc

This prints in the YACC file:
1. the %union representing returned values from Lex
2. the %types indicating what type is returned by each production
3. the token names
4. the %start, which is taken to be the first production in the EBNF file.

Note that a lot of this is hard-coded. Name conflicts will occur if
the input file uses any of the following as tokens (spelled in all
upper case):
BAD
CHARSTRING
COLON
DOLLAR
EQUALS
INTSTRING
LBOX,
LPAREN
RBOX
REALSTRING
RPAREN
SLASH

*/

void printYaccMiddle( /* ARGUMENTS             */
 FILE * yaccFile)     /* YACC file to print in */
{
  int n;
  int m;

  printYaccUnionAndTypes(yaccFile);
  for (n = 0; n < 26; n++)
    {
      for (m = 0; ((m < LETTERSIZE) && (tokenNames[n][m])); m++)
	{
	  fprintf(yaccFile, "%%token %s\n", tokenNames[n][m]);
	}
    }
  for (m = 0; ((m < LETTERSIZE) && (terminalNames[m])); m++)
    {
      if (strcmp(terminalNames[m], "INTSTRING") == 0)
	{
	  fprintf(yaccFile, "%%token <ival> INTSTRING\n");
	}
      else if (strcmp(terminalNames[m], "REALSTRING") == 0)
	{
	  fprintf(yaccFile, "%%token <rval> REALSTRING\n");
	}
      else
	fprintf(yaccFile, "%%token <sval> %s\n", terminalNames[m]);
    }
  fprintf(yaccFile,
	  "\n"
	  "%%token BAD\n"
	  "%%token COLON\n"
	  "%%token DOLLAR\n"
	  "%%token EQUALS\n"
	  "%%token LBOX\n"
	  "%%token LPAREN\n"
	  "%%token RBOX\n"
	  "%%token RPAREN\n"
	  "%%token SEMICOLON\n"
	  "%%token SHARP\n"
	  "%%token SLASH\n"
	  "\n"
	  "%%start %s\n", productions.first->data->lhs);
  fprintf(yaccFile,
	  "\n"
	  "%%%%\n\n");
}

/********************************************************************/

/* printYaccParseMany

Returned Value: none

Called By: printYaccStart

This prints the parseManyFiles function in the YACC file:

The parseManyFiles function this writes parses a number of input
files, discarding the parse tree from each file.

*/

void printYaccParseMany( /* ARGUMENTS             */
 FILE * yaccFile)        /* YACC file to print in */
{
  fprintf(yaccFile,
"/* parseManyFiles\n"
"\n"
"This parses all the input files whose names are given in the\n"
"file whose name is fileNameFile. As it runs, it prints the name\n"
"of each file it parses followed by either \"0 errors\" or some error\n"
"messages followed by \"N errors\".\n"
"\n"
"*/\n"
"\n"
"void parseManyFiles(\n"
" char * fileNameFile,\n"
" char * reportName)\n"
"{\n"
"  FILE * fileList;\n"
"  static char fileName[256];\n"
"  int nameLength;\n"
"\n"
"  fileList = fopen(fileNameFile, \"r\");\n"
"  if (fileList == 0)\n"
"    {\n"
"      fprintf(stderr, \"unable to open file %%s for reading\\n\",\n"
"              fileNameFile);\n"
"      exit(1);\n"
"    }\n"
"  if (reportName)\n"
"    {\n"
"      report = fopen(reportName, \"wb\");\n"
"      if (report == 0)\n"
"        {\n"
"          fprintf(stderr, \"unable to open file %%s for writing\\n\",\n"
"                  reportName);\n"
"	  exit(1);\n"
"	}\n"
"    }\n"
"  else\n"
"    report = stdout;\n"
"  lexMessage[0] = 0;\n"
"  while (fgets(fileName, 256, fileList))\n"
"    {\n"
"      nameLength = strlen(fileName);\n"
"      if (nameLength == 255)\n"
"	{\n"
"	  fprintf(stderr, \"file name too long: %%s\\n\", fileName);\n"
"	  exit(1);\n"
"        }\n"
"      while ((fileName[nameLength - 1] == 10) ||\n"
"             (fileName[nameLength - 1] == 13))\n"
"	{ // get rid of the end of line character(s)\n"
"	  fileName[nameLength - 1] = 0;\n"
"	  nameLength--;\n"
"	}\n"
"      if (strcmp((fileName + nameLength - 4), \".stp\"))\n"
"	{\n"
"	  fprintf(stderr, \"file name does not end in .stp: %%s\\n\",\n"
"                  fileName);\n"
"	  exit(1);\n"
"	}\n"
"      fprintf(report, \"*****************************************\\n\\n\");\n"
"      fprintf(report, \"%%s\\n\\n\", fileName);\n"
"      yyin = fopen(fileName, \"rb\");\n"
"      if (yyin == 0)\n"
"	{\n"
"	  fprintf(stderr, \"unable to open file %%s for reading\\n\",\n"
"                  fileName);\n"
"	  exit(1);\n"
"	}\n"
"      yyparse();\n"
"      fclose(yyin);\n"
"      if (numErrors == 0)\n"
"	linkAll();\n"
"      fprintf(report, \"%%d errors\\n\\n\", numErrors);\n"
"      if (tree)\n"
"	{\n"
"	  delete tree;\n"
"	  tree = 0;\n"
"	}\n"
"      numErrors = 0;\n"
"    }\n"
"  fclose(fileList);\n"
"  fprintf(report, \"\\n\");\n"
"  if (report != stdout)\n"
"    fclose(report);\n"
"}\n");
}

/********************************************************************/

/* printYaccParseOne

Returned Value: none

Called By: printYaccStart

This prints the parseOneFile function in the YACC file.

The parseOneFile function this writes parses one input file and saves the
parse tree.

*/

void printYaccParseOne( /* ARGUMENTS             */
 FILE * yaccFile)       /* YACC file to print in */
{
  fprintf(yaccFile,
"/* parseOneFile\n"
"\n"
"This parses one input file.\n"
"\n"
"*/\n"
"\n"
"int parseOneFile(\n"
" const char * part21Name,\n"
" char * reportName,\n"
" bool quiet)\n"
"{\n"
"  if (reportName)\n"
"    {\n"
"      report = fopen(reportName, \"wb\");\n"
"      if (report == 0)\n"
"        {\n"
"          fprintf(stderr, \"unable to open file %%s for writing\\n\",\n"
"                  reportName);\n"
"	  exit(1);\n"
"	}\n"
"    }\n"
"  else\n"
"    report = stdout;\n"
"  lexMessage[0] = 0;\n"
"  yyin = fopen(part21Name, \"rb\");\n"
"  if (yyin == 0)\n"
"    {\n"
"      fprintf(stderr, \"unable to open file %%s for reading\\n\",\n"
"              part21Name);\n"
"      exit(1);\n"
"    }\n"
"  yyparse();\n"
"  fclose(yyin);\n"
"  if (numErrors == 0)\n"
"    linkAll();\n"
"  else if (tree)\n"
"    {\n"
"      delete tree;\n"
"      tree = 0;\n"
"    }\n"
"  if (!quiet || numErrors)\n"
"    fprintf(report, \"%%d error%%s\\n\",\n"
"	    numErrors, ((numErrors == 1) ? \"\" : \"s\"));\n"
"  if (report != stdout)\n"
"    fclose(report);\n"
"  return numErrors;\n"
"}\n");
}

/********************************************************************/

/* printYaccProduction

Returned Value: none

Called By: printYaccProductions

This prints YACC rule and action for one production. In most cases,
this uses only the data in the production, but there are exceptions.

To allow the parser to continue after a line in which there is an
error, this is inserting an error handling line as the last definition
of dataStart, fileDescription, fileEnd, fileName, fileSchema, fileStart,
headerStart, and instancePlus.

If any of these productions is renamed, or the EBNF is otherwise
changed so that a single line may be represented some other way, this
function will have to be changed.

*/

void printYaccProduction( /* ARGUMENTS                        */
 production * prod,       /* production to print              */
 FILE * yaccFile,         /* YACC file to print in            */
 bool direct)             /* true = use direct access to data */
{
  char * prodName;
  defList * defins;

  prodName = prod->lhs;
  defins = prod->defs;
  fprintf(yaccFile, "%s :\n", prodName);
  if (prod->isList)
    {
      printYaccForList(prod, prodName, defins, yaccFile, direct);
    }
  else if (prod->isOptional == 1)
    {
      if (prod->optProd->isSupertype == 2)
	printYaccForOptProd0(prod, yaccFile, direct);
      else
	printYaccForOptProd1(prod->transferName, yaccFile, direct);
    }
  else if (prod->isOptional == 2)
    {
      printYaccForOptProd2(prod->transferName, yaccFile);
    }
  else if (prod->isSupertype)
    {
      printYaccForSupertype(prodName, defins, yaccFile);
    }
  else if (defins->findLength() == 2)
    printYaccForParenList(prodName, defins, yaccFile);
  else
    {
      printYaccForPlain(prodName, defins, &(prod->attNames), yaccFile, direct);
    }
  if ((strcmp(prodName, "dataStart") == 0) ||
      (strcmp(prodName, "fileDescription") == 0) ||
      (strcmp(prodName, "fileEnd") == 0) ||
      (strcmp(prodName, "fileName") == 0) ||
      (strcmp(prodName, "fileSchema") == 0) ||
      (strcmp(prodName, "fileStart") == 0) ||
      (strcmp(prodName, "headerStart") == 0) ||
      (strcmp(prodName, "instancePlus") == 0))
    {
      fprintf(yaccFile,
"\t| error SEMICOLON\n"
"\t  {\n"
"\t    numErrors++;\n"
"\t    yyerrok;\n"
"\t  }\n");
    }
   fprintf(yaccFile, "\t;\n\n");
}

/********************************************************************/

/* printYaccProductions

Returned Value: none

Called By: printYacc

This prints in the YACC file all the productions except:
 (1) those that define terminalNames (they are dummies)
 (2) those that give the spelling of a keyword (they are used to print Lex)
 (3) those that are supertypes of instances (they don't appear in YACC rules).

The terminalNames array, which is an array of pointers to strings that
has NULLs at the end, cannot get too big, so it is not necessary
to check for overflow here.

We are assuming that the first production is the start symbol.

FIX - Item (3) in the list above and the "prod->beInstance" line below
should be changed in the case of a mixed supertype, since such a thing
might appear in a YACC rule. See documentation of printYaccUnionAndTypes
for more details.

*/

void printYaccProductions( /* ARGUMENTS                        */
 FILE * yaccFile,          /* YACC file to print in            */
 bool direct)              /* true = use direct access to data */
{
  prodListCell * aCell;
  production * prod;
  char * leftName;
  int n;  // counter, also int required by findToken

  printYaccFirstProduction(productions.first->data, yaccFile);
  for (aCell = productions.first->next; aCell; aCell = aCell->next)
    {
      prod = aCell->data;
      leftName = prod->lhs;
      for (n = 0; terminalNames[n]; n++)
	{  
	  if (!(strcmp(leftName, terminalNames[n])))
	    break;
	}
      if (terminalNames[n] ||        // do not process terminal names
	  findToken(leftName, &n) || // do not process token names
	  prod->beInstance)          // do not process supertypes of instances
	continue;
      printYaccProduction(prod, yaccFile, direct);
    }
}

/********************************************************************/

/* printYaccRecordRefOpt

Returned Value: none

Called By: printYaccRecordRefs

This prints the YACC action for an optional attribute. The action is to set
reference pointers if reference pointers should be set and then delete
the item from the rule that was used to carry the instance id if the
item from the rule is a (dummy) instance.

Example 1 -
Suppose:
  prodName == direction
  attName == "refDirection"
  n == 9
  before == "get_"
  after == "()"
and suppose that direction is not a mixed supertype.
Then this prints the following.

	      if ($9)
		{
		  $$->refDirection = 0;
		  direction_refs.push_back(&($$->refDirection));
		  direction_nums.push_back($9->get_iId()->get_val());
		  delete $9->get_iId();
		  delete $9;
		}

Example 2 -
Suppose:
  prod == toolpathSpeedprofile
  attName == "itsSpeed"
  n == 9
  before == "get_"
  after == "()"
and suppose that toolpathSpeedprofile is a mixed supertype with
beInstance == toolpathSpeed. Then this prints the following.
The check of whether $9 is a toolpathSpeed is needed because $9 could
also be a real or a speedName, in which case $9 should not be modified.

              if (($9) && ($9->isA(toolpathSpeed_E)))
		{
		  toolpathSpeed * v;
		  v = dynamic_cast<toolpathSpeed *>($9);
		  $$->itsSpeed = 0;
		  toolpathSpeedprofile_refs.push_back(&($$->itsSpeed));
		  toolpathSpeedprofile_nums.push_back(v->get_iId()->get_val());
		  delete v->get_iId();
		  delete $9;
		}

*/

void printYaccRecordRefOpt( /* ARGUMENTS                                  */
 production * prod,         /* production whose optional is the attribute */
 char * attName,            /* name of attribute to print                 */
 int n,                     /* index in rule                              */
 FILE * yaccFile,           /* YACC file to print in                      */
 char * before,             /* "get_" if indirect or "" if direct         */
 char * after)              /* "()" if indirect or "" if direct           */
{
  production * sub;

  if (prod->isSupertype == 2)
    {
      sub = prod->beInstance;
      fprintf(yaccFile, "\t      if (($%d) && ($%d->isA(%s_E)))\n",
	      n, n, sub->lhs);
      fprintf(yaccFile, "\t\t{\n");
      fprintf(yaccFile, "\t\t  %s * v;\n", sub->lhs);
      fprintf(yaccFile, "\t\t  v = dynamic_cast<%s *>($%d);\n", sub->lhs, n);
      fprintf(yaccFile, "\t\t  $$->%s = 0;\n", attName);
      fprintf(yaccFile, "\t\t  %s_refs.push_back(&($$->%s));\n",
	      prod->lhs, attName);
      fprintf(yaccFile, "\t\t  %s_nums.push_back(v->%siId%s->%sval%s);\n",
	      prod->lhs, before, after, before, after);
      fprintf(yaccFile, "\t\t  delete v->%siId%s;\n", before, after);
      fprintf(yaccFile, "\t\t  delete $%d;\n", n);
      fprintf(yaccFile, "\t\t}\n");
    }
  else
    {
      fprintf(yaccFile, "\t      if ($%d)\n", n);
      fprintf(yaccFile, "\t\t{\n");
      fprintf(yaccFile, "\t\t  $$->%s = 0;\n", attName);
      fprintf(yaccFile, "\t\t  %s_refs.push_back(&($$->%s));\n",
	      prod->lhs, attName);
      fprintf(yaccFile, "\t\t  %s_nums.push_back($%d->%siId%s->%sval%s);\n",
	      prod->lhs, n, before, after, before, after);
      fprintf(yaccFile, "\t\t  delete $%d->%siId%s;\n", n, before, after);
      fprintf(yaccFile, "\t\t  delete $%d;\n", n);
      fprintf(yaccFile, "\t\t}\n");
    }
}
 

/********************************************************************/

/* printYaccRecordRefs

Returned Value: none

Called By:  printYaccAction

This prints the part of the YACC action that records the references to
instanceIds.

InstancIds for attributes that (1) are optional, and (2) have values that
are instances, and (3) are not NULL have been stored in dummy instances.
After the number of the instanceId for a dummy has been extracted,
the dummy is deleted. Since the destructors do not delete instanceIds,
however, the instanceId in the dummy is deleted before the dummy is deleted.

InstanceIds for attributes that are not optional and have values that
are instances are also no longer needed after their value is extracted,
so they are deleted, too.

Even when referencing is indirect, get_ and set_ functions are not
needed for referencing data members of classes that are descended from
instance, because all such classes declare the yyparse function as a
friend (see printCppClassParent and printCppClassTop). It is necessary
to make yyparse a friend because on the lines setting _refs, the
construct &($$->get_%s()) does not work while &($$->%s) does work.

*/

void printYaccRecordRefs( /* ARGUMENTS                          */
 expList * exps,          /* expressions from production        */
 stringList * attNames,   /* attribute names                    */
 FILE * yaccFile,         /* YACC file to print in              */
 char * before,           /* "get_" if indirect or "" if direct */
 char * after)            /* "()" if indirect or "" if direct   */
{
  expListCell * expCell;
  stringListCell * attCell;
  expression * exp;         // expression to print from
  int n;                    // index of exp in rule
  int wrote;                // 1 means wrote some code, 0 = not

  wrote = 0;
  attCell = attNames->first;
  for (n=1, expCell = exps->first ; expCell; n++, expCell = expCell->next)
    {
      exp = expCell->data;
      if ((exp->theType == TERMINAL) || (exp->theType == NONTERMINAL))
	{
	  if (!attCell)
	    {
	      fprintf(stderr, "not enough attribute names\n");
	      exit(1);
	    }
	  if ((exp->theType == NONTERMINAL) && (exp->prodValue))
	    {
	      if (exp->prodValue->isOptional == 1)
		{
		  if (wrote == 0)
		    {
		      fprintf(yaccFile, "\n");
		      wrote = 1;
		    }
		  printYaccRecordRefOpt(exp->prodValue->optProd, attCell->data,
					n, yaccFile, before, after);
		}
	      else if ((exp->prodValue->isInstance) ||
		       (exp->prodValue->beInstance))
		{
		  if (wrote == 0)
		    {
		      fprintf(yaccFile, "\n");
		      wrote = 1;
		    }
		  fprintf(yaccFile, "\t      %s_refs.push_back(&($$->%s));\n",
			  exp->prodValue->lhs, attCell->data);
		  fprintf(yaccFile, 
			  "\t      %s_nums.push_back($%d->%sval%s);\n",
			  exp->prodValue->lhs, n, before, after);
		  fprintf(yaccFile, "\t      delete $%d;\n", n);
		}
	    }
	  attCell = attCell->next;
	}
    }
  if (wrote)
    fprintf(yaccFile, "\t   ");
  fprintf(yaccFile, " }\n");
}

/********************************************************************/

/* printYaccRule

Returned Value: None

Called By:
  printYaccFirstProduction
  printYaccForPlain

This prints in the YACC file a YACC rule. It prints all expressions in
exps.  For expressions that are productions with isInstance == true or
non-NULL beInstance, this prints "instanceId". Otherwise, it calls
printYaccExpression.

*/

void printYaccRule( /* ARGUMENTS                 */
 expList * exps,    /* expressions to print from */
 FILE * yaccFile)   /* YACC file to print in     */
{
  expListCell * expCell;
  expression * exp;

  fprintf(yaccFile, "\t ");
  expCell = exps->first;
  if (!expCell)
    fprintf(yaccFile, " /* empty */");
  for ( ; expCell; expCell = expCell->next)
    {
      exp = expCell->data;
      if ((exp->prodValue) && 
	  ((exp->prodValue->isInstance) ||
	   (exp->prodValue->beInstance)))
	{
	  fprintf(yaccFile, " instanceId");
	}
      else
	{
	  printYaccExpression(exp, yaccFile);
	}
    }
  fprintf(yaccFile, "\n");
}

/********************************************************************/

/*  printYaccStart

Returned Value: none

Called By: printYacc

This prints the beginning of the YACC file. It calls:
1. printYaccIncDefs to print #includes and #defines
2. printYaccGlobals to declare yyin, yylex and other global variables
   (some shared with the lexer)
3. printYaccLinkers to print the functions that link instances to
   references to instances
4. printYaccLinkAll to print the function that links instances to references
5. printYaccYyerror to print the yyerror function
6. printYaccParseMany to print the parseManyFiles function
7. printYaccParseOne to print the parseOneFile function

Between the calls to printYaccYyerror and printYaccParseMany this prints
the declaration of the yyparse function.

*/

void printYaccStart(  /* ARGUMENTS                           */
 FILE * yaccFile,     /* YACC file to print in               */
 char * baseFileName, /* base file name for including header */
 bool direct)         /* true = use direct access to data    */
{
  fprintf(yaccFile, "%%{\n\n");
  printYaccIncDefs(yaccFile, baseFileName, direct);
  printStarLine(yaccFile);
  printYaccGlobals(yaccFile);
  printStarLine(yaccFile);
  printYaccLinkers(yaccFile);
  printStarLine(yaccFile);
  printYaccLinkAll(yaccFile);
  printStarLine(yaccFile);
  printYaccYyerror(yaccFile);
  printStarLine(yaccFile);
  fprintf(yaccFile, "int yyparse();\n");
  printStarLine(yaccFile);
  printYaccParseMany(yaccFile);
  printStarLine(yaccFile);
  printYaccParseOne(yaccFile);
  printStarLine(yaccFile);
  fprintf(yaccFile, "%%}\n\n");
}

/********************************************************************/

/* printYaccUnionAndTypes

Called By: printYaccMiddle

This prints in the YACC file (1) the %union and (2) the %type list.

-------------------

First this function goes through the productions list and puts some of
them on the toPrint list. A production is placed on the toPrint list if
it satisfies all of the following conditions:
    is not a terminal name
    is not a token name
    is not named "instancePlus"
    is not an unmixed supertype of an instance
    is not an optional parent whose optional child has isSupertype != 2
    
-------------------

Then this function goes through the toPrint list and generates the
union. It increments a counter N as it writes each line of the union.
If a production is not a list, a line of the union has the form:

     prodName   * valN;

Where prodName is also the name of the C++ class for the production.

If a production is a list, a line of the union has the form:

     std::list<itemName *>  valN;

Where itemName is also the name of the C++ class for the production
being listed, except that:
1. for a list of CHARSTRING, the itemName is char
2. for a list of REALSTRING, the itemName is double, and
3. for a list of instancePlus, the itemName is instance.

Then this function adds the following lines to the union:
      char   * sval;  (always added)
      int      ival;  (added if INTSTRING is a terminal name)
      double   rval;  (added if REALSTRING is a terminal name)

-------------------

Then this function goes through the toPrint list again and writes
type declarations of the form:

    %type <valN> prodName

That line is not written if a production is a mixed supertype.  This
is correct for the two mixed supertypes in the EBNF for ISO 14649
since the two mixed supertypes in that file (toolpathSpeedprofile and
trimmingSelect) do not appear in any YACC rule. Special rules and
actions are printed in the YACC file by printYaccForOptProd0 if a
mixed supertype is an optional child (toolpathSpeedprofile is one of
those); the rules use the subtypes of the optional child rather than
using the optional child. A similar thing is done in printYaccForList
for a list of mixed supertypes.

FIX - This function should should be changed to check if a mixed
supertype P will appear in a rule and to print the %type line if P
does appear. Also, printYaccProduction should be changed similarly.

Extra %type lines are written in three cases:

1. For a production that is an optional child with isSupertype != 2,
this writes a line for the optional parent prodName using the same N.

2. For a production P that has an ancestor A that is the optional
child of an optional parent Q that uses the name of P as its
transferName, this writes an additional line using the name of Q and
the same N. There may be more than one such ancestor. The ebnf in a
case like this might be the following:

P = PNAME, '(', ')' ;

A = P | Z ;

Q = A | $ ;

3. For the production named "instance", this writes an additional line
using the same N with prodName "instancePlus".

Note that a production may fall under both 1 and 2 above.

Note that in the union, the names are C++ class names, while in the
type declarations, the names are production names.

*/

void printYaccUnionAndTypes( /* ARGUMENTS             */
 FILE * yaccFile)            /* YACC file to print in */
{
  prodList toPrint;
  prodListCell * prodCell;
  production * prod;
  prodListCell * anCell;
  char * prodName;
  char * itemName;
  //defListCell * defCell;
  //int m;                   // counter for definitions
  int n;
  int j;

  prodCell = productions.first;
  prod = prodCell->data;
  if (strcmp(prod->lhs, "inputFile"))
    {
      fprintf(stderr, "first production must be inputFile but is not\n");
      exit(1);
    }
  toPrint.pushBack(prod);
  for (prodCell = prodCell->next; prodCell; prodCell = prodCell->next)
    {
      prod = prodCell->data;
      prodName = prod->lhs;
      for (n = 0; terminalNames[n]; n++)
	{
	  if (strcmp(prodName, terminalNames[n]) == 0)
	    break;
	}
      if (terminalNames[n] ||           // do not process terminal names
	  findToken(prodName, &n) ||    // do not process token names
	  (strcmp(prodName, "instancePlus") == 0) || // not process instancePlus
	  ((prod->beInstance) &&        // do not process supertypes unless
	   (prod->isSupertype != 2)) || //   mixed
	  (prod->isOptional == 1) ||    // do not process optional parent
	  (prod->isOptional == 2))      // do not process optional parent
	continue;
      toPrint.pushBack(prod);
    }
  fprintf(yaccFile, "%%union {\n");
  n = 1;
  for (prodCell = toPrint.first; prodCell; prodCell = prodCell->next)
    {
      prod = prodCell->data;
      prodName = prod->lhs;
      if (prod->isList)
	{
	  itemName =
	    prod->defs->first->data->expressions->last->data->itemName;
	  j = fprintf(yaccFile, "  std::list<%s *> ",
		      ((strcmp(itemName, "CHARSTRING") == 0) ? "char" :
		       (strcmp(itemName, "REALSTRING") == 0) ? "double" :
		       (strcmp(itemName, "instancePlus") == 0) ? "instance" :
		       itemName));
	  for ( ; j < 35; j++)
	    fputc(' ', yaccFile);
	  fprintf(yaccFile, "* val%d;\n", n++);
	  
	}
      else
	{
	  j = fprintf(yaccFile, "  %s ", prodName);
	  for ( ; j < 35; j++)
	    fputc(' ', yaccFile);
	  fprintf(yaccFile, "* val%d;\n", n++);
	}
    }
  fprintf(yaccFile, "  char                             * sval;\n");
  for (n = 0; ((n < LETTERSIZE) && (terminalNames[n])); n++)
    {
      if (strcmp(terminalNames[n], "INTSTRING") == 0)
	{
	  fprintf(yaccFile, "  int                                ival;\n");
	}
      else if (strcmp(terminalNames[n], "REALSTRING") == 0)
	{
	  fprintf(yaccFile, "  double                             rval;\n");
	}
    }
  fprintf(yaccFile, "}\n\n");
  n = 1;
  for (prodCell = toPrint.first; prodCell; prodCell = prodCell->next)
    {
      prod = prodCell->data;
      prodName = prod->lhs;
      if (prod->isSupertype != 2)
	fprintf(yaccFile, "%%type <val%d> %s\n", n, prodName);
      if (prod->isOptional == 3)
	fprintf(yaccFile, "%%type <val%d> %s\n", n, prod->optProd->lhs);
      if (strcmp(prodName, "instance") == 0)
	fprintf(yaccFile, "%%type <val%d> instancePlus\n", n);
      else
	{
	  for (anCell = prod->ancestors.first; anCell; anCell = anCell->next)
	    { 
	      if ((anCell->data->isOptional == 3) &&
		  (anCell->data->isSupertype != 2) &&
		  anCell->data->optProd->transferName &&
		  (strcmp(anCell->data->optProd->transferName, prodName) == 0))
		{
		  fprintf(yaccFile, "%%type <val%d> %s\n", n,
			  anCell->data->optProd->lhs);
		}
	    }
	}
      n++;
    }
  fprintf(yaccFile, "\n");
}

/********************************************************************/

/* printYaccYyerror

Returned Value: none

Called By: printYaccStart

The yyerror function this writes prints two lines. The first line
includes any error message that may have been stored by Lex in the
lexMessage array, followed by any message the YACC parser may have.
The second line is the text of the line that caused the error, up
to and including the last thing read by Lex. The unread part of the
line is not printed.

*/

void printYaccYyerror( /* ARGUMENTS             */
 FILE * yaccFile)      /* YACC file to print in */
{
  fprintf(yaccFile,
"/* yyerror\n"
"\n"
"If lexMessage contains a message, lexMessage[0] will not be 0,\n"
"and a syntax error will have occurred, since BAD will have been\n"
"returned by the lexer. In this case, only the lexMessage is\n"
"printed, since reporting the syntax error (s) only adds confusion.\n"
"\n"
"*/\n"
"\n"
"int yyerror(char * s)\n"
"{\n"
"  int n;\n"
"\n"
"  if (lexMessage[0])\n"
"    {\n"
"      fprintf(report, \"Error: %%s\\n\", lexMessage);\n"
"      lexMessage[0] = 0;\n"
"    }\n"
"  else\n"
"    fprintf(report, \"Error: %%s\\n\", s);\n"
"  fprintf(report, \"%%s\\n\", lineText);\n"
"  for (n = 0; lineText[n] != 0; n++);\n"
"  if (lineText[n-1] != '\\n')\n"
"    fprintf(report, \"\\n\");\n"
"  return 0;\n"
"}\n");
}

/********************************************************************/

/* recordClass

Returned Value: none

Called By:  recordClasses
  
This records the name of a class. The class name is stored in
alphabetical order in the classNames array (which has a separate
sub-array for each letter of the alphabet).

*/

void recordClass(  /* ARGUMENTS            */
 char * className) /* class name to record */
{
  int n;
  int k;
  int result;
  char ** letterNames;

  letterNames = classNames[className[0] - 'a'];
  for (n = 0; ((n < CLASSSIZE) && (letterNames[n] != 0)); n++)
    {
      result = strcmp(className, letterNames[n]);
      if (result == 0) /* already recorded */
	return;
      else if (result < 0) /* className comes before letterNames[n] */
	break;
    }
  if (n == CLASSSIZE)
    {
      fprintf(stderr, "Too many classes starting with %c\n", className[0]);
      exit(1);
    }
  if (letterNames[n] != 0)
    { // shift right to make room for className
      for (k = n; ((k < CLASSSIZE) && (letterNames[k] != 0)); k++);
      if (k == CLASSSIZE)
	{
	  fprintf(stderr, "Too many classes starting with %c\n", className[0]);
	  exit(1);
	}
      for (; k >= n; k--)
	{
	  letterNames[k] = letterNames[k-1];
	}
    }
  letterNames[n] = className;
}

/********************************************************************/

/* recordClasses

Called By: printCppClasses

This records in the classNames array the names of classes that will be
printed when classes are printed from the productions in the toPrint
list. The class name is the same as the production name.

*/

void recordClasses(  /* ARGUMENTS                                      */
 prodList * toPrint) /* list of productions for which to print classes */
{
  prodListCell * prodCell;

  for (prodCell = toPrint->first; prodCell; prodCell = prodCell->next)
    { // gather all the class names
      recordClass(prodCell->data->lhs);
    }
}

/********************************************************************/

/* recordTerminal

Returned Value: none

Called By:  action for Expression

This records the names of terminals. The terminalName is stored in
alphabetical order in the terminalNames array.

*/

void recordTerminal(  /* ARGUMENTS               */
 char * terminalName) /* terminal name to record */
{
  int n;
  int k;
  int result;

  for (n = 0; ((n < LETTERSIZE) && (terminalNames[n] != 0)); n++)
    {
      result = strcmp(terminalName, terminalNames[n]);
      if (result == 0) /* already recorded */
	return;
      else if (result < 0) /* terminalName comes before terminalNames[n] */
	break;
    }
  if (n == LETTERSIZE)
    {
      fprintf(stderr, "Too many terminals\n");
      exit(1);
    }
  else if (terminalNames[n] == 0)
    {
      terminalNames[n] = terminalName;
      return;
    }
  for (k = n; ((k < LETTERSIZE) && (terminalNames[k] != 0)); k++);
  if (k == LETTERSIZE)
    {
      fprintf(stderr, "Too many terminals\n");
      exit(1);
    }
  for (; k >= n; k--)
    { // shift right to make room for terminalName
      terminalNames[k] = terminalNames[k-1];
    }
  terminalNames[n] = terminalName;
}

/********************************************************************/

/* recordToken

Returned Value: none

Called By:
  action for Expression
  action for productionList 

This records the tokenName. tokenNames is an array of 26 arrays (one
for each first letter) of pointers to names. The tokenName is stored
in alphabetical order in the subarray of tokenNames that corresponds
to the first letter of the tokenName.

Some token names include digits, underscores, or minus signs. These
names are changed in the EBNF file to contain only upper case letters,
since EBNF does not allow any underscores or minus signs in names and
does not allow a name to start with a digit. The actual spellings of
these token names, however, are included in the EBNF file. After the
entire EBNF file has been read, the reviseSpelling function inserts
the actual spellings of these token names into tokenLexes.

*/

void recordToken(  /* ARGUMENTS            */
 char * tokenName) /* token name to record */
{
  int n;
  int k;
  int result;
  char ** letterNames;

  letterNames = tokenNames[tokenName[0] - 'A'];
  for (n = 0; ((n < LETTERSIZE) && (letterNames[n] != 0)); n++)
    {
      result = strcmp(tokenName, letterNames[n]);
      if (result == 0) /* already recorded */
	return;
      else if (result < 0) /* tokenName comes before letterNames[n] */
	break;
    }
  if (n == LETTERSIZE)
    {
      fprintf(stderr, "Too many tokens starting with %c\n", tokenName[0]);
      exit(1);
    }
  if (letterNames[n] != 0)
    { // shift right to make room for tokenName
      for (k = n; ((k < LETTERSIZE) && (letterNames[k] != 0)); k++);
      if (k == LETTERSIZE)
	{
	  fprintf(stderr, "Too many tokens starting with %c\n", tokenName[0]);
	  exit(1);
	}
      for (; k >= n; k--)
	{
	  letterNames[k] = letterNames[k-1];
	}
    }
  letterNames[n] = tokenName;
}

/********************************************************************/

/* reviseSpelling

Returned Value: None

Called By: main

First, this makes each pointer in the tokenLexes array point to the
same name that is pointed at by the corresponding element of tokenNames
(so there are two pointers to the same thing).

Then this looks at all the productions. For each production this calls
findToken to see if the left side of the production is the name of a
token. If it is the name of a token, findToken records the position in
tokenNames at which it was found. If any production has a token on the
left side, the right side should give the correct spelling to look for
in Lex in order to recognize the token. The right side should consist
of a single definition containing expressions that are all either type
ONECHAR or type TWOCHAR. The correct string to look for in Lex is formed
and stored in the position of tokenLexes corresponding to the position
in tokenNames at which the token was found.

If the contents of the right side of a production defining a token are
not what they should be, an error message is printed and sebnf2pars exits.

*/

void reviseSpelling() /* NO ARGUMENTS */
{
  prodListCell * aCell;       // a prodListCell to examine
  char * leftName;            // the name on the left side of a production
  int n;                      // index of position in tokenLexes
  int k;                      // index for buffer
  defList * defs;             // the definition to examine
  expList * exps;             // the expressions to examine
  expListCell * expCell;      // expListCell to examine
  expression * exp;           // an expression to examine
  
  for (k = 0; k < 26; k++)
    {
      for (n = 0; ((n < LETTERSIZE) && (tokenNames[k][n])); n++)
	tokenLexes[k][n] = tokenNames[k][n];
    }
  for (aCell = productions.first; aCell; aCell = aCell->next)
    {
      leftName = aCell->data->lhs;
      if (findToken(leftName, &n))
	{
	  defs = aCell->data->defs;
	  if ((defs->first == 0) ||
	      (defs->first != defs->last) ||
	      (defs->first->data->expressions->first == 0))
	    { // not exactly one definition
	      fprintf(stderr, 
		      "Token %s does not have exactly one spelling\n",
		      leftName);
	      exit(1);
	    }
	  exps = defs->first->data->expressions;
	  k = 0;
	  for (expCell = exps->first; expCell; expCell = expCell->next)
	    {
	      exp = expCell->data;
	      if (exp->theType == ONECHAR)
	        buffer[k++] = exp->itemName[0];
	      else if (exp->theType == TWOCHAR)
		{
		  if (exp->itemName[1] != (exp->itemName[0] + ('a' - 'A')))
		    { // second letter not lower case of first (upper) letter
		      fprintf(stderr,
			      "In token %s spelling %c differs from %c\n",
			      leftName, exp->itemName[0], exp->itemName[1]);
		      exit(1);
		    }
		  buffer[k++] = exp->itemName[0];
		}
	      else
		{ // not a ONECHAR or a TWOCHAR
		  fprintf(stderr, "Token %s spelling has a bad expression\n",
			  leftName);
		  exit(1);
		}
	    }
	  buffer[k] = 0;
	  tokenLexes[leftName[0] - 'A'][n] = strdup(buffer);
	}
    }
}

/********************************************************************/

/* selectProductions

Returned Value: none

Called By: printCppClasses

This puts all the productions for which classes should be printed into
the toPrint list. The productions which should be printed are all
except:
1. terminal names
2. token names
3. lists
4. the instancePlus production
5. optional parents

The terminalNames array, which is an array of pointers to strings that
has NULLs at the end, cannot get too big, so it is not necessary
to check for overflow here.

*/
void selectProductions( /* ARGUMENTS                                  */
 prodList * toPrint)    /* list of productions to process, built here */
{
  prodListCell * prodCell;
  production * prod;
  char * prodName;
  int n;
  
  for (prodCell = productions.first; prodCell; prodCell = prodCell->next)
    {
      prod = prodCell->data;
      prodName = prod->lhs;
      for (n = 0; terminalNames[n]; n++)
	{
	  if (strcmp(prodName, terminalNames[n]) == 0)
	    break;
	}
      if (terminalNames[n])
	continue; // do not process terminal names
      else if (findToken(prodName, &n))
	continue; // do not process token names
      else if (prod->isList)
	continue; // do not process lists
      else if (strcmp(prodName, "instancePlus") == 0)
	continue; // do not process instancePlus
      else if ((prod->isOptional == 1) || (prod->isOptional == 2))
	continue; // do not process optional parents
      toPrint->pushBack(prod);
    }
}

/********************************************************************/

/* yyerror

Returned Value: int (0)

Called By: yyparse

If a parse error occurs while parsing the EBNF file, this prints
whatever string the parser provides as an explanation of the error.

*/

int yyerror( /* ARGUMENTS       */
 char * s)   /* string to print */
{
  fprintf(stderr, "%s\n", s);
  return 0;
}

/********************************************************************/

