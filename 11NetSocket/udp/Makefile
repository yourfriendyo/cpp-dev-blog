all: UdpServer UdpClient

UdpClient: UdpClient.cc
	g++ -o $@ $^ -std=c++11
	
UdpServer: UdpServer.cc
	g++ -o $@ $^ -std=c++11 -g

.PHONY: clean
clean:
	rm -f UdpServer UdpClient
