#include <stdio.h> 
#include <string.h>
/*  subroutine ,string.h<strcat: '\0',str"n"cat: ?>*/
int mystrstr(char *text,char *pat);
void strstring(char *text,char *pat);
void strdelete(char *text,char *pat);
void strreplace(char *text,char *pat);          /*method 1*/
void strreplace2(char *text,char *pat);         /*method 2*/

int main() {
	char text[] = "apple";
	char pat[]  = "ppl";
	
	mystrstr(text,pat);             
	strstring(text,pat);
	strdelete(text,pat);
	strreplace(text,pat);
	strreplace2(text,pat);
	return 0;
}
int mystrstr(char *text,char *pat){
	int m = strlen(text);
	int n = strlen(pat);
	int a,b=0,i=0;                  /* a=loop, i=numbers, b=same location */
	          
	for(a=0;a<m;a++){
		if(text[a]!=pat[b]){
			if(b!=(n-1)){
				i++;                     /*alphabets after the string pat[] */
			}
		}          
		else{
			if(b!=(n-1)){
				for(b=0;b<n;b++){
					if(text[a+b+1]!=pat[b+1]){     /*judge next*/
						if(b!=(n-1)){
		                b=0;
		                i++;                /*not match completly --> not find out*/
					    }
					break;              /*avoid infinite loop*/
				    }
			    }
			}
	    }
	}
	return i;
}
void strstring(char *text,char *pat){
	char *test;
	
	test = strstr(text,pat);            /*find out the same*/
	printf("%p\n",test);               
}
void strdelete(char *text,char *pat){                /* " " --> "a" --> "a\0" --> "ae"*/
	char temp[20];
	int n = strlen(pat),i=mystrstr(text,pat);
	
	strncpy(temp,text,i);            /*copy the alphabets after the string pat[] to the temp*/
	temp[i]='\0';             /*strncpy doesn't have '\0' at the end of the string*/
	strcat(temp,text+i+n);                   /*the alphabets before the string pat[] append in the temp*/
	printf("%s\n",temp);
}
void strreplace(char *text,char *pat){
	char temp[20],rep[] ="lic";
	int n = strlen(pat),i=mystrstr(text,pat);
	
	strncpy(temp,text,i);
	temp[i]='\0';
	strcat(temp,rep);
	strcat(temp,text+i+n);
	printf("%s\n",temp);
}
void strreplace2(char *text,char *pat){             
	char *test,rep[] ="lic";
	int i,m=strlen(rep);
	
	test = strstr(text,pat);            
	for(i=0;i<m;i++)test[i]=rep[i];           /*replace the same*/
	printf("%s\n",text);
}
