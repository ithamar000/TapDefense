/*
Assigned by:
Student1 Eliran Malka #302830617
Student2 Itamar Yacoby #203023338
*/
#include <stdio.h>

int delDig(int num, int d);
void Ex06();

void main()
{
	Ex06();
	system("pause");
}
void Ex06()
{
	int num, d;
	printf("enter number:\n");
	scanf_s("%d", &num);
	printf("enter digit to delete:\n");
	scanf_s("%d", &d);
	printf("%d\n", delDig(num, d));

}
/*
Deleting specific digits from num in a recursive way
	num - the number
	d - the digit to delete from num
*/
int delDig(int num,int d)
{

	if (num < 10) // Base condition
		if (num == d)
			return 0;
		else
			return num;
	if (num % 10 == d) //Checking if units digit is d
		return delDig(num / 10, d); //Deleting the digit from num 
	else
		return 10*delDig(num / 10, d)+(num%10); //Continuing without deleting a digit
}