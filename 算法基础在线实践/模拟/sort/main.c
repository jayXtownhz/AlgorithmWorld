/**********************************
* ��������
* ����������������ĵ�k������
*
* ���ߣ�jay.xu
* ���ڣ�2019-07-17
* ���룺1��������еĸ���m�͵�k������
*       2���ṩ�ο�������
* ������ο����к��k������
*
* ˼·��1���������е�n����x1,x2,x3,x4...,xn
*       2����Xn��ʼ������ң�ֱ���ҵ�ĳ��λ��Xj������Xj-1 < Xj
*       3����Xj,Xj+1,...Xn���ҵ���С�ı�Xj-1����������������Xj-1����
*       4����λ��j��λ��n����������С�����������У��õ����յ���һ������
*       5�����⣬���X1,X2,...,Xn�Ѿ��ǽ������У�������һ��������Xn,Xn-1,...,X1
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

    printf("�������������: \n");
    scanf("%d", &m);

    while(m)
    {
        printf("������������ɳ��Ⱥ͵ڼ�������(�Կո����): \n");
        scanf("%d %d", &n, &k);
        printf("���������ο�����ֵ�����س�: \n");
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
