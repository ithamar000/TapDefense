#include <stdio.h>


double calctur(int n, double x);

void main()
{
	printf("%.2lf", calctur(5, 2.0));
	system("pause");
}

double calctur(int n, double x)
{
	double mona = x;
	double mecha = 1;
	double sum = 3*x;
	for (double i = 2; i < (2 * n + 3); i += 2)
	{
		mona = mona * x;
		mecha = mecha * i*(i + 1);
		sum += (mona *(i + 3)) / mecha;
	}
	return sum;
}