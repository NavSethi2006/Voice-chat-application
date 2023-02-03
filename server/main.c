#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

int server_sock;
int client_sock;
int client_size;

struct sockaddr_in server_addr;
struct sockaddr_in client_addr;

char ip[INET_ADDRSTRLEN];

pthread_t server_thread;

int main()
{

    // Define server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    // makes sure no error
    if (server_sock < 0)
    {
        printf("[-]COULD NOT START SERVER\n");
        exit(1);
    }
    printf("[+]SERVER STARTED...\n");
    // type of connection
    server_addr.sin_family = AF_INET;
    // port
    server_addr.sin_port = htons(PORT);
    // define which machine
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if ((bind(server_sock,
              (struct sockaddr *)&server_addr,
              sizeof(server_addr))) < 0)
    {
        printf("[-]COULD NOT BIND TO SERVER\n");
        exit(1);
    }

    if ((listen(server_sock, 1)) < 0)
    {
        printf("[-]COULD NOT FIND CLIENT\n");
        exit(1);
    }

    printf("[+]FINDING CLIENTS...\n");

    inet_ntop(AF_INET, &(server_addr.sin_addr), ip, INET_ADDRSTRLEN);

    while (1)
    {

        client_size = sizeof(client_addr);
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, (socklen_t *)&client_size)) < 0)
        {
            printf("cant reach client\n");
            exit(1);
        }

        printf("[+] CLIENT ACCEPTED AT IP : %s,\n PORT : %d,\n SIZEOF : %d\n",
               ip,
               client_addr.sin_port,
               client_size);
    }
}