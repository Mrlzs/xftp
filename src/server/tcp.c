#include "../../include/xftp.h"

int initTcp(int *sfd, char *host, int port){
    int ret = 0;

    //1. socket 
    *sfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(*sfd, -1, "server socket.");

    //2. bind 

    struct sockaddr_in serAddr;
    bzero(&serAddr, sizeof(serAddr));
    
    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr(host);
    serAddr.sin_port = htons(port);
    
    ret = bind(*sfd, (struct sockaddr *) &serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "server bind");


    // 3. lisiten 
    ret = listen(*sfd, 10);

    return 0;
}