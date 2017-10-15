#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/*stack : first in last out ; queue : first in first out*/
void qadd(char*,char,int);
void qdelete(char*,int,int,int);
void refresh(char*,int,int,int);
void line(int*,int*);
void queue1(int*,int,int,int);
void queue2(int*,int,int,int);
int main() {
	char a[MAX]="ABCB";
	int q1[MAX]={6,9,3,7,5},q2[MAX]={5,7,6};
	char b='D';
	int n,front=0,rear;
	for(n=0;n<MAX;n++){        /*the numbers of array*/
		if(a[n]=='\0'){
			break;
		}
	} 
//	printf("%d\n",n);
    rear=n;
	qadd(a,b,rear);
	qdelete(a,front,rear,n);
	refresh(a,n,front,rear);
	line(q1,q2);
	return 0;
} 
void qadd(char *a,char b,int rear){  /*put new element into the last*/
	a[rear]=b;
	printf("%s\n",a);
	rear++;
}
void qdelete(char *a,int front,int rear,int n){    /*remove the first element*/
	if(front!=rear){
		for(front++;front<=n;front++){    /*a[front] : 0 --> 1*/
//			printf("%d",front);
			printf("%c",a[front]);
		}
	}
	printf("\n");
}
void refresh(char *a,int n,int front,int rear){   /*remove the all elements before a[front]*/
	if(front!=0){
		while(rear!=n-1){
			front--;
			rear--;
		}
	}
	printf("%d\n",front);
}
void line(int *q1,int *q2){      /*line system*/
	int s,n1,n2,front1=0,front2=0,rear1,rear2,i1=0,i2=0;
	for(n1=0;n1<MAX;n1++){        /*the numbers of q1*/
		if(q1[n1]=='\0'){
			break;
		}
	}
	rear1=n1; 
	for(n2=0;n2<MAX;n2++){         /*the numbers of q2*/
		if(q2[n2]=='\0'){
			break;
		}
	} 
	rear2=n2;
	scanf("%d",&s);
	while(s>-3){
		if(s==-1){         /*if s=-1 , remove the first element of the q1*/
			front1++;
		    i1++;
			queue1(q1,i1,front1,rear1);
			n1--;
		}
		else if(s==-2){      /*if s=-2 , remove the first element of the q2*/
			front2++;
			i2++;
			queue2(q2,i2,front2,rear2);
			n2--;
		}
		else if(s>=0){
			if(n1<=n2){        /*if n1<=n2 , put s into q1*/
				q1[rear1]=s;
		        rear1++;
		        queue1(q1,i1,front1,rear1);
		        n1++;
	        }
	        else{
	        	q2[rear2]=s;          /*on the contrary,put s into q2*/
		        rear2++;
		        queue2(q2,i2,front2,rear2);
		        n2++;
	        }
		}
		scanf("%d",&s);
	}
	queue1(q1,i1,front1,rear1);
	queue2(q2,i2,front2,rear2);
}
void queue1(int *q1,int i1,int front1,int rear1){     /*current q1*/
	printf("q1 : ");
	for(front1=i1;front1<rear1;front1++){
		printf("%d",q1[front1]);
	}
	printf("\n");
}
void queue2(int *q2,int i2,int front2,int rear2){    /*current q2*/
	printf("q2 : ");
	for(front2=i2;front2<rear2;front2++){
		printf("%d",q2[front2]);
	}
	printf("\n");
}
