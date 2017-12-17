#include <stdio.h>
#include <stdlib.h>

int paths[6][6] = {{ 0,99,99,20,99,99},       /*    3     -->  0  */
                   {50, 0,99,99,20,99},       /*   0,4    -->  1  */
                   {45,10, 0,99,35,99},       /*  0,1,4   -->  2  */
				   {10,15,99, 0,99,99},       /*   0,1    -->  3  */
				   {99,99,30,15, 0, 3},       /*  2,3,5   -->  4  */
				   {99,99,99,99,99, 0},};     /*   Null   -->  5  */
//paths[i][j] = j links to i, paths[i][j] = 99 that is represented j doesn't link to i

int steps[5][6];
//steps[i][j]  =   the shortest length of 0 takes (i + 1) steps to go to j

int shortest[6][6];
//shortest[i][j]  =  the shortest path between 0 and i would be through shortest[i][0~5]

void choose(int j, int k, int n) {
	int x, y;
	for (x = 1;x < 5;x++) {
		if (shortest[j][x] == 0) {
		    //if shortest[j][x] is recorded
							
			if (n > 1) {
				/*if the length of the path from 0 takes i steps to j through k is less than 
				     the length of the path from 0 takes (i - 1) steps to j, and than,
					 the length of the path from 0 takes i steps to j through k is larger than 
				     the length of the path from 0 takes i steps to j through (k + j < 6)
					    (i.e.)0 --> 4 : 99, 0 --> 2 --> 4: 75, 0 --> 3 --> 4: 25*/ 
				     
				shortest[j][x - 1] = 0;
				//delete the recorded number
				
				for (y = 1;y < 5;y++) {
					//if 0 go to shortest[j][x - 1] through many numbers, delete them, too
					
					if (shortest[k][y] != 0) {
						shortest[j][x - y - 1] = 0;
					}
				}
				n = 1;
				x = 0;
				//restart them
				
				continue;
			}
			for (y = 0;y < 5;y++) {
				//copy the elements from 0 to k(shortest[k][]) into shortest[j][]
				
				if (shortest[k][y + 1] == 0) {
					shortest[j][x + y] = k;
					break;
				}
				shortest[j][x + y] = shortest[k][y + 1];
			}
			break;
		}
	}
}

void showSteps() {
	//show the length of the path from 0 to j in (i + 1) steps
	
	int i, j;
	printf("\t      0   1   2   3   4   5\n");
	for (i = 0;i < 5;i++) {
		printf("The %d steps : ", (i + 1));
		for (j = 0;j < 6;j++) {
			printf("%d, ", steps[i][j]);
		}
		printf("\n");
	}
}

void showShortest() {
	//show the shortest length of the path from 0 to i
	
	int i, j;
	for (i = 0;i < 6;i++) {
		printf("%d : ", i);
		if (i == 0) {
			//if the element is the start
			
			printf("%d\n", i);
			continue;
		}
		for (j = 0;j < 5;j++) {
			if ((j > 0) && (shortest[i][j] == 0)) {
				//if j which 0 go to i through is all displayed
				
				break;
			}
			printf("%d --> ", shortest[i][j]);
		}
		if (steps[4][i] != 99) {
			printf("%d", i);
		}
		else {
			//if 0 can't go to the element
			
			printf("X");
		}
		printf("\n");
	}
}

int main() {
	int i, j, k, n;
	
	for (i = 0;i < 6;i++) {
		steps[0][i] = paths[i][0];
		//0 links to i for one step
		
		shortest[i][0] = 0;
		//the start from 0 to i
	}
	for (i = 1;i < 5;i++) {
		for (j = 0;j < 6;j++) {
			n = 0;
			//n = from i to j through k may change the steps[i][j] for many times if steps[i - 1][j] > steps[i - 1][k] + paths[j][k]
			
			for (k = 0;k < 6;k++) {
				//from i to j through k
				
				if (steps[i - 1][j] > steps[i - 1][k] + paths[j][k]) {
					/*if the shortest length of 0 takes (i - 1) steps to j is larger than 
					      the shortest length of 0 takes (i - 1) steps to k   plus
					            the length of the path from k to j                     */
					
					steps[i][j] = steps[i - 1][k] + paths[j][k];
					/*       the length of 0 takes i steps to j            is 
					  the shortest length of 0 takes (i - 1) steps to k   plus 
					       the length of the path from k to j     */
					
					n++;
					choose(j, k, n);
					//put k into shortest[j][0~5]
					
				}
			}
			if (steps[i][j] == 0) {
				//if the shortest length of 0 takes i steps to j equals takes (i - 1) steps to j 
				
				steps[i][j] = steps[i - 1][j];
			}
		}
	}
	showSteps();
	printf("\n");
	showShortest();
	return 0;
}
