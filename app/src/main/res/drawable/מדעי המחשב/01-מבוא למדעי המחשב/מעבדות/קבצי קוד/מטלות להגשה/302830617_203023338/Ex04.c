/*
Assigned by:
Student1 Eliran Malka #302830617
Student2 Itamar Yacoby #203023338
*/
#include <stdio.h>

void Ex04();
double CalcE(int n, double x);

void main()
{
	Ex04();
	system("pause");
}

void Ex04()
{
	double exp;
	printf("enter exponent:\n");
	scanf_s("%lf", &exp);
	printf("the value of E^%.0lf is: %.3lf\n",exp,CalcE(1000, exp));
}

double CalcE(int n, double x)
{
	int i;
	double lastValue=1, sum=1;
	for (i = 1; i <= n; i++) 
	{
		lastValue = lastValue * (x / i); //Calculating current value by using last value
		sum += lastValue; // Adding current value to total sum
	}
	return sum;
}