#include <stdio.h>
#include <stdlib.h>
/*It represent a binary tree by linked list and recursive idea*/
/*malloc is a dynamic address,and can't know what you may considered as to be in it*/
typedef struct node{
	char data;
	struct node *leftchild;
	struct node *rightchild;
}node;
node *tree;
void add(char a){   /*add the node of the root*/
	node *tmp = (node*)malloc(sizeof(node));   /*add an address*/
	tmp->data = a;    /*the new address data is the variable of a*/
	tree = tmp;           /*paste the new address into the tree*/
	printf("%c\n",tree->data);
}
void addleft(char a,node *tree){     /*add the node of the leftchild into the root*/
	node *tmp = (node*)malloc(sizeof(node));
	tmp->data = a;
	tree->leftchild = tmp;
	printf("tree->data : %c\n",tree->data);
	printf("%c\n",tree->leftchild->data);
	tree->leftchild->leftchild = '\0';      /*put an empty value into the new leftchild of the new root*/
	tree->leftchild->rightchild = '\0';      /*put an empty value into the new rightchild of the new root*/
}
void addright(char a,node *tree){       /*add the node of the rightchild into the root*/
	node *tmp = (node*)malloc(sizeof(node));
	tmp->data = a;
	tree->rightchild = tmp;
	printf("tree->data : %c\n",tree->data);
	printf("%c\n",tree->rightchild->data);
	tree->rightchild->leftchild = '\0';
	tree->rightchild->rightchild = '\0';
}
void preorder(node *tree){        /*root -> leftchild -> rightchild*/
	if(tree){
		printf("%c, ",tree->data);
		preorder(tree->leftchild);
		preorder(tree->rightchild);
	}
}
void xorder(node *tree){      /*root -> rightchild -> leftchild*/
	if(tree){
		printf("%c, ",tree->data);
		xorder(tree->rightchild);
		xorder(tree->leftchild);
	}
}
int main() {
	add('A');
	addleft('F',tree);
	addleft('I',tree->leftchild);
	addright('G',tree->leftchild);
	addright('H',tree->leftchild->rightchild);
	addright('B',tree);
	addleft('E',tree->rightchild);
	addright('C',tree->rightchild);
	addleft('D',tree->rightchild->rightchild);
	preorder(tree);
	printf("\n\n");
	xorder(tree);
	printf("\n\n");
	return 0;
}
