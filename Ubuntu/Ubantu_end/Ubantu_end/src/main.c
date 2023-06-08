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
#include "Num_length_print.h"
#include "num_length.h"
#include "num_reverse_print.h"

int main()
{
    pthread_t th; //创建线程th
    pthread_create(&th, NULL, Num_length_print, NULL); //线程执行Num_length_print函数，传输值为NULL
    pthread_join(th, NULL); //等待线程，如果不等待线程完成，main可能会先完成导致报错；
    printf("\n");
    return 0;
}