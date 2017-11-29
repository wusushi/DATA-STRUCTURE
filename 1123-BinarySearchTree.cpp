#include <stdio.h>
#include <stdlib.h>

int a[] = {2,5,7,13,18,29,33,50};

typedef struct node{
	int data;
	struct node *leftchild, *rightchild;
}node;

int question_find() {
	//ask for the question about search element and return which element do you want to search for
	
	int d;
	
	printf("Which element do you want to search¡G");
	scanf("%d", &d);
	return d;
}

void array_BinarySearchTree(int d) {
	//it represents an idea about BinarySearchTree depends on array
	 
	int max = sizeof(a)/sizeof(int);
	int left = 0, right = max - 1, mid = max/2 - 1;
	//left : the index of the array ; right : the rear element of the array ; mid : the middle element of the array (the root of the tree)
	
	while (a[left] < a[right]&&mid < max&&mid >= 0) {
		//if the left element is larger than the right element ,jump awat the loop (BinarySearchTree is an ascend order)
		
		if (a[mid] == d) {
			// if find out what you input
			
			printf("OH! you got it!\n");
			printf("you find it at a[%d]¡G %d\n", mid, a[mid]);
			break;
		}
		else if (a[mid] > d) {
			// if the element is less than the standard (a[mid]) ,it should be in the left of the array (a[mid--])
			
			left++;
			// if the element is not in the array ,a[left] would be larger than a[right]
			
			mid--;
		}
		else {
			// if the element is larger than the standard (a[mid]) ,it should be in the right of the array (a[mid++])
			
			right--;
			// if the element is not in the array ,a[right] would be less than a[left]
			
			mid++;
		} 
	}
	if (a[mid] != d) {
		// if the element is not in the array
		
		printf("Oops! that's not true!\n");
	}
}

void add(int d, int i, node *tree) {
	//link the node to the tree
	
	node *tmp = (node*)malloc(sizeof(node));
	tmp->data = d;
	// the node you want to link
	
	switch (i) {
		case 1:
			// if want to link at the left of the tree
			
		    tree->leftchild = tmp;
		    tree->leftchild->leftchild = '\0';
		    tree->leftchild->rightchild = '\0';
			break;
		case 2:
			// if want to link at the right of the tree
			
		    tree->rightchild = tmp;
		    tree->rightchild->leftchild = '\0';
		    tree->rightchild->rightchild = '\0';
			break;
		default:
		    break; 
	}
}

node *searchparent(node *tree, int d) {
    //search for the key(parent) of the node
	 
	node *tmp = tree;
	printf("tmp->data ¡F %d\n", tmp->data);
	// the root of the tree
	
	while(((tmp->leftchild != '\0') ? tmp->leftchild->data != d : tmp != '\0')&&((tmp->rightchild != '\0') ? tmp->rightchild->data != d : tmp != '\0')&&tmp->data != d) {
		// the current node might not have the left of the node(leftchild) or the right of the node(rightchild) 
		
		if (tmp->data > d) {
			// if the data you search for is less than the current node ,it might be at the the left of the node
			
			if (tmp->leftchild == '\0') {
				// if the current node doesn't have the left node, it might not be in this tree
				
				break;
			}
			else if (tmp->leftchild->data < d&&tmp->leftchild->rightchild == '\0') {
				// if the left of the current node isn't larger than the data, it might not be in this tree
				// in addition, the left of the current node doesn't have the rightchild, it might not be in this tree
				
				break;
			}
			tmp = tmp->leftchild;
			// search for the next(the left of the current node)
			
		}
		else if (tmp->data < d) {
			// if the data you search for is larger than the current node ,it might be at the the right of the node(opposite to the last if loop)
			
			if (tmp->rightchild == '\0') {
				
				break;
			}
			else if (tmp->rightchild->data > d&&tmp->rightchild->leftchild == '\0') {
				break;
			}
			tmp = tmp->rightchild;
		}
		printf("tmp->data ¡F %d\n", tmp->data);
	}
	return tmp;
}

void node_BinarySearchTree(node *tree, int d) {
	//it represents an idea about binary search tree depends on linked list
	
	node *tmp = searchparent(tree, d);
    if (tmp->data == d) {
    	//if the data is at the root of the tree
    	
    	printf("you find out it at %p\n", tmp);
		printf("OH! you got it!\n");
	}
	else if ((tmp->leftchild != '\0') ? tmp->leftchild->data == d : tmp == '\0') {
		//if the data is at the left the tmp(the parent node of the node)
    	
		printf("tmp->leftchild->data ¡F %d\n", tmp->leftchild->data);
		printf("you find out it at %p\n", tmp->leftchild);
		printf("OH! you got it!\n");
	}
	else if ((tmp->rightchild != '\0') ? tmp->rightchild->data == d : tmp == '\0') {
		//if the data is at the right the tmp(the parent node of the node)
    	
		printf("tmp->rightchild->data ¡F %d\n", tmp->rightchild->data);
		printf("you find out it at %p\n", tmp->rightchild);
		printf("OH! you got it!\n");
	}
	else {
		//if the data is not at the tree
    	
		printf("Oops! that's not true!\n");
	}
}

void node_BinaryDeleteTree(node *tree) {
	int d = 0;
	
	printf("Which element do you want to delete¡G");
	scanf("%d", &d);
	node *tmp = searchparent(tree, d);
	//find out the parent of the tree if it is in the tree
	
	if (tmp->data == d) {
		// if it is at the root of the tree
		
		if (tmp->leftchild != '\0') {
			// if it has the left of the tree, then find out the rightest of the left of the tree
			
			node *rep = tmp->leftchild;
			//rep is the left of the tmp(the left node of the root)
			
			while (rep->rightchild != '\0') {
				// if it has the right node of the current rep
				
				rep = rep->rightchild;
				//find out the next
			}
			printf("rep->data : %d\n", rep->data);
			node *parent = searchparent(tree, rep->data);
			//find out the parent of the rep(the node replace the root of the tree)
			
			if (tmp->rightchild != '\0') {
				// if the tree has the right of the tree
				
				rep->rightchild = tmp->rightchild;
				//the right node of the rep is the right node of the root
			}
			if (rep == tmp->leftchild) {
				// if rep is the left node of the root(the left node of the tree dosen't have the right node
				
				if (tmp->leftchild->leftchild != '\0') {
					// if the left node of the tree has the left node
					
					tmp->leftchild = tmp->leftchild->leftchild;
					// the current left node of the root is the the left node of the left node of the tree
				}
				else {
					// if the left node of the tree dosen't have the left node
					
					tmp->leftchild = '\0';
				}
			}
			else {
				// if rep is not the left node of the root(the left node of the tree has the right node
				
				rep->leftchild = tmp->leftchild;
				// the left node of the rep is the left node of the root
				
				parent->rightchild = '\0';
				// the right node of the parent(the parent of the node replace the root) link to NULL
			}
			tmp->data = rep->data;
			// you can't change the address of the root, so change the value of it
		}
	}
	else if ((tmp->leftchild != '\0') ? tmp->leftchild->data == d : tmp == '\0') {
		// if it is at the left of the tmp(the parent node of the tree)
		
		if (tmp->leftchild->leftchild != '\0'&&tmp->leftchild->rightchild != '\0') {
			// if it links two node (the idea depends on deletind the root)
			
			node *rep = tmp->leftchild->leftchild;
			while (rep->rightchild != '\0') {
				rep = rep->rightchild;
			}
			printf("rep->data : %d\n", rep->data);
			rep->rightchild = tmp->leftchild->rightchild;
			if (rep == tmp->leftchild->leftchild) {
				if (tmp->leftchild->leftchild->leftchild != '\0') {
					rep->leftchild = tmp->leftchild->leftchild->leftchild;
				}
			}
			else {
				rep->leftchild = tmp->leftchild->leftchild;
			}
			tmp->leftchild = rep;
			// you can change the address of the left node of the parent
		}
		else if (tmp->leftchild->leftchild != '\0') {
		    // if it only link to the left of the left of the tmp(the parent node of the tree)
		    
			tmp->leftchild = tmp->leftchild->leftchild;
			//link to next
		}
		else if (tmp->leftchild->rightchild != '\0') {
			// if it only link to the right of the left of the tmp(the parent node of the tree)
			
			tmp->leftchild = tmp->leftchild->rightchild;
			//link to next
		}
		else {
			// if it is the leaf of the left of the tmp(the parent node of the tree)
			
			tmp->leftchild = '\0';
			//the left node of the parent links to NULL
		}
	}
	else if ((tmp->rightchild != '\0') ? tmp->rightchild->data == d : tmp == '\0') {
		// if it is at the right of the tmp(the parent node of the tree)
		// the idea depends on deeting the left node of the tmp
		
		if (tmp->rightchild->leftchild != '\0'&&tmp->rightchild->rightchild != '\0') {
			node *rep = tmp->rightchild->leftchild;
			while (rep->rightchild != '\0') {
				rep = rep->rightchild; 
			}
			printf("rep->data : %d\n", rep->data);
			rep->rightchild = tmp->rightchild->rightchild;
			if (rep == tmp->rightchild->leftchild) {
				if (tmp->rightchild->leftchild->leftchild != '\0') {
					rep->leftchild = tmp->rightchild->leftchild->leftchild;
				}
			}
			else {
				rep->leftchild = tmp->rightchild->leftchild;
			}
			tmp->rightchild = rep;
		}
		else if (tmp->rightchild->leftchild != '\0') {
			tmp->rightchild = tmp->rightchild->leftchild;
		}
		else if (tmp->rightchild->rightchild != '\0') {
			tmp->rightchild = tmp->rightchild->rightchild;
		}
		else {
			tmp->rightchild = '\0';
		}
	}
	else {
		// if the data you want to delete is not in the tree
		
		printf("Oops! the tree doesn't have this element!\n");
	}
	d = question_find();
	node_BinarySearchTree(tree, d);
	// find the data you want to delete, whether it is in the tree or not
}

void preorder(node *tree) {
	// print out the tree depends on preorder
	
	node *tmp = tree;
	if (tmp != '\0') {
		preorder(tmp->leftchild);
		printf("%d,", tmp->data);
		preorder(tmp->rightchild);
	}
}

int main() {
	int d;
	d = question_find();
	array_BinarySearchTree(d);
    node *tree = (node*)malloc(sizeof(node));
	tree->data = 30;                        /*       30                  */
	add(5,1,tree);                         /*       /  \                */
	add(2,1,tree->leftchild);             /*       5   40              */      
	add(40,2,tree);                      /*       /   /  \            */
	add(35,1,tree->rightchild);         /*       2   35   80         */
	add(80,2,tree->rightchild);
	d = question_find();
	node_BinarySearchTree(tree, d);
	preorder(tree);
	printf("\n");
	node_BinaryDeleteTree(tree);
	preorder(tree);
	printf("\n");
	return 0;
}
