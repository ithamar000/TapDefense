#include <stdio.h>


void main(){
	int a, b;
	printf("hello! \nplease enter 2 numbers: \n");
	scanf_s("%d%d",&a,&b);
	printf("%.2lf\n",(double)a/b);
	system("pause");

}