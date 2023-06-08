#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>


//整数逆序输出
void num_reverse_print(int num,char* result)
{
    int str_len = 0;
    //如果num > 0,模10输出余数，得到逆序
    while(num > 0)
    {
        str_len += sprintf(result + str_len,"%d",num%10);
        num /= 10;
    }
    result[str_len] = '\0';
}
