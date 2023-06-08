//
//  main.c
//  Ubuntu
//
//  Created by HiLau on 2023/6/7.
//

#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

void* Num_length_print(void* args);
int num_length(int num);
void num_reverse_print(int num);
bool log_inout(const char* filename,const char* content);
//void num_order_print(int num);



void* Num_length_print(void* args)
{
    int num = 0;
    int ret = 0;
    printf("请输入一位不多于五位数的正整数:");
    scanf("%d",&num);
    ret = num_length(num);
    printf("这是一个%d位数\n",ret);
    printf("逆序输出为:\n");
    num_reverse_print(num);
//    printf("顺序输出为:\n");
//    num_order_print(num);
    
    time_t t = time(NULL); //获取当前时间
    char log_content[100]={}; //日志内容大小
    //sprintf函数 - write to the character string str
    sprintf(log_content,"[%s] %d逆序打印 ｜ 位数:%d\n",ctime(&t),num,ret);
    //bool函数，只有TURE和FALSE，返回值只有0和1；
    bool TRUE = log_inout("log.txt",log_content);
    if(!TRUE)
    {
        printf("ERROR!\n");
    }
    return NULL;
}


int main()
{
    pthread_t th; //创建线程th
    pthread_create(&th, NULL, Num_length_print, NULL); //线程执行Num_length_print函数，传输值为NULL
    pthread_join(th, NULL); //等待线程，如果不等待线程完成，main可能会先完成导致报错；
    printf("\n");
    return 0;
}

//判断整数位数
int num_length(int num)
{
    int count = 0;
    if(num < 10)
    {
        count = 1;
    }
    else if(num < 100)
    {
        count = 2;
    }
    else if(num < 1000)
    {
        count = 3;
    }
    else if(num < 10000)
    {
        count = 4;
    }
    else
    {
        count = 5;
    }
    return count;
}


//整数逆序输出
void num_reverse_print(int num)
{
    //如果num > 0,模10输出余数，得到逆序
    while(num > 0)
    {
        printf("%d",num%10);
        num /= 10;
    }
    printf("\n");
}

//顺序依次输出 - 递归
//void num_order_print(int num)
//{
//    if(num>9)
//    {
//        num_order_print(num/10);
//    }
//    printf("%d ",num%10);
//}

//bool类型
bool log_inout(const char* filename,const char* content)
{
    //用fopen打开log.txt，二进制追加的方式写入；如果log.txt不存在，则自动创建
    //二进制追加是因为fwrite
    FILE* fp = fopen("Num_length_print_log.txt", "ab");
    //FILE* fp = fopen("Num_length_print_log.txt", "a"); // -fputs
    if (fp == NULL)
    {
        printf("ERROR\n");
        return false;
    }
    size_t str_len = strlen(content);
    fwrite(content, str_len, 1, fp);
    //fputs(content, fp);
    fclose(fp);
    return true;
}
