#include <stdio.h>
#include <stdlib.h>
/*It is a circle queue by linked list*/
typedef struct node{
	int data;
	struct node *link;
}node;
node *rear;
void qadd(int n){
	node *tmp = (node*)malloc(sizeof(node));  /*new address*/
	tmp->link = rear->link;          /*new address link to address*/
	rear->link = tmp;            /*the last address link to new address*/
	tmp->data = n;        /*the new address data is n*/
	rear = tmp;       /*new rear address equals the new address*/
	printf("rear->data : %d\n",rear->data);   /*new value*/
	printf("rear->link : %d\n",rear->link);      /*new rear link to dummy*/
	printf("rear->link->data : %d\n",rear->link->data);   /*dummy's data*/
	printf("rear : %d\n\n\n",rear);         /*the new rear address*/
}
void qdelete(){
	printf("delete : %d\n",rear->link->link->data);    /*the value which is wanted to delete*/
	if(rear->link->link == rear){        /*the value which is wanted to delete is the only data in this links*/
		rear = rear->link;        /*there is only dummy in this link*/
		rear->link = rear;              /*rear link to itself = dummy link to itself*/
 	}
	else{
		rear->link->link = rear->link->link->link;   /*the first value is deleted and dummy link to the second value */
	}
	printf("first : %d\n\n\n",rear->link->link->data);    /*the first value(the second value)*/
}
void print(){
	node *tmp = rear->link->link;  /*the first address*/
	printf("The current node : ");
	while(tmp->data!=-1){    /*if the address is not the dummy*/
		printf("%d , ",tmp->data);  
		tmp = tmp->link;             /*the next address*/
	}
	printf("\n\n\n");
}
int main() {
	node *dummy = (node*)malloc(sizeof(node));  /*dummy is an address which any value is not in it without -1*/
	dummy->data = -1;
	dummy->link = dummy;     /*dummy link to itself*/
	rear = dummy;          /*rear = dummy*/
	printf("dummy : %d\n",dummy);
	printf("dummy->link : %d\n",dummy->link);
	printf("dummy->data : %d\n\n\n",dummy->data);
	qadd(25);
	qadd(55);
	print();
	qadd(47);
	qdelete();
	qdelete();
    qadd(62);
    qadd(56);
	print();
	return 0;
}
