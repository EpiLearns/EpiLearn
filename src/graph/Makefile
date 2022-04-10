#Makefile

CPPFLAGS =
CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LDFLAGS = 
LDLIBS = `pkg-config --libs gtk+-3.0` -lm -rdynamic

SRC = graph.c parser.c node.c
OBJ = ${SRC:.c=.o}

graph: ${OBJ}

clean:
	${RM} ${OBJ}
	${RM} graph

# END