#include <stdio.h>


void main() {
	int a,b,c;
	printf("hello! \nplease enter 3 numbers: \n");
	scanf_s("%d%d%d",&a,&b,&c);
	printf("the avg is:%.2lf\n", (double)(a+b+c)/3);
	system("pause");

}