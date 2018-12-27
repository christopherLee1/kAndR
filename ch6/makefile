SHELL := /bin/bash
CC = gcc-6
FLAGS = 
DEPS = ch6Code.h
OBJ1 = exer6-1.o ch6Code.o
OBJ2 = exer6-2.o ch6Code.o
OBJ3 = exer6-3.o ch6Code.o
OBJ4 = exer6-4.o ch6Code.o
OBJ5 = exer6-5.o ch6Code.o
OBJ6 = exer6-6.o ch6Code.o
OBJFREQ = wordFreq.o ch6Code.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

all: exer6-1 exer6-2 exer6-3 exer6-4 exer6-5 exer6-6 wordFreq tags

exer6-1: $(OBJ1)
	$(CC) -o $@ $^ $(FLAGS)

exer6-2: $(OBJ2)
	$(CC) -o $@ $^ $(FLAGS)

exer6-3: $(OBJ3)
	$(CC) -o $@ $^ $(FLAGS)

exer6-4: $(OBJ4)
	$(CC) -o $@ $^ $(FLAGS)

exer6-5: $(OBJ5)
	$(CC) -o $@ $^ $(FLAGS)

exer6-6: $(OBJ6)
	$(CC) -o $@ $^ $(FLAGS)

wordFreq: $(OBJFREQ)
	$(CC) -o $@ $^ $(FLAGS)

test: all
	@cat test.txt | ./exer6-1
	@printf "result should be 1\n"

tags:
	@find . -name "*.[ch]" | xargs ctags -a

clean:
	@rm -f *.o
	@rm -f exer6-1 ch6Code exer6-2 wordFreq
	@rm -rf *.dSYM tags
