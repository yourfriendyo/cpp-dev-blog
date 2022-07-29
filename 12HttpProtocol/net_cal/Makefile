all : HttpClient HttpServer

HttpClient:HttpClient.cc
	g++ -o $@ $^ -std=c++11

HttpServer:HttpServer.cc
	g++ -o $@ $^ -std=c++11 -lpthread

.PHONY:clean
clean:
	rm -f HttpClient HttpServer