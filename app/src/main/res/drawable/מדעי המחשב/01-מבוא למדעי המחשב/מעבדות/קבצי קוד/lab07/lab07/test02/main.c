#include <stdio.h>




double SandD(int num, int dig);

void main()
{

	printf("%lf \n", SandD(154, 7));
	system("pause");
}

double SandD(int num, int dig)
{
	double sum=0;
	while (num > 9)
	{
		if ((num % 10) < dig)
		{
			sum += (num %10);
			printf("mod%d\n", num % 10);
		}
		num = (num / 10);

	}
	return sum;
}