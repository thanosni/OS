#include <stdio.h>

int add(int *n1, int *n2, int *n3);

int main(void) {
	int n[3];
	for (int i = 0; i < 3; i++) {
		printf("Enter integer %d :", i+1);
		scanf("%d", &n[i]);
	}
	int sum = add(&n[0], &n[1], &n[2]);
	printf("The sum is : %d\n", sum);
     	return 0;	
}

int add(int *n1, int *n2, int *n3) {
	return *n1 + *n2 + *n3;
}
