#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "arm_socket.h"

int PORT = 4444;
char IP[] = "10.42.0.10";
const char* message = "Hello, server!";
char buffer[100];

int main() 
{
    int sock;
    if ((sock = arm_socket(ARM_AF_INET, ARM_SOCK_STREAM, 0)) < 0) {
        printf("Can't create socket!\n");
        exit(1);
    }

    struct arm_sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
    addr.sin_family = ARM_AF_INET;
    addr.sin_port = htons(PORT);
	inet_pton(ARM_AF_INET, IP, &addr.sin_addr);

    if (arm_connect(sock, (struct arm_sockaddr*) &addr, sizeof(addr)) < 0) {
        printf("Can't connect!\n");
        exit(2);
    }

    arm_send(sock, message, strlen(message), 0);
    arm_recv(sock, buffer, sizeof(buffer), 0);

    printf("%s\n", buffer);
    close(sock);

    return 0;
}