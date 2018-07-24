SHELL := /bin/bash
CC = gcc-6
FLAGS = 
DEPS = ch5Code.h
OBJ13 = exer5-13.o ch5Code.o
OBJ14 = exer5-14.o ch5Code.o
OBJ15 = exer5-15.o ch5Code.o
OBJ16 = exer5-16.o ch5Code.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

all: exer5-13 exer5-14 exer5-15 exer5-16

test: test15 test16

test15:
	@echo "diff (gsort -n sort3.txt) (cat sort3.txt | ./exer5-16 -n)";\
	diff <(gsort -n sort3.txt) <(cat sort3.txt | ./exer5-16 -n) &> /dev/null;\
	if [[ $$? -ne "0" ]]; then\
       pr -mt <(gsort -n sort3.txt) <(cat sort3.txt | ./exer5-16 -n); \
    fi
	
	@echo "diff (gsort -nr sort3.txt) (cat sort3.txt | ./exer5-16 -nr)";\
	diff <(gsort -nr sort3.txt) <(cat sort3.txt | ./exer5-16 -nr) &> /dev/null;\
	if [[ $$? -ne 0 ]]; then\
       pr -mt <(gsort -nr sort3.txt) <(cat sort3.txt | ./exer5-16 -nr); \
    fi
	
	@echo "diff (gsort -n sort2.txt) (cat sort2.txt | ./exer5-16 -n)";\
	diff <(gsort -n sort2.txt) <(cat sort2.txt | ./exer5-16 -n) &> /dev/null;\
	if [[ $$? -ne 0 ]]; then\
       pr -mt <(gsort -n sort2.txt) <(cat sort2.txt | ./exer5-16 -n); \
    fi
	
	@echo "diff (gsort -nr sort2.txt) (cat sort2.txt | ./exer5-16 -nr)";\
	diff <(gsort -nr sort2.txt) <(cat sort2.txt | ./exer5-16 -nr) &> /dev/null;\
	if [[ $$? -ne 0 ]]; then\
       pr -mt <(gsort -nr sort2.txt) <(cat sort2.txt | ./exer5-16 -nr); \
    fi
	
	@echo "diff (gsort -n sort.txt) (cat sort.txt | ./exer5-16 -n)";\
	diff <(gsort -n sort.txt) <(cat sort.txt | ./exer5-16 -n) &> /dev/null;\
	if [[ $$? -ne 0 ]]; then\
       pr -mt <(gsort -n sort.txt) <(cat sort.txt | ./exer5-16 -n); \
    fi
	
	@echo "diff (gsort -nr sort.txt) (cat sort.txt | ./exer5-16 -nr)";\
	diff <(gsort -nr sort.txt) <(cat sort.txt | ./exer5-16 -nr) &> /dev/null;\
	if [[ $$? -ne 0 ]]; then\
	    pr -mt <(gsort -nr sort.txt) <(cat sort.txt | ./exer5-16 -nr); \
	fi

test16:
	@echo "diff (gsort -d sort3.txt) (cat sort3.txt | ./exer5-16 -d)";\
	diff <(gsort -d sort3.txt) <(cat sort3.txt | ./exer5-16 -d) &> /dev/null;\
	if [[ $$? -ne "0" ]]; then\
       pr -mt <(gsort -d sort3.txt) <(cat sort3.txt | ./exer5-16 -d); \
    fi
	
	@echo "diff (gsort -dr sort3.txt) (cat sort3.txt | ./exer5-16 -dr)";\
	diff <(gsort -dr sort3.txt) <(cat sort3.txt | ./exer5-16 -dr) &> /dev/null;\
	if [[ $$? -ne 0 ]]; then\
       pr -mt <(gsort -dr sort3.txt) <(cat sort3.txt | ./exer5-16 -dr); \
    fi
	
	@echo "diff (gsort -d sort2.txt) (cat sort2.txt | ./exer5-16 -d)";\
	diff <(gsort -d sort2.txt) <(cat sort2.txt | ./exer5-16 -d) &> /dev/null;\
	if [[ $$? -ne 0 ]]; then\
       pr -mt <(gsort -d sort2.txt) <(cat sort2.txt | ./exer5-16 -d); \
    fi
	
	@echo "diff (gsort -dr sort2.txt) (cat sort2.txt | ./exer5-16 -dr)";\
	diff <(gsort -dr sort2.txt) <(cat sort2.txt | ./exer5-16 -dr) &> /dev/null;\
	if [[ $$? -ne 0 ]]; then\
       pr -mt <(gsort -dr sort2.txt) <(cat sort2.txt | ./exer5-16 -dr); \
    fi
	
	@echo "diff (gsort -d sort.txt) (cat sort.txt | ./exer5-16 -d)";\
	diff <(gsort -d sort.txt) <(cat sort.txt | ./exer5-16 -d) &> /dev/null;\
	if [[ $$? -ne 0 ]]; then\
       pr -mt <(gsort -d sort.txt) <(cat sort.txt | ./exer5-16 -d); \
    fi
	
	@echo "diff (gsort -dr sort.txt) (cat sort.txt | ./exer5-16 -dr)";\
	diff <(gsort -dr sort.txt) <(cat sort.txt | ./exer5-16 -dr) &> /dev/null;\
	if [[ $$? -ne 0 ]]; then\
       pr -mt <(gsort -dr sort.txt) <(cat sort.txt | ./exer5-16 -dr); \
    fi
	

exer5-16: $(OBJ16)
	$(CC) -o $@ $^ $(FLAGS)

exer5-15: $(OBJ15)
	$(CC) -o $@ $^ $(FLAGS)

exer5-14: $(OBJ14)
	$(CC) -o $@ $^ $(FLAGS)

exer5-13: $(OBJ13)
	$(CC) -o $@ $^ $(FLAGS)

clean:
	@rm *.o
	@rm -rf *.dSYM
