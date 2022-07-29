all : CalClient CalServer

CalClient : CalClient.cc
	g++ -o $@ $^ -std=c++11

CalServer : CalServer.cc
	g++ -o $@ $^ -std=c++11 -lpthread

.PHONY : clean
clean:
	rm -f CalClient CalServer