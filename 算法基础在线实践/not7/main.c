/**********************************
* 与7无关的数
* 求：给定正整数范围内，与7无关数的平方和
*
* 作者：jay.xu
* 日期：2019-07-17
* 输入：正整数n<10000
* 输出：与7无关数的平方和
*
* 思路：1、排除被7整除的数
*       2、排除10机制表示含7的数
*       3、累加与7无关数的平方和
********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM    10

int main(void)
{
    int n;
    int sum;
    char str[NUM];

    printf("请输入运算的正整数(<8895): \n");

    while(scanf("%d", &n) != EOF)
    {
        if(n > 8894)
        {
            printf("您输入的数字过大. \n\n");
            printf("请输入运算的正整数(<8895): \n");\
            continue;
        }
        sum = 0;

        for(int i=0; i<n; i++)
        {
            if(i % 7 == 0)
                continue;    // 排除被7整除的数

            itoa(i, str, 10);

            if(strstr(str, "7"))
                continue;    // 排除10进制数中含7的数

            sum += i * i;
        }

        printf("小于%d的与7无关数的平方和: %d\n\n", n, sum);
        printf("请输入运算的正整数(<8895): \n");
    }

    return 0;
}
