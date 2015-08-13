/*************************************************************************
	> File Name: client.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年08月13日 星期四 10时57分50秒
 ************************************************************************/

/*
 * This is my client  
 */

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
#include<strings.h>
#include<unistd.h>
#include<arpa/inet.h>

#define PORT 8000
#define MAXSLEEP 128

/*
 * debug log function
 */
#define DEBUG_PRINT 1
#if defined(DEBUG_PRINT)
#define DEBUG(...)\
        do{\
           fprintf(stderr,"-----DEBUG-----\n");\
           fprintf(stderr,"%s,%s\n",__TIME__,__DATE__);\
           fprintf(stderr,"%s:%d:%s():",__FILE__,__LINE__,__func__);\
           fprintf(stderr,__VA_ARGS__);\
        }while(0)
#endif

static int fd,ret;
static struct sockaddr_in servaddr;

int client_init(int port ,const char *ip)
{
    int sockfd,ret;

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd < 0)
    {
        perror("clinet socket error");
        return -1;
    }

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port=htons(port);
    ret = inet_pton(AF_INET,ip,&servaddr.sin_addr);
    if(ret != 1)
    {
        DEBUG("<IPAddress>:xxx.xxx.xxx.xxx\n");
        return -2;
    }

    return sockfd;
}

int imb_heartbeat(int fd)
{
    int alive,error,idle,cnt,intv;

    /*
     * open keepalive on fd
     */
    Restart:
    alive = 1;//set keepalive open
    ret=setsockopt(fd,SOL_SOCKET,SO_KEEPALIVE,&alive,sizeof(alive));
    if(ret < 0)
    {
        DEBUG("set socket option error.\n");
        goto Restart;
    }
    
    /*
     * 60S without data,send heartbeat package
     */
    idle = 30;
    ret = setsockopt(fd,SOL_TCP,TCP_KEEPIDLE,&idle,sizeof(idle));
    if(ret < 0)
    {
        DEBUG("set keepalive idle error.\n");
        return -1;
    }

    /*
     * without any respond,3m later resend package
     */
    intv = 180;
    ret = setsockopt(fd,SOL_TCP,TCP_KEEPINTVL,&intv,sizeof(intv));
    if(ret < 0)
    {
        DEBUG("set keepalive intv error.\n");
        return -2;
    }

    /*
     * send 5 times,without any response,mean connect lose 
     */
    cnt = 5;
    ret = setsockopt(fd,SOL_TCP,TCP_KEEPCNT,&cnt,sizeof(cnt));
    if(ret < 0)
    {
        DEBUG("set keepalive cnt error.\n");
        return -3;
    }
}

 int imb_connect(int sockfd,const struct sockaddr *servaddr,socklen_t addrlen)
{
    int nsec;
    for(nsec = 1;nsec <= MAXSLEEP;nsec <<= 1)
    {
        if(connect(sockfd,servaddr,addrlen) == 0)
            return 0;//connection accepted
        if(nsec <= MAXSLEEP/2)//sleep nesc,then connect retry
            sleep(nsec);
    }
    return -1;
}

int main(int argc,const char *argv[])
{
    
    if(argc != 2)
    {
        DEBUG("Usage: run <IPAdress>\n");
        exit(1);
    }

    /*
     * socket communication
     */
    fd = client_init(PORT,argv[1]);
    if(fd < 0)
    {
        DEBUG("client_init error.\n");
        exit(2);
    }

    ret = imb_connect(fd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    if(ret < 0)
    {
        DEBUG("connect error.\n");
        exit(3);
    }

    ret = imb_heartbeat(fd);
    if(ret < 0)
    {
        DEBUG("heartbeat error.\n");
        exit(4);
    }

    while(1)
    {
        //do sth
    }

    close(fd);

    return 0;
}
