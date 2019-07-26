/**********************************
* 计算24点
* 题目描述：
*
*
* 输入：
* 多组4个数字，以空格隔开。
*
* 输出：
* 输出计算公式。
*
* 思路：
*
* 作者：jay.xu
* 日期：2019-07-23
*
********************************/

#include <stdio.h>
#include <math.h>

int ans = 0;

void counting24(double a[], int n)
{
    int i, j, x, y, k, m;

    double b[4];

    if(n == 1 && a[0] > 0 && fabs(a[0] - 24) < 0.0001)
        ans = 1;
    else if(n > 1)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(i == j)
                    continue;
                for(m = k = 0; k < n; k++)
                    if(k != i && k != j)
                    {
                        b[m] = a[k];
                        m++;
                    }
                b[m] = a[i] + a[j];
                counting24(b, m + 1);
                b[m] = a[i] - a[j];
                counting24(b, m + 1);
                b[m] = a[i] * a[j];
                counting24(b, m + 1);
                if(a[j] != 0)
                {
                    b[m] = a[i] / a[j];
                    counting24(b, m + 1);
                }
            }
        }
    }
}


int main(void)
{
    double a[4];

    while(scanf("%lf%lf%lf%lf", &a[0], &a[1], &a[2], &a[3]) != EOF)
    {
        ans = 0;
        counting24(a, 4);
        if(ans != 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
