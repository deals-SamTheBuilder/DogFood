/*************************************************************************
	> File Name: generics.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Sat 08 Oct 2016 05:40:48 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>

#define ERROR_LEN 255

static void error(char *err_buf,const char *fmt,...);

static void error(char *err_buf,const char *fmt,...)
{
    //assert(err_buf);
    if ( err_buf == NULL )
        return;

    va_list ap;

    va_start(ap,fmt); // 指向可变参数的首地址

    vsnprintf(err_buf,ERROR_LEN,fmt,ap);

    va_end(ap);
}

int main()
{
    char buf[ERROR_LEN] = {0};

    error(buf,"This is test %s function","error");

    printf("%s\n",buf);

    return 0;
}
