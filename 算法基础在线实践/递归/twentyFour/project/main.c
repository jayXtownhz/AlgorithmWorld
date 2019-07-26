#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include "itemopeation.h"


int number[4]={0};//输入的四个整数 
PITEM p1_head=NULL;//第一集群 
PITEM p2_head=NULL;//第二集群 
PITEM p3_head=NULL;//第三集群 
PITEM p4_head=NULL;//第三集群 

int cmp(PITEM left,PITEM right); //比较两个使用的数字是否有交集 
void free_all_node(); //释放所有集群空间 
void calc();    
void input();  //输入数据 

void list_cross(PITEM left,PITEM right,PITEM result); //结合产生下一集群 
    
void output();
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	p1_head=(struct s_item*)malloc(sizeof(ITEM));
   
    input();         //输入同时产生第一集群 
    
    calc(); 
    
   
    output();
    
    free_all_node();
    
    getch();
	return 0;
}


void input(){
	printf("请输入四个整数\n");
	int count=0;
	
	//输入整数产生第一集群 
	while(count<4){

	if(scanf("%d",&number[count])!=1){
		continue;
	}
	
	//生成节点 
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
	
	int i=0;//初始化
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




//核心代码产生第四集群 
void calc(){
	
	
	//产生集群二
	p2_head=(struct s_item*)malloc(sizeof(ITEM));
	p2_head->next=NULL;
	
	list_cross(p1_head,p1_head,p2_head);  //产生集群二 
	
	//产生集群三
	p3_head=(struct s_item*)malloc(sizeof(ITEM));
	p3_head->next=NULL;
	
	list_cross(p1_head,p2_head,p3_head);  //产生集群二 
	
	//产生集群三
	p4_head=(struct s_item*)malloc(sizeof(ITEM));
	p4_head->next=NULL;
	
	list_cross(p2_head,p2_head,p4_head);  //产生集群二 
	list_cross(p1_head,p3_head,p4_head);  //产生集群二 

	
}

//比较集群之间是否有相同数字 
int cmp(PITEM left,PITEM right){
	int i;
	for(i=0;i<4;i++){
		if(left->flag[i]==1&&right->flag[i]==1){
			return 1;
		}
	}
	return 0;
}

//结合两个集群产生下一个集群 
void list_cross(PITEM left,PITEM right,PITEM result){
	
	    PITEM p,q;
		for(p=left->next;p!=NULL;p=p->next){       //循环调用两个集群中所有集合 
		for(q=right->next;q!=NULL;q=q->next)
		     if(cmp(p,q)==0){         //只有两集合不含相同数字才运算 
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

//输出结果 
void output(){
	 
	 PITEM p=p4_head->next;  //p指向第四集群的头结点，第四集群即最后四个数字都已经使用的集合 

	 //消除重复的表达式 
	 
	 PITEM q,pre;
	 for(;p!=NULL;p=p->next){
	 	for(q=p->next,pre=p;q!=NULL;){
	 		   if(strcmp(p->expr,q->expr)==0){
	 		   	     
	 		   	     pre->next=q->next;
	 		   	     PITEM temp=q;       //pre为p的前一个节点 
	 		   	     q=q->next;
	 		   	    
	 		   	     free(temp);//消失重复点; 
	 		   	     temp=NULL;
	 		   	     
				}else{
					q=q->next;
					pre=pre->next;
				}
		 }
	 }
	 
	 
	 //输出 
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
//释放集群空间 
void free_all_node(){
   free_node(p1_head);
   free_node(p2_head);
   free_node(p3_head);
   free_node(p4_head);
} 












