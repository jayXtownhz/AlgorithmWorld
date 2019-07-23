/**********************************
* 熄灯问题
* 题目描述：
* 5行6列的开关，当按一下按钮后，周围的灯会改变一次状态。矩阵角上按钮改变周围3个灯状态，
* 边上按钮影响4个灯状态，其他按钮影响5个灯的状态。
* 给定一个矩阵按钮的初始状态，要求给出按下哪些按钮，确保所有灯都熄灭。
*
* 作者：jay.xu
* 日期：2019-07-17
* 输入：
* 给出5行6列的状态数字，0表示灯熄灭，1表示灯点亮
*
* 输出：
* 输出5行6列数字，0表示不需要按该按钮，1表示需要按下对应的按钮。
*
* 思路：
********************************/

#include <stdio.h>

int n;
int block[7][8], ans[7][8];

// 判断当前解是否可行
int check_ans()
{
    for(int i = 2; i <= 6; ++i)
    {
        for(int j = 1; j <= 6; ++j)    // 第i行第j列的灯状态唯一确定
            ans[i][j] = block[i-1][j] ^ ans[i-1][j] ^ ans[i-1][j-1] ^ ans[i-1][j+1] ^ ans[i-2][j];
    }

    for(int j = 1; j <= 6; ++j)
        if(ans[6][j] == 1)
            return 0;
    return 1;
}

void solve()
{
    for(int i = 0; i < (1<<6); ++i)
    {
        int k = i;
        for(int j = 1; j <= 6; ++j)
        {
            ans[1][j] = k % 2;
            k /= 2;
        }
        if(check_ans())
            break;
    }

    for(int i = 1; i <= 5; ++i)
    {
        for(int j = 1; j <= 6; ++j)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
}

int main(void)
{
    for(int j = 1; j<= 5; ++j)
        for(int k = 1; k <= 6; ++k)
            scanf("%d", &block[j][k]);

    solve();

    return 0;
}
