/**********************************
* 合唱队形问题
* 题目描述：
* N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学不交换位置就能排成合唱队形。
* 合唱队形定义：设K位同学从左到右依次编号为1, 2, …, K，他们的身高分别为T1, T2, …, TK，
* 则他们的身高满足T1 < T2 < … < Ti， Ti > Ti+1 > … > TK (1 <= i <= K)。
* 要求：已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。
*
*
* 作者：jay.xu
* 日期：2019-07-17
* 输入：
* 输入的第一行是一个整数N，表示同学的总数。
* 第二行有n个整数，用空格分隔，第i个整数Ti是第i位同学的身高（厘米）
*
* 输出：
* 输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。
*
* 解题思路：
* 定义n位同学的身高数组为a[n]（注意这里数组长度不允许为变量，这里只是为了理解将n写如到[]中）
*
* 假设第i（0<= i <= n - 1）个同学为最高点，分别求出此时i左边的最长递增子序列长度inc1[i]，
* i右边的最长递减子序列长度inc2[i]，由于最高点i同时包括在了inc1[i]和inc2[i]之中，
* 因此实际的合唱队形的长度为inc1[i] + inc2[i] - 1。
* 而我们求得的最后结果就是i从1到n - 1中，使得inc1[i] + inc2[i] - 1最大的情况。
*
* 具体实现：
* 现在设i为下标，循环i从0到n-1，求得各种i值对应的inc1[i]；循环i从0到n-1，求得各种i值对应的inc2[i]。
* 最后循环i从0到n-1，求得各种i值对应的inc[i] + inc2[i] - 1最大的情况ans，然后n - ans即为出列同学的人数。
*
* 当i = 0的时候，最高点0左边只有它自己，因此inc1[0] = 1；当i = n - 1的时候，最高点n - 1右边只有它自己，因此inc2[n - 1] = 1;
* 当i处于0到n - 1之间时的求法也很好理解，在求inc1[i]时，j = (0 ~ i - 1)的inc[j]已经得出来了，
* 所以我们只需要比较在前面的这些序列中加上a[i]时的最长递增序列，
* 即在a[i]大于前面这些序列值的情况下inc[j] + 1最大的情况即为inc[i]。
********************************/


#include <stdio.h>

#define QUE 200

int inc1[QUE],inc2[QUE],a[QUE];
//inc1-->longest increase array from head to tail
//inc2-->longest increase array from tail to head

int main()
{
    int n;

    printf("输入队列长度: \n");

    while(scanf("%d", &n) != EOF)
    {
        int ans = 0, i, j;

        //输入n个人的身高
        printf("输入逐个身高, 空格隔开: \n");
        for(i = 0; i < n; i++)
            scanf("%d",&a[i]);
        //inc1[i]是存储以i为最高点时左边的递增子序列长度
        inc1[0] = 1;
        for(i = 1; i < n; i++)
        {
            inc1[i] = 1;
            for(j = 0; j < i; j++)
                if(a[i] > a[j] && inc1[j] + 1 > inc1[i])
                    inc1[i] = inc1[j] + 1;
        }
        //inc2[i]是存储以i为最高点时左边的递减子序列长度
        inc2[n - 1] = 1;
        for(i = n - 2; i >= 0; i--)
        {
            inc2[i] = 1;
            for(j = n - 1; j > i; j--)
                if(a[j] < a[i] && inc2[j] + 1 > inc2[i])
                    inc2[i] = inc2[j] + 1;
        }

        for(i = 0; i <= n; i++)
            if(inc1[i] + inc2[i] - 1 > ans)
                ans = inc1[i] + inc2[i] - 1;
        printf("最少出列数: \n");
        printf("%d\n\n", n - ans);

        printf("输入队列长度: \n");
    }

    return 0;
}
