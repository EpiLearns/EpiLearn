BINARY=tetris

CC= gcc -std=c99
CFLAGS= `pkg-config --cflags gtk+-3.0`
LIBS=`pkg-config --libs gtk+-3.0`


OBJS=tetris.o shape.o checker.o tetwin.o



.PHONY:clean




all:${OBJS}
	${CC} ${CFLAGS}  $^ -o ${BINARY} ${LIBS}


tet-tetris.o:tetris.c config.h
	${CC} ${CFLAGS} -c $< -o $@

tet-shape.o:shape.c config.h
	${CC} ${CFLAGS} -c $< -o $@


tet-checker.o:checker.c config.h
	${CC} ${CFLAGS} -c $< -o $@

tet-tetwin.o:tetwin.c config.h
	${CC} ${CFLAGS} -c $< -o $@



clean:
	-rm *.o
	-rm ${BINARY}