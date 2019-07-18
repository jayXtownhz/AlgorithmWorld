/**********************************
* 排序问题
* 求：输出给定序列数的第k个序列
*
* 作者：jay.xu
* 日期：2019-07-17
* 输入：1、组成序列的个数m和第k个序列
*       2、提供参考的序列
* 输出：参考序列后第k个序列
*
* 思路：1、给定排列的n个数x1,x2,x3,x4...,xn
*       2、从Xn开始向左查找，直到找到某个位置Xj，满足Xj-1 < Xj
*       3、在Xj,Xj+1,...Xn中找到最小的比Xj-1大的数，将这个数和Xj-1交换
*       4、将位置j到位置n的所有数从小到大重新排列，得到最终的下一个排序
*       5、例外，如果X1,X2,...,Xn已经是降序排列，则其下一个排序是Xn,Xn-1,...,X1
********************************/


#include <stdio.h>

#define NUM    1025

int a[1025] = {0};

void NextPermutation(int size)
{
    int i;
    int temp;
    int flag = size - 1;

    while(flag > 0 && a[flag - 1] > a[flag])
        flag--;

    if(flag == 0)
    {
        for(i = 0; i < size; i++)
            a[i] = i + 1;
        return;
    }

    for(i = size - 1; i >= flag; i--)
    {
        if(a[i] > a[flag - 1])
        {
            temp = a[flag - 1];
            a[flag - 1] = a[i];
            a[i] = temp;
            break;
        }
    }

    while(size - 1 > flag)
    {
        temp = a[size - 1];
        a[size - 1] = a[flag];
        a[flag] = temp;
        flag++;
        size--;
    }
}

int main(void)
{
    int m, n, k;
    int i;

    printf("请输入运算次数: \n");
    scanf("%d", &m);

    while(m)
    {
        printf("请输入序列组成长度和第几个序列(以空格隔开): \n");
        scanf("%d %d", &n, &k);
        printf("请逐个输入参考序列值，并回车: \n");
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);

        for(i = 0; i < k; i++)
            NextPermutation(n);

        for(i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        m--;
    }

    return 0;
}
