COMPILE = /usr/bin/g++ -c -v -g -Wall
LINK = /usr/bin/g++ -v

##################################################################

# sebnf2pars YACC and Lex processing

source/sebnf2parsLex.cc : source/sebnf2pars.lex
	flex -L -t source/sebnf2pars.lex > source/sebnf2parsLex.cc

source/sebnf2parsYACC.cc : source/sebnf2pars.y
	bison -d -l -o source/sebnf2parsYACC.cc source/sebnf2pars.y

##################################################################

# sebnf2pars executable

bin/sebnf2pars : ofiles/sebnf2parsYACC.o\
                      ofiles/sebnf2parsLex.o\
                      ofiles/ebnfClasses.o
	$(LINK) -o bin/sebnf2pars ofiles/sebnf2parsYACC.o\
                                  ofiles/sebnf2parsLex.o\
                                  ofiles/ebnfClasses.o

ofiles/sebnf2parsLex.o : source/sebnf2parsLex.cc\
                              source/sebnf2parsYACC.hh
	$(COMPILE) -o ofiles/sebnf2parsLex.o source/sebnf2parsLex.cc

ofiles/sebnf2parsYACC.o : source/sebnf2parsYACC.cc\
                               source/sebnf2parsYACC.hh\
                               source/ebnfClasses.hh
	$(COMPILE) -o ofiles/sebnf2parsYACC.o\
                       source/sebnf2parsYACC.cc

ofiles/ebnfClasses.o : source/ebnfClasses.hh source/ebnfClasses.cc
	$(COMPILE) -o ofiles/ebnfClasses.o source/ebnfClasses.cc

##################################################################

