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

test: all
	@cat test.txt | ./exer6-1
	@printf "result should be 1\n"

clean:
	@rm -f *.o
	@rm -f exer6-1 ch6Code
	@rm -rf *.dSYM
