/*************************************************************************
	> File Name: generics.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Sat 08 Oct 2016 05:40:48 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdarg.h>
#include<sys/socket.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>

#define XXX_API static
#define XXX_ERROR -1
#define XXX_OK 0

#define ERROR_LEN 255

XXX_API void xxx_handle_error(char *error,const char *fmt,...);
XXX_API int xxx_net_listen(char *error,int fd,int backlog);

/* 具体项目应用可以替换为log库 */
XXX_API void xxx_handle_error(char *error,const char *fmt,...)
{
    //assert(err_buf);
    if ( error == NULL )
        return;

    va_list ap;

    va_start(ap,fmt); // 指向可变参数的首地址

    vsnprintf(error,ERROR_LEN,fmt,ap); // 存入err_buf

    va_end(ap);
    
    printf("%s\n",error);
}

XXX_API int xxx_net_listen(char *error,int fd,int backlog)
{
    /* Use a backlog of 512 entries. We pass 511 to the listen() call because
     * the kernel does: backlogsize = roundup_pow_of_two(backlogsize + 1);
     * which will thus give us a backlog of 512 entries. */

    if(listen(fd,backlog) != 0) //backlog default is 32.
    {
        xxx_handle_error(error,"listen: %s",strerror(errno)); // perror 只保存上一个errno,有可能打印时已更新
        close(fd);
        return XXX_ERROR;
    }

    return XXX_OK;
}

int main()
{
    /* test xxx_handle_error */
    char buf[ERROR_LEN] = {0};
    xxx_handle_error(buf,"This is test %s function","error");

    return 0;
}
