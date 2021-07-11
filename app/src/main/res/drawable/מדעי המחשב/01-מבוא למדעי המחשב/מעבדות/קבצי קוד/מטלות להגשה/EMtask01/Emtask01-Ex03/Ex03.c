/*
Assigned by:
Student1 Eliran Malka #302830617
Student2 Itamar Yacoby #203023338
*/
#include <stdio.h>
#include <math.h>

void SloveEquation(int n);
void EX03();

void main()
{
	EX03();
	system("pause");
}
void EX03()
{
	SloveEquation(42);
}

void SloveEquation(int n)
{
	int maxDist = 0, maxx, maxy;
	double x;
	for (int i = 0; i <= n / 5; i++) //Checking y values since numbers larger than n/5 will never solve the equation
	{
		x = ((n-(5.0 * i)) / 3); // Calculation x values from the equation
		if (x-(int)x  == 0) // If x is rational it his value is invalid
		{
			printf("x:%.0lf, y:%d\n", x, i);
			if (abs(x - i) > maxDist) // if current distance is larger than last values replacing last values
			{
				maxDist = abs(x - i);
				maxx = x;
				maxy = i;
			}
		}
	}
	printf("\nthe max is \nx:%d,y:%d\n\n", maxx, maxy);

}