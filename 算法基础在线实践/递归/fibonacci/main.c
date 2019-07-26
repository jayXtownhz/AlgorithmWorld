/**********************************
* 斐波那契数列
* 题目描述：
*
*
* 输入：
* 斐波那契数列行数。
*
* 输出：
* 斐波那契数值。
*
* 思路：
*
* 作者：jay.xu
* 日期：2019-07-24
*
********************************/

#include <stdio.h>

/*
void power_matrix(uint64_t m[][2], unsigned int exp)
{
uint64_t result[][2] = { 1,0,0,1 }; // 单位矩阵
uint64_t temp[2][2]; // 计算n次矩阵
for (unsigned int i = 1; i <= exp; i++)
    {
    temp[0][0] = result[0][0] * m[0][0] + result[0][1] * m[1][0];
    temp[0][1] = result[0][0] * m[0][1] + result[0][1] * m[1][1];
    temp[1][0] = result[1][0] * m[0][0] + result[1][1] * m[1][0];
    temp[1][1] = result[1][0] * m[0][1] + result[1][1] * m[1][1];
    memcpy(result, temp, sizeof(uint64_t) * 4);
    }
    memcpy(m, result, sizeof(uint64_t) * 4);
}
void generate_matrix()
{
uint64_t m[2][2] = { 1,1,1,0 }; // 1次矩阵
uint64_t temp[2][2];
for (int i = 0; i < 8; i++)
{
memcpy(temp, m, 4 * sizeof(uint64_t));
printf("{");
power_matrix(temp, 1 << i);
for (int j = 0; j < 2; j++)
{
for (int k = 0; k < 2; k++)
{
printf("%llu, ", temp[j][k]);
}
}
printf("},\n");
}
}
*/
// 递归方式
long long fibonacciA(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n <= 2)
        return 1;
    return fibonacciA(n - 1) + fibonacciA(n - 2);
}
// 循环方式
long long fibonacciB(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    long long f1 = 1, f2 = 1, fn;
    for (unsigned int i = 3; i <= n; i++)
    {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }

    return fn;
}
// 快速幂+矩阵方式
long long fibonacci6(unsigned int n)
{
    const static long long cache[][2][2] = {
        { 1, 0, 0, 1 },    // 0次幂(无用)
        { 1, 1, 1, 0 },    // 1次幂(2^0,1)
        { 2, 1, 1, 1 },    // 2次幂(2^1,2)
        { 5, 3, 3, 2 },    // 4次幂(2^2,3)
        { 34, 21 ,21, 13 },    // 8次幂(2^3,4)
        { 1597, 987, 987 ,610 },    // 16次幂(2^4,5)
        { 3524578, 2178309, 2178309, 1346269 },    // 32次幂(2^5,4)
        { 17167680177565, 10610209857723, 10610209857723, 6557470319842},    //64次幂(2^6,5)
        { 8102862946581596898, 18154666814248790725, 18154666814248790725, 8394940206042357789}    //128次幂(2^7,6)
    };
    long long result[][2] = { 1,0,0,1 };    // 单位矩阵
    long long temp[2][2];
    int bit_pos = 1;
    while (n)
    {
        if (n & 1)
        {
            temp[0][0] = result[0][0] * cache[bit_pos][0][0] + result[0][1] * cache[bit_pos][1][0];
            temp[0][1] = result[0][0] * cache[bit_pos][0][1] + result[0][1] * cache[bit_pos][1][1];
            temp[1][0] = result[1][0] * cache[bit_pos][0][0] + result[1][1] * cache[bit_pos][1][0];
            temp[1][1] = result[1][0] * cache[bit_pos][0][1] + result[1][1] * cache[bit_pos][1][1];
            memcpy(result, temp, sizeof(long long) * 4);
        }
        n >>= 1;
        bit_pos++;
    }
    // result[1][0] * 1 + result[1][1] * 0;
    return result[1][0] * 1;
}

int main(void)
{
    unsigned int i, n;
    long long value;

    printf("输入斐波那契数列行数: \n");
    while(scanf("%d", &n) != EOF)
    {
        for (i = 0; i <= n; i++)
        {
            value = fibonacci6(i);
            fprintf(stdout, "%lld ", value);
        }
        fprintf(stdout, "\n\n");
        printf("输入斐波那契数列行数: \n");
    }

    return 0;
}
