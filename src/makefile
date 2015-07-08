#Makefile para construir clong

CC = g++
OBJS = main.o Game.o Ball.o Util.o
CFLAGS = -Wall -g -c -std=c++11
LFLAGS = -Wall -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system

clong : $(OBJS)
	$(CC) $(OBJS) -o clong.out $(LFLAGS) 

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

Game.o : Game.hpp Game.cpp Ball.hpp Defs.hpp
	$(CC) $(CFLAGS) Game.cpp

Ball.o : Ball.hpp Ball.cpp Defs.hpp
	$(CC) $(CFLAGS) Ball.cpp

Util.o: Util.hpp Util.cpp
	$(CC) $(CFLAGS) Util.cpp

clean:
	\rm *.o clong.out
