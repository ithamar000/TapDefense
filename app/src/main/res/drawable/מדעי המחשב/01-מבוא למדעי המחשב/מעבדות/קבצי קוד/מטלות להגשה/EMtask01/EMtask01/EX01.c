/*
Assigned by:
Student1 Eliran Malka #302830617
Student2 Itamar Yacoby #203023338
*/
#include <stdio.h>

void Ex1();
int isItBigger(int k);
void main()
{
	Ex1();
}
void Ex1()
{
	int k;
	//input
	printf("enter the number to check: \n");
	scanf_s("%d", &k);
	//קריאה לפונקציה שבודקת האם המספר גדול מסכום 2 מספרים בסדרת מספרים והדפסת התוצאה למשתמש
	if (isItBigger(k) == 1)
		printf("there is two numbers are bigger from K\n");
	else if(isItBigger(k) == 0)
	{
		printf("there is NO numbers are bigger from K\n");
	}
	system("pause");
}

int isItBigger(int k)
{
	int num, temp = 0;

	do
	{
		printf("enter mumber please:"); //input numbers
		scanf_s("%d", &num);
		if (num + temp > k)		// test for the new num and the big number so far biggest from k 
			return 1;
		if (num > temp)			//  Test and input to "temp" variable The largest number recorded so far
			temp = num;
	} while (num != -1);		// The stop condition is  number input diffrent from "-1"	
	return 0;
}
