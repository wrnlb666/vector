CC = gcc
CFLAG = -Wall -Wextra -std=c17 -pedantic -g -Og -ggdb
OBJ = *.o
LIB = -L . -lvector

vector: vector.c
	$(CC) $(CFLAG) -shared -fPIC $< -o lib$@.so

test: test.c
	$(CC) $(CFLAG) $< -o $@ $(LIB)