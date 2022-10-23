libmath.a : add.o sub.o
	ar -rc $@ $^
%.o : ./src/%.c 
	gcc -c $<

.PHONY:output
output:
	mkdir output 
	cp -rf libmath.a output/
	cp -rf  src/*.h output/

.PHONY:clean
clean:
	rm -rf libmath.a *.o output

