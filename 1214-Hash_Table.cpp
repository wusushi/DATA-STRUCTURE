#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int b[] = {101, 199, 499, 1001};
//buckets

int value[100];
//the value of the key

char *name[100] = {"Jacob", "Mason", "William", "Jayden", "Noah", "Michael", "Ethan", "Alexander", "Aiden", "Daniel",
	               "Anthony", "Matthew", "Elijah", "Joshua", "Liam", "Andrew", "James", "David", "Benjamin", "Logan",
				   "Christopher", "Joseph", "Jackson", "Gabriel", "Ryan", "Samuel", "John", "Nathan", "Lucas", "Christian",
	               "Jonathan", "Caleb", "Dylan", "Landon", "Isaac", "Gavin", "Brayden", "Tyler", "Luke", "Evan", 
				   "Carter", "Nicholas", "Isaiah", "Owen", "Jack", "Jordan", "Brandon", "Wyatt", "Julian", "Aaron",
	               "Sophia", "Isabella", "Emma", "Olivia", "Ava", "Emily", "Abigail", "Madison", "Mia", "Chloe",
				   "Elizabeth", "Ella", "Addison", "Natalie", "Lily", "Grace", "Samantha", "Avery", "Sofia", "Aubrey",
				   "Brooklyn", "Lillian", "Victoria", "Evelyn", "Hannah", "Alexis", "Charlotte", "Zoey", "Leah", "Amelia",
				   "Zoe", "Hailey", "Layla", "Gabriella", "Nevaeh", "Kaylee", "Alyssa", "Anna", "Sarah", "Allison",
	               "Savannah", "Ashley", "Audrey", "Taylor", "Brianna", "Aaliyah", "Riley", "Camila", "Khloe", "Claire"};
//the key
	
void SetOn() {
	//change the type of name[i] from string to int
	
	int n, k;
	for (n = 0;n < 100; n++) {
		for (k = 0;k < strlen(name[n]);k++) {
			value[n] = value[n] + *(name[n] + k);
		}
	}
}

void seperate() {
	//seperate the two hash function
	
	int i;
	for (i = 0;i < 30;i++) {
		printf("-");
	}
	printf("\n");
}

int HashLiner(int hash_table[], int b, int S, int s, int n, int k) {
	//one of the open addressing : Linear Probing, in which the interval between probes is fixed(usually 1)
	
	for (n = 0;n < 100;n++) {
		if (hash_table[value[n]%b] == -1) {
			//if the value(value by the value(int) of name mod b) of hash_table is emepty(-1) 
			
			hash_table[value[n]%b] = value[n];
			//the value of hash_table is the value of name
			
			S++;
		}	
		else {
			while ((hash_table[value[n]%b + s] != -1) && (value[n]%b + s != b - 1)) {
				//find out the following empty address of hash_table
				
				s++;
				S++;
			}
			if (value[n]%b + s != b - 1) {
				//if it doesn't reach to the last address of hash_table
				
				hash_table[value[n]%b + s] = value[n];
			}
			else {
				s = 0;
				//restart the inserted from the head(hash_table[0])
				
				S++;
				while (hash_table[s] != -1) {
					s++;
					S++;
				}
				hash_table[s] = value[n];
			}
			s = 0;
			//restart it
			 
			S++;
	    }
//		printf("S : %d\n", S);
//		printf("n : %d\n", n);
	}
	return S;
}

int HashQuadratic(int hash_table[], int b, int S, int s, int n, int k) {
	//one of the open addressing : Quadratic Probing, in which the interval between probes is square of successive outputs 
	//the way of this function is similiar to HashLiner, and it would not be interpreted
	
	for (n = 0;n < 100;n++) {
		if (hash_table[value[n]%b] == -1) {
			hash_table[value[n]%b] = value[n];
			S++;
		}
		else {
			while ((hash_table[value[n]%b + (s * s)] != -1) && (value[n]%b + (s * s) != b - 1)) {
				s++;
				S++;
				if (value[n]%b + (s * s) >= b - 1) {
					if (value[n]%b + (s * s) == b - 1) {
						k = 0;
					}
					else {
						k = 0 - (b - value[n]%b);
						//the distance from the address originally inserted to the final address
						 
					}
					break;
				}
			}
			if (value[n]%b + (s * s) < b - 1) {
				hash_table[value[n]%b + (s * s)] = value[n];
			}
			else {
				if (hash_table[k] != -1) {
					while (hash_table[k + s * s] != -1) {
						s++;
						S++;
						if (s * s >= b - 1) {
							//if the square of the increament is larger than the size of the bucket
							
							n = 100;
							S = -100;
							break;
						}
						else if(k + s * s >= b) {
							//if the next address exceed the final address of hash_table again
							  
							k = 0 - (b - (k + s * s));
						}
					}
				}
				if (hash_table[k] == -1&&k >= 0) {
					//if the inserted address is the final addreess of hash_table
					
					S++;
					hash_table[k] = value[n];
				}
				else {
					hash_table[k + s * s] = value[n];
				}
			}
			s = 0;
			S++;
		}
//		printf("S : %d\n", S);
//		printf("n : %d\n", n);
	}
	return S;
}

int main() {
	int s, i;
	double S;
	int n, k, d;
	//s is calculate how long from the originally address of hash_table to the entry
	//i is the four buckets
	//S is the sum of the steps by inserting and finding out the entry
	//n is the size of the array in this program
	//k is the an address when the next address exceed the size of hash_table, and it has to find out the next from the head
	//d is the numbers of hash function
	
	SetOn();
	for (d = 0;d < 2;d++) {
		for (i = 0;i < 4;i++) {
			S = 0;
			s = 0;
			int hash_table[b[i]]; 
		
			for (n = 0;n < b[i];n++) {
				hash_table[n] = -1;
				//set a number(-1) in hash_table that is repreasented the address is empty in hash_table
				
			}
			if (d == 0) {
				//Open Addressing : Liner Probing
				
				S = HashLiner(hash_table, b[i], S, s, n, k);
				printf("Linear Probing(b = %d) : ", b[i]);
			}
			else if (d == 1) {
				//Open Addressing : Quadratic Probing
				
				S = HashQuadratic(hash_table, b[i], S, s, n, k);
				printf("Quadratic Probing(b = %d) : ", b[i]);
			}
		    if (S < 0) {
		    	//if the next is exceed the buckets in quadratic probing
		    	
				printf("ERROR!!\n");
			}
			else {
				printf("S = %.2f\n", S/100);
			}
		}
		if (d < 1) {
			seperate();
		}
	}
	return 0;
}
