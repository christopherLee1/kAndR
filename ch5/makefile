CC = gcc-6
FLAGS = 
DEPS = ch5Code.h
OBJ13 = exer5-13.o ch5Code.o
OBJ14 = exer5-14.o ch5Code.o
OBJ15 = exer5-15.o ch5Code.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

all: exer5-13 exer5-14 exer5-15

exer5-15: $(OBJ15)
	$(CC) -o $@ $^ $(FLAGS)

exer5-14: $(OBJ14)
	$(CC) -o $@ $^ $(FLAGS)

exer5-13: $(OBJ13)
	$(CC) -o $@ $^ $(FLAGS)

clean:
	@rm *.o
	@rm -rf *.dSYM
