all: project

project: main.o cut.o
	cc main.o cut.o -o project
main.o : main.c cut.h
	cc -Wall -c main.c
cut.o : cut.c cut.h
	cc -Wall -c cut.c
clear:
	rm -rf *o project
