# Simple makefile's project

OBJS = main.o Element.o Composite.o Property.o JsonReader.o
SOURCE = main.cpp Element.cpp Composite.cpp Property.cpp JsonReader.cpp
HEADER = Property.h Element.h Composite.h JsonReader.h
OUT = main.exe
CC = g++
FLAGS = -c -g -Wall
LFLAGS =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Composite.o: Composite.cpp
	$(CC) $(FLAGS) Composite.cpp

Element.o: Element.cpp
	$(CC) $(FLAGS) Element.cpp

JsonReader.o: JsonReader.cpp
	$(CC) $(FLAGS) JsonReader.cpp

Property.o: Property.cpp
	$(CC) $(FLAGS) Property.cpp

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

c:
	del $(OBJS) $(OUT)

r: $(OUT)
	$(OUT)
