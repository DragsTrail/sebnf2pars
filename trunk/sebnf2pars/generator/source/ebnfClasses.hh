/******************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I. 
*****************************************************************************/

#include <stdlib.h> // for exit, etc.

/*

This file provides a set of classes that may be used to build abstract
syntax trees for EBNF files representing STEP Part 21 files. The
classes include enough methods and data members to represent any
language described using a subset of EBNF, but they also include
methods and data members needed to support the complex processing done
by sebnf2pars.y, which automatically builds C++ classes and parsers
for STEP Part 21 files.

As used in this system, an EBNF file is a list of productions. Each
production sets a production name to be equivalent to a list of
definitions. The definitions are separated by vertical bars and the
list is terminated by a semicolon. Each definition is a list of
expressions.

In an EBNF file, the ordering of the productions and definitions lists
is irrelevant. The ordering of an expressions list in EBNF is
significant. In the C++ classes it is convenient to keep all lists
ordered so that they may be traversed easily. Definitions and
expressions lists may be empty. An empty productions list is possible
but pointless, since then there would be an empty file and no language.

Each class defined here has one destructor that does nothing and two
constructors. The first constructor takes no arguments and does
nothing.  The second constructor takes arguments that are the same as
its data members and sets the data members to the arguments.

This file defines its own lists rather than using C++ lists. This is
done because doubly linked lists are used to enable traversal in
either direction. For each of the three list types, a listCell class
and a list class are defined. The listCell classes each have three
pointers: back (a listCell), next (a listCell), and data (an instance
of the class being listed). The list classes have two pointers to
listCells: last and first.

In each of the three list types, some of the following functions are
defined (see ebnfClasses.cc for more details):

pushBack - adds an item in a new listCell that is inserted at the end
of the list.

pushFront - adds an item in a new listCell that is inserted at the front
of the list.

The stringList and stringListCell classes are not needed for representing
EBNF but are used in sebnf2pars.

*/

class definition;
class defListCell;
class defList;
class expression;
class expListCell;
class expList;
class production;
class prodListCell;
class prodList;
class stringList;
class stringListCell;

/********************************************************************/

/* class stringListCell

This is a list cell class for making singly linked lists of strings.

*/

class stringListCell
{
 public:
  stringListCell(){data = 0; next = 0;}
  stringListCell(char * dataIn)
    {data = dataIn; next = 0;}
  ~stringListCell(){}

  char * data;
  stringListCell * next;
};

/********************************************************************/

/* class stringList

This is a list class for singly linked lists of strings.  The record
method puts a string into the list in alphabetical order (if the
existing list is in alphabetical order) and eliminates duplicates.

*/

class stringList
{
 public:
  stringList()
  {
    first = 0;
    last = 0;
  }
  ~stringList(){}
  void record(char * dataIn);
  void pushBack(char * dataIn);
  int findLength();
  stringListCell * member(char * aString);
  
  stringListCell * first;
  stringListCell * last;
};

/********************************************************************/

/* class definition

A definition is a list of expressions.

*/

class definition
{
public:
  definition()
  {
    expressions = 0;
  }
  definition(expList * expressionsIn)
  {
    expressions = expressionsIn;
  }
  ~definition(){}

  expList * expressions; // expressions giving the definition
};

/********************************************************************/

/* class defListCell

This defines the type of doubly-linked cell used to make defLists.
Pointers are kept to the previous cell, to the next cell, and to a
definition.

*/

class defListCell
{
public:
  defListCell(){}
  defListCell(definition * def)
  {
    data = def;
    next = 0;
    back = 0;
  }
  ~defListCell(){}

  defListCell * next;
  defListCell * back;
  definition * data;
};

/********************************************************************/

/* class defList

This is a doubly-linked list type for definitions.  Pointers are kept
to the first and last cells.

If a list is not empty, first should point to the first cell in the
list, and last should point to the last cell in the list.

If a list is empty, first and last should both be set to NULL.

*/

class defList
{
public:
  defList()
  {
    first = 0;
    last = 0;
  }
  defList(definition * def)
  {
    defListCell * aCell;

    aCell = new defListCell(def);
    first = aCell;
    last = aCell;
  }
  ~defList(){}

  int findLength();
  void pushBack(definition * def);
  void pushFront(definition * def);

  defListCell * first;
  defListCell * last;
};

/********************************************************************/

/* class expression

The expression class can be used to represent a wide variety of things
because theType (which is an integer) can represent any type the
user wants it to represent. Valid values for theType are not
specified here.

The definition of expression is tailored, however, so that it can
conveniently represent a production.

To represent a production, the application should designate an integer
to mean "this represents a production" and set theType to that
integer. Then the itemName may be used to give the name of the
production, and the prodValue may be used to hold a pointer to the
production. If desired, different integers may be used to represent
different types of production. It is suggested that prodValue be set
to NULL when theType does not signify a production.

The itemName may be used to hold whatever string the application
wishes, and its meaning may vary according to the value of theType.

*/

class expression
{
public:
  expression()
  {
    theType = 0;
    itemName = 0;
    prodValue = 0;
  }
  expression(int theTypeIn, char * itemNameIn, production * prodValueIn)
  {
    theType = theTypeIn;
    itemName = itemNameIn;
    prodValue = prodValueIn;
  }
  ~expression(){}
  
  int theType;
  char * itemName;
  production * prodValue;
};

/********************************************************************/

/* class expListCell

This defines the type of doubly-linked cell used to make expLists.
Pointers are kept to the previous cell, to the next cell, and to an
expression.

*/

class expListCell
{
public:
  expListCell(){}
  expListCell(expression * exp)
  {
    data = exp;
    next = 0;
    back = 0;
  }
  ~expListCell(){}

  expListCell * next;
  expListCell * back;
  expression * data;
};

/********************************************************************/

/* class expList

This is a doubly-linked list type for expressions.  Pointers are kept
to the first and last cells.

If a list is not empty, first should point to the first cell in the
list, and last should point to the last cell in the list.

If the list is empty, first and last should both be set to NULL.

The "setProdValue" method inserts prod as the prodValue of any expression
in "this" list if the itemName of the expression is the same as the
name of the production.

*/

class expList
{
public:
  expList()
  {
    first = 0;
    last = 0;
  }
  expList(expression * exp)
  {
    expListCell * aCell;

    aCell = new expListCell(exp);
    first = aCell;
    last = aCell;
  }
  ~expList(){}

  int findLength();
  void pushBack(expression * exp);
  void pushFront(expression * exp);
  void setProdValue(production * prod);

  expListCell * first;
  expListCell * last;
};

/********************************************************************/

/* class prodListCell

This defines the type of doubly-linked cell used to make prodLists.
Pointers are kept to the previous cell, to the next cell, and to a
production.

*/

class prodListCell
{
public:
  prodListCell()
  {
    data = 0;
    next = 0;
    back = 0;
  }
  prodListCell(production * prod)
  {
    data = prod;
    next = 0;
    back = 0;
  }
  ~prodListCell(){}

  prodListCell * next;
  prodListCell * back;
  production * data;
};

/********************************************************************/

/* class prodList

This is a doubly-linked list type for productions.  Pointers are kept
to the first and last cells.

If a list is not empty, first should point to the first cell in the
list, and last should point to the last cell in the list.

If the list is empty, first and last should both be set to NULL.

*/

class prodList
{
public:
  prodList()
  {
    first = 0;
    last = 0;
  }
  prodList(production * prod)
  {
    prodListCell * aCell;

    aCell = new prodListCell(prod);
    first = aCell;
    last = aCell;
  }
  ~prodList(){}

  int findLength();
  void pushBack(production * prod);
  prodListCell * member(production * prod);

  prodListCell * first;
  prodListCell * last;
};

/********************************************************************/

/* class production

A production says the lhs (left-hand side) is equivalent to any of
the defs (definitions).

An optional production is a production of the form:

P = C | '$' ;

P will be called an "optional parent" and C will be called an
"optional child". C++ classes are not generated for optional parents.

Several data members

1. ancestors (prodList, default is empty list) - a list of productions
from which the production is descended. Ancestors are used in setting
the beInstance of each production and for writing the isA
function. Optional parents are omitted from ancestors since there are
are no classes for them. Also the "instance" production is not
included in ancestors.

2. attNames (stringList, default is empty list) - This is a list of
the names of the attributes of the production, including those
inherited from supertypes.

3. beInstance (production, default is NULL) - This is set in
findBeInstance. If a production P is the ancestor of a production Q
that is an instance, the beInstance of P is set to point to Q. In most
uses of beInstance, what is important is whether it is zero or
non-zero, and the value of a non-zero beInstance is irrelevant.
However, the value is used when an optional is being handled.

4. defs (defList *, default is NULL) - a pointer to a list of the
definitions of the production. It is set by the parser.

5. isInstance (bool, default is false) - this is set to true in
findIsInstance if the production is a subtype of instance.

6. isList (int, default is 0) - this is set to 2 if the production is
a comma-separated list or to 1 if the production is a list not
separated by commas.

7. isOptional (int, default is 0) - this is set in findOptProds to:
   1 if the production is an optional parent in which the optional
     child is an instance or the supertype of an instance
   2 if the production is an optional parent in which the optional
     child is not an instance or the supertype of an instance
   3 if the production is an optional child

8. isSupertype (bool, default is 0) - this is set in findSupertypes
to true if each definition the production has only one expression
and that expression is a production that is not a list.

9. lhs (char *, default is NULL) - this is the name of the production.
It is set by the parser.

10. myAtts (stringList, default is empty list) - This is a list of
the names of the attributes of the production, not including those
inherited from supertypes. The list is filled in findMyAtts.

11. myExps (expList, default is empty list) - This is a list of the
expressions that go with the myAttNames. The list is filled in
findMyExps.

12. optProd (production *, default is 0) - Set in findOptProds. If
isOptional is 1 or 2, this is a pointer to the optional child. If
isOptional is 3, this is a pointer to the optional parent.

13. subtypeOf (prodList, default is empty list) - this is set in
findSupertypes to contain the productions of which the production is a
subtype. This list may have more than one element only if the production
has no attributes.

14. transferName (char *, default is NULL) - for each optional parent
P, this is set in findTransferName to the name of a production that is
an instance and is either the optional child C of P or is a subtype of C.

15. wasPrinted (bool, default is false) - this is set and used in
printCppClasses to true once a class for the production has been
printed.

Also, see documentation of the methods in the ebnfClasses.cc file.

Note that since a production has a prodList as one of its attributes,
production must be defined after prodList.



*/

class production
{
public:
  production()
  {
    ancestors.first = 0;
    ancestors.last = 0;
    attNames.first = 0;
    attNames.last = 0;
    beInstance = 0;
    defs = 0;
    isInstance = false;
    isList = 0;
    isOptional = 0;
    isSupertype = false;
    lhs = 0;
    myAtts.first = 0;
    myAtts.last = 0;
    myExps.first = 0;
    myExps.last = 0;
    optProd = 0;
    subtypeOf.first = 0;
    subtypeOf.last = 0;
    transferName = 0;
    wasPrinted = false;
  }
  production(char * lhsIn, defList * defsIn);
  ~production(){}
  
  prodList ancestors;      // list of productions from which this is descended
  stringList attNames;     // names of attributes including supertypes
  production * beInstance; // non-NULL=use will be an instance, NULL = not
  defList * defs;          // the definitions of the production
  bool isInstance;         // true=is a subtype of instance, false=not
  int isList;              // 0=not a list, 1=list no commas, 2=list with commas
  int isOptional;          // 0, 1, 2, or 3 - see above
  bool isSupertype;        // true = this prod is a supertype of other prods
  char * lhs;              // the name of the production (lhs = left-hand side)
  stringList myAtts;       // names of attributes excluding supertypes
  expList myExps;          // expressions matching myAttNames
  production * optProd;    // 0 or a pointer to an optional parent or child
  prodList subtypeOf;      // list of productions of which this is a subtype
  char * transferName;     // name for transferring id of optional
  bool wasPrinted;         // true = class for this production was printed 

  int findIsList();
};

/********************************************************************/

