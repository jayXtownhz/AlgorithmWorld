/**********************************
* ���Լ��
* ��Ŀ������
*
*
* ���룺
* 2��������
*
* �����
* ���Լ��
*
* ˼·��
*
* ���ߣ�jay.xu
* ���ڣ�2019-07-23
*
********************************/

#include <stdio.h>

/* ��ٷ�
*
* ��������a, b, c��
* c = min(a, b)
* Ȼ��a, b�ֱ���c�����ֻҪ��һ�����ܱ�c����������ѭ����c--��μ���
* ֪��a, b����ͬʱ��c���������н���
*
*/
void divisorA(int a, int b)
{
    int c;
    int d = 0;

    c = (a > b) ? b : a;
    while(a % c != 0 || b % c != 0)
    {
        c--;
        d++;
    }
    printf("���Լ����: %d\n", c);
    printf("ѭ������: %d\n", d);
}

/* �����
*
* ������a, b��
* a > b, a = a - b;
* a < b, b = b - a;
* ���������������ֱ��a == b��
* ֱ��a, b����ͬʱ��c���������н�����
*
*/
void divisorB(int a, int b)
{
    int d = 0;
    while(a != b)
    {
        if(a > b)
            a = a - b;
        else
            b = b - a;
        d++;
    }
    printf("���Լ����: %d\n", a);
    printf("ѭ������: %d\n", d);
}

/* �����
*
* ������������ a % b = c
* ���c = 0;��bΪ���Լ��
* ���c != 0,�� a = b��b = c��������1��ʼִ��
* ѭ�����Ƿ�������ж���������c�Ƿ�Ϊ0
*
*/
void divisorC(int a, int b)
{
    int c, d = 0;

    c = a % b;
    while(c != 0)
    {
        a = b;
        b = c;
        c = a % b;
        d++;
    }
    printf("���Լ����: %d\n", b);
    printf("ѭ������: %d\n", d);
}

int main(void)
{
    int a, b;

    while(1)
    {
        printf("�����������������Լ��: ");
        if(scanf("%d%d", &a, &b) == EOF)
            break;
        divisorC(a, b);
        printf("\n");
    }

    return 0;
}
