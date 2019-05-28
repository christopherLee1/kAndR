SHELL := /bin/bash
CC = gcc-6
FLAGS = 
DEPS = ch8Code.h my_stdio.h malloc.h
OBJ1 = cp.o ch8Code.o
OBJ2 = exer8-1.o ch8Code.o
OBJ3 = exer8-3.o ch8Code.o
OBJ4 = exer8-4.o ch8Code.o
OBJ5 = exer8-5.o ch8Code.o
OBJ6 = exer8-6.o ch8Code.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

all: cp exer8-1 tags exer8-3 exer8-4 exer8-5 exer8-6

exer8-6: $(OBJ6)
	$(CC) -o $@ $^ $(FLAGS)

exer8-5: $(OBJ5)
	$(CC) -o $@ $^ $(FLAGS)

exer8-3: $(OBJ3)
	$(CC) -o $@ $^ $(FLAGS)

exer8-4: $(OBJ4)
	$(CC) -o $@ $^ $(FLAGS)

cp: $(OBJ1)
	$(CC) -o $@ $^ $(FLAGS)

exer8-1: $(OBJ2)
	$(CC) -o $@ $^ $(FLAGS)

tags:
	@find . -name "*.[ch]" | xargs ctags -a

clean:
	@rm -f *.o
	@rm -rf *.dSYM tags
	@rm -f cp exer8-1 exer8-3 exer8-4
