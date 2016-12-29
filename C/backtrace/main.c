/*************************************************************************
	> File Name: main.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Wed 28 Dec 2016 04:11:45 PM CST
 ************************************************************************/

#include <stdio.h>
#include "bt.h"

int five(void)
{
    printf("This is 5\n");
    print_trace();
    return 0;
}

int four(void)
{
    printf("This is 4\n");
    print_trace();
    five();
    return 0;
}

int three(void)
{
    printf("This is 3\n");
    print_trace();
    four();
    return 0;
}

int two(void)
{
    printf("This is 2\n");
    print_trace();
    three();
    return 0;
}

int one(void)
{
    printf("This is 1\n");
    print_trace();
    two();
    return 0;
}

int main(void)
{
    one();
    return 0;
}
