#include "../../include/xftp.h"
#include "./include/client.h"


int main(int argc, char *argv[]){

    ARGS_CHECK(argc, 3);

    int sfd;
    connectTcp(&sfd, argv[1], atoi(argv[2]));
    
    do_epoll(sfd);
    

    return 0;
}