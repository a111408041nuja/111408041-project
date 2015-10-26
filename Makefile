all: project

project:
	cc main.c -o project

clear:
	rm -rf *o project
