SHELL := /bin/bash
CC = gcc-6
FLAGS = 
DEPS = ch7Code.c
OBJ1 = exer7-1.o ch7Code.o
OBJ2 = exer7-2.o ch7Code.o
OBJ3 = exer7-3.o ch7Code.o
OBJ4 = exer7-4.o ch7Code.o
OBJ5 = cat.o
OBJ6 = exer7-6.o ch7Code.o
OBJ7 = exer7-7.o ch7Code.o
OBJ8 = exer7-8.o ch7Code.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

all: exer7-1 exer7-2 exer7-3 exer7-4 cat exer7-6 exer7-7 exer7-8

exer7-1: $(OBJ1)
	$(CC) -o $@ $^ $(FLAGS)

exer7-2: $(OBJ2)
	$(CC) -o $@ $^ $(FLAGS)

exer7-3: $(OBJ3)
	$(CC) -o $@ $^ $(FLAGS)

exer7-4: $(OBJ4)
	$(CC) -o $@ $^ $(FLAGS)

exer7-6: $(OBJ6)
	$(CC) -o $@ $^ $(FLAGS)

exer7-7: $(OBJ7)
	$(CC) -o $@ $^ $(FLAGS)

exer7-8: $(OBJ8)
	$(CC) -o $@ $^ $(FLAGS)

cat: $(OBJ5)
	$(CC) -o $@ $^ $(FLAGS)

tags:
	@find . -name "*.[ch]" | xargs ctags -a

clean:
	@rm -f *.o
	@rm -rf *.dSYM tags
	@rm -f exer7-1 exer7-2 exer7-3 exer7-4 cat exer7-6 exer7-7
