#include <stdio.h>
#include <stdlib.h>


void hollow(int n) {                            
	//from 1 to (n- 1) hollow part tall               
	
	int i, j;    
	
	for (i = 0;i < (n - 1);i++) {
		for (j = 0;j <= (n - 1) + i;j++) {
			if (j == (n - 1 - i) || j == (n - 1 + i)) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

void Hollow_Pyramid(int n) {                  
	//the n line
	
	int i, j;
	
	hollow(n);
	for (j = 0;j < n * 2 - 1;j++) {       
		printf("*");
	} 
	printf("\n");
}

void Hollow_Arrow(int n) {
	//from n line to (n + 2) line
	
	int i, j;
	
	hollow(n);
	for (i = 0;i < n - 2;i++) {
		for (j = 0;((i == 0) ? (j < n * 2 - 1) : j < n * 2 - n / 2 - 1);j++) {
			if (j > (n / 2)&&j < n * 2 - n / 2 - 2) {
				printf(" ");
			}
			else if (i > 0&&j < (n / 2)) {
				printf(" ");
			}
			else {
				printf("*");
			}
		} 
		printf("\n");
	}
	for (i = 0;i < n * 2 - n / 2 - 1;i++) {
		//the (n - 2) line
		
		if (i < (n / 2)) {
			printf(" ");
		}
		else {
			printf("*");
		}
	}
	printf("\n");
}

void Hollow_ChristmasTree(int n) {
	//from n line to (n + 2) line
	
	int i, j;
	
	hollow(n);
	for (i = 0;i < 2;i++) {
		for (j = 0;((i == 0) ? (j < n * 2 - 1) : j < n + 1);j++) {
			if (j > (n - 2)&&j < n) {
				printf(" ");
			}
			else if (i > 0&&j < (n - 2)) {
				printf(" ");
			}
			else {
				printf("*");
			}
		} 
		printf("\n");
	}
	for (i = 0;i < n + 1 ;i++) {
		//the (n + 2) line
		
		if (i < (n - 2)) {
			printf(" ");
		}
		else {
			printf("*");
		}
	}
	printf("\n");
}

void conversion(int n, int base) {     // (i.e.)n = 10, base = 2  --> output : 1010 
	//convert n in base base
	
	if (n >= base) {
		conversion((n / base), base);
	}
	printf("%d", n % base);
}

int main() {
	int n, base;
	
	printf("How tall is hollow pyramid which you want to design : ");
	scanf("%d", &n);
	Hollow_Pyramid(n);
	printf("How tall is hollow christmas tree which you want to design : ");
	scanf("%d", &n);
	Hollow_ChristmasTree(n);
	printf("How tall is hollow arrow which you want to design : ");
	scanf("%d", &n);
	Hollow_Arrow(n);
    printf("How big number in decimal you want to convert : ");
	scanf("%d", &n);
	printf("How big you want to design to the base : ");
	scanf("%d", &base);
	conversion(n,base);
	return 0;
}
