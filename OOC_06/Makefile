CC = gcc
CFLAGS = -Wall -O0 -g3 -std=c99

Object.o:
	$(CC) $(CFLAGS) -c Object.c -o Object.o

Point.o: Object.o
	$(CC) $(CFLAGS) -c Point.c -o Point.o
	
Circle.o: Object.o Point.o
	$(CC) $(CFLAGS) -c Circle.c -o Circle.o

Compartment.o: Object.o
	$(CC) $(CFLAGS) -c Compartment.c -o Compartment.o

all: Object.o Point.o Circle.o Compartment.o
	$(CC) $(CFLAGS) -o any_test any.c Object.o
	$(CC) $(CFLAGS) -o points_test points.c Object.o Point.o
	$(CC) $(CFLAGS) -o circles_test circles.c Object.o Point.o Circle.o
	$(CC) $(CFLAGS) -o compartments compartments.c Object.o Compartment.o

clean:
	rm -f *.o any_test circles_test points_test compartments