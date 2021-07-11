#include <stdio.h>

void main()
{
	int money;
	int nis200=0, nis100=0, nis50=0, nis20=0, coin10=0, coin5=0, coin2=0, coin1=0;
	printf("Enter your value: \n");
	scanf_s("%d", &money);
		if (money >= 200)
		{
			nis200 = money / 200;
			money = money % 200;
		}
		if (money >= 100)
		{
			nis100= money / 100;
			money = money % 100;
		}
		if (money >= 50)
		{
			nis50 = money / 50;
			money = money % 50;
		}



	printf("note 200: %d \nnote 100: %d \nnote 50: %d\n", nis200, nis100, nis50);
	printf("-----%d", money);
	getch();



}