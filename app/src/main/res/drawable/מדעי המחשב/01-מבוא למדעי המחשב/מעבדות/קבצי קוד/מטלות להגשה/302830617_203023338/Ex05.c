/*
Assigned by:
Student1 Eliran Malka #302830617
Student2 Itamar Yacoby #203023338
*/
#include <stdio.h>

int howManyDiv(int num);
int isBig(int num);
void Ex05();

void main()
{

	Ex05();
	system("pause");
}
void Ex05()
{
	int num;
	printf("enter number to check\n");
	scanf_s("%d", &num);
	printf("the number is big:%d\n", isBig(num));

}
/*
Checking if number is "Big"
"Big" means a number has more dividers than numbers smaller than him.
*/
int isBig(int num)
{
	int divNum = howManyDiv(num); // Checking number of dividers of Num
	for (int i = 1; i < num; i++)  
	{
		if (howManyDiv(i) >= divNum) // Num isn't "Big"
			return 0;
	}
	return 1; // Num is "Big"
}

int howManyDiv(int num) // Returning number of dividers of num
{
	int i, count=0;
	for (i = 1; i <= num; i++)
	{
		if (((double)num / i) - (num / i) == 0) // no reminder means i is a divider of num
			count++;
	}
	return count; // returning number of dividers
}