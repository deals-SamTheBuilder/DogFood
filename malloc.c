/*************************************************************************
	> File Name: malloc.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月23日 星期四 21时29分39秒
 ************************************************************************/
/*
 *动态分配内存实例
 */

#include<stdio.h>
#include<stdlib.h>

void *MALLOC(size_t size)
{
    void *men;
    men=(void *)malloc(size);//类型指派可选
    if(men == NULL)
    {
        fprintf(stderr,"Malloc failed!\n");
        exit(1);
    }
    return men;
}

void FREE(void *men)
{
    free(men);
    men=NULL;
}

int main(void)
{
    int *array;

    array=(int *)MALLOC(8*sizeof(int));
    /*do sth*/
     FREE(array);
    
    return 0;
}
