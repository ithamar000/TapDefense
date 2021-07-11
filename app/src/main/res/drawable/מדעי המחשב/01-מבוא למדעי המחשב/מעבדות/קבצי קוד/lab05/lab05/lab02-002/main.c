#include <stdio.h>

int lucas(int n, int *arr);
int Nlucas(int n);
void main()
{
	int num;
	int arr[500] = {0};

	printf("enter number: \n");
	scanf_s("%d", &num);
	printf("the number in the place num on Lucas session is:   %d \n", lucas(num,arr));
	printf("the number in the place num on Lucas session is no Rec:   %d \n", Nlucas(num));
	system("pause");
}

int Nlucas(int n)
{
	int i, sum = 0, sumn1 = 1, sumn2 = 2;
	for (i = 2; i <= n; i++)
	{
		sum = sumn1+sumn2;
		sumn2 = sumn1;
		sumn1 = sum;
	}
	return sum;
}

int lucas(int n, int *arr)
{
	if (n == 0)
		return 0;
	if (n < 3)
		return 1;
	return lucas(n - 1) + lucas(n - 2);
}

int lucas1(int n)
{
	if (n == 0)
		return 2;
	if (n == 1)
		return 1;
	return lucas(n - 1) + lucas(n - 2);

}