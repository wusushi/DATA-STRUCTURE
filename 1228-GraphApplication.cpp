#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	char direction;
	struct node *leftchild;
	struct node *rightchild;
	struct node *parent;
}node;
//data : the key of the node
//direction : the direction of the node links to
//leftchild : the node links to its leftmost child
//rightchild : the node links to its rightmost child
//parent : the node links to its parent node

char path[10];
//path is an array recorded to the node's position(direction)

int G[6][6] = {{0, 1, 0, 0, 0, 0},        	 /*  0  -->     1   */
               {1, 0, 1, 1, 0, 0},       	 /*  1  -->  0, 2, 3*/
			   {0, 1, 0, 0, 1, 1},       	 /*  2  -->  1, 4, 5*/
			   {0, 1, 0, 0, 0, 1},        	 /*  3  -->    1, 5 */
			   {0, 0, 1, 0, 0, 0},       	 /*  4  -->     2   */
			   {0, 0, 1, 1, 0, 0},};         /*  5  -->    2, 3*/

char V[6] = {'c', 'c', 'c', 'c', 'c', 'c'};
//V is recorded the color of the graph G
			   
void add (int n, int direction, node *tree) {
	//insert a node to the tree, and record the node which links to new node
	
	node *tmp = (node*)malloc(sizeof(node));
	tmp->data = n;
	switch (direction) {
		case 0:
			tree->leftchild = tmp;
			tmp->parent = tree;
			tmp->direction = 'L';
			tmp->leftchild = 0;
			tmp->rightchild = 0;
			break;
		case 1:
			tree->rightchild = tmp;
			tmp->parent = tree;
			tmp->direction = 'R';
			tmp->leftchild = 0;
			tmp->rightchild = 0;
			break;
		default:
			break;
	}
}

int max (int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int treeHeight (node *tree) {
	//algorithm the height of the tree
	
	static int h = 1;
	if (tree == 0) {
		return 0;
	}
	return max(treeHeight(tree->leftchild), treeHeight(tree->rightchild)) + 1;
}

void Find (node *tree, node *root, char data) {
	//find out the path from tree(node) to the root including null node(data) in this tree
	
	int i = 2, j;
	node *tmp = tree;
	
	path[0] = data;
	path[1] = tmp->direction;
	while (tmp->parent != root) {
		path[i++] = tmp->parent->direction;
		tmp = tmp->parent;
	}
	for (j = (i - 1);j >= 0;j--) {
		printf("%c, ", path[j]);
	}
	printf("\t(%d steps)\n", i);
}

void BFS (node *root) {
	//find out the null node in this tree by BFS(breadth first search)
	 
	int a = 1, j;
	node *g[10]; 
	//use node *g[10] to store the node is linked by every g[0]
	
	g[0] = root;
	//the queue starts from the root
	
	for (node *tmp = root; tmp != 0;) {
		tmp = g[0];
		if (tmp->leftchild == 0) {
			//if find out the null at the left node of tmp
			
			Find(tmp, root, 'L');
			break;
		}
		else if (tmp->rightchild == 0) {
			//if find out the null at the right node of tmp
			
			Find(tmp, root, 'R');
			break;
		}
		else {
			//if be not find out the null node at all
			
			if (tmp->leftchild != 0) {
				g[a++] = tmp->leftchild;
			}
			if (tmp->rightchild != 0) {
				g[a++] = tmp->rightchild;
			}
			for (j = 0;j < (a - 1);j++) {
			//throw away the g[0], and move the rest node in the array g to the previous
			
				g[j] = g[j + 1];
			}
//			printf("tmp : %d\n", tmp->data);
		}
	}
}

void bipartite() {
	//bipartite graph is a graph whose vertices are divided to two colors(field), 
	//and the color of every vertex are different from the adjacent vertex
	  
	int i, j;
	for (i = 0; i < 6;i++) {
		for (j = 0;j < 6;j++) {
			if (G[i][j] == 1) {
				//if i links to j
				
				if ((V[i] == 'R'&&V[j] == 'R')||(V[i] == 'R'&&V[j] == 'R')) {
					//if the color of the vertex i is same with the color of the vertex j
					
					printf("OH! the graph is not Bipartite!\n");
					i = 10;
					break;
				}
				if (V[i] == 'B') {
					V[j] = 'R';
				}
				else if (V[i] == 'R') {
					V[j] = 'B';
				}
				else {
					V[i] = 'R';
					V[j] = 'B';
				}
				//put another color to the vertex j according to the color of the vertex i
			}
		}
	}
	if (i == 6) {
		printf("Yes! the graph is Bipartite!\n");
	}
	for (i = 0;i < 6;i++) {
		//repreasent the color of all vertices of the graph G
		
		printf("%c, ", V[i]);
	}
	printf("\n");
}

void show (node *tree) {
	//repreasent the trace of inorder using the tree
	
	node *tmp = tree;
	if (tmp != '\0') {
		show(tmp->leftchild);
		printf("%d, ", tmp->data);
		show(tmp->rightchild);
	} 
}

int main() {
	node *tree = (node*)malloc(sizeof(node));           	/*                      30                 */
	tree->data = 30;                                    	/*                     /  \                */
	add(15, 0, tree);                                   	/*                   15    40              */
	add(40, 1, tree);                                   	/*                  / \      \             */
	add( 5, 0, tree->leftchild);                        	/*                 5  20     45            */
	add(20, 1, tree->leftchild);                       	 	/*                    /     /  \           */
	add(18, 0, tree->leftchild->rightchild);            	/*                   18    43  50          */
	add(45, 1, tree->rightchild);                       	/*                             /           */
	add(50, 1, tree->rightchild->rightchild);          	 	/*                            48           */
	add(43, 0, tree->rightchild->rightchild);           	/*                             \           */
	add(48, 0, tree->rightchild->rightchild->rightchild);	/*                             49          */
	add(49, 1, tree->rightchild->rightchild->rightchild->leftchild);
	
	printf("height : %d\n", treeHeight(tree));
	BFS(tree);
	show(tree);
	printf("\n");
	bipartite();
	return 0;
}
