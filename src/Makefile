#	File: SIMPLE_MAKEFILE
#	Author: David Villalobos
#	Date: 2021-14-03

OBJS = main.o Element.o Composite.o Property.o Json.o
SOURCE = main.cpp Element.cpp Composite.cpp Property.cpp Json.cpp
OUT = main.exe
CC = g++
FLAGS = -c -g -Wall

#make
all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

Composite.o: Composite.cpp
	$(CC) $(FLAGS) Composite.cpp

Element.o: Element.cpp
	$(CC) $(FLAGS) Element.cpp

Json.o: Json.cpp
	$(CC) $(FLAGS) Json.cpp

Property.o: Property.cpp
	$(CC) $(FLAGS) Property.cpp

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

# clean
c:
	del $(OBJS) $(OUT)

# run
r: $(OUT)
	$(OUT)
