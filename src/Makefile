# Simple makefile's project

OBJS = main.o Composite.o
SOURCE = main.cpp Composite.cpp
HEADER = Property.h Simple.h Composite.h
OUT = main.exe
CC = g++
FLAGS = -c -g -Wall
LFLAGS =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Composite.o: Composite.cpp
	$(CC) $(FLAGS) Composite.cpp

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

clean:
	del $(OBJS) $(OUT)

run: $(OUT)
	$(OUT)
