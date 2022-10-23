#include <iostream>
#include <string>
#include <cstdlib>
#include <jsoncpp/json/json.h>
#include "Socket.hpp"
#include "Protocol.hpp"

using namespace NSTcpSocket;

void Usage(std::string proc) {
    std::cout << "Usage \n\t" << proc << "server_ip server_port" << std::endl;
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        Usage(argv[0]);
    }
    std::cout << "hello HttpClient" << std::endl;

    int sock = TcpSocket::Socket();
    TcpSocket::Connect(sock, argv[1], atoi(argv[2]));

    // while (true) {
    request_t req;
    std::cout << "Input the first data->";
    std::cin >> req.x;
    std::cout << "Input the second data->";
    std::cin >> req.y;
    std::cout << "Input the operator->";
    std::cin >> req.op;

    //序列化
    std::string enjson_string = SerializeRequest(req);
    TcpSocket::Send(sock, enjson_string);

    //反序列化
    response_t resp;
    std::string buffer;
    if (TcpSocket::Recv(sock, buffer)) {
        DeserializeResponse(buffer, resp);
        std::cout << "status[0:success]:" << resp.status << " result:" << resp.result << std::endl;
    }

    // }
    return 0;
}