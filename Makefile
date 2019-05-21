CC = g++
CFLAGS = -std=c++11 -g

all: main.cpp common.o calculator.h
	$(CC) $(CFLAGS) main.cpp common.o -o calculator_main

common.o: common.cpp common.h
	$(CC) $(CFLAGS) -c common.cpp

clean:
	rm -rf *.o calculator_main
