/**********************************
* 质数的和与积
* 题目描述：
* 两个质数的和是S，它们的积最大是多少？
*
* 作者：jay.xu
* 日期：2019-07-17
* 输入：
* 正整数S（0<=S<= 10000）
*
* 输出：
* 两个质数的最大乘积。
*
* 思路：1、采用筛法找出小于S的所有质数。
*       2、最大乘积一定是大小最接近的两个质数之积，可以两分法查找。
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

    printf("输入质数和S: \n");

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
