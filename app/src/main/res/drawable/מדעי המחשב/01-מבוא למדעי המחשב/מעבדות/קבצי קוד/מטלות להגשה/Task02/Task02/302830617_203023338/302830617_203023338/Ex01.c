#include <stdio.h>
#include <assert.h>


void maxProfit(double stock[], int size, int *ibuy, int *isell);
void Ex01();
double *input_array_dyn(int *n);

void main()
{
	Ex01();
	system("pause");
}

void Ex01()
{
	int n;
	double *arr = input_array_dyn(&n); //����� ����
	int buyDay, sellDay;

	maxProfit(arr, n, &buyDay, &sellDay); //����� ��������

	printf("buy: %d , sell: %d\n", buyDay, sellDay); //����� ��� ������ ������
	free(arr);
}

double *input_array_dyn(int *n)
{
	int i;
	double *a;
	printf("enter the length of the array\n");
	scanf_s("%d", n);
	a = (double *)calloc(*n, sizeof(double));
	assert(a); /* calloc() worked */
	printf("enter the array of length %d\n", *n);
	for (i = 0; i < *n; i++)
		scanf_s("%lf", a + i);
	return a;
}

/*
������� ������� ����� ������� �� ����� ��� �� ����� ������ ����  �� ��� ����� ������
����� ��� ����� ������ ������� ������� ����� �����
*/
void maxProfit(double stock[],int size,int *ibuy,int *isell)
{
	int min = 0; //���� �� ����� ��� ����
	int buy=0,sell=0; //����� ��� �� ����� ������ �� �����
	double mProfit = 0;

	for (int i = 1; i <= size-1; i++) //������� ����� ���� �� ��� ����� ������� �������� ���� ������
	{
		if ((stock[i] - stock[min]) > mProfit) //  ����� ��� ����� ������ ���� ���� ������ ����� ���� ����� ��� ���� ������ ����� ����
		{
			buy = min;
			sell = i;
			mProfit = stock[i] - stock[min];
		}

		if (stock[i] < stock[min]) //����� ��� ���� ��� ���� ��� ����
			min = i;
	}
	*isell = sell;
	*ibuy = buy;
}