#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ustat.h>
#include <fcntl.h> /* Definition of AT_* constants */
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <sys/epoll.h> 
#include <sys/types.h>
#define ARGS_CHECK(argv, n)               \
    {                                     \
        if ((argv) != (n))                \
        {                                 \
            puts("argv is not correct."); \
            return -1;                    \
        }                                 \
    }
#define ERROR_CHECK(var, val, msg) \
    {                              \
        if ((var) == (val))        \
        {                          \
            perror(msg);           \
            return -1;             \
        }                          \
    }
