/**********************************
* ������Ԫ��
* ��Ŀ������
* ��֪0 <= a,b,c <=n, ��a + b��2�ı�����b + c��3�ı�����a + b + c��5�ı�����
* �ҵ�һ��a, b, c��ʹa + b + c���
*
* ���ߣ�jay.xu
* ���ڣ�2019-07-17
* ���룺
* ������N��N<= 100��
*
* �����
* a, b, c�� a + b + c
*
* ˼·��
********************************/

#include <stdio.h>


int main(void)
{
    int n;
    int flag = 0;
    int a, b, c;

    printf("����������N: \n");
    while(scanf("%d", &n) != EOF)
    {
        for(a = n; a >= 0; a--)
            for(b = n; b >= 0; b--)
                for(c = n; c >= 0; c--)
                    if((a + b) % 2 == 0 && (b + c) % 3 == 0 && (a + b + c) % 5 == 0)
                    {
                        printf("a=%d, b=%d, c=%d, max=%d\n\n", a, b, c, a + b + c);
                        goto loop;
                    }
loop:
        printf("����������N: \n");
    }

    return 0;
}
