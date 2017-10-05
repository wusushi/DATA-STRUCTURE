#include <stdio.h> 

void MyBubble(int *a,int n,int i,int j);
void MyInsertion(int *a,int n,int i,int j);
void MySelection(int *a,int n,int i,int j);
void MyShell(int *a,int n,int i,int j,int m);
/*subroutine:wanting to declare an array have to declare its size first*/
int main() {
	int a[]={58,21,6,96,78},n=sizeof(a)/sizeof(int),i,j,m;
    MyBubble(a,n,i,j);
    MyInsertion(a,n,i,j);
    MySelection(a,n,i,j);
    MyShell(a,n,i,j,m);
	return 0;
}
void MyBubble(int *a,int n,int i,int j){                  /*compare each adjacent items and swap them*/
	printf("氣泡排序法:");
	for(i=0;i<n;i++){         /*i = elements numbers*/
		for(j=0;j<n-i-1;j++){      /*ascending order*/
			if(a[j]>a[j+1]){                       /*swap*/ 
				a[j]=a[j]+a[j+1];
				a[j+1]=a[j]-a[j+1];
				a[j]=a[j]-a[j+1];
			}
		}
    }
    for(i=0;i<n;i++)printf("%d,",a[i]);
}
void MyInsertion(int *a,int n,int i,int j){  /*put the left-most element which is not arranged into the sorted list and sort*/
	printf("\n插入排序法:");
	for(i=0;i<n;i++){           
		for(j=i;j>=0;j--){                        /*j = the sorted numbers*/
			if(a[j]<a[j-1]){
				a[j]=a[j]+a[j-1];
			    a[j-1]=a[j]-a[j-1];
			    a[j]=a[j]-a[j-1];
		    }
		}
	}
	for(i=0;i<n;i++)printf("%d,",a[i]);/*the left-most element is not necessarily the smallest*/
}
void MySelection(int *a,int n,int i,int j){           /*put the smallest element which is not arranged into the right-most sorted list*/
	printf("\n選擇排序法:");
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){        /*find out the smallest element which is unsorted*/
			if(a[j]<a[i]){
				a[j]=a[j]+a[i];
				a[i]=a[j]-a[i];
				a[j]=a[j]-a[i];
			}
		}
		printf("%d,",a[i]);
	}
}
void MyShell(int *a,int n,int i,int j,int m){         /*a generalizaation of insertion sort*/
	printf("\n希爾排序法:");   /*i = divide the list elements into two groups and repeat until turn out to be one group*/
	for(i=n/2;i>=1;i/=2){    /*ex:5   i=2-->1   ;  ex:11   i=5-->2-->1;*/
		for(j=0;j<n/i;j++){     /*j = the numbers of the group*/
		    for(m=1;(j+i*m)<n;m++){    /*m = the numbers of the elements of the group*/
		    	if(a[j]>a[j+i*m]){
		    		a[j]=a[j]+a[j+i*m];
				    a[j+i*m]=a[j]-a[j+i*m];
				    a[j]=a[j]-a[j+i*m];
			    }
			}
		}
	}
	for(i=0;i<n;i++)printf("%d,",a[i]);
}
