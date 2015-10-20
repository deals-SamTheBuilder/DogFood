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
#include<string.h>

/*
 * 方法一：使用malloc
 */
void *MALLOC(size_t size)
{
    void *men;
    men = (void *)malloc(size);//类型指派可选
    if(men == NULL)
    {
        fprintf(stderr,"Malloc failed!\n");
        exit(1);
    }
    
    memset(men,'\0',size);

    return men;
}

/*
 * 方法二：使用calloc
 */
void *CALLOC(size_t n,size_t size)
{
    void *men;
    men = (void *)calloc(n,size);//类型指派可选
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
    men = NULL;
}

int main(void)
{
    int *array;
    char *str;
    
    array = (int *)MALLOC(8*sizeof(int));
    str = (char *)CALLOC(8,sizeof(char));
    
    /*do sth*/
    FREE(array);
    FREE(str);

    return 0;
}
