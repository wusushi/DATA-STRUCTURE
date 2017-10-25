#include <stdio.h>
#include <stdlib.h>
#define size 9         /*the size of the maze*/

typedef struct{            /*direction*/
		int vert;
		int horiz;
	}offsets;
offsets move[8];
int main() {
	int maze[size][size]={{1,1,1,1,1,1,1,1,1},
	                      {1,0,0,1,1,0,0,1,1},
				          {1,0,1,0,1,1,0,1,1},
				          {1,0,1,1,0,1,1,0,1},
				          {1,0,1,1,1,1,0,1,1},
				          {1,0,1,1,0,1,0,1,1},
				          {1,1,0,1,1,0,1,0,1},
				          {1,0,1,0,0,1,1,0,1},
				          {1,1,1,1,1,1,1,1,1},};
	int row=1,col=1,dir=0,nextRow=0,nextCol=0,top=0,stackRow[100],stackCol[100],n=0,i=0,j=0,k=0;
	move[0].vert=-1	    ,move[0].horiz=0;         		/*North*/
	move[1].vert=-1		,move[1].horiz=1;         		        /*Northeast*/
	move[2].vert=0 		,move[2].horiz=1;         		/*East*/
	move[3].vert=1 		,move[3].horiz=1;         		       /*Southeast*/
	move[4].vert=1 		,move[4].horiz=0;         		/*South*/
	move[5].vert=1 		,move[5].horiz=-1;        		        /*Southwest*/
	move[6].vert=0 		,move[6].horiz=-1;        		/*West*/
	move[7].vert=-1		,move[7].horiz=-1;        		       /*Northwest*/
	stackRow[0]=1,stackCol[0]=1;               /*start*/
	while(row!=(size-2)||col!=(size-2)){         /*destination*/
		k++;
		if(k>50){
			break;         /*if infinite loop*/
		}
		if(top>0){       /*pop the position from the top of the stack*/
			top--;
			maze[row][col]++;         /*passed through but not be a corrcet way*/
			printf("maze[%d][%d] = %d\n",row,col,maze[row][col]);
		}
		row=stackRow[top],col=stackCol[top];        /*current status is previous status*/
		printf("(pop)stackRow[%d] = %d ,stackCol[%d] = %d\n",top,stackRow[top],top,stackCol[top]);
		printf("(pop)row = %d ,col = %d , top = %d\n",row,col,top);
		for(i=0;i<8;i++){              /*find out the next position*/
			if(maze[row+move[i].vert][col+move[i].horiz]==0){
				dir=i;
				break;
			}
		}
		while(dir<8){
			nextRow=row+move[dir].vert,nextCol=col+move[dir].horiz;         /*the next position*/
			if(row==(size-2)&&col==(size-2)){     /*if find out the destination*/
				break;
			}
			else if(maze[nextRow][nextCol]<9&&maze[nextRow][nextCol]!=1){      /*go head*/ 
				for(i=0;i<8;i++){             /*how many direction can it go toward*/
					if(maze[row+move[i].vert][col+move[i].horiz]==0){
						n++;                      
						maze[row][col]=n;     
					}
				}
				printf("n = %d ,maze[%d][%d] = %d\n",n,row,col,maze[row][col]);
				if(n==1){                /*only one way*/
					maze[row][col]=9;
					for(i=0;i<8;i++){
					    if(maze[nextRow+move[i].vert][nextCol+move[i].horiz]==0){
						    j++;
					    }
				    }
				    if(j==0){           /*the bottom of the road*/
				    	maze[nextRow][nextCol]=9;
					}
					j=0;        /*re-start*/
				}
				row=nextRow,col=nextCol;
				top++;
				stackRow[top]=row,stackCol[top]=col;    /*push the position to the stack*/
				printf("(push)stackRow[%d] = %d ,stackCol[%d] = %d\n",top,stackRow[top],top,stackCol[top]);
		        printf("(push)row = %d ,col = %d , top = %d\n",row,col,top);
				n=0;
				dir=0;         /*re-start*/
			}
			else{
				dir++;      /*the next direction*/
			}
		}
	}
	if(row==(size-2)&&col==(size-2)){
		printf("OH!you got it!\n");     /*if find out the destination*/
	}
	else{
		printf("Sorry!you are lost!\n");   /*else*/
	}
	for(i=0;i<size;i++){                 /*print out the maze*/
		for(j=0;j<size;j++){
			if(i==1&&j==1){
				printf("S");         /*start*/
				continue;
			}
			else if(i==(size-2)&&j==(size-2)){
				printf("E");       /*the destination*/
				continue;
			}
			else if(maze[i][j]==1){
				printf("|");           /*the wall*/
			}
			else if(maze[i][j]==0){
				printf("0");          /* the road which is not to go*/
			}
			else if(maze[i][j]<=9){
				printf("#");              /* the road which is correct and go by*/
			}
			else if(maze[i][j]<=11){
				printf("*");                 /* the road which passes through but not be correct*/
			}
			else{
				printf(" ");          /*ERROR!*/
			}
		}
		printf("\n");
	}
	return 0;
}
