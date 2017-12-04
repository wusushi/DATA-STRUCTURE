#include <stdio.h>
#include <stdlib.h>

int Matrix[4][4] = {{0,0,1,1},       //       0, 1, 2, 3   
                    {0,0,0,1},       
			        {1,0,0,0},      
			        {1,1,0,0},};     
			        
int dfn[4] = {-1,-1,-1,-1};   
//record dfn[i] whether it is recorded or not (dfn[i] == -1 represents that it is not recorded)    

int DFS[4][4] = {{0,0,0,0},
                 {0,0,0,0},
			     {0,0,0,0},
			     {0,0,0,0},};
//record DFS[i][j] whether it is recorded or not (DFS[i][j] == 0 and Matrix[i][j]represents that it is a cycle

int Cost[7][7] = {{ 0,28, 0, 0, 0,10, 0},
                  {28, 0,16, 0, 0, 0,14},
				  { 0,16, 0,12, 0, 0, 0},
				  { 0, 0,12, 0,22, 0,18},
				  { 0, 0, 0,22, 0,25,24},
				  {10, 0, 0, 0,25, 0, 0},
				  { 0,14, 0,18,24, 0, 0},};
//Minnum Cost Spanning Trees

void dfs(int v) {
	//search for dfn[v] by recursion and record whether be recorded or not
	
	int i;
	static int count = 0;
	//count repreasents the number of how fast to find out it 
	
	dfn[v] = count++;
    for (i = 0;i < 4;i++) {
    	if (Matrix[v][i] == 1&&dfn[i] == -1) {
    		//if v links to i, and it is not recorded
    		
    		printf("%d links to %d\n", v, i);
    		dfs(i);
    		DFS[v][i] = 1;
    		DFS[i][v] = 1;
    		//DFS[v][i] = 1 and DFS[i][v] = 1 repreasent that Matrix[v][i] has been recorded
		}
	}
}	

int hasCycle() {
	//repreasent whether this graph has cycle or not
	
	int i ,j;
	for (i = 0;i < 4;i++) {
		for (j = 0;j < 4;j++) {
			if (Matrix[i][j] == 1&&DFS[i][j] == 0) {
				//this situation repreasents that i links to j, and it is not recorded --> cycle
				
				printf("Thers is a circle in this graph : ");
				return 1;
			}
		}
	}
	if (i == 4&&j == 4) {
		//if it runs over the previous nested loop completely 
		
		printf("Thers is no circle in this graph : ");
		return -1;
	}
}	

int hasRing (int i, int j, int x) {
	//search for that add this edge whether form a cycle or not
	
	int k, d, y;
	//if j links to k, Cost[i][j] is less than the current min --> y = k
	//if k links to d, search for this edge whether form a cycle --> x = previous k
	
	for (k = 0;k < 7;k++) {
		if (Cost[j][k] == 1) {
			//if j links to k and this edge has been recorded
			
			x = 0;
			//restart x, and if search for whether this edge forms a cycle : x = the previous k
			
			y = k;
			//y = the current k
			
			for (d = 0;d < 7;d++) {
				//search for any other edge that results in a cycle
				if (Cost[k][d] == 1) {
					//if k links to d and this edge has been recorded
					
					printf("i : %d\tj : %d\tk : %d\td : %d\tx : %d\n", i, j, k, d, x);
					if (x == k) {
						//if it links to itself  (x = the previous k)
						
						if (i == d) {
							//if it links to start(i)
							
							d = 0;
							break;
						}
						if (x != d) {
							k = d;
							d = -1;
							//put k to next component(d), and restart to search for it
						}	
					}
					else if (x != d) {
						//if x(the previous k) doesn't equal d(it links to itself)
						
						if (i == d&&x != 0) {
							//if it links to start(i) and it is not in the begining
							
							d = 0;
							break;
						}
						x = k;
						//x = the previous k
						
						k = d;
						//k = the next component
						
						d = -1;
						//restart to search for the next edge
					}
					else {
						//if x == d
						
						x = k;
					}
				}
			}
			k = y;
			//k = the non-recorded k (line 84)
			
			if (d != 7) {
				//if i links to j results in a cycle --> k = 0
				
				k = 0;
				break;
			}
			printf("\n");
		}
	}
	return k;
}

int Kruskal() {
	//Kruskal's Algorithm : build a minimum cost spanning tree by adding edges at a time
	
	int i, j, k, m = 0, y, x = 0, d;
	//i, j repreasent the two-dimensional array ; m repreasents how many links in this graph 
	//if i links to j, Cost[i][j] is less than the current min --> y = j
	//if i links to j, search for this edge whether form a cycle --> x = previous i
	
	int min = 100;
	int minCost = 0;
	//min : the rest minnist cost(if no cycle), minCost : the current sum
	
	while (m <= 9) {
		// m repreasents how many links in this graph 
		
		for (i = 0;i < 7;i++) {
			for (j = 0;j < 7;j++) {
				if (Cost[i][j] < min&&Cost[i][j] > 1) {
				//Cost[i][j] = 0 : i doesn't link to j ; Cost[i][j] = 1 repreasent i link to j and it is recorded
				    
					printf("\tCost[%d][%d] : %d\tmin : %d\n", i, j, Cost[i][j], min);
					y = j; 
					//y = the current j
					
					x = 0;
					//restart x, and if search for whether this edge forms a cycle : x = the previous k
					 
					k = hasRing(i, j, x);
					//if k = 7,  this edge doesn't form a cycle, otherwise it forms a cycle
					
					for (d = 0;d < 7;d++) {
						//search for any other edge that results in a cycle
						 
						if (Cost[i][d] == 1) {
							if (k != 7) {
								break;
							}
							k = hasRing(i, d, x);
							if (k != 7) {
								break;
							}
						}
					}
					if (k == 7) {
						min = Cost[i][y];
						//min = the current minnist cost
					}
					j = y;
					//j = the non-recorded j (line 169)
				}
			}
		}
		printf("min : %d\n", min);
		if (min != 100) {
			//if min has been changed, plus it to minCost
			
			minCost = minCost + min;
		}
		else {
			break;
		}
		for (i = 0;i < 7;i++) {
			for (j = 0;j < 7;j++) {
				if (Cost[i][j] == min&&Cost[i][j] != 0) {
					//recorded the minnist cost edge to change the cost into 1
					
					printf("Cost[%d][%d] : %d\n", i, j, Cost[i][j]);
					Cost[i][j] = 1;
					Cost[j][i] = 1;
					break;
				}
			}
		}
		printf("minCost : %d\n", minCost);
		min = 100;
		//restart the minnist cost
		
		m++;
		//the next edge
	}
	return minCost;
}

int main() {
	int i;
	dfs(2);
	printf("\n");
	printf("%d\n\n", hasCycle());
	printf("\tcost : %d\n", Kruskal());
	return 0;
}
