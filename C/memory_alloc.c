/*************************************************************************
	> File Name: memory_application.c
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
    void *mem;
    mem = (void *)malloc(size);//类型指派可选
    if(mem == NULL)
    {
        fprintf(stderr,"MALLOC failed!\n");
        exit(EXIT_FAILURE);
    }
    
    //memset(men,'\0',size);
    memset(mem,0x00,size);

    return mem;
}

/*
 * 方法二：使用calloc
 */
void *CALLOC(size_t n,size_t size)
{
    void *mem;
    mem = (void *)calloc(n,size);//类型指派可选
    if(mem == NULL)
    {
        fprintf(stderr,"CALLOC failed!\n");
        exit(EXIT_FAILURE);
    }
    
    return mem;
}

void *REALLOC(void *mem,size_t new_size)
{
	void *tmp_mem = realloc(mem, new_size);
	if (tmp_mem == NULL)
	{
		fprintf(stderr,"REALLOC failed!\n");
		exit(EXIT_FAILURE);
	}
	mem = tmp_mem;

	return mem;
}

void FREE(void *mem)
{
    free(mem);
    mem = NULL;
}

int main(void)
{
    int *array;
    char *str;
    
    array = (int *)MALLOC(8*sizeof(int));
    str = (char *)CALLOC(8,sizeof(char));
    
    str = (char *)REALLOC(str,20*sizeof(char));

    FREE(array);
    FREE(str);

    return 0;
}
