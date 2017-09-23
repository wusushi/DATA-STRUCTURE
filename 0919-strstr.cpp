#include <stdlib.h>
#include <stdio.h> 
#include <string.h>

int main() {
	char text[] = "Pneumonoultramicroscopicsilicovolcanoconiosis";
	char pat[]  = "micro";
	int m = strlen(text);
	int n = strlen(pat);
	int a,b=0,i=0;              /*a,b=the number of array's element; i=frequency */
	for(a=0;a<m;a++){
		if(text[a]==pat[b]){
			i++;
			if(i!=n){
				if(text[a+1]!=pat[b+1]){
					i=0;
				    b=0;
				    b--;         /*first minus then plus is 0*/
				}
			}
			b++;               /*next element*/
		}
	}
	if(i==n){
		printf("yes,you are right.\n");
	}
	else
	printf("-1\n");			
	return 0;
}
