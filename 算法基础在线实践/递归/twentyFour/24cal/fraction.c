#include "fraction.h"

//���Լ�� 
int commonDivisor(int a,int b){
	int temp=0;
	while(b!=0){
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}

//��С������ 
int commonMultiple(int a,int b){
	return a*b/commonDivisor(a,b);
}


//�����ļӷ� 
FRACTION plus(FRACTION a,FRACTION b){
	
	if(a.den==b.den){ //��ĸ��ͬ 
		
		a.num=a.num+b.num;
	}else{
		int cm=commonMultiple(a.den,b.den);
		a.num=a.num*(cm/a.den)+b.num*(cm/b.den);
		a.den=cm;
	}
	
	//��a,���ӷ�ĸͬ����Լ�� 
	int cm= commonDivisor(abs(a.num),a.den); 
	a.num/=cm;
	a.den/=cm;
	
	return a;
}

//�������� 
FRACTION sub(FRACTION a,FRACTION b){
	
	if(a.den==b.den){ //��ĸ��ͬ 
		
		a.num=a.num-b.num;
	}else{
		int cm=commonMultiple(a.den,b.den);
		a.num=a.num*(cm/a.den)-b.num*(cm/b.den);
		a.den=cm;
	}
	//��a,���ӷ�ĸͬ����Լ�� 
	int cm= commonDivisor(abs(a.num),a.den); 
	a.num/=cm;
	a.den/=cm;
	
	return a;
}

//�����˷� 
FRACTION multiple(FRACTION a,FRACTION b){
	 
	 a.num*=b.num;
	 a.den*=b.den;
	 
	int cm= commonDivisor(abs(a.num),a.den); 
	a.num/=cm;
	a.den/=cm;
	
	return a;
}


//�����ĳ��� 
FRACTION division(FRACTION a,FRACTION b){
	int temp;
  if(b.num==0){
       a.num=0;
       a.den=0;
	   return a;//���ܳ�0 �����ط��ӣ���ĸΪ0����Ϊ��־ 
  }else if(b.num>0){
  	   temp=b.num;
  	   b.num=b.den;
  	   b.den=temp;
  }else{
  	  temp =abs(b.num);
  	   b.num=b.den;
  	   b.den=temp;
  	   b.num*=-1;
  }
  return multiple(a,b);
}
