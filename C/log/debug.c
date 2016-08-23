/*************************************************************************
	> File Name: debug.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月23日 星期四 18时19分48秒
 ************************************************************************/

/*
 * 反斜线把这个定义延续到下一行,define遇到换行符就结束；
 *_ _func__和_Function_一样的；
 * 使用do{...}while(0)构造后的宏定义不会受到大括号、分号等的影响，而且可以定义空宏而不受警告。
 * ##__VA_ARGS__ ,可变参数宏,##可以支持0个参数.
 */

/* 
 * __LINE__：在源代码中插入当前源代码行号；
 * __FILE__：在源文件中插入当前源文件名；
 * __DATE__：在源文件中插入当前的编译日期
 * __TIME__：在源文件中插入当前编译时间；
 * __func__：输出函数名称。
 */

#include<stdio.h>

#define DEBUG_PRINT do{}while(0)
#define PROJECT "MyProject"

#if defined(DEBUG_PRINT)
#define DEBUG(...)\
        do{\
            fprintf(stderr,"-----DEBUG-----\n");\
            fprintf(stderr,"[%s]\n",PROJECT);\
            fprintf(stderr,"%s %s\n",__TIME__,__DATE__);\
            fprintf(stderr,"%s:%d:%s():",__FILE__,__LINE__,__func__);\
            fprintf(stderr,__VA_ARGS__);\
        }while(0)
#endif

int main(void)
{
    DEBUG("Debug successfully!\n");
    return 0;
}
