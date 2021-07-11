#include <stdio.h>
#include <math.h>

double calcShipoa(double x1, double y1, double x2, double y2);
double calcHituh(double x, double y, double m);
struct stock
{
	double openP;
	double closeP;
	double maxP;
	double minP;
	int voleum;
};

void main()
{
	//printf("%.2lf\n",calcShipoa(2, 4, 3, 6));
	printf("%.2lf\n", calcHituh(2,4, calcShipoa(2, 4, 3, 6)));
	system("pause");


}

double calcShipoa(double x1, double y1, double x2, double y2)
{
	return (y2 - y1) / (x2 - x1);
}

double calcHituh(double x, double y, double m)
{
	return (y - (m*x));
}