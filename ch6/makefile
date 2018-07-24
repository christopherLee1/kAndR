SHELL := /bin/bash
CC = gcc-6
FLAGS = 
DEPS = ch6Code.h
OBJ1 = exer6-1.o ch6Code.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

all: exer6-1

exer6-1: $(OBJ1)
	$(CC) -o $@ $^ $(FLAGS)

clean:
	@rm -f *.o
	@rm -f exer6-1 ch6Code
	@rm -rf *.dSYM
