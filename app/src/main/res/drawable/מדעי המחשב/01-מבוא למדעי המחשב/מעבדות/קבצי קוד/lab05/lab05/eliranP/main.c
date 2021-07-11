#include <stdio.h>
double Shipoa(int x1, int y1, int x2, int y2);
double x1P[4];
double y1P[4];
double x2P[4];
double y2P[4];
double m[4];

void main()
{

	int i;
	for (i = 0; i <= 1;i++)
	{
		printf("enter point1: \n");
		scanf_s("%lf",&x1P[i]);
		scanf_s("%lf", &y1P[i]);
		printf("enter point2: \n");
		scanf_s("%lf", &x2P[i]);
		scanf_s("%lf", &y2P[i]);
		
	}
	for (int j = 0; i < 1; j++)
	{
		m[j] = Shipoa(x1P[j], y1P[j], x2P[j], y2P[j]);
	}
	printf("the m is: %lf \n", m[0]);
	printf("the m is: %lf \n", m[1]);
//	printf("%lf", Shipoa(3, 2, 4, 4));
	system("pause");
}

double Shipoa(double x1, double y1, double x2, double y2)
{
	return((y2 - y1) / (x2 - x1));
}