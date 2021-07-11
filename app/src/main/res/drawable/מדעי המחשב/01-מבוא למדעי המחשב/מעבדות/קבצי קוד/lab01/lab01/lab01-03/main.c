#include<stdio.h>

void main() {
	int days,months,years,daysI;
	printf("Enter please numbers of days:\n");
	scanf_s("%d", &daysI);
	
	years = daysI / 365;
	months = ((daysI % (years*365))/30);
	days = ((daysI % 365) % 30);
	
	printf("years:\t%d\nmonts\t%d\ndays:\t%d\n",years,months,days);

	system("pause");
}