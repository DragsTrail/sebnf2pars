COMPILE = /usr/bin/g++ -c -v -g -Wall
LINK = /usr/bin/g++ -v
INCLUDE = -Iinclude

##################################################################

# iso14649parser - compiling

bin/iso14649parser : ofiles/iso14649parser.o\
                     ofiles/iso14649YACC.o\
                     ofiles/iso14649Lex.o\
                     ofiles/iso14649classes.o
	$(LINK) -o bin/iso14649parser ofiles/iso14649parser.o\
                                      ofiles/iso14649YACC.o\
                                      ofiles/iso14649Lex.o\
                                      ofiles/iso14649classes.o

ofiles/iso14649classes.o: source/iso14649classes.cc\
                          include/iso14649classes.hh
	$(COMPILE) $(INCLUDE) -o ofiles/iso14649classes.o\
                                 source/iso14649classes.cc

ofiles/iso14649Lex.o : source/iso14649Lex.cc\
                       include/iso14649YACC.hh\
                       include/iso14649classes.hh
	$(COMPILE) $(INCLUDE) -o ofiles/iso14649Lex.o source/iso14649Lex.cc

ofiles/iso14649YACC.o : source/iso14649YACC.cc\
                        include/iso14649YACC.hh\
                        include/iso14649classes.hh
	$(COMPILE) $(INCLUDE) -o ofiles/iso14649YACC.o source/iso14649YACC.cc

ofiles/iso14649parser.o : source/iso14649parser.cc include/iso14649classes.hh
	$(COMPILE) $(INCLUDE) -o ofiles/iso14649parser.o\
                   source/iso14649parser.cc

##################################################################



# iso14649parser - source

source/iso14649.lex: source/iso14649.y

include/iso14649classes.hh: source/iso14649.y

source/iso14649classes.cc: source/iso14649.y

source/iso14649.y: \
                  ../../generator/bin/sebnf2pars\
                  ../../ebnf/iso14649.ebnf
	dos2unix -n ../../ebnf/iso14649.ebnf iso14649.ebnf
	../../generator/bin/sebnf2pars iso14649
	mv iso14649.lex source
	mv iso14649.y source
	mv iso14649classes.hh include
	mv iso14649classes.cc source
	rm iso14649.ebnf

source/iso14649Lex.cc : source/iso14649.lex
	flex -L -t source/iso14649.lex > source/iso14649Lex.cc

source/iso14649YACC.cc : source/iso14649.y
	bison -d -l -o source/iso14649YACC.cc source/iso14649.y
	mv source/iso14649YACC.hh include

source/iso14649YACC.hh : source/iso14649.y
	bison -d -l -o source/iso14649YACC.cc source/iso14649.y
	mv source/iso14649YACC.hh include

##################################################################

