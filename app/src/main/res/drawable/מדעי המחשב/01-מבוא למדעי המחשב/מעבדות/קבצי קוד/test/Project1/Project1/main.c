#include <stdio.h>

void main() {
	int a, b,div;
	double result;

	printf("please enter 2 numbers \n");
	scanf_s("%d", &a);
	scanf_s("%d", &b);

	printf("please enter divider \n");
	scanf_s("%d", &div);

	result = (a + b) / (double)div;

	printf("the avg between %d and %d is %.2lf \n",a,b,result);
	system("pause");
}