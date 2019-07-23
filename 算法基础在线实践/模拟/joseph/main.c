/**********************************
* 约瑟夫问题
* 求：最后剩下一人的编号
*
* 作者：jay.xu
* 日期：2019-07-16
* 输入：总人数N，报数的值M(0<m<n)
* 输出：最后剩余人的编号
*
* 思路：
********************************/


#include <stdio.h>

#define NUM 10000
int cycle[NUM];

void init_cycle()
{
    for(int i = 0; i < NUM; i++)
    {
        cycle[i] = 0;
    }
}

int main(void)
{
    int n, m;
    printf("请输入总人数和报数值(以空格隔开): \n");
    scanf("%d %d", &n, &m);

    while(1)
    {
       if(n == 0 && m == 0)
           break;

       int index = -1;
       int count = 0;

       init_cycle();
       for(int i = 1; i < n; i++)
       {
           count = 0;
           while(count != m)
           {
               index = (index + 1) % n;
               if(cycle[index] == 0)
               {
                   // 如果未到退圈，计数
                   // 如果累计到m，该位置的点退圈，置1
                   count++;
                   if(count == m)
                       cycle[index] = 1;
               }
           }
       }

       // 打印未出圈点编号
       for(int i = 0; i < n; i++)
       {
           if(cycle[i] == 0)
           {
               printf("最后一人的编号: %d \n\n", i + 1);
               break;
           }
       }

       printf("请输入总人数和报数值(以空格隔开) \n");
       scanf("%d %d", &n, &m);
    }

    return 0;
}
