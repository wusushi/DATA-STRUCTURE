#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*#include <time.h> : that is used to set random not repeated*/

int AOV[6][6] = {{0,0,0,0,0,0},       /*  Null  -->  0  */
                 {1,0,0,0,0,0},       /*   0    -->  1  */
                 {1,0,0,0,0,0},       /*   0    -->  2  */
				 {1,0,0,0,0,0},       /*   0    -->  3  */
				 {0,1,1,1,0,0},       /*1, 2, 3 -->  4  */
				 {0,0,1,1,0,0},};     /*  2, 3  -->  5  */

int a[6] = {0,1,2,3,4,5};
//record a[i] whether it is recorded or not (a[i] != -1 represents that it is not recorded)    
 
int Matrixa[3][3] = {{ 1, 0,-1},
                     { 2, 3, 1},
				     {-2, 4, 5},};
//calculate Matrix_Multiplication by Matrixa * Matrixb				   
int Matrixb[3][3] = {{ 0, 3,-3},
                     { 6,-1, 0},
				     { 2, 2,-2},};

int MatrixA[5][5] = {{ 0, 1, 0, 0, 0},
                     { 0, 0, 1, 0, 0},
					 { 0, 0, 0, 1, 0},
					 { 0, 0, 0, 0, 1},
					 { 0, 0, 1, 0, 0},};	
//the start of the trainsitive closure matrix

int MatrixAA[5][5] = {{ 0, 1, 0, 0, 0},
                      { 0, 0, 1, 0, 0},
					  { 0, 0, 0, 1, 0},
					  { 0, 0, 0, 0, 1},
					  { 0, 0, 1, 0, 0},};
//the next of the trainsitive closure matrix					  	
					  
int MatrixAk[5][5] = {{ 0, 1, 0, 0, 0},
                      { 0, 0, 1, 0, 0},
					  { 0, 0, 0, 1, 0},
					  { 0, 0, 0, 0, 1},
					  { 0, 0, 1, 0, 0},};	
//the sum(A0||A1||A2||~||AK) of the trainsitive closure matrix					  	

int MatrixAJ[5][5] = {{ 0, 0, 0, 0, 0},
                      { 0, 0, 0, 0, 0},
					  { 0, 0, 0, 0, 0},
					  { 0, 0, 0, 0, 0},
					  { 0, 0, 0, 0, 0},};	
//the recorded next matrix of the trainsitive closure matrix					  	
					  
void change(int i) {
	//record i is recorded
	 
	int j;
	
	for (j = 0;j < 6;j++) {
		AOV[j][i] = 0;
		//i is no longer to link to j
		
		AOV[i][j] = -1;
		//AOV[i][j] = -1 is repreasented that it is recorded
	}
}
				 
void Toplogical_Order() {
	//it is repreasented the order of the vertices
	
	int i, j, n = 0, r = (rand()%6) + 0;
	
	for (i = 0;i < 6;i++) {
		for (j = 0;j < 6;j++) {
			if (AOV[i][j] == 0) {
				n++;
			}
			if (n == 6) {
				//if no one else link to the vertex(i) 
				
				a[i] = -1;
			}
		}
		n = 0;
		//restart
	}
	while (a[r] != -1) {
		//search the vertex which is no one else link to and is not recorded
		
		r = (rand()%6) + 0;
	}
	printf("%d, ", r);
	a[r] = 6;
	for (j = 0;j < 6;j++) {
		if (a[j] != 6) {
			//record the vertex which is the next
			
			change(r);
			Toplogical_Order();
		}
	}
}

void Matrix_Multiplication() {
	//calculate Matrix_Multiplication
	
	int i, j, k, sum = 0;
	
	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			for(k = 0;k < 3;k++) {
				sum = sum + Matrixa[i][k] * Matrixb[k][j];
			}
			if (sum >= 0&&sum < 10) {
				printf(" %d, ", sum);
			}
			else {
				printf("%d, ", sum);
			}
		    sum = 0;
		}
		printf("\n");
	}
}

void Trainsitive_Closure() {
	int i, j, k, n = 0, m = 0, sum = 0;
	
	printf("How many steps do you want to run : ");
	scanf("%d", &m);
	while (m != 1) {
		//run (m - 1) steps
		
		for (i = 0;i < 5;i++) {
			//calculate Matrix_Multiplication
			for (j = 0;j < 5;j++) {
				for (k = 0;k < 5;k++) {
					sum = sum + MatrixAA[i][k] * MatrixA[k][j];
					//the matrix is the previous matrix multiply the first matrix
				}
				MatrixAJ[i][j] = sum;
			    sum = 0;
			    //restart
			}
		}
		for (i = 0;i < 5;i++) {
			for (j = 0;j < 5;j++) {
				MatrixAA[i][j] = MatrixAJ[i][j];
				//the next matrix is the recorded matrix
				
				MatrixAk[i][j] = MatrixAk[i][j] || MatrixAA[i][j];
			}
		}
		m--;
	}
	for (i = 0;i < 5;i++) {
		for (j = 0;j < 5;j++) {
			printf("%d, ", MatrixAk[i][j]);
			//output it
		}
		printf("\n");
	}
}

int main() {
	srand(time(NULL));
	Toplogical_Order();
	printf("\n");
	Matrix_Multiplication();
	Trainsitive_Closure();
	return 0;
}
