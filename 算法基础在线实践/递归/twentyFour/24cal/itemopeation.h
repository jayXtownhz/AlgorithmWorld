#include "fraction.h"
#include <string.h>
#include <ctype.h>
#include <malloc.h>

typedef char EXPRESS[40]; //存储具体的表达式，如2*3 
typedef struct s_item{
	FRACTION value;      //集合的值 如expr为2*3，value.num=6,value.den=1 
	EXPRESS expr;         //表达式 
	int flag[4];//第四位确定使用的四个数字
	struct s_item* next; 
}ITEM,*PITEM;

PITEM add(PITEM a,PITEM b); //两个相加 
PITEM divide(PITEM a,PITEM b); //两个相除 
PITEM mutiply(PITEM a,PITEM b); //两个相乘 
PITEM subtract(PITEM a,PITEM b); //两个相减 




