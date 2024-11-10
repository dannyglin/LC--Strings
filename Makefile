#########################################################
#  file name   : Makefile                               #
#  author      : Danny Lin		                        #
#  description : Makefile to automate compiling         #
#                and linking                            #
#########################################################
CC = gcc
CFLAGS = -Wall

all: program1 program2 program3 program4

my_string.o: my_string.c my_string.h
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o

program1: program1.c my_string.o
	$(CC) $(CFLAGS) program1.c my_string.o -o program1

program2: program2.c my_string.o
	$(CC) $(CFLAGS) program2.c my_string.o -o program2

program3: program3.c
	$(CC) $(CFLAGS) program3.c -o program3

program4: program4.c my_string.o
	$(CC) $(CFLAGS) program4.c my_string.o -o program4

clean:
	rm -f *.o

clobber: clean
	rm -f program1 program2 program3 program4