#include <stdio.h>
#include <stdlib.h>
/*this is an idea about Linked List*/ 
void del(char*,int*,int,int,int,int);
void insert(char*,int*,int,int,int,int,int,char);
void search(char*,int*,int,int,int,int);
int main() {
	char data[]={"H CE  WBF V"},a='G';     /* a = insert to the array data*/
	int link[]={11,-1,4,9,-1,-1,0,3,1,-1,7};  /* -1 : blank space -> emepty value ; first = 3 ; end = 0*/
    int dn=sizeof(data)-1,ln=sizeof(link)/sizeof(int),i,j,first=7;/*dn = the element numbers of data ; ln = the element numbers of link */
    del(data,link,dn,ln,i,first);  
    insert(data,link,dn,ln,i,j,first,a);
    search(data,link,dn,ln,i,j);
	return 0;
}
void del(char *data,int *link,int dn,int ln,int i,int first){   /*delete the element of data*/
	for(i=0;i<=dn;i++){    
    	if(data[i]=='B'){          /*delete 'C' : find out which element point to 'C'*/
    		data[link[i]-1]=' ';      /*change 'C' to ' ' */
    		link[i]=link[link[i]-1];    /*link[i] = which of 'C' link : B3 -> B4*/
    		break;
		}
	}
	for(i=0;i<=dn;i++){
    	if(data[i]==' '){      /*change the link[] of 'C' into -1*/
    		link[i]=-1;     /* -1 : blank space */
		}
	}
	printf("data : ");
	for(i=0;i<dn;i++){                /*the current status of data[]*/
		printf("%c,",data[i]);
	}
	printf("\n");
	printf("link : ");
	for(i=0;i<ln;i++){                  /*the current status of link[]*/
		printf("%d,",link[i]);
	}
	printf("\n");
	printf("linked list : ");
	i=first;
	while(link[i]!=0){              /*sort the data ,from first value ,end at link[i] = 0*/
		printf("%c,",data[i]);           /*print out the element of data*/
		i=link[i]-1;              /*i = the next element of data*/
	}
	printf("%c",data[i]);      /*i = (link[i] = 0)*/
	printf("\n");
}
void insert(char *data,int *link,int dn,int ln,int i,int j,int first,char a){  /*insert the element of data*/
    for(i=0;i<dn;i++){
    	if(data[i]==' '){        /*change the first emepty value into a='G'*/
    		data[i]=a;
    		break;
		}
	}
	for(j=0;j<dn;j++){          
    	if(data[j]=='F'){            /*find out the previous element which want to insert*/
    		link[i]=link[j];     /*change the link value which is inserted into the previous element link value*/
    		link[j]=i+1;      /*change the link value of previous element into the inserted element link value*/
    		break;
		}
	}
	printf("data : ");
    for(i=0;i<dn;i++){               /*the current status of data[]*/
		printf("%c,",data[i]);
	}
	printf("\n");
	printf("link : ");
	for(i=0;i<ln;i++){                       /*the current status of link[]*/
		printf("%d,",link[i]);
	}
	printf("\n");
	printf("linked list : ");
	i=first;
	while(link[i]!=0){               /*sort the data ,from first value ,end at link[i] = 0*/
		printf("%c,",data[i]);             /*print out the element of data*/
		i=link[i]-1;              /*i = the next element of data*/
	}
	printf("%c",data[i]);              /*i = (link[i] = 0)*/
	printf("\n");
}
void search(char *data,int *link,int dn,int ln,int i,int j){   /*find out the previous element which is inputed*/
	char a;
	scanf("%c",&a);                      /*inputed character*/
	for(i=0;i<=dn;i++){
    	if(data[i]==a){           /*find out the place which is inputed*/
    		break;
		}
	}
	for(j=0;j<=ln;j++){
		if(link[j]==i+1){          /*find out the data link to the inputed character*/
			printf("%c   %d\n",data[j],link[j]);
		}
	}
}
