#include <stdio.h>

double DigitandNum(int num, int digit, int *sumDig);

void main()
{
	int Cdig=0;
	double sum=0;
	int num = 928743;
	int dig = 4;
	sum = DigitandNum(num, dig, &Cdig);
	printf("Avg is: %.2lf \ncount dig is: %d \n", sum, Cdig);
	system("pause");

}

double DigitandNum(int num, int digit, int *CountDig)
{
	double sum=0;
	*CountDig = 0;
	while (num > 9)
	{
		if ((num % 10) < digit)
		{
			*CountDig = *CountDig +1;
			sum+= num%10;
		}
		num = (num / 10);

	}
	if ((num % 10) < digit)
	{
		*CountDig = *CountDig + 1;
		sum = sum + (num % 10);
	}

	return (sum / *CountDig);
}