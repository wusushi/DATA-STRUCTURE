#include <stdio.h>
#include <stdlib.h>
//Sorting algorithm : selection, insertion, quick

typedef struct node{
	int data;
	struct node *link;
}node;
node *rear;

void print (int a[], int n, int i) {
	//output the ordered lst by array
	
	for (i = 0;i < n;i++) {
		printf("%d, ", a[i]);
	}
	printf("\n");
}

void show() {
	//output the ordered lst by linked-list
	
	node *tmp = rear->link->link;
	while (tmp->data != -1) {
		printf("%d, ", tmp->data);
		tmp = tmp->link;
	}
	printf("\n");
}

void selection(int a[], int n, int i, int j) {
	//Selection sort : put the minnum number in the unsorted list into the rightest sorted list
	 
	for (i = 0;i < n;i++) {
		for (j = i;j < n;j++) {
			if (a[j] < a[i]) {
				//compare the largest number is ordered with the unsorted list
				
				a[j] = a[i] + a[j];
				a[i] = a[j] - a[i];
				a[j] = a[j] - a[i];
			}
		}
	}
	printf("Selection sort : ");
	print(a,n,i);
	//print the sorted array a by function selection 
}

void add(int n) {
	//add an number(put it before the dummy(the first ang the final)) into a circled linked-list
	
	node *tmp = (node*)malloc(sizeof(node));
	tmp->data = n;
	tmp->link = rear->link;
	rear->link = tmp;
	rear = tmp;
}

void insertion(int a[], int n, int i, int j) {
	//Insertion Sort : insert the first unsorted number in the ordered list
	
	node *dummy = (node*)malloc(sizeof(node));
	//the position is the first number and the final number in the circled linked-list
	
	dummy->data = -1;
	dummy->link = dummy;
	rear = dummy;
	for (i = 0;i < n;i++) {
		add(a[i]);
		//add all numbers in the array a to the linked-list
	}
	node *tmp = rear->link;
	//the node is linked to the next node in the ordered linked-list
	
	node *insert = tmp->link->link; 
	//the node is inserted to the ordered linked-list
	
	node *final = tmp->link;
	//the node is the final node in the ordered linked-list
	
	for (i = 1;i < n;i++) {
		tmp = rear->link;
		//restart the node tmp at the node dummy(beginning node)
		
		for (j = 1;j <= i;j++) {
			if (tmp->link->data > insert->data) {
				//if find out node(be inserted) which is larger than the inserted node
				
				final->link = insert->link;
				//final node links to the node which(the next inserted node) inserted node links to  
				
				insert->link = tmp->link;
				//the inserted node links to the node which tmp links to
				
				tmp->link = insert;
				//and the node tmp links to the inserted node
				
				insert = final->link;
				//the next inserted node
				
				break;
				//escape
			}
			tmp = tmp->link;
			//the next tmp if the current tmp links to is not larger than the inserted node
		}
		if (i != (n - 1 )) {
			//if the rear node is not the final node
			
			if (j == (i + 1)) {
				//if the inserted node is larger than the final node(the next final node is the inserted node) 
				
				final = insert;
				//the next final node is the inserted node(the final node links to)
				
				insert = final->link;
				//the next inserted node is the node next final node links to(the inserted node links to) 
			}
		}
		else {
			//if the rear node is the final node(all node in the linked-list is already sorted)
			 
			rear = final;
		}
//		show();
	}
	printf("Insertion sort : ");
	show();
	//print the sorted circled linked list(array a) by function insertion
}

void quick(int a[], int left, int right) {
	/*Quick sort : consider a number in the array (the first number in the array in this function) as pivot,
	               and all elements less than the pivot come before the pivot, otherwise, come after the pivot, 
				   recursively apply the above steps to the sub-array of elements less than the pivot and elements larger than the pivot seperately
	*/
	
	int pivot = a[left]; 
	int l = left, r = right;
	int k;
	//pivot(the first element in the sub-array) is the the element piclking up all element in the sub-array
	//l is the first index in the sub-array
	//r is the final index in the sub-array
	//k is the variable to algorithm the for loop
	
	left++;
	right--;
	//a[left] is the fist element in the sub-array without the pivot
	//a[right] is the final element in the sub-array
	
	for (k = l;k < r;k++) {
		if (left >= right&&a[l] > a[right]) {
			//if all elements is sorted and the pivot is larger than the tha all element come before the pivot
			
			a[l] = a[right] + a[l];
			a[right] = a[l] - a[right];
			a[l] = a[l] - a[right];
			break;
		}
		else if (left <= right) {
			//all elements in the sub-array is not already sorted
			
			if (a[left] >= pivot&&a[right] <= pivot) {
				//if the left index element is larger than the pivot and the right index element is less than the pivot in the sub-array
				
				a[right] = a[left] + a[right];
				a[left] = a[right] - a[left];
				a[right] = a[right] - a[left];
			}
			if (a[left] <= pivot) {
				//if the left index element is less than the pivot(the left index is sorted)
				
				left++;
			}
			if (a[right] >= pivot) {
				//if the right index element is larger than the pivot(the right index is sorted)
				
				right--;
			}
		}
	}
//	for (k = l;k < r;k++) {
//		printf("%d, ", a[k]);
//	}
//	printf("\n");
    if (right > l&&(r - l) > 2) {
    	//if all elements(the number of them are larger than 3) less than the pivot is not all sorted
    	
    	quick(a, l, right);
	}
    if (left < r&&(r - l) > 2) {
    	//if all elements(the number of them are larger than 3) larger than the pivot is not all sorted
    	
    	quick(a, left, r);
	}
}

int main() {
	int a[] = {12, 2, 16, 30, 8, 28, 4, 10, 20, 6, 18};
	int na = sizeof(a)/sizeof(int);
	int b[] = {26, 5, 37, 1, 61, 11, 59, 15, 48, 19};
	int nb = sizeof(b)/sizeof(int);
	int i = 0, j;
	//the array a is used to repreasent for the function selection and the function insertion
	//na is the numbers of the elements in the array a
	//the array b is used to repreasent for the function quick
	//nb is the numbers of the elements in the array b
	//i and j is used to algorithm for loop
	
	selection(a,na,i,j);
//    insertion(a,na,i,j);
//    quick(b,i,nb);
//	printf("Quick sort : ");
//	print(b,nb,i);
	//print the sorted array b by function quick
	
	return 0;
}
