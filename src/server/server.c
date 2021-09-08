#include "../../include/xftp.h"
#include "./include/server.h"




int main(int argc, char *argv[]){

    ARGS_CHECK(argc, 3);

    int sfd;
    initTcp(&sfd, argv[1], atoi(argv[2])); 

    ser_do_epoll(sfd);


    return 0;
}
