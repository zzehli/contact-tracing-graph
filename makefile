CC=g++
CFLAGS=-g -Wall
SOURCES=*.cpp
OBJ= graph.o main.o 

graph: ${OBJ}
	${CC} -o graph ${CFLAGS} ${OBJ}


graph.o: graph.cpp graph.h
	${CC} ${CFLAGS} -c graph.cpp
main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp


clean:	
	rm -f graph ${OBJ}
	@echo "cleaned up!"
