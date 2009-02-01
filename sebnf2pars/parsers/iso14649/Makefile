COMPILE = /usr/bin/g++ -c -v -g -Wall
LINK = /usr/bin/g++ -v
INCLUDE = -Iinclude

##################################################################

# iso14649parser - compiling

bin/iso14649parser : ofiles/iso14649YACC.o\
                     ofiles/iso14649Lex.o\
                     ofiles/iso14649classes.o\
                     ofiles/iso14649parser.o
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

ofiles/iso14649parser.o : source/iso14649parser.cc\
                          source/iso14649classes.cc\
                          include/iso14649classes.hh
	$(COMPILE) $(INCLUDE) -o ofiles/iso14649parser.o\
                   source/iso14649parser.cc

##################################################################

# iso14649parserDirect - compiling


bin/iso14649parserDirect : ofiles/iso14649YACCDirect.o\
                           ofiles/iso14649LexDirect.o\
                           ofiles/iso14649classesDirect.o\
                           ofiles/iso14649parserDirect.o
	$(LINK) -o bin/iso14649parserDirect ofiles/iso14649parserDirect.o\
                                            ofiles/iso14649YACCDirect.o\
                                            ofiles/iso14649LexDirect.o\
                                            ofiles/iso14649classesDirect.o

ofiles/iso14649classesDirect.o: source/iso14649classesDirect.cc\
                          include/iso14649classesDirect.hh
	$(COMPILE) $(INCLUDE) -o ofiles/iso14649classesDirect.o\
                                 source/iso14649classesDirect.cc

ofiles/iso14649LexDirect.o : source/iso14649LexDirect.cc\
                       include/iso14649YACCDirect.hh\
                       include/iso14649classesDirect.hh
	$(COMPILE) $(INCLUDE) -o ofiles/iso14649LexDirect.o\
                       source/iso14649LexDirect.cc

ofiles/iso14649YACCDirect.o : source/iso14649YACCDirect.cc\
                        include/iso14649YACCDirect.hh\
                        include/iso14649classesDirect.hh
	$(COMPILE) $(INCLUDE) -o ofiles/iso14649YACCDirect.o\
                        source/iso14649YACCDirect.cc

ofiles/iso14649parserDirect.o : source/iso14649parserDirect.cc\
                                include/iso14649classesDirect.hh
	$(COMPILE) $(INCLUDE) -o ofiles/iso14649parserDirect.o\
                   source/iso14649parserDirect.cc

##################################################################

# iso14649parser - source

source/iso14649.lex: source/iso14649.y

include/iso14649classes.hh: source/iso14649.y

source/iso14649classes.cc: source/iso14649.y

source/iso14649.y: ../../generator/bin/sebnf2pars\
                   ../../ebnf/iso14649.ebnf
	dos2unix -n ../../ebnf/iso14649.ebnf iso14649.ebnf
	../../generator/bin/sebnf2pars iso14649 indirect
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

# iso14649parserDirect - source

source/iso14649parserDirect.cc: source/iso14649parser.cc bin/directify
	bin/directify < source/iso14649parser.cc >\
                        source/iso14649parserDirect.cc

source/iso14649Direct.lex: source/iso14649Direct.y

include/iso14649classesDirect.hh: source/iso14649Direct.y

source/iso14649classesDirect.cc: source/iso14649Direct.y

source/iso14649Direct.y: ../../generator/bin/sebnf2pars\
                         ../../ebnf/iso14649.ebnf
	dos2unix -n ../../ebnf/iso14649.ebnf iso14649.ebnf
	../../generator/bin/sebnf2pars iso14649 direct
	mv iso14649.lex source/iso14649Direct.lex
	mv iso14649.y source/iso14649Direct.y
	mv iso14649classes.hh include/iso14649classesDirect.hh
	mv iso14649classes.cc source/iso14649classesDirect.cc
	rm iso14649.ebnf

source/iso14649LexDirect.cc : source/iso14649Direct.lex
	flex -L -t source/iso14649Direct.lex > source/iso14649LexDirect.cc

source/iso14649YACCDirect.cc : source/iso14649Direct.y
	bison -d -l -o source/iso14649YACCDirect.cc source/iso14649Direct.y
	mv source/iso14649YACCDirect.hh include

source/iso14649YACCDirect.hh : source/iso14649Direct.y
	bison -d -l -o source/iso14649YACCDirect.cc source/iso14649Direct.y
	mv source/iso14649YACCDirect.hh include

##################################################################

# directify
# directify changes a C++ code file by changing all
# get_XX() to XX and changing all set_XX(Y) to XX = Y.
# It may be used with input iso14649parser.cc
# and output iso14649parserDirect.cc

source/directifyLex.cc : source/directify.lex
	flex -L -t source/directify.lex > source/directifyLex.cc

bin/directify: source/directifyLex.cc
	 g++ -v -g -Wall -o bin/directify  source/directifyLex.cc
