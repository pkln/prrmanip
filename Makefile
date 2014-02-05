#Makefile
all: geomcalc works
	gcc -o workspace GeometricCalc.o workspace.o -lm
geomcalc:
	gcc -c GeometricCalc.c -lm
works:
	gcc -c workspace.c -lm
