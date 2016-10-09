/*************************************************************************
	> File Name: generics.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Sat 08 Oct 2016 05:40:48 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>

#define XXX_NET static
#define ERROR -1

#define ERROR_LEN 255

XXX_NET void handle_error(char *error,const char *fmt,...);

XXX_NET void handle_error(char *error,const char *fmt,...)
{
    //assert(err_buf);
    if ( error == NULL )
        return;

    va_list ap;

    va_start(ap,fmt); // 指向可变参数的首地址

    vsnprintf(error,ERROR_LEN,fmt,ap); // 存入err_buf

    va_end(ap);
}

int main()
{
    char buf[ERROR_LEN] = {0};

    handle_error(buf,"This is test %s function","error");

    printf("%s\n",buf);

    return 0;
}
