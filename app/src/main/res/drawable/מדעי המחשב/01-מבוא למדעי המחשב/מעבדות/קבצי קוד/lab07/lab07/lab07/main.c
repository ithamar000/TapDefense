#include <stdio.h>

void maxNum(int *pNum1, int *pNum2, int *pNum3);

void main()
{
	int num1 = 1000, num2 = 500, num3 = 900;
	printf("num 1: %d num 2: %d num 3: %d \n", num1, num2, num3);
	maxNum(&num1,&num2,&num3);
	printf("num 1: %d num 2: %d num 3: %d \n", num1, num2, num3);
	system("pause");
}

void maxNum(int *pNum1, int *pNum2, int *pNum3)
{
	int temp;
	if (*pNum2 > *pNum1) 
	{
		temp = *pNum1;
		*pNum1 = *pNum2;
		*pNum2 = temp;
	}
	 if (*pNum3 > *pNum1)
	{
		temp = *pNum1;
		*pNum1 = *pNum3;
		*pNum3 = temp;
	}
	 if (*pNum3 > *pNum2)
	 {
		 temp = *pNum2;
		 *pNum2 = *pNum3;
		 *pNum3 = temp;
	 }
}