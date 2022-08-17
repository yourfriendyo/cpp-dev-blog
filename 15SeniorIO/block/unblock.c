#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void SetNonBlock(int fd)
{
    int fl = fcntl(fd, F_GETFL);
    if (fl < 0)
    {
        perror("fcntl error\n");
        return;
    }

    fcntl(fd, F_SETFL, fl | O_NONBLOCK);
}

int main()
{
    SetNonBlock(0);

    char buffer[1024];
    while (1)
    {
        errno = 0;
        ssize_t s = read(0, buffer, sizeof(buffer) - 1);
        if (s > 0)
        {
            buffer[s] = 0;
            write(1, buffer, strlen(buffer));
            printf("read success, s: %ld, errno: %d\n", s, errno);
        }
        else {
            if (errno == EAGAIN || errno == EWOULDBLOCK)
            {
                printf("read failed, s: %ld, errno: %d\n", s, errno);
                // Try Again
            }
            else {
                printf("read error, s: %ld, errno: %d\n", s, errno);
            }
        }

        sleep(1);
    }

    return 0;
}
