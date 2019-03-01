main.o: main.c trout.h
		gcc -c main.c

util.o: util.c trout.h
		gcc -c util.c

trout.o: main.c trout.h
		gcc -c trout.c

trout: trout.o util.o main.o
	gcc -Wall trout.o util.o main.o -o trout
