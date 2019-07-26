#include <math.h>
#include <stdlib.h>

typedef struct{
	int num;//分子 
	int den;//分母 
}FRACTION;  //注意分数的符号放在分子上 


int commonDivisor(int a,int b);//最大公约数 
int commonMultiple(int a,int b);//最小公倍数 
//公倍数和公约数用于化简和计算分数 

FRACTION plus(FRACTION a,FRACTION b);//分数的加法 
FRACTION sub(FRACTION a,FRACTION b);//分数的减法 
FRACTION multiple(FRACTION a,FRACTION b);//分数乘法 
FRACTION division(FRACTION a,FRACTION b);//分数的除法 


