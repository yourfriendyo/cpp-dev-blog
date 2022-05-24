libmath.so : add.o sub.o
	gcc -shared -o $@ $^ # -shared 共享库也就是动态库 
%.o : ./src/%.c 
	gcc -fPIC -c $< # 目标文件与位置无关

.PHONY:output
output:
	mkdir output 
	cp -rf libmath.so output/
	cp -rf  src/*.h output/

.PHONY:clean
clean:
	rm -rf libmath.so *.o output

