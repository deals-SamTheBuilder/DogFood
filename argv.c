/*************************************************************************
	> File Name: argv.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月29日 星期三 15时26分00秒
 ************************************************************************/

/*
 *命令行参数实例
 */

#include<stdio.h>
#include<stdlib.h>

int main(int argc,const char *argv[])
{
    int i;

    if(argc<2)
    {
        fprintf(stderr,"Usage: ./a.out 1 2 3\n");
        exit(1);
    }

    for(i=0;argv[i]!=NULL;i++)
        printf("argv[%d]:%s\n",i,argv[i]);

    exit(0);
}
