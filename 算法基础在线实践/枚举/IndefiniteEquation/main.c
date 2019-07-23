/**********************************
* 不定方程求解
* 题目描述：
* 给定正整数a, b, c，求不定方程ax + by = c的所有非负整数解组数。
*
* 作者：jay.xu
* 日期：2019-07-17
* 输入：
* 正整数a, b, c (<= 1000)
*
* 输出：
* 整数解组数。
*
* 思路：
********************************/

#include <stdio.h>


int main(void)
{
    int a, b, c;
    int count;

    printf("输入正整数a, b, c, 以空格隔开: \n");

    while(scanf("%d%d%d", &a, &b, &c) != EOF)
    {
        count = 0;
        for(int x = 0; x <= c; x++)
            for(int y = 0; y <= c; y++)
                if(a * x + b * y == c)
                {
                    printf("%dx + %dy = %d, x = %d, y = %d\n",
                           a, b, c, x, y);
                    count++;
                }
        printf("共有整数解: %d 组\n\n", count);
        printf("输入正整数a, b, c, 以空格隔开: \n");
    }

    return 0;
}
