/********************************
* 校门外的树
* 求：马路上剩余树木的数量
*
* 作者：jay.xu
* 日期：2019-07-16
* 输入：马路长度L（正整数），区域数目M（正整数），每个区域的起点和终点
* 输出：剩余树木的数量

* 思路：采用一个大数组保存马路上原始树木的状态，
*       修改移走区域的数组值，最终统计剩余的数量
********************************/


#include <stdio.h>
#include <string.h>

int main(void)
{
    int m, n, j, k;
    int t[10001];

    printf("请输入马路长度(米)和区间数量(以空格隔开): \n");

    while(scanf("%d %d", &m, &n) != EOF)
    {
        memset(t, 0, sizeof(t));
        printf("请输入移除树木的起点和终点(以空格隔开): \n");
        while(n--)
        {
            scanf("%d %d", &j, &k);
            for(int i=j; i<=k; i++)
            {
                t[i] = 1;
            }
        }

        int nCount = 0;
        for(int i=0; i<=m; i++)
        {
            if(t[i] == 0)
                nCount++;
        }
        printf("马路上剩余树木总数: %d\n", nCount);

        printf("\n\n请输入马路长度(米)和区间数量(以空格隔开): \n");
    }

    return 0;
}
