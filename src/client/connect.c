
#include "../../include/xftp.h"


int connectTcp(int *sfd, char *host, int port){
    int ret = 0;

    // 1. socket 
    *sfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(*sfd, -1, "client socket");
    
    //2. connect 

    struct sockaddr_in clientAddr;
    bzero(&clientAddr, sizeof(clientAddr));
    
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_addr.s_addr = inet_addr(host);
    clientAddr.sin_port = htons(port);

    ret = connect(*sfd, (struct sockaddr *) &clientAddr, sizeof(clientAddr));
    ERROR_CHECK(ret, -1, "connect");
    
    return 0;
}