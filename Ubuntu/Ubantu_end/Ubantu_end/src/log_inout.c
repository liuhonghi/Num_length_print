#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

bool log_inout(const char* filename,const char* content)
{
    //用fopen打开log.txt，二进制追加的方式写入；如果log.txt不存在，则自动创建
    //二进制追加是因为fwrite，fwrite是以二进制写入
    //fputs直接追加的方式即可
    FILE* fp = fopen("Num_length_print_log.txt", "a");
    //FILE* fp = fopen("Num_length_print_log.txt", "a"); // -fputs
    if (fp == NULL)
    {
        printf("ERROR ");
        return false;
    }
    size_t str_len = strlen(content);
    fwrite(content,str_len,1, fp);
    //fputs(content, fp);
  fflush(fp);
    fclose(fp);
    return true;
}

