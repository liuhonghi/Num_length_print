
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>


void* Num_length_print(void* args)
{
    int num = 0;
    int ret = 0;
    char result[20];
    int len = strlen(result);
    printf("请输入一位不多于五位数的正整数:");
    scanf("%d",&num);
    ret = num_length(num);
    printf("这是一个%d位数\n",ret);
    printf("逆序输出:\n");
    num_reverse_print(num,result);
    
    printf("%s\n",result);
//    printf("顺序输出为:\n");
//    num_order_print(num);
    
    time_t t = time(NULL); //获取当前时间
    char* str_time = ctime(&t);
    str_time[24] = '\0';
    char log_content[1024]={}; //日志内容大小
    //sprintf函数 - write to the character string str
    //把ctime、num、ret整合到log_content字符串中
    sprintf(log_content,"[%s][%d]逆序打印:[%s] 位数:[%d]\n",str_time,num,result,ret);
    //bool函数，只有TURE和FALSE，返回值只有0和1；
    bool TRUE = log_inout("Num_length_print_log.txt",log_content);
    if(!TRUE)
    {
        printf("ERROR!");
    }
    return NULL;
}
