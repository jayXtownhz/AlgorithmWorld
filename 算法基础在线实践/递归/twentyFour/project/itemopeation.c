#include "itemopeation.h"

extern int number[4]; 

PITEM add(PITEM a,PITEM b) //两个相加 
{	
	
	  PITEM x=(struct s_item*)malloc(sizeof(struct s_item));
      x->value=plus(a->value,b->value);
      
      int m;
      for(m=0;m<4;m++){
      	 x->flag[m]=0;
	  }
      

      int k=0;
      x->expr[k]='(';
      int j;
      for(j=0;a->expr[j]!='\0';j++){
      	  x->expr[++k]=a->expr[j];
	  }
	  x->expr[++k]='+'; 
	  for(j=0;b->expr[j]!='\0';j++){
      	  x->expr[++k]=b->expr[j];
	  }
	  x->expr[++k]=')';
	  x->expr[++k]='\0';
	    
	
	  int i=0;
	  for(i=0;i<4;i++){
	  	   if(a->flag[i]==1){
	  	   	    x->flag[i]=1;
			 }
			
		    if(b->flag[i]==1){
		    	x->flag[i]=1;
			}
			 
			 
	  }
	  
      x->next=NULL; 
     
      return x;
}


PITEM divide(PITEM a,PITEM b){ //集合相除 
	 PITEM x=(struct s_item*)malloc(sizeof(struct s_item));
      x->value=division(a->value,b->value);
      
           int m;
      for(m=0;m<4;m++){
      	 x->flag[m]=0;
	  }
      if(x->value.num==0&&x->value.den==0){
      	   free(x);
      	   return NULL;
	  }
      
         int k=0;
      x->expr[k]='(';
      int j;
      for(j=0;a->expr[j]!='\0';j++){
      	  x->expr[++k]=a->expr[j];
	  }
	  x->expr[++k]='/'; 
	  for(j=0;b->expr[j]!='\0';j++){
      	  x->expr[++k]=b->expr[j];
	  }
	  x->expr[++k]=')';
	  x->expr[++k]='\0';
	  
	  int i=0;
	  for(i=0;i<4;i++){
	  	   if(a->flag[i]==1){
	  	   	    x->flag[i]=1;
			 }
			
		    if(b->flag[i]==1){
		    	x->flag[i]=1;
			}
			 
			 
	  }
	  
      x->next=NULL; 
      return x;
}
PITEM mutiply(PITEM a,PITEM b)//两个相乘 
{
      PITEM x=(struct s_item*)malloc(sizeof(struct s_item));
      x->value=multiple(a->value,b->value);
           int m;
      for(m=0;m<4;m++){
      	 x->flag[m]=0;
	  }
         int k=0;
      x->expr[k]='(';
      int j;
      for(j=0;a->expr[j]!='\0';j++){
      	  x->expr[++k]=a->expr[j];
	  }
	  x->expr[++k]='*'; 
	  for(j=0;b->expr[j]!='\0';j++){
      	  x->expr[++k]=b->expr[j];
	  }
	  x->expr[++k]=')';
	  x->expr[++k]='\0';
	  
	  int i=0;
	  for(i=0;i<4;i++){
	  	   if(a->flag[i]==1){
	  	   	    x->flag[i]=1;
			 }
			
		    if(b->flag[i]==1){
		    	x->flag[i]=1;
			}
			 
			 
	  }
	  
      x->next=NULL; 
      return x;
}


PITEM subtract(PITEM a,PITEM b){  //相减 
	 PITEM x=(struct s_item*)malloc(sizeof(struct s_item));
      x->value=sub(a->value,b->value);
           int m;
      for(m=0;m<4;m++){
      	 x->flag[m]=0;
	  }
         int k=0;
      x->expr[k]='(';
      int j;
      for(j=0;a->expr[j]!='\0';j++){
      	  x->expr[++k]=a->expr[j];
	  }
	  x->expr[++k]='-'; 
	  for(j=0;b->expr[j]!='\0';j++){
      	  x->expr[++k]=b->expr[j];
	  }
	  x->expr[++k]=')';
	  x->expr[++k]='\0';
	  
	  int i=0;
	  for(i=0;i<4;i++){
	  	   if(a->flag[i]==1){
	  	   	    x->flag[i]=1;
			 }
			
		    if(b->flag[i]==1){
		    	x->flag[i]=1;
			}
			 
			 
	  }
	  
      x->next=NULL; 
      return x;
}



