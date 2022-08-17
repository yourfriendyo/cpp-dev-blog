#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <sys/select.h>
#include <sys/types.h>
#include "Socket.hpp"

using namespace NSTcpSocket;

static void Usage(std::string proc) {
    std::cout << "Usage: \n\t" << proc << " port" << std::endl;
    exit(1);
}
