#include <stdio.h>

void main() {
	char c1, c2, c3;
	int num1;
	printf("enter 3 chars:\n"); 
	scanf_s("%c", &c1); rewind(stdin);
	scanf_s("%c",&c2);	rewind(stdin);
	scanf_s("%c",&c3);	rewind(stdin);
	num1 = (c1%48)*100+((c2%48) * 10) + (c3%48);
	printf("%d\n",num1);
	system("pause");
}