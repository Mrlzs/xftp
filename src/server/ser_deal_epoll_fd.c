#include "../../include/xftp.h"


int ser_deal_epoll_fd(int epoll_fd, int sfd, int epfd, int *newFd){
    char buf[512] = {0};
    int ret = 0;
    //1. STDIN_FILENO
    if(STDIN_FILENO == epoll_fd){
        
        bzero(buf, sizeof(buf));

        ret = read(STDIN_FILENO, buf, sizeof(buf) - 1);
        ERROR_CHECK(ret, -1, "read");

        if(0 == ret){
            fprintf(stderr, "user is actively leaving.\n");
            return 0;    
        }
        if(-1 != (*newFd) )
            send(*newFd, buf, ret, 0);
        
    }

    //2. sfd
    if(sfd == epoll_fd){
        
        struct sockaddr_in addr; 
        socklen_t sockLen;
        *newFd = accept(sfd, (struct sockaddr *)&addr , &sockLen);
        ERROR_CHECK(*newFd, -1, "accept");

        struct epoll_event en;
        en.data.fd = *newFd;
        en.events = EPOLLIN;
        ret = epoll_ctl(epfd, EPOLL_CTL_ADD, *newFd, &en);
        ERROR_CHECK(ret, -1, "epoll_ctl");
    } 
    // 3. newFd 
    if(epoll_fd == *newFd){
        
        ret = recv(*newFd, buf, sizeof(buf) - 1, 0);
        ERROR_CHECK(ret, -1, "recv");
        
        if(ret == 0){
            fprintf(stderr, "the client is leaving..\n");

            struct epoll_event en;
            en.data.fd = *newFd;
            
            int ret1 = epoll_ctl(epfd, EPOLL_CTL_DEL, *newFd, &en);
            ERROR_CHECK(ret1, -1, "epoll_ctl");
            *newFd = -1;
            return 0;
        }
        printf("the msg from client is %s", buf);
    }
    return 0;
}