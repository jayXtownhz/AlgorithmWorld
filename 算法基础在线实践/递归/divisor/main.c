/**********************************
* 最大公约数
* 题目描述：
*
*
* 输入：
* 2个正整数
*
* 输出：
* 最大公约数
*
* 思路：
*
* 作者：jay.xu
* 日期：2019-07-23
*
********************************/

#include <stdio.h>

/* 穷举法
*
* 三个变量a, b, c；
* c = min(a, b)
* 然后a, b分别与c相除，只要有一个不能被c整除，继续循环，c--逐次减少
* 知道a, b都能同时被c整除，运行结束
*
*/
void divisorA(int a, int b)
{
    int c;
    int d = 0;

    c = (a > b) ? b : a;
    while(a % c != 0 || b % c != 0)
    {
        c--;
        d++;
    }
    printf("最大公约数是: %d\n", c);
    printf("循环次数: %d\n", d);
}

/* 相减法
*
* 两个数a, b；
* a > b, a = a - b;
* a < b, b = b - a;
* 两个数不断相减，直到a == b。
* 直到a, b都能同时被c整除，运行结束。
*
*/
void divisorB(int a, int b)
{
    int d = 0;
    while(a != b)
    {
        if(a > b)
            a = a - b;
        else
            b = b - a;
        d++;
    }
    printf("最大公约数是: %d\n", a);
    printf("循环次数: %d\n", d);
}

/* 相除法
*
* 将两整数求余 a % b = c
* 如果c = 0;则b为最大公约数
* 如果c != 0,则 a = b；b = c；继续从1开始执行
* 循环的是否继续的判断条件就是c是否为0
*
*/
void divisorC(int a, int b)
{
    int c, d = 0;

    c = a % b;
    while(c != 0)
    {
        a = b;
        b = c;
        c = a % b;
        d++;
    }
    printf("最大公约数是: %d\n", b);
    printf("循环次数: %d\n", d);
}

int main(void)
{
    int a, b;

    while(1)
    {
        printf("输入两个数字求最大公约数: ");
        if(scanf("%d%d", &a, &b) == EOF)
            break;
        divisorC(a, b);
        printf("\n");
    }

    return 0;
}
