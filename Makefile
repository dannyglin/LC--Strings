#########################################################
#  file name   : Makefile                               #
#  author      : Danny Lin                              #
#  description : Makefile to automate compiling         #
#                and linking                            #
#########################################################



all: program1 program2 program3 program4

my_string.o: my_string.c my_string.h
	clang -c my_string.c -o my_string.o

program1: program1.c my_string.o
	clang program1.c my_string.o -o program1

program2: program2.c my_string.o
	clang program2.c my_string.o -o program2

program3: program3.c
	clang program3.c -o program3

program4: program4.c my_string.o
	clang program4.c my_string.o -o program4

clean:
	rm -f *.o

clobber: clean
	rm -f program1 program2 program3 program4