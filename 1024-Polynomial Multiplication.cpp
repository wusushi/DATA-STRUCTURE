#include <stdio.h>
#include <stdlib.h>
/*It represent polynomial multiplication by an idea about linked list and circled queue*/
typedef struct polyNode{
	int coef;             /*coefficient*/
	int expon;             /*exponent*/
	struct polyNode *link;
}polyNode;
polyNode *a,*b,*c;  /*a -> multiplier; b -> multiplicand; c -> result*/
void adda(int nc,int ne){     /*add an value including coefficient and exponent into a(multiplier)*/
	polyNode *tmp = (polyNode*)malloc(sizeof(polyNode));
	tmp->link = a->link;      /*new address link to what the last a link to*/
    a->link = tmp;         /*a link to new address*/
	tmp->coef = nc;          /*put new coefficient and new exponent into new address*/
	tmp->expon = ne;
	a = tmp;            /*replace new address by a*/
	printf("a->coef : %d\n",a->coef);                  /*testing*/
	printf("a->expon : %d\n",a->expon);
	printf("a : %d\n",a);
	printf("a->link : %d\n",a->link);
}
void addb(int nc,int ne){        /*add an value including coefficient and exponent into b(multiplicand)*/
	polyNode *tmp = (polyNode*)malloc(sizeof(polyNode));
	tmp->link = b->link;
    b->link = tmp;
	tmp->coef = nc;
	tmp->expon = ne;
	b = tmp;
	printf("b->coef : %d\n",b->coef);
	printf("b->expon : %d\n",b->expon);
	printf("b : %d\n",b);
	printf("b->link : %d\n",b->link);
}
void addc(int nc,int ne){     /*add an value including coefficient and exponent into c(result)*/
	polyNode *tmp = (polyNode*)malloc(sizeof(polyNode));
	tmp->link = c->link;
    c->link = tmp;
	tmp->coef = nc;
	tmp->expon = ne;
	c = tmp;
}
void sortc(int n){     /*sort result by bubble sort*/
	polyNode *tmpc = c->link->link;
	for(int m=0;m<n;m++){     /*n is the nuumbers of section of result*/
		for(;tmpc->expon >= 0;tmpc = tmpc->link){
			if(tmpc->coef == 0&&tmpc->expon == 0){    /*if link to dummy*/
			    break;
		    }
			if(tmpc->expon < tmpc->link->expon){   /*swap*/
				tmpc->expon = tmpc->expon + tmpc->link->expon;
				tmpc->link->expon = tmpc->expon - tmpc->link->expon;
				tmpc->expon = tmpc->expon - tmpc->link->expon;
				tmpc->coef = tmpc->coef + tmpc->link->coef;
				tmpc->link->coef = tmpc->coef - tmpc->link->coef;
				tmpc->coef = tmpc->coef - tmpc->link->coef;
		    }
		}
		tmpc = c->link->link;   /*return to the first section of the current result*/
	}
}
void mergec(){        /*merge the coefficient when the same exponent in the result*/
	polyNode *tmpc = c->link->link;
	for(;tmpc->expon >= 0;){
		if(tmpc->link->coef == 0&&tmpc->link->expon == 0){  /*if link to dummy*/
			break;
		}
		else if(tmpc->expon == tmpc->link->expon){    /*merge*/
			tmpc->coef = tmpc->coef + tmpc->link->coef;
			tmpc->link = tmpc->link->link;
		}
		else{
			tmpc = tmpc->link;
		}
	}
}
void print(){    /*print out the multiplicand and multiplier and layout*/
	polyNode *tmpa = a->link->link;
	printf("A : %dx^%d",tmpa->coef,tmpa->expon); 
	tmpa = tmpa->link;
	while(tmpa->expon != -1){
		printf(" + ");
		if(tmpa->coef < 0){   /*if coefficient is a negative number*/
			printf("(%d)",tmpa->coef);
		}
		else{
			printf("%d",tmpa->coef);
		}
		printf("x^%d",tmpa->expon);
		tmpa = tmpa->link;           /*the next section of the multiplier*/
	}
	printf("\n");
	polyNode *tmpb = b->link->link;
	printf("B : %dx^%d",tmpb->coef,tmpb->expon);
	tmpb = tmpb->link;
	while(tmpb->expon != -1){
		printf(" + ");
		if(tmpb->coef < 0){
			printf("(%d)",tmpb->coef);
		}
		else{
			printf("%d",tmpb->coef);
		}
		printf("x^%d",tmpb->expon);
		tmpb = tmpb->link;           /*the next section of the multiplicand*/
	}
	printf("\n\n");
}
void printc(){   /*print out the result and layout*/
	polyNode *tmpc = c->link->link;
	printf("C : %dx^%d",tmpc->coef,tmpc->expon);
	tmpc = tmpc->link;
	while(tmpc->expon >= 0){
		if(tmpc->coef == 0&&tmpc->expon == 0){
			break;
		}
		if(tmpc->coef != 0){
			printf(" + ");
			if(tmpc->coef < 0){
				printf("(%d)",tmpc->coef);
			}
			else{
				printf("%d",tmpc->coef);
			}
			if(tmpc->expon > 1){
				printf("x^%d",tmpc->expon);
			}
			else if(tmpc->expon == 1){
				printf("x");
			}
		}
		tmpc = tmpc->link;   /*the next section of the result*/
	}
	printf("\n");
}
int main() {
	int nc = 0,ne = 0,n = 0;  /*nc = coefficient; ne = exponent; n = the numbers of section of the result*/
	polyNode *dummya = (polyNode*)malloc(sizeof(polyNode));   /*setting dummy for circled queue is useful to manage it*/
	dummya->coef = 0;
	dummya->expon = 0;
	dummya->link = dummya;
	a = dummya;
	printf("a : %d\n",a);                       /*testing*/
	printf("a->link : %d\n",a->link);
	polyNode *dummyb = (polyNode*)malloc(sizeof(polyNode));
	dummyb->coef = 0;
	dummyb->expon = 0;
	dummyb->link = dummyb;
	b = dummyb;
	printf("b : %d\n",b);
	printf("b->link : %d\n",b->link);
	polyNode *dummyc = (polyNode*)malloc(sizeof(polyNode));
	dummyc->coef = 0;
	dummyc->expon = 0;
	dummyc->link = dummyc;
	c = dummyc;
	printf("c : %d\n",c);
	printf("c->link : %d\n",c->link);
	while(ne != -1){
		printf("input your polynomials coefficient for multiplicand : ");
	    scanf("%d",&nc);    
	    printf("input your polynomials exponent for multiplicand : ");
	    scanf("%d",&ne);
		adda(nc,ne);           /*input one section to multiplicand*/
        printf("a : %d\n",a);    	/*testing*/
	}
    ne = 0;
	while(ne != -1){
		printf("input your polynomials coefficient for multiplier : ");
	    scanf("%d",&nc);
	    printf("input your polynomials exponent for multiplier : ");
	    scanf("%d",&ne);
		addb(nc,ne);          /*input one section to multiplier*/
        printf("b : %d\n",b);        /*testing*/
	}
	print();       /*print out what input in the multiplicand and multiplier*/
	polyNode *tmpa = a->link->link;    /*tmpa = the first section of multiplier*/
	polyNode *tmpb = b->link->link;       /*tmpb = the first section of multiplicand*/
	for(;tmpa->expon >= 0;tmpa = tmpa->link){
		for(;tmpb->expon >= 0;tmpb = tmpb->link){
			addc(tmpa->coef * tmpb->coef , tmpa->expon + tmpb->expon);
		    printf("c->coef : %d\t",c->coef);
		    printf("c->expon : %d\n",c->expon);
		    n++;
		}
		tmpb = b->link->link;   /*return to the first section of multiplicand*/
	}
	printf("\n");
	sortc(n);
	printc();
	mergec();
	printc();
	return 0;
}
