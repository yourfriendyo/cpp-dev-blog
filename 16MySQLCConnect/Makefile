mysql_test:mysql_test.cc
	g++ -o $@ $^ -lmysqlclient -L/usr/lib64/mysql -std=c++11
.PHONY:clean
clean:
	rm -f mysql_test
