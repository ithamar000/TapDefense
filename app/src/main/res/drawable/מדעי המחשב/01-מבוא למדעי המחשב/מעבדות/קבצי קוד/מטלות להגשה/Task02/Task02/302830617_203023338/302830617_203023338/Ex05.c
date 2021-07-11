/*
Assigned by:
Student1 Eliran Malka #302830617
Student2 Itamar Yacoby #203023338
*/
#include <stdio.h>
#include <assert.h>

int countArr(int arr[], int size);
int *input_array_dyn(int *n);
void Ex05();

void main()
{
	Ex05();
	system("pause");
}

int *input_array_dyn(int *n)
{
	int i;
	int *a;
	printf("enter the length of the array\n");
	scanf_s("%d", n);
	a = (int *)calloc(*n, sizeof(int));
	assert(a); /* calloc() worked */
	printf("enter the array of length %d\n", *n);
	for (i = 0; i < *n; i++)
		scanf_s("%d", a + i);
	return a;
}

void Ex05()
{
	int n=0;
	int *arr = input_array_dyn(&n);
	printf("%d\n", countArr(arr, n));
	free(arr);
}
/*
�������� ����� ���� ������ ����� ������ ������� 
��� ��� ������� ������� ����� ������ ����� ���� 0 ����� �� ����� ���� 1 
*/
int countArr(int arr[], int size)
{
	int *cArr;
	cArr = (int*)calloc(size, sizeof(int)); // ����� ���� ����� ��� ����� �� �����
	for (int i = 0; i <= size - 1; i++)		// ���� �� ��� ����� 
	{
		cArr[arr[i]]++;						// ����� ���� ������ ������� �� ���� �� ����� �����
		if (cArr[arr[i]] > 1)				//����� ��� ���� ���� ����� �1 ���� ����� �� ���� �� �� �������
		{
			free(cArr);
			return 0;
		}
	}
	free(cArr);
	return 1;
}