/**********************************
* Լɪ������
* �����ʣ��һ�˵ı��
*
* ���ߣ�jay.xu
* ���ڣ�2019-07-16
* ���룺������N��������ֵM(0<m<n)
* ��������ʣ���˵ı��
*
* ˼·��
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
    printf("�������������ͱ���ֵ(�Կո����): \n");
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
                   // ���δ����Ȧ������
                   // ����ۼƵ�m����λ�õĵ���Ȧ����1
                   count++;
                   if(count == m)
                       cycle[index] = 1;
               }
           }
       }

       // ��ӡδ��Ȧ����
       for(int i = 0; i < n; i++)
       {
           if(cycle[i] == 0)
           {
               printf("���һ�˵ı��: %d \n\n", i + 1);
               break;
           }
       }

       printf("�������������ͱ���ֵ(�Կո����) \n");
       scanf("%d %d", &n, &m);
    }

    return 0;
}
