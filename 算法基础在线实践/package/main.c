/********************************
* 装箱问题
* 求：需要使用的最少包装箱数量
*
* 作者：jay.xu
* 日期：2019-07-16
* 输入：需要打包的产品数量清单
* 输出：所需包装箱数量
*
* 思路：1、计算大于或等于3x3所需的包装箱数
*       2、计算2x2的空位数，与2x2的产品进行对比，如不足，增加新的包装箱
*       3、计算1x1的空位数，与1x1的产品进行对比，如不足，证件新的包装箱
********************************/

#include <stdio.h>

int main(void)
{
    int n, a, b, c, d, e, f, x, y;
    // n表示需要的箱子
    // x表示1 x 1的空位数目
    // y表示2 x 2的空位数目

    int u[4] = {0, 5, 3, 1};
    // 表示3 x 3的产品分别是4K，4K+1,4K+2,4K+3时，
    // 为3 x 3产品打开的新箱子中剩余2 x 2的空位数

    printf("请输入包装产品的数量清单(以空格隔开), \n");
    printf("对应为1x1 2x2 3x3 4x4 5x5 6x6 \n");
    printf("输入全部为零时退出(0 0 0 0 0 0): \n");

    while(scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f) != EOF)
    {
        if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f== 0)
            break;

        n = f + e + d + (c + 3) / 4;
        // 长宽大于或等于3 x 3所需包装箱数

        y = 5 * d + u[c % 4];
        // 长宽大于或等于3 x 3产品包装后，剩余2 x 2的空位数

        if(b > y)
            n += (b - y + 8) / 9;
            // 多出来的2 x 2箱子应该占用的新箱子数

        x = 36 * n - 36 * f - 25 * e - 16 * d - 9 * c - 4 * b;
        // 所有箱子剩下的1 x 1空位

        if(a > x)
            n += (a - x + 35) / 36;

        printf("需要包装箱数量: %d\n\n", n);
    }

    return 0;
}
