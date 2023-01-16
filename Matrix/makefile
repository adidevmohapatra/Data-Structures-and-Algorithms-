CFLAGS = -Wall -g
CC = g++ --std=c++17

all: main.o matrix.o 
    $(CC) $(CFLAGS) -o output main.o matrix.o

main.o: main.cpp
    $(CC) $(CFLAGS) -c main.cpp

matrix.o: matrix.cpp matrix.h
    $(CC) $(CFLAGS) -c matrix.cpp

run:
    ./output

clean:
    rm *.o output