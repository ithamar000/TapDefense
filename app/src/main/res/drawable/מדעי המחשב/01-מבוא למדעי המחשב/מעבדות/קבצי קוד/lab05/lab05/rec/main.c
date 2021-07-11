#include <stdio.h>


void main()
{
	printf("%d \n", paw(2,7));
	system("pause");
}

int paw(int x,int n)
{
	int temp;
	if (n == 1)
		return x;
	if (n == 0)
		return 1;
	temp = paw(x, n / 2);
	if (n % 2 == 0)
		return (temp*temp);
	return (temp*temp*x);

}