#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include "itemopeation.h"


int number[4]={0};//������ĸ����� 
PITEM p1_head=NULL;//��һ��Ⱥ 
PITEM p2_head=NULL;//�ڶ���Ⱥ 
PITEM p3_head=NULL;//������Ⱥ 
PITEM p4_head=NULL;//������Ⱥ 

int cmp(PITEM left,PITEM right); //�Ƚ�����ʹ�õ������Ƿ��н��� 
void free_all_node(); //�ͷ����м�Ⱥ�ռ� 
void calc();    
void input();  //�������� 

void list_cross(PITEM left,PITEM right,PITEM result); //��ϲ�����һ��Ⱥ 
    
void output();
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	p1_head=(struct s_item*)malloc(sizeof(ITEM));
   
    input();         //����ͬʱ������һ��Ⱥ 
    
    calc(); 
    
   
    output();
    
    free_all_node();
    
    getch();
	return 0;
}


void input(){
	printf("�������ĸ�����\n");
	int count=0;
	
	//��������������һ��Ⱥ 
	while(count<4){

	if(scanf("%d",&number[count])!=1){
		continue;
	}
	
	//���ɽڵ� 
	PITEM pnew;
	pnew=(struct s_item*)malloc(sizeof(ITEM));
	
	int j=0;
	for(j=0;j<4;j++){
		pnew->flag[j]=0;
	}
	
	pnew->flag[count]=1;
	FRACTION a;
	a.num=number[count];a.den=1;
	pnew->value=a;
	
	int i=0;//��ʼ��
	for(i=0;i<40;i++){
		pnew->expr[i]='\0';
	} 
			
	itoa(number[count],pnew->expr,10);		
	
	pnew->flag[count]=1;
	
	pnew->next=p1_head->next;
	p1_head->next=pnew;
	
	
	
	count++;
    }
	
} 




//���Ĵ���������ļ�Ⱥ 
void calc(){
	
	
	//������Ⱥ��
	p2_head=(struct s_item*)malloc(sizeof(ITEM));
	p2_head->next=NULL;
	
	list_cross(p1_head,p1_head,p2_head);  //������Ⱥ�� 
	
	//������Ⱥ��
	p3_head=(struct s_item*)malloc(sizeof(ITEM));
	p3_head->next=NULL;
	
	list_cross(p1_head,p2_head,p3_head);  //������Ⱥ�� 
	
	//������Ⱥ��
	p4_head=(struct s_item*)malloc(sizeof(ITEM));
	p4_head->next=NULL;
	
	list_cross(p2_head,p2_head,p4_head);  //������Ⱥ�� 
	list_cross(p1_head,p3_head,p4_head);  //������Ⱥ�� 

	
}

//�Ƚϼ�Ⱥ֮���Ƿ�����ͬ���� 
int cmp(PITEM left,PITEM right){
	int i;
	for(i=0;i<4;i++){
		if(left->flag[i]==1&&right->flag[i]==1){
			return 1;
		}
	}
	return 0;
}

//���������Ⱥ������һ����Ⱥ 
void list_cross(PITEM left,PITEM right,PITEM result){
	
	    PITEM p,q;
		for(p=left->next;p!=NULL;p=p->next){       //ѭ������������Ⱥ�����м��� 
		for(q=right->next;q!=NULL;q=q->next)
		     if(cmp(p,q)==0){         //ֻ�������ϲ�����ͬ���ֲ����� 
		     	  PITEM temp=NULL;
		     	  if((temp=add(p,q))!=NULL){
		     	  	  temp->next=result->next;
		     	  	  result->next=temp;
				   } 
				    if((temp=subtract(p,q))!=NULL){
		     	  	  temp->next=result->next;
		     	  	  result->next=temp;
				   } 
				    if((temp=divide(p,q))!=NULL){
		     	  	  temp->next=result->next;
		     	  	  result->next=temp;
				   } 
				    if((temp=mutiply(p,q))!=NULL){
		     	  	  temp->next=result->next;
		     	  	  result->next=temp;
				   } 
				  
			 }
	}
}

//������ 
void output(){
	 
	 PITEM p=p4_head->next;  //pָ����ļ�Ⱥ��ͷ��㣬���ļ�Ⱥ������ĸ����ֶ��Ѿ�ʹ�õļ��� 

	 //�����ظ��ı��ʽ 
	 
	 PITEM q,pre;
	 for(;p!=NULL;p=p->next){
	 	for(q=p->next,pre=p;q!=NULL;){
	 		   if(strcmp(p->expr,q->expr)==0){
	 		   	     
	 		   	     pre->next=q->next;
	 		   	     PITEM temp=q;       //preΪp��ǰһ���ڵ� 
	 		   	     q=q->next;
	 		   	    
	 		   	     free(temp);//��ʧ�ظ���; 
	 		   	     temp=NULL;
	 		   	     
				}else{
					q=q->next;
					pre=pre->next;
				}
		 }
	 }
	 
	 
	 //��� 
	 p=p4_head->next;
	 while(p!=NULL){
	   if(p->value.num==24&&p->value.den==1){
      
	 	 puts(p->expr);
	   
	 }


	 	p=p->next;
	 	} 
	
 }
	



void free_node(PITEM p){
	while(p!=NULL){
		PITEM temp=p;
		p=p->next;
		
		free(temp);
		temp=NULL;
	}
}
//�ͷż�Ⱥ�ռ� 
void free_all_node(){
   free_node(p1_head);
   free_node(p2_head);
   free_node(p3_head);
   free_node(p4_head);
} 












