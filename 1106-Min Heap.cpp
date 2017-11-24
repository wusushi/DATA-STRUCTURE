#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
//input the function¡Glog() whose base is e 
//sort the array by MIn Heap
				          
int main() {
	int a[] = {58,21,6,96,78,44,87,52,13,47,17};
	int j = 0, k = 0;
	/*
	testing¡Flog()
	int z = log(8) / log(2);
	printf("%d\n", z);
	*/
	for (j = 0;j < log(sizeof(a)/sizeof(int) + 1) / log(2);j++) {
		//the complexity of min heap is O(log(n + 1) / log(2))
		
		for (k = 0;k < sizeof(a)/sizeof(int)/2;k++) {
			//compare the parent and it's children
			
			if (a[k * 2 + 2] == '\0') {
				//if parent doesn't have right child
				
				if (a[k] > a[k * 2 + 1]) {
					// swamp it if left child is less than it's parent
					
					a[k] = a[k] + a[k * 2 + 1];
					a[k * 2 + 1] = a[k] - a[k * 2 + 1];
					a[k] = a[k] - a[k * 2 + 1];
				}
			}
			else if (a[k * 2 + 1] < a[k * 2 + 2]) {
				//if left child is less than right child
				
				if (a[k] > a[k * 2 + 1]) {
					// swamp it if left child is less than it's parent
					
					a[k] = a[k] + a[k * 2 + 1];
					a[k * 2 + 1] = a[k] - a[k * 2 + 1];
					a[k] = a[k] - a[k * 2 + 1];
				}
			}
			else {
				//if left child is greater than right child
				
				if (a[k] > a[k * 2 + 2]) {
					// swamp it if right child is less than it's parent
					
				    a[k] = a[k] + a[k * 2 + 2];
					a[k * 2 + 2] = a[k] - a[k * 2 + 2];
					a[k] = a[k] - a[k * 2 + 2];
			    }
			}
		}
	}
	printf("Min heaps : ");
	for (j = 0;j < sizeof(a)/sizeof(int); j++) printf("%d,", a[j]);
	//print the sorted array by min heap
	return 0;
}
