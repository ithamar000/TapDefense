#include <stdio.h>

int DigitsIsEven(int n);

void main()
{
	int num;
	printf("enter number \n");
	scanf_s("%d", &num);
	if (DigitsIsEven(num)==1)
		printf("the number is: even \n");
	else
		printf("the number is: odd \n");

	system("pause");
}

int DigitsIsEven(int n)
{

	if (n % 2 == 1)
		return 0;
	if (n < 10)
	{
		if (n % 2 == 0)
			return 1;
	}
	else
		return DigitsIsEven(n / 10);
}