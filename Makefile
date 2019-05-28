CC = g++
BIN = main
BUILD = ./src/obj
OBJS = ${BUILD}/${BIN}.o
SRC = ./src
CFLAGS = -std=c++11
INC = -I/usr/include -I./include
LIB = -L/usr/lib -L/usr/local/lib


${BIN}: ${OBJS}
	${CC} -o ${BIN} ${OBJS} ${INC} ${LIB} 

${BUILD}/%.o: ${SRC}/%.cpp
	${CC} -c -o $@ $< ${INC} ${CFLAGS}

clean: 
	rm ${BUILD}/*.o 
	rm ${BIN}
	rm *results.csv