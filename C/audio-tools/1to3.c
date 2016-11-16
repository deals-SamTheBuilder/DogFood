/*************************************************************************
	> File Name: 1to3.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Wed 16 Nov 2016 10:08:06 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define OUT_FILE "three_channels.pcm"
#define RAW_PASS 8
#define NEW_PASS 3

void *my_calloc(size_t n,size_t size)
{
    void *men;
    
    men = (void *)calloc(n,size);
    if(men == NULL)
    {
        fprintf(stderr,"calloc failed!\n");
        exit(EXIT_FAILURE);
    }
    
    return men;
}

void my_free(void *men)
{
    if (men != NULL)
    {
        free(men);
        men = NULL;
    }
}


int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr,"Usage:Please choose the input file!");
        exit(EXIT_FAILURE);
    }

    FILE *in = fopen(argv[1],"rb");
    if(in == NULL)
    {
        fprintf(stderr,"Error:%s open failed!",argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *out = fopen(OUT_FILE,"wb");
    if(out == NULL)
    {
        fprintf(stderr,"Error:%s open failed!",OUT_FILE);
        exit(3);
    }

    char *in_buf = (char *)my_calloc(1,2*RAW_PASS);
    char *out_buf = (char *)my_calloc(1,2*NEW_PASS);
    
    int ret = 0;
    int i = 0;
    
    while(1)
    {
        if(fread(in_buf,1,2*RAW_PASS,in) != 2*RAW_PASS)
            break;
        for(i = 0;i <= 2*NEW_PASS-1;i++)
        {
            if(i<=2*(NEW_PASS-1)-1)
                out_buf[i] = in_buf[i];
            else
                out_buf[i] = in_buf[i]; // eight -> seven 
        } 
        fwrite(out_buf,1,2*NEW_PASS,out);
    }
    
    my_free(in_buf);
    my_free(out_buf);
    fclose(in);
    fclose(out);
    
    return 0;
}
/*static int agn_echo_separate_channel(lua_State *L) 
{
    size_t size = 0;
    const char *data = luaL_checklstring(L, 1, &size);
    if(data == NULL || size == 0 || (size % 4 != 0))
    {
        printf("separate channel failed.\n");
        lua_pushnil(L);
        return 1;
    }
    int frameLen = size / 4;
    short int *outData = (short int *)calloc(frameLen, sizeof(short int));
    if(outData == NULL)
    {
        printf("separate channel calloc failed.\n");
        lua_pushnil(L);
        return 1;
    }
    short int *dataPtr = (short int *)data;
    int i = 0;
    for(i = 0; i < frameLen; i++)
    {
        outData[i] = dataPtr[2 * i];
    }
    lua_pushlstring(L, (char *)outData, frameLen * 2);    //left channel
    memset(outData, 0, frameLen * 2);
    for(i = 0; i < frameLen; i++)
    {
        outData[i] = dataPtr[2 * i + 1];
    }
    lua_pushlstring(L, (char *)outData, frameLen * 2);    //right channel
    free(outData);
    return 2;

}*/


