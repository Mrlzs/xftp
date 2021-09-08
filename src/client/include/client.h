
int connectTcp(int *sfd, char *host, int port);
int deal_epoll_fd(int epoll_fd, int sfd);
int do_epoll(int sfd);