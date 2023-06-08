#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

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
