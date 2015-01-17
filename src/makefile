#Makefile para construir clong

CC = g++
OBJS = main.o Game.o Ball.o
CFLAGS = -Wall -g -c -std=c++11
LFLAGS = -Wall -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system

clong.out : $(OBJS)
	$(CC) $(OBJS) -o clong $(LFLAGS) 

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

Game.o : Game.hpp Game.cpp Ball.hpp Defs.hpp
	$(CC) $(CFLAGS) Game.cpp

Ball.o : Ball.hpp Ball.cpp Defs.hpp mt19937ar.h
	$(CC) $(CFLAGS) Ball.cpp

clean:
	\rm *.o clong
