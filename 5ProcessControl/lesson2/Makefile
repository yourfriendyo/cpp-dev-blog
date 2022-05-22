.PHONY:all
all : myexe myload
	
myexe : myexe.c
	gcc -o $@ $^ -std=c99
myload : myload.c
	gcc -o $@ $^ -std=c99
.PHONY:clean
clean:
	rm -rf myexe myload
