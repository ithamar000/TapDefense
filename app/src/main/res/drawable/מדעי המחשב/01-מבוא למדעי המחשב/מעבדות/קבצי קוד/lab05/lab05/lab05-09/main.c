#include <stdio.h>

int repdig(int num);
int repdigplus(int num);
int num1;

void main()
{
	int a = 356;
	int b = 356;
	printf("%d \n", a);
	printf("%d \n", repdig(a));
	printf("%d \n", repdigplus(b));
	system("pause");

}

int repdig(int num)
{
	
	if (num < 10)
	{
		return num-1;
	}
	return (10*repdig(num / 10)) + ((num % 10) - 1);
}
int repdigplus(int num)
{

	if (num < 10)
	{
		return (num%10) +1;
	}
	return (10*repdig(num / 10) ) + ((num+1 % 10));
}