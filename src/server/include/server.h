
int initTcp(int *sfd, char *host, int port);
int ser_deal_epoll_fd(int epoll_fd, int sfd, int epfd, int *newFd);
int ser_do_epoll(int sfd);