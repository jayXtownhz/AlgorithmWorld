/**********************************
* �����������
* ��Ŀ������
* ����������a, b, c���󲻶�����ax + by = c�����зǸ�������������
*
* ���ߣ�jay.xu
* ���ڣ�2019-07-17
* ���룺
* ������a, b, c (<= 1000)
*
* �����
* ������������
*
* ˼·��
********************************/

#include <stdio.h>


int main(void)
{
    int a, b, c;
    int count;

    printf("����������a, b, c, �Կո����: \n");

    while(scanf("%d%d%d", &a, &b, &c) != EOF)
    {
        count = 0;
        for(int x = 0; x <= c; x++)
            for(int y = 0; y <= c; y++)
                if(a * x + b * y == c)
                {
                    printf("%dx + %dy = %d, x = %d, y = %d\n",
                           a, b, c, x, y);
                    count++;
                }
        printf("����������: %d ��\n\n", count);
        printf("����������a, b, c, �Կո����: \n");
    }

    return 0;
}
