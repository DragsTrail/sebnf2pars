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

#include <string.h>          // for strdup
#include "ebnfClasses.hh"    // for classes referenced in debnf2yaccYACC.hh
#include "sebnf2parsYACC.hh" // for tokens, yylval, etc.

#define ECHO_IT 1
#define ECH if (ECHO_IT) ECHO

  int n;
  int first;
  char lexbuf[80];
%}

W [ \t]*
%x COMMENT

%%

  /* This lex file looks for the following items in a SEBNF file.         */

  /* 1. Comments. A comment starts with (* and ends with *). It may have  */
  /* any characters inside, including newlines. Comments are read and     */
  /* ignored.                                                             */

  /* 2. Single characters that represent SEBNF separator symbols. These   */
  /* are: IS, OR, and SEMICOLON.                                          */

  /* 3. A single character inside single quotes. This is a ONECHAR. The   */
  /* yylval.sval is set to a string containing the one character.         */

  /* 4. Two or more characters inside single quotes. This is a            */
  /* TERMINALSTRING. The yylval.sval is set to a string containing the    */
  /* characters.                                                          */

  /* 5. Something of the form ('A'|'B'), where A and B may be replaced    */
  /* by any letters (upper case or lower case). This is a TWOCHAR. The    */
  /* yylval.sval is set to a string containing the two characters.        */

  /* 6. A single blank line. This is read and ignored.                    */

  /* 7. A newline. This is read and ignored.                              */

   /* 9. A word starting with a lower case letter and containing only      */
  /* letters and digits. This is a NONTERMINAL. The yylval.sval is set    */
  /* to the characters in the word.                                       */

  /* 10. A word starting with an upper case letter followed by a lower    */
  /* case letter and containing only letters. This is a TERMINAL. The     */
  /* yylval.sval is set to the letters in the word all changed to upper   */
  /* case. The name TERMINAL is misleading. These words are actually      */
  /* undefined non-terminals for which definitions could be written.      */

  /* 11. A word starting with an upper case letter and having only upper  */
  /* case letters and digits in it. This is a KEYWORD, which is a         */
  /* terminal symbol. yylval.sval is set to the characters in the word.   */

  /* The expressions here allow white space before and after almost       */
  /* everything. This makes lex decide whether to include any white       */
  /* space with the preceding item or the following item. lex should      */
  /* not get confused, because lex makes each item as large as            */
  /* possible. Thus, any white space between two items should stick to    */
  /* the first of the two.                                                */

{W}"(*"                    { ECH; BEGIN(COMMENT); /* delete comments start */ }
<COMMENT>.                 { ECH;  /* delete comments middle */ }
<COMMENT>\n                { ECH;  /* delete comments middle */ }
<COMMENT>"*)"{W}           { ECH; BEGIN(INITIAL); /* delete comments end */ }
{W}={W}                    { ECH; return IS; }
{W}"|"{W}                  { ECH; return OR; }
{W}","{W}                  { ECH; return COMMA; }
{W}";"{W}                  { ECH; return SEMICOLON; }
{W}'.'{W}                  { ECH; 
                             for (n = 0; yytext[n] != '\''; n++);
                             yytext[0] = yytext[n+1];
                             yytext[1] = 0;
                             yylval.sval = strdup(yytext);
                             return ONECHAR;
                           }
{W}'.[^']+'{W}             { ECH;
                             for (first = 0; yytext[first] != '\''; first++);
                             first++;
 			     for (n = first; yytext[n] != '\''; n++);
 			     yytext[n] = 0;
                             yylval.sval = strdup(yytext + first);
			     return TERMINALSTRING;
                           }
{W}"("{W}'.'{W}"|"{W}'.'{W}")"{W} { ECH;
                             for (n = 0; yytext[n] != '\''; n++);
                             yytext[0] = yytext[n+1];
                             for (n = (n + 3); yytext[n] != '\''; n++);
                             yytext[1] = yytext[n+1];
                             yytext[2] = 0;
                             yylval.sval = strdup(yytext);
			     return TWOCHAR;
                           }
^[ \t]*\n                  { ECH; /* skip blank lines */ }
\n                         { ECH; /* skip single newlines */ }
{W}[a-z][a-zA-Z0-9]*{W}    { ECH; /* non-terminals may contain digits */
                             for (first = 0; yytext[first] < 'a'; first++);
			     for (n = first; yytext[n] >= '1'; n++);
			     yytext[n] = 0;
                             yylval.sval = strdup(yytext + first);
			     return NONTERMINAL;
                           }
{W}[A-Z][a-z][a-zA-Z]*{W}  { ECH; /* spell terminals in all upper case */
                             for (first = 0; yytext[first] < 'A'; first++);
			     for (n = first; yytext[n] >= 'A'; n++)
			       {
				 if (yytext[n] > 'Z')
				   yytext[n] = (yytext[n] + ('A' - 'a'));
			       }
			     yytext[n] = 0;
                             yylval.sval = strdup(yytext + first);
			     return TERMINAL;
                           }
  /* See the documentation at the start of this file */
{W}[A-Z][A-Z0-9]*{W}       { ECH;
                             int k = 0;
                             for (n = 0; yytext[n] < '0'; n++); // skip blanks
			     if ((yytext[n] == 'E') &&
				 (yytext[n+1] == 'O') &&
				 (yytext[n+2] == 'F') &&
				 ((yytext[n+3] == 0) ||
				  (yytext[n+3] == ' ') ||
				  (yytext[n+3] == '\t')))
			       {
				 sprintf(lexbuf, "WW");
				 k = 2;
			       }
			     for (; yytext[n] >= '0'; n++)
			       {
				 lexbuf[k++] = yytext[n];
			       }
			     lexbuf[k] = 0;
			     yylval.sval = strdup(lexbuf);
			     return KEYWORD;
                           }
.                          {ECH; return BAD; }

%%

int yywrap()
{
  return 1;
}
