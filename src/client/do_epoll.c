#include "./include/client.h"
#include "../../include/xftp.h"

int do_epoll(int sfd){
    int ret;

    int epfd = epoll_create(1); 
    ERROR_CHECK(epfd, -1, "epll_create");

    struct epoll_event event, evs[2];
    bzero(&event, sizeof(event));

    //1. 加入 socket id
    event.data.fd = sfd;
    event.events = EPOLLIN;
    ret = epoll_ctl(epfd, EPOLL_CTL_ADD, sfd, &event);
    ERROR_CHECK(ret, -1, "epoll_ctl ");

    //2. 加入 标准输入 
    event.data.fd = STDIN_FILENO;
    ret = epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &event);
    ERROR_CHECK(ret, -1, "epoll_ctl ");

    //3. 监听 
    for(;;){
        
        int readNum = epoll_wait(epfd, evs, 2, -1);
        for (int i = 0; i < readNum; i++){
            ret = deal_epoll_fd(evs[i].data.fd, sfd);  
            if(ret == -1){
                return -1;
            }
        }
    } 

    return 0;
}