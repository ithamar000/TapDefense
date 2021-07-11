/*
Assigned by:
Student1 Eliran Malka #302830617
Student2 Itamar Yacoby #203023338
*/
#include <stdio.h>

void Ex2();
int binLong(int n);				//the function check about the max same digit at binary number


void main()
{
	Ex2();
	system("pause");
}
void Ex2()
{
	int n;
	printf("enter the lenth of the binary number\n");	//input from user
	scanf_s("%d", &n);
	printf("the max same digit is: %d\n",binLong(n));
}


int binLong(int n)
{
	int max=1,bin,count=1,first,sec;					//Definition of variables
	if (n == 0)
		return 0;
	printf("enter the binary number\n");
	scanf_s("%d", &bin);
	sec = bin;
	while (n>1)// One digit was already recived so condition is until 1
	{
		printf("enter the binary digit:\n");
		scanf_s("%d", &bin);
		first = bin;
		if (first == sec)					//check if the digit the same
			count++;
		else
			count = 1;					//if the digit not same the counter start again
		if (count > max)	//Checking if current sequence is larger
			max = count;
		sec = bin;
		n--;
	}
	return max;
}
