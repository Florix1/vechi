CC=gcc
CFLAGS= -Wall
SOURCES=coada.c decodificare.c main.c
LDFLAGS=header.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=tema3

build :  $(EXECUTABLE)

$(EXECUTABLE):  $(OBJECTS) $(LDFLAGS)

	$(CC)  $(SOURCES) -o $(EXECUTABLE)

clean :

	remove -f  tema3 *.o
