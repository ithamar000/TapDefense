#include <stdio.h>

void main() {

	int num1;
	double dist,a1;
	printf("enter the dist:\n");
	scanf_s("%lf", &dist);
	printf("enter the 'a1' num:\n");
	scanf_s("%lf", &a1);
	printf("enter the 'n' number:\n");
	scanf_s("%int", &num1);

	printf("A n = %.1lf\n", (a1+dist*(num1-1)));
	system("pause");
}