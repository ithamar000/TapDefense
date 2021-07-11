#include <stdio.h>


void main()
{
	int i=0,sum=0,j=0,sum1=0,n=1000;

	for (; i<= n; i+=3)
	{
		sum += i;
		if (i % 5 == 0)
			sum = sum - i;

	}
	for (; j<= n; j+=5)
	{
			sum1 += j;

	}
	

	printf("the summary of numbers is: %d \n", sum+sum1);
	getch();
}