#include "../../include/xftp.h"


int deal_epoll_fd(int epoll_fd, int sfd){
    char buf[512] = {0};
    int ret = 0;
    //1. STDIN_FILENO
    if(STDIN_FILENO == epoll_fd){

        bzero(buf, sizeof(buf));

        ret = read(STDIN_FILENO, buf, sizeof(buf) - 1);
        ERROR_CHECK(ret, -1, "read");

        if(0 == ret){
            fprintf(stderr, "user is actively leaving.");
            return 0;    
        }
        send(sfd, buf, ret, 0);
    }

    //2. sfd

    if(sfd == epoll_fd){

        bzero(buf, sizeof(buf));

        ret = recv(sfd, buf, sizeof(buf) - 1, 0); 
        ERROR_CHECK(ret, -1, "recv");
        
        if(ret == 0){
            fprintf(stderr, "the server is leaving..\n");
            return -1;   
        }
        printf("the msg from server is %s", buf);
    } 
}
