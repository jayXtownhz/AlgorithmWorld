#include "fraction.h"
#include <string.h>
#include <ctype.h>
#include <malloc.h>

typedef char EXPRESS[40]; //�洢����ı��ʽ����2*3 
typedef struct s_item{
	FRACTION value;      //���ϵ�ֵ ��exprΪ2*3��value.num=6,value.den=1 
	EXPRESS expr;         //���ʽ 
	int flag[4];//����λȷ��ʹ�õ��ĸ�����
	struct s_item* next; 
}ITEM,*PITEM;

PITEM add(PITEM a,PITEM b); //������� 
PITEM divide(PITEM a,PITEM b); //������� 
PITEM mutiply(PITEM a,PITEM b); //������� 
PITEM subtract(PITEM a,PITEM b); //������� 




