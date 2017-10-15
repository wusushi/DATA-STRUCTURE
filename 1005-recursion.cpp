#include <stdio.h>
#include <stdlib.h>

int factorial(int);         /*n! = n*(n-1)*(n-2)*...*2*1 */
int fibonacci(int);                /*Fn = F(n-1)+F(n-2) */
void TOH(int,char,char,char);             /*source -->  destination */
int main() {
	int n,i=1;
	printf("Please enter a number for the Factorial of n : ");
	scanf("%d",&n);
	printf("%d! = %d\n",n,factorial(n));
	fflush(stdin);          /*clear the register */
	printf("Please enter a number for the Fibonacci of n : ");
	scanf("%d",&n);
	printf("F%d = %d\n",n,fibonacci(n));
	fflush(stdin);
	printf("Please enter a number for the tower of Hanoi : ");
	scanf("%d",&n);
	printf("the tower of Hanoi of %d :\n",n);
	TOH(n,'A','B','C');
	return 0;
} 
int factorial(int n){         /*0!=1, 1!=1, 2!=2, 3!=6, 4!=24, 5!=120, 6!=720, 7!=5040...*/
	if(n<=1){
		return n=1;            /*0!=1, 1!=1*/
	}
	else{
		return n=n*factorial(n-1);       /*  n*(n-1)  */
	}
}
int fibonacci(int n){       /*1, 1, 2, 3, 5, 8, 13, 21, 34, 55*/
	if(n<=2){
		return n=1;        /*1, 1*/
	}
	else{
		return fibonacci(n-1)+fibonacci(n-2);     /* n = (n-1) + (n-2) */
	}
}
void TOH(int n,char source,char temp,char destination){     /*n = which sheet ,put the n of sheet from source to destination*/
	if(n==1){
		printf("the number %d of sheet : %c --> %c\n",n,source,destination);
	}
	else{
		TOH(n-1,source,destination,temp);    /* number of times : n-1, A --> B */
        printf("the number %d of sheet : %c --> %c\n",n,source,destination);    /* A --> C */
        TOH(n-1,temp,source,destination);      /* number of times : n-1, B --> C */
	}
}
