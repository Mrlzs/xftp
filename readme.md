
项目：项目上传和下载工具

整个过程利用TCP/IP协议来保证信息的完整可靠性

功能：
1. 客户端可以进行文件的下载 

服务端(S):
1. 利用进程池，可以支持多个用户同时访问
2. 每个进程可以对一个用户进行服务

客户端(C)：
1. 通过传输文件名来下载文件 