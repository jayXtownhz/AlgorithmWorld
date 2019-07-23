/**********************************
* 数字三元组
* 题目描述：
* 已知0 <= a,b,c <=n, 且a + b是2的倍数，b + c是3的倍数，a + b + c是5的倍数。
* 找到一组a, b, c，使a + b + c最大。
*
* 作者：jay.xu
* 日期：2019-07-17
* 输入：
* 正整数N（N<= 100）
*
* 输出：
* a, b, c与 a + b + c
*
* 思路：
********************************/

#include <stdio.h>


int main(void)
{
    int n;
    int flag = 0;
    int a, b, c;

    printf("输入正整数N: \n");
    while(scanf("%d", &n) != EOF)
    {
        for(a = n; a >= 0; a--)
            for(b = n; b >= 0; b--)
                for(c = n; c >= 0; c--)
                    if((a + b) % 2 == 0 && (b + c) % 3 == 0 && (a + b + c) % 5 == 0)
                    {
                        printf("a=%d, b=%d, c=%d, max=%d\n\n", a, b, c, a + b + c);
                        goto loop;
                    }
loop:
        printf("输入正整数N: \n");
    }

    return 0;
}
