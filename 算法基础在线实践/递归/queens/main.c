/**********************************
* 八皇后问题
* 题目描述：
*
*
* 输入：
*
*
* 输出：
*
*
* 思路：
*
* 作者：jay.xu
* 日期：2019-07-23
*
********************************/

#include <stdio.h>

int q[92][8], row[8], num = 0;

void queen(int i)
{
    int j, k;

    if(i == 8)
    {
        for(j = 0; j < 8; j++)
            q[num][j] = row[j];
        num++;
        return;
    }

    for(j = 1; j <= 8; j++)
    {
        for(k = 0; k < i; k++)
            if(row[k] == j || abs(k - i) == abs(row[k] - j))
                break;
        if(k == i)
        {
            row[k] = j;
            queen(i + 1);
        }
    }
}

int main(void)
{
    int n, i, b, j;

    queen(0);

    printf("Enter the n: \n");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &b);
        for(j = 0; j < 8; j++)
            printf("%d ", q[b - 1][j]);
        printf("\n");
    }

    return 0;
}
