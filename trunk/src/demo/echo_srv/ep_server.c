/* epoll echo server demo */
/* 
   客户端连接 telnet 1235 , 
   退出 客户端发送: q 回车
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>


#define ECHO_MAX_IN     1024 /* 最大不能超过1024 个字节 */
#define ECHO_PORT       1235
#define ECHO_LITSTEN_QUEUE 20

/* 将socket 设置为noblocking */
inline int nonblocking(int fd)
{
    int nb;
    nb = 1;
    return ioctl(fd, FIONBIO, &nb);
}

/* 主程序 */
int main()
{
    int srvfd, cnnfd;
    int epfd, nfds;
    char buf[ECHO_MAX_IN];
    
    struct sockaddr_in srvaddr;
    struct sockaddr_in cnnaddr;
    struct epoll_event ev,events[ECHO_LITSTEN_QUEUE];
    socklen_t clilen = sizeof cnnaddr;
    
    srvfd = socket(AF_INET, SOCK_STREAM, 0);

    if ( -1 == srvfd) {
        perror("socket error\n");
        exit(1);
    }
    
    if (nonblocking(srvfd) == - 1) {
        perror("nonblocking srvfd error\n");
        exit(1);
    }

    memset(&srvaddr, 0, sizeof(struct sockaddr_in));
    srvaddr.sin_family  = AF_INET;
    srvaddr.sin_port    = htons(ECHO_PORT);
    srvaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(srvfd, (struct sockaddr*) &srvaddr, sizeof (struct sockaddr)) == -1){
       perror("bind error\n"); 
       exit(1);
    }

    if (listen(srvfd, ECHO_LITSTEN_QUEUE) == -1){
        perror("listen error\n");
        exit(1);
    }

    memset(&ev, 0, sizeof(struct epoll_event));
    epfd = epoll_create ( ECHO_LITSTEN_QUEUE );
    ev.data.fd = srvfd;
    ev.events  = EPOLLIN|EPOLLET;
    epoll_ctl(epfd, EPOLL_CTL_ADD, srvfd, &ev);

    // 主循环 
    for(;;) {
        int i;
        int n = 0; 
        nfds = epoll_wait(epfd, events, ECHO_LITSTEN_QUEUE, 500);
        for(i = 0; i < nfds; i++){
            if (events[i].data.fd == srvfd) {  /* 监听到有新的客户端连接进入 */ 
                if ((cnnfd = accept(srvfd, (struct sockaddr*) &cnnaddr, &clilen))<0) {
                    perror("cnnfd accept error\n");
                    exit(1);
                }
                nonblocking(cnnfd);
                // printf ("get connection from %s; cnnfd is %d\n", inet_ntoa(cnnaddr.sin_addr), cnnfd);
                ev.data.fd = cnnfd;
                ev.events = EPOLLIN|EPOLLET;
                epoll_ctl(epfd, EPOLL_CTL_ADD, cnnfd, &ev);
            } else if (events[i].events & EPOLLIN) { /* 粗略的认为不是主监听请求的EPOLLIN请求就是用户数据输入*/
                if ((cnnfd = events[i].data.fd) < 0 ) continue;
                memset(buf, 0, sizeof(buf));
                if (n = read(cnnfd, buf, ECHO_MAX_IN)) {
                    if ( errno == ECONNRESET ) {
                        close(cnnfd);
                        events[i].data.fd = -1;
                    } else if ( n == 0)  {
                        close(cnnfd);
                        events[i].data.fd = -1;
                    }
                    else {
                        //printf ("buf is [%s], strlen buf is [%d]\n", buf, strlen(buf));
                    }
                    write(cnnfd, buf, n);
                    // 按Q退出程序  q ENTER
                    if ( buf[0] == 'q' && (buf[1] == 10 || buf[1] == 13) ) {
                        epoll_ctl( epfd, EPOLL_CTL_DEL, cnnfd, &ev);
                        close(cnnfd);
                        goto quit;
                    }
                    /*
                    // 将客户端连接的fd设置为写操作的fd 
                    ev.data.fd = cnnfd;
                    ev.events  = EPOLLOUT|EPOLLET;
                    epoll_ctl(epfd, EPOLL_CTL_MOD, cnnfd, &ev);
                } else if (events[i].events & EPOLLOUT) {
                    cnnfd = events[i].data.fd;
                    write (cnnfd, buf, n);
                    //ev.data.fd =cnnfd;
                    // ev.events = EPOLLIN|EPOLLET;
                    //epoll_ctl(epfd, EPOLL_CTL_MOD, cnnfd, &ev);
                    */
                }

            }
            
        }
    }

    quit: 
        close( srvfd );
    return 0;
}



