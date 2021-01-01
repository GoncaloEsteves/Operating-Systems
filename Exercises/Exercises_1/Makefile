CC = gcc

CFLAGS = -Wall

program: main.o guiao00.o

guiao00.o: guiao00.h guiao00.c

main.o: guiao00.h main.c

clean:
	rm -f program *.o