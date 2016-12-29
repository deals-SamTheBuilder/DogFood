/*************************************************************************
	> File Name: bt.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Mon 12 Dec 2016 03:59:26 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>

/* stack's max depth to print */
#define DUMP_STACK_DEPTH_MAX 100

/* print stack */
void print_trace()
{
    void *array[DUMP_STACK_DEPTH_MAX] = {0};
    char **strings = NULL;
    size_t depth = 0;
    size_t i = 0;

    /* get function address from stack */
    depth = backtrace(array,DUMP_STACK_DEPTH_MAX);

    /* address transform to information to print */
    strings = (char **)backtrace_symbols(array,depth);//auto malloc
    if (NULL == strings)
    {
        perror("backtrace_symbols");
        exit(EXIT_FAILURE);
    }

    /* print */
    printf("Obtained %zd stack frames.\n",depth);
    for(i = 0;i < depth;i++)
    {
        printf("%p : %s \n",array[i],strings[i]);
    } 

    free(strings);
    strings = NULL;
}
