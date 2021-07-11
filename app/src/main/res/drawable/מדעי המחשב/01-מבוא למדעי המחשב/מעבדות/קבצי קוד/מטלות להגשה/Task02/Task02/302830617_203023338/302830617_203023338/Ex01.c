#include <stdio.h>
#include <assert.h>


void maxProfit(double stock[], int size, int *ibuy, int *isell);
void Ex01();
double *input_array_dyn(int *n);

void main()
{
	Ex01();
	system("pause");
}

void Ex01()
{
	int n;
	double *arr = input_array_dyn(&n); //קליטת מערך
	int buyDay, sellDay;

	maxProfit(arr, n, &buyDay, &sellDay); //קריאה לפונקציה

	printf("buy: %d , sell: %d\n", buyDay, sellDay); //הדפסת ימי המכירה והקניה
	free(arr);
}

double *input_array_dyn(int *n)
{
	int i;
	double *a;
	printf("enter the length of the array\n");
	scanf_s("%d", n);
	a = (double *)calloc(*n, sizeof(double));
	assert(a); /* calloc() worked */
	printf("enter the array of length %d\n", *n);
	for (i = 0; i < *n; i++)
		scanf_s("%lf", a + i);
	return a;
}

/*
פונקציה המעבירה בעזרת מצביעים את הימים בהם יש לקנות ולמכור מניה  על מנת למקסם רווחים
במידה ולא קיימת אפשרות להרוויח הפונציה תחזיר אפסים
*/
void maxProfit(double stock[],int size,int *ibuy,int *isell)
{
	int min = 0; //היום בו המניה הכי זולה
	int buy=0,sell=0; //הימים בהם יש לקנות ולמכור את המניה
	double mProfit = 0;

	for (int i = 1; i <= size-1; i++) //מתחילים מהיום השני כי ימי הקניה והמכירה מאותחלים ליום הראשון
	{
		if ((stock[i] - stock[min]) > mProfit) //  בדיקת האם ההפרש הנוכחי גדול יותר מההפרש הקיים משמע התגלו ימי קניה ומכירה טובים יותר
		{
			buy = min;
			sell = i;
			mProfit = stock[i] - stock[min];
		}

		if (stock[i] < stock[min]) //בדיקה האם קיים יום קניה זול יותר
			min = i;
	}
	*isell = sell;
	*ibuy = buy;
}