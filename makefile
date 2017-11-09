all: hw10.c
	gcc hw10.c
run: all
	./a.out
clean: 
	rm msgs
	rm *~
