#include <stdio.h>
#include <stdlib.h>

int* defArr10();
void numArr10(int *p);

void main()
{
	int* pArr;
	pArr = defArr10();
	numArr10(pArr);
	for (int i = 0; i < 10; i++)
	{
		printf("arr %d , is : %d\n", i, pArr[i]);
	}

	free(pArr);
	system("pause");
}

int* defArr10()
{
	return (int*)malloc(sizeof(int) * 10);
}

void numArr10(int *p)
{
	for (int i = 0; i < 10; i++)
		p[i] = i;
}