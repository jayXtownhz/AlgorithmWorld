#include <math.h>
#include <stdlib.h>

typedef struct{
	int num;//���� 
	int den;//��ĸ 
}FRACTION;  //ע������ķ��ŷ��ڷ����� 


int commonDivisor(int a,int b);//���Լ�� 
int commonMultiple(int a,int b);//��С������ 
//�������͹�Լ�����ڻ���ͼ������ 

FRACTION plus(FRACTION a,FRACTION b);//�����ļӷ� 
FRACTION sub(FRACTION a,FRACTION b);//�����ļ��� 
FRACTION multiple(FRACTION a,FRACTION b);//�����˷� 
FRACTION division(FRACTION a,FRACTION b);//�����ĳ��� 


