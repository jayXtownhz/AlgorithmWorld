/**********************************
* �����ĺ����
* ��Ŀ������
* ���������ĺ���S�����ǵĻ�����Ƕ��٣�
*
* ���ߣ�jay.xu
* ���ڣ�2019-07-17
* ���룺
* ������S��0<=S<= 10000��
*
* �����
* �������������˻���
*
* ˼·��1������ɸ���ҳ�С��S������������
*       2�����˻�һ���Ǵ�С��ӽ�����������֮�����������ַ����ҡ�
********************************/

#include <stdio.h>

#define NUM 1300

typedef unsigned char byte;
int primeNum[NUM];
int count;

int prime(int n)
{
    int i;
    count = 0;
    byte *prime = malloc((n + 1) * sizeof(byte));
    // int *prime = malloc((n+1) * sizeof(int));

    for(i = 2; i < n; i++)
    {
        prime[i] = 1;
    }

    for(i = 2; i <= n; i++)
    {
        if(prime[i] == 1)
        {
            // printf("%d ", i);
            primeNum[count] = i;
            count++;

            for(int j = i+i; j < n; j+=i)
                prime[j] = 0;
        }
    }

    free(prime);

    // printf("\n");
    // printf("%d\n", count);

    return 0;
}

int main(void)
{
    int s;
    int max;
    int flag;

    printf("����������S: \n");

    while(scanf("%d", &s) != EOF)
    {
        prime(s);

        /*
        for(int i = 0; i < count; i++)
        {
            printf("%d ", primeNum[i]);
        }*/

        flag = 0;

        for(int i = count / 2; i >= 0; i--)
        {
            max = s - primeNum[i];
            for(int j = i + 1; j <= count; j++)
            {
                if(max == primeNum[j])
                {
                    printf("max = %d, prime numbers are: [%d],[%d]\n",
                           max * primeNum[i], primeNum[i], primeNum[j]);
                    flag = 1;
                    //break;
                }
            }
            //if(flag == 1)
            //    break;
        }
        if(flag == 0)
            printf("There is no current condition!\n");

        printf("\n");
    }

    return 0;
}
