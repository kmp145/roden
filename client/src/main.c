#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main (){


    int sockfd = 0, portNumber = 9999;
    char recvBuffer[1024], *IPAddress;
    IPAddress = malloc(sizeof(char)*17);
    struct sockaddr_in servAddr;

    memset(recvBuffer, '0', sizeof(recvBuffer)); //flush recvBuffer
    strcpy("192.168.0.12", IPAddress);
    if((sockfd = socket(AF_INET, SOCK_STREAM,0)) < 0){
        fprintf(stdout, "Could not create socket...\nExiting...\n\n");
        return 1;
      }

    fprintf (stdout,"Socket successfully created!\n");

    memset(&servAddr, '0', sizeof(servAddr));//flush servAddr

    //setting up servAddr
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(portNumber);
    if(inet_pton(AF_INET, IPAddress, &servAddr.sin_addr) <=0){
        fprintf(stdout, "inet_pton error...\nExiting...\n");
        return 1;
    }


    fprintf(stdout, "hello world!\n");
    return 0;
}
