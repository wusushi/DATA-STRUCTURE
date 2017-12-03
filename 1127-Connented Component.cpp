#include <stdio.h>
#include <stdlib.h>

/*static int : the value would be changed if the following instructons change it until the program finish.*/
			   
int Matrix[10][10] = {{0,0,1,1,0,0,0,0,0,0},    	//int Matrix1[4][4] = {{0,0,1,1},       0, 1, 2, 3
                 	  {0,0,0,1,0,0,0,0,0,0},    	//                     {0,0,0,1},
			     	  {1,0,0,0,0,0,0,0,0,0},    	//			           {1,0,0,1},
			     	  {1,1,0,0,0,0,0,0,0,0},    	//			           {1,1,1,0},}; 
			     	  {0,0,0,0,0,1,1,0,0,0},    	//int Matrix2[3][3] = {{0,1,1},         4, 5, 6
			     	  {0,0,0,0,1,0,1,0,0,0},    	//                     {1,0,1},
			     	  {0,0,0,0,1,1,0,0,0,0},    	//			           {1,1,0},};
			     	  {0,0,0,0,0,0,0,0,1,1},    	//int Matrix3[3][3] = {{0,1,1},         7, 8, 9
			     	  {0,0,0,0,0,0,0,1,0,0},    	//			           {1,0,0},
			     	  {0,0,0,0,0,0,0,1,0,0},};  	//			           {1,0,0},};
			   
int dfn[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
//record dfn[i] whether it is recorded or not (dfn[i] == -1 represents that it is not recorded 

int a[10] = {0,1,2,3,4,5,6,7,8,9};
//a[i] repreasents Matrix[i][] or Matrix[][i] 

int dfs(int v) {
	//search for a[v] by recursion and return how many graph in this program 
	
	int i;
	static int count = 0;
	static int n = 1;
	//count repreasents the number of how fast to find out it ; n repreasents how many graph in it
	
	dfn[v] = count++;
    a[v] = -1;
    //v repreasents it has been found out
	  
    for (i = 0;i < 10;i++) {
    	//there are 10 elements in this program
    	
    	if (Matrix[v][i] == 1&&dfn[i] == -1) {
    		//if v links to i, and i is not recorded
    		
    		printf("%d links to %d\n", v, i);
		    dfs(i);
		}
		else if (a[2] == -1&&a[4] != -1) {
			//the next graph, its first element is 4
			
			n++;
			printf("\n");
			dfs(4);
		}
		else if (a[6] == -1&&a[8] != -1) {
			//the third graph, its first element is 8
			
			n++;
			printf("\n");
			dfs(8);
		}
	}
	return n;
}	

int main() {
	int i;
	dfs(1);
	printf("\na[10] = {");
	for (i = 0;i < 10;i++) {
    	printf("%d,", a[i]);
    	//if a[i] is recorded, it repreasents -1
	}
	printf("}\n\n");
	printf("There are %d matrix in this program!\n", dfs(1));
	return 0;
}
