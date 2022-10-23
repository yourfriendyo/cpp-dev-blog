mycode   : mycode.o
	gcc -o mycode      mycode.o
mycode.o : mycode.s
	gcc -o mycode.o -c mycode.s
mycode.s : mycode.i
	gcc -o mycode.s -S mycode.i
mycode.i : mycode.c
	gcc -o mycode.i -E mycode.c
.PHONY:clean
clean:
	rm -rf mycode.o mycode.s mycode.i
