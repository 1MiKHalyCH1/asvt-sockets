#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "arm_socket.h"

int PORT = 4444;
char IP[] = "localhost";
const char* message = "Hello, client!";
char buffer[1000];

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

    int enable = 1;
    arm_setsockopt(sock, ARM_SOL_SOCKET, ARM_SO_REUSEADDR, &enable, sizeof(enable));

    if (arm_bind(sock, (struct arm_sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("Can't bind!\n");
        exit(2);
    }

    arm_listen(sock, 1);

    printf("Ready!\n");
    
    int client, bytes_read;
    while(1) {
        if((client = accept(sock, NULL, NULL)) < 0) {
            printf("Bad client!\n");
            close(sock);
            exit(3);
        }

        while(1) {
            bytes_read = arm_recv(client, buffer, sizeof(buffer), 0);
            if (bytes_read <= 0) break;
            printf("%s (%i bytes)\n", buffer, bytes_read);
            memset(buffer, 0, sizeof(buffer));
            arm_send(client, message, strlen(message), 0);
        }
        close(client);
    }

    return 0;
}