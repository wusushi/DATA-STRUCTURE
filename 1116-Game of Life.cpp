#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
// Sleep() is included in the library of <windows.h>

/*
the rule of the Game of Life ¡G
    1.Any live cell(0) would lives to the next generation if two or three live neighbors with it.
	2.Any dead cell(1) would lives to the next generation if three live neighbors with it. 
	3.The cell would be dead in the others situations.
*/

typedef struct{
	int vert;
	int horiz;
}offset;
offset move[8];
//it is repeasented to 8 directions.  vert¡Fvertical ; horiz¡Fhorizontal 

int chess[10][10] = {{1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1},
				     {1,1,1,1,1,1,1,1,1,1},
				     {1,1,1,0,1,1,1,1,1,1},
				     {1,1,1,1,0,1,1,1,1,1},
				     {1,1,0,0,0,1,1,1,1,1},
				     {1,1,1,1,1,1,1,1,1,1},
				     {1,1,1,1,1,1,1,1,1,1},
				     {1,1,1,1,1,1,1,1,1,1},
				     {1,1,1,1,1,1,1,1,1,1},};
    //the current screen  (only change and ouput the elements from chess[1][1] to chess[8][8])
	 
int change[10][10] = {{1,1,1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1,1,1},
					  {1,1,1,1,1,1,1,1,1,1},
					  {1,1,1,0,1,1,1,1,1,1},
				      {1,1,1,1,0,1,1,1,1,1},
				      {1,1,0,0,0,1,1,1,1,1},
				      {1,1,1,1,1,1,1,1,1,1},
				      {1,1,1,1,1,1,1,1,1,1},
				      {1,1,1,1,1,1,1,1,1,1},
				      {1,1,1,1,1,1,1,1,1,1},};
	//the next screen     (the rest elements to be periphery that would not change and output)

int search(int row, int col) {
	//search how many live neighbors is with the current position(chess[row][col])
	
	int dir, n = 0;
	move[0].vert = -1  ,	  move[0].horiz = 0;      //North
    move[1].vert = -1  ,	  move[1].horiz = 1;         //NorthEast
	move[2].vert = 0   ,	  move[2].horiz = 1;     //East
	move[3].vert = 1   ,	  move[3].horiz = 1;         //SouthEast
	move[4].vert = 1   ,	  move[4].horiz = 0;     //South
	move[5].vert = 1   ,	  move[5].horiz = -1;         //SouthWest
	move[6].vert = 0   ,	  move[6].horiz = -1;    //West
	move[7].vert = -1  ,	  move[7].horiz = -1;          //NorthWest
	
	for (dir = 0;dir < 8;dir++) {
		//search for the eight directions
		
		if (chess[row + move[dir].vert][col + move[dir].horiz] == 0) {
			//if any live cell in this direction
			
			n++;
		}
	}
	return n;
}

void refresh() {
	//search how many cells would be change
	
	int row, col, n;
	
	for (row = 1;row < 9;row++) {
		//chess[1-8][]
		
		for (col = 1;col < 9;col++) {
			//chess[][1-8]
			
			if (chess[row][col] == 0) {
				//if the current element is a live cell
				
				n = search(row, col);
				if (n != 2&&n != 3) {
					change[row][col] = 1;
					//change the live cell to dead to the next generation if the situation mathes to rule 3
					
				}
			}
			else if (chess[row][col] == 1) {
				//if the current element is a dead cell
				
				n = search(row, col);
				if (n == 3) {
					change[row][col] = 0;
					//change the dead cell to live to the next generation if the situation mathes to rule 2
					
				}
			}
		}
	}
}

void show() {
	//output the current screen
	
	int i, j;
	
	for(i = 1;i < 9;i++) {
		for(j = 1;j < 9;j++){
			if(chess[i][j] != change[i][j]) {
				chess[i][j] = change[i][j];
				//change the current screen to next
				
			}
			printf("%d", chess[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int k = 0;
	
	while(k != 1) {
		system("cls");
		//remake the screen
		
		show();
		refresh();
		Sleep(250);
		//wait for 250ms 
	}
	return 0;
}
