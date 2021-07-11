#include <stdio.h>
void print_C1(int num, char c1, char c2);

void main()
{
	int num;
	char c11 = 'E', c22 = 'M';
	printf("enter number: \n");
	scanf_s("%d", &num);
	
	print_C1(num, c11,c22);
	printf("/n");
	system("pause");
}

void print_C1(int num, char c1, char c2)
{
	if (num < 1)
		return;
	printf("%c", c1);
	print_C1(num - 1,c1,c2);
	printf("%c%c",c2, c2);





}