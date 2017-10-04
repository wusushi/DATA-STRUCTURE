#include <stdio.h> 

void MyBubble();
void MyInsertion();
void MySelection();
void MyShell();

int main() {
    MyBubble();
    MyInsertion();
    MySelection();
    MyShell();
	return 0;
}
void MyBubble(){                  /*compare each adjacent items and swap them*/
	int a[]={58,21,6,96,78},i,j;
	printf("氣泡排序法:");
	for(i=0;i<sizeof(a)/sizeof(int);i++){         /*i = elements numbers*/
		for(j=sizeof(a)/sizeof(int)-i-1;j>=0;j--){      /*ascending order*/
			if(a[j]<a[j-1]){                       /*swap*/ 
				a[j]=a[j]+a[j-1];
				a[j-1]=a[j]-a[j-1];
				a[j]=a[j]-a[j-1];
			}
		}
		printf("%d,",a[i]);
    }
}
void MyInsertion(){            /*put the left-most element which is not arranged into the sorted list and sort*/
	int a[]={58,21,6,96,78},i,j;
	printf("\n插入排序法:");
	for(i=0;i<sizeof(a)/sizeof(int);i++){           
		for(j=i;j>=0;j--){                        /*j = the sorted numbers*/
			if(a[j]<a[j-1]){
				a[j]=a[j]+a[j-1];
			    a[j-1]=a[j]-a[j-1];
			    a[j]=a[j]-a[j-1];
		    }
		}
	}
	for(i=0;i<sizeof(a)/sizeof(int);i++)printf("%d,",a[i]);/*the left-most element is not necessarily the smallest*/
}
void MySelection(){             /*put the smallest element which is not arranged into the right-most sorted list*/
	int a[]={58,21,6,96,78},i,j;
	printf("\n選擇排序法:");
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		for(j=i;j<sizeof(a)/sizeof(int);j++){        /*find out the smallest element which is unsorted*/
			if(a[j]<a[i]){
				a[j]=a[j]+a[i];
				a[i]=a[j]-a[i];
				a[j]=a[j]-a[i];
			}
		}
		printf("%d,",a[i]);
	}
}
void MyShell(){         /*a generalizaation of insertion sort*/
	int a[]={58,21,6,96,78},i,j,m;
	printf("\n希爾排序法:");   /*i = divide the list elements into two groups and repeat until turn out to be one group*/
	for(i=sizeof(a)/sizeof(int)/2;i>=1;i/=2){    /*ex:5   i=2-->1   ;  ex:11   i=5-->2-->1;*/
		for(j=0;j<sizeof(a)/sizeof(int)/i;j++){     /*j = the numbers of the group*/
		    for(m=1;(j+i*m)<sizeof(a)/sizeof(int);m++){    /*m = the numbers of the elements of the group*/
		    	if(a[j]>a[j+i*m]){
		    		a[j]=a[j]+a[j+i*m];
				    a[j+i*m]=a[j]-a[j+i*m];
				    a[j]=a[j]-a[j+i*m];
			    }
			}
		}
	}
	for(i=0;i<sizeof(a)/sizeof(int);i++)printf("%d,",a[i]);
}
