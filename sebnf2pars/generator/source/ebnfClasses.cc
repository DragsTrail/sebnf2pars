/******************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I. 
*****************************************************************************/

/*

This file implements the EBNF classes defined in ebnfClasses.hh.

*/

#include "ebnfClasses.hh"
#include <string.h>       // strcmp
#include <stdio.h>

/********************************************************************/

/* defList::findLength

This finds the length of a defList. An empty list has length zero.

*/

int defList::findLength()
{
  int length;
  defListCell * defCell;

  length = 0;
  for (defCell = first; defCell; defCell = defCell->next)
    length++;
  return length;
}

/********************************************************************/

/* defList::pushBack

This puts a new cell at the end of the list and sets last to the
new cell.

If the list is empty at the outset, this sets first to the new cell.

*/

void defList::pushBack(definition * def)
{
  defListCell * defCell;
  
  defCell = new defListCell(def);
  if (last)
    {
      last->next = defCell;
      defCell->back = last;
    }
  else
    {
      first = defCell;
    }
  last = defCell;
}

/********************************************************************/

/* defList::pushFront

This puts a new cell at the front of the list and sets first to the
new cell.

If the list is empty at the outset, this sets last to the new cell.

*/

void defList::pushFront(definition * def)
{
  defListCell * defCell;
  
  defCell = new defListCell(def);
  if (first)
    {
      first->back = defCell;
      defCell->next = first;
    }
  else
    {
      last = defCell;
    }
  first = defCell;
}

/********************************************************************/

/* expList::findLength

This finds the length of an expList. An empty list has length zero.

*/

int expList::findLength()
{
  int length;
  expListCell * expCell;

  length = 0;
  for (expCell = first; expCell; expCell = expCell->next)
    length++;
  return length;
}

/********************************************************************/

/* expList::pushBack

This puts a new cell at the end of the list and sets last to the
new cell.

If the list is empty at the outset, this sets first to the new cell.

*/

void expList::pushBack(expression * exp)
{
  expListCell * expCell;
  
  expCell = new expListCell(exp);
  if (last)
    {
      last->next = expCell;
      expCell->back = last;
    }
  else
    {
      first = expCell;
    }
  last = expCell;
}

/********************************************************************/

/* expList::pushFront

This puts a new cell at the front of the list and sets first to the
new cell.

If the list is empty at the outset, this sets last to the new cell.

*/

void expList::pushFront(expression * exp)
{
  expListCell * expCell;
  
  expCell = new expListCell(exp);
  if (first)
    {
      first->back = expCell;
      expCell->next = first;
    }
  else
    {
      last = expCell;
    }
  first = expCell;
}

/********************************************************************/

/* expList::setProdValue

This inserts prod as the prodValue of any expression in "this"
list if the itemName of the expression is the same as the name
of the production.

*/

void expList::setProdValue(
 production * prod)
{
  expListCell * expCell;

  for (expCell = first; expCell; expCell = expCell->next)
    {
      if (expCell->data->itemName == NULL); // might be NULL
      else if (strcmp(expCell->data->itemName, prod->lhs) == 0)
	{
	  expCell->data->prodValue = prod;
	}
    }
}

/********************************************************************/

/* production::findIsList

findIsList decides if a production is a list (in a specific format),
returning 1 if it is a list with no commas, 2 if it is a list with
commas and 0 if not. A production is judged to be a list if:
1. It has two definitions, and
2. the expression list in the first definition has one expression, and
3. the expression list in the second definition has 2 or 3 expressions, and
4. the lhs (left-hand side) of the production is the same as the
   itemName of the first expression in the second definition, and
5. the itemName of the first expression in the first defintion is
   the same as the itemName of the last expression in the second
   definition, and
6. if the second definition has 3 expressions, the item name of the
   middle expression is "c" (for comma).

The following production is a prototypical example of an EBNF
production defining a type 2 list.

intList =
	  intVal
	| intList , c , intVal
	;

Note that this requires that all lists use left recursion and all
lists define a list item (the first expression in the first definition).

*/

int production::findIsList()
{
  int length;

  if (defs->findLength() != 2)
    return 0;
  if (defs->first->data->expressions->findLength() != 1)
    return 0;
  length = defs->last->data->expressions->findLength();
  if ((length != 2) && (length != 3))
    return 0;
  if (strcmp(lhs, defs->last->data->expressions->first->data->itemName))
    return 0;
  if (strcmp(defs->first->data->expressions->first->data->itemName,
	     defs->last->data->expressions->last->data->itemName))
    return 0;
  if (length == 3)
    {
      if (strcmp(defs->last->data->expressions->first->next->data->itemName,
		 "c"))
	return 0;
      else
	return 2;
    }
  return 1;
}

/********************************************************************/

/* production::production

*/

production::production(
 char * lhsIn,
 defList * defsIn)
{
  ancestors.first = 0;
  ancestors.last = 0;
  attNames.first = 0;
  attNames.last = 0;
  beInstance = false;
  defs = defsIn;
  isInstance = false;
  isList = 0;
  isOptional = 0;
  isSupertype = 0;
  lhs = lhsIn;
  myAtts.first = 0;
  myAtts.last = 0;
  myExps.first = 0;
  myExps.last = 0;
  optProd = 0;
  subtypeOf.first = 0;
  subtypeOf.last = 0;
  transferName = 0;
  wasPrinted = false;

  isList = findIsList();
}

/********************************************************************/

/* prodList::findLength

This finds the length of a prodList. An empty list has length zero.

*/

int prodList::findLength()
{
  int length;
  prodListCell * prodCell;

  length = 0;
  for (prodCell = first; prodCell; prodCell = prodCell->next)
    length++;
  return length;
}

/********************************************************************/

/* prodList::pushBack

This puts a new cell at the end of the list and sets last to the
new cell.

If the list is empty at the outset, this sets first to the new cell.

*/

void prodList::pushBack(
 production * prod)
{
  prodListCell * prodCell;
  
  prodCell = new prodListCell(prod);
  if (last)
    {
      last->next = prodCell;
      prodCell->back = last;
    }
  else
    {
      first = prodCell;
    }
  last = prodCell;
}

/********************************************************************/

/* prodList::member

member looks for prod in "this" prodList. If prod is found, member
returns a pointer to the first prodListCell pointing at prod. If prod
is not found, member returns NULL.

*/

prodListCell * prodList::member(production * prod)
{
  prodListCell * prodCell;
  
  for (prodCell = first; prodCell; prodCell = prodCell->next)
    {
      if (prodCell->data == prod)
	break;
    }
  return prodCell;
}

/********************************************************************/

/* stringList::findLength

This finds the length of a stringList. An empty list has length zero.

*/

int stringList::findLength()
{
  int length;
  stringListCell * stringCell;

  length = 0;
  for (stringCell = first; stringCell; stringCell = stringCell->next)
    length++;
  return length;
}

/********************************************************************/

/* stringList::record

The record method puts the dataIn string into a list in alphabetical order
if the list is already in alphabetical order. If the dataIn string is
the same as a string already on the list, it is ignored.

*/

void stringList::record(
 char * dataIn)
{
  stringListCell * aCell;
  stringListCell * newCell;
  stringListCell * backCell;
  int compVal;
  
  if (first == 0)
    { // list is empty
      first = new stringListCell(dataIn);
      last = first;
    }
  else
    {
      for (aCell = first; aCell; aCell = aCell->next)
	{
	  compVal = strcmp(dataIn, aCell->data);
	  if (compVal < 0)
	    { // dataIn comes before aCell, so insert it.
	      if (aCell == first)
		{
		  first = new stringListCell(dataIn);
		  first->next = aCell;
		}
	      else
		{
		  newCell = new stringListCell(dataIn);
		  backCell->next = newCell;
		  newCell->next = aCell;
		}
	      break;
	    }
	  else if (compVal == 0)
	    { // ignore duplicate
	      break;
	    }
	  else; // if (compVal > 0) new cell goes somewhere after aCell
	  backCell = aCell;
	}
      if (!aCell)
	{ // new cell must go at the end
	  last = new stringListCell(dataIn);
	  backCell->next = last;
	}
    }
}

/********************************************************************/

/* stringList::pushBack

*/

void stringList::pushBack(
 char * dataIn)
{
  stringListCell * newCell;
  
  newCell = new stringListCell(dataIn);
  if (last == 0)
    { // list is empty
      first = new stringListCell(dataIn);
      last = first;
    }
  else
    {
      newCell = new stringListCell(dataIn);
      last->next = newCell;
      last = newCell;
    }
}

/********************************************************************/

/* stringList::member

member looks for a stringCell in "this" stringList that points at a
string that is the same as aString. As soon as such a stringCell is
found, member returns a pointer to it (thus, if there is more than one
such stringCell, the one earliest in the list is returned). If no such
stringCell is found, member returns NULL.

*/

stringListCell * stringList::member(char * aString)
{
  stringListCell * stringCell;
  
  for (stringCell = first; stringCell; stringCell = stringCell->next)
    {
      if (strcmp(stringCell->data, aString) == 0)
	break;
    }
  return stringCell;
}

/********************************************************************/

