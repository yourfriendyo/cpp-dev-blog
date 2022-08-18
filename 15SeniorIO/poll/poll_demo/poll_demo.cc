#include <iostream>
#include <cstring>
#include <unistd.h>
#include <poll.h>

int main()
{
    struct pollfd rfds;
    rfds.fd = 0;
    rfds.events = POLLIN;
    rfds.revents = 0;

    while (1)
    {
        int n = poll(&rfds, 1, 1000);
        if (n < 0) {
            std::cerr << "poll error" << std::endl;
        }
        else if (n == 0) {
            std::cout << "remote close" << std::endl;
        }
        else {
            if (rfds.revents & POLLIN) {
                char buffer[128];
                size_t s = read(0, buffer, sizeof(buffer));
                if (s > 0) {
                    buffer[s] = 0;
                    std::cout << "client# " << buffer << std::endl;
                }
                write(1, buffer, strlen(buffer));
            }
        }
    }
    return 0;
}
