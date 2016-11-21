/*************************************************************************
	> File Name: channel_get.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Mon 21 Nov 2016 04:59:30 PM CST
 ************************************************************************/
	
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void *audio_calloc(size_t n,size_t size)
{
    void *men;
    
    men = (void *)calloc(n,size);
    if(men == NULL)
    {
        fprintf(stderr,"Error:calloc failed!\n");
        exit(EXIT_FAILURE);
    }
    
    return men;
}

void audio_free(void *men)
{
    if (men != NULL)
    {
        free(men);
        men = NULL;
    }
}

int main(int argc, const char *argv[])
{
    if(argc != 5)
    {
        fprintf(stderr,"Usage: channel_get input_channel(s) input_file output_channel_number output_file\n");
        exit(EXIT_FAILURE);
    }
    
    int raw = atoi(argv[1]);
    int n = atoi(argv[3]);
    if (raw < 0 || n < 0)
    {
        fprintf(stderr,"Error: channel(s) must be positive number");
        exit(EXIT_FAILURE);
    }
    
    printf("Running message:\n  input_file:%s\n  input_channel(s):%d\n  output_file:%s\n  output_channel(s):%d\n\n",argv[2],raw,argv[4],n);
    
    /* channel judge */
    if (raw >= n)
    {
        printf("Action: get NO.%d channel data from %s\n",n,argv[2]);
    }
    else
    {
        fprintf(stderr,"Error: %s is only %d channels,No.%d output_channel out of range\n",argv[2],raw,n);
        exit(EXIT_FAILURE);
    }

    /* open file */
    FILE *in = fopen(argv[2],"rb");
    if(in == NULL)
    {
        fprintf(stderr,"Error:%s open failed!\n",argv[2]);
        exit(EXIT_FAILURE);
    }

    FILE *out = fopen(argv[4],"wb");
    if(out == NULL)
    {
        fprintf(stderr,"Error:%s open failed!\n",argv[4]);
        exit(EXIT_FAILURE);
    }

    int frame_len = sizeof(short int);
    short int *in_buf = (short int *)audio_calloc(raw,frame_len);
    short int *out_buf = (short int *)audio_calloc(new,frame_len);
    
    int i = 0;
    
    while(1)
    {
        if(fread(in_buf,frame_len,raw,in) != raw)
            break;

        for(i = 0;i <= new;i++)
        {
            if (raw == 1)
                out_buf[i] = in_buf[0];
            else
                out_buf[i] = in_buf[i];
        } 
        
        fwrite(out_buf,frame_len,new,out);
        memset(in_buf, 0, raw*frame_len);
        memset(out_buf, 0, new*frame_len);
    }
   
    printf("\nSuccess\n");

    audio_free(in_buf);
    audio_free(out_buf);
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


