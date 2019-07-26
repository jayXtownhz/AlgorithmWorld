#include "fraction.h"

//最大公约数 
int commonDivisor(int a,int b){
	int temp=0;
	while(b!=0){
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}

//最小公倍数 
int commonMultiple(int a,int b){
	return a*b/commonDivisor(a,b);
}


//分数的加法 
FRACTION plus(FRACTION a,FRACTION b){
	
	if(a.den==b.den){ //分母相同 
		
		a.num=a.num+b.num;
	}else{
		int cm=commonMultiple(a.den,b.den);
		a.num=a.num*(cm/a.den)+b.num*(cm/b.den);
		a.den=cm;
	}
	
	//简化a,分子分母同除公约数 
	int cm= commonDivisor(abs(a.num),a.den); 
	a.num/=cm;
	a.den/=cm;
	
	return a;
}

//分数减法 
FRACTION sub(FRACTION a,FRACTION b){
	
	if(a.den==b.den){ //分母相同 
		
		a.num=a.num-b.num;
	}else{
		int cm=commonMultiple(a.den,b.den);
		a.num=a.num*(cm/a.den)-b.num*(cm/b.den);
		a.den=cm;
	}
	//简化a,分子分母同除公约数 
	int cm= commonDivisor(abs(a.num),a.den); 
	a.num/=cm;
	a.den/=cm;
	
	return a;
}

//分数乘法 
FRACTION multiple(FRACTION a,FRACTION b){
	 
	 a.num*=b.num;
	 a.den*=b.den;
	 
	int cm= commonDivisor(abs(a.num),a.den); 
	a.num/=cm;
	a.den/=cm;
	
	return a;
}


//分数的除法 
FRACTION division(FRACTION a,FRACTION b){
	int temp;
  if(b.num==0){
       a.num=0;
       a.den=0;
	   return a;//不能除0 ，返回分子，分母为0，作为标志 
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
