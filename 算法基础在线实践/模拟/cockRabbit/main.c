/********************************
* 鸡兔同笼问题
* 求：最多动物数 与 最少动物数
*
* 作者：jay.xu
* 日期：2019-07-16
* 输入：总脚数N（正整数）
* 输出：最少动物数 最多动物数
*
* 思路：（1）如果N为奇数，无答案，输出0 0
*       （2）如果N是偶数且能被4整除，则最少N/4只兔子，最多N/2只鸡
*       （3）如果N是偶数且不能被4整除，则最少(N - 2)/4只兔子和1只鸡，最多N/2只鸡
********************************/


#include <stdio.h>

int main(void)
{
    int nCases, nFeets;
    int nMax, nMin;

    printf("请输入样本数量: \n");

    while(scanf("%d", &nCases) != EOF)
    {
        for(int i=0; i<nCases; i++)
        {
            printf("请输入动物的总脚数: \n");

            scanf("%d", &nFeets);

            if(nFeets % 4 == 0){
                nMax = nFeets / 4;
                nMin = nFeets / 2;

            }
            else if(nFeets % 2 == 0){
                nMax = nFeets / 4 + 1;
                nMin = nFeets / 2;
            }
            else{
                nMax = 0;
                nMin = 0;
            }

            printf("最少的动物数: %d, 最多的动物数: %d\n", nMax, nMin);
        }

        printf("\n\n请输入样本数量: \n");
    }

    return 0;
}
