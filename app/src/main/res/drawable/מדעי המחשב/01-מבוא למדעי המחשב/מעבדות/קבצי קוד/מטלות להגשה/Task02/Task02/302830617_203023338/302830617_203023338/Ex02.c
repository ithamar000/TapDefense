#include <stdio.h>
#include <assert.h>

int moveZero(int arr[], int size);
void Ex02();
int *input_array_dyn(int *n);

main()
{
	Ex02();
	system("pause");
}


void Ex02()
{
	int n=0;
	int *arr = input_array_dyn(&n); // ����� ����

	printf("%d\n", moveZero(arr, n));
	free(arr);

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

/*
������� ������ ���� �� ������ ����� ������� �� ������ �����.
����� �������� ������ �� ���� ������� ������ �-0
*/
int moveZero(int arr[], int size)
{
	int i = 0, last = (size - 1), count=0;
	while (last >= i) //������ ��� �� ����� �� ����� ����� ������ �� ����
	{
		if (arr[i] == 0) //����� 0 �����
		{
			if (arr[last] != 0) //���� ������� ����� ���� ��� ��� ����� ����� 
			{
				arr[i] = arr[last]; 
				arr[last] = 0;
				i++; //����� ������� ������ �� ���� ���� ���� 0
				last--; //����� ������� ����� �� ���� ���� 0
				count++; // ���� ��� ����� �-0
			}
			else 
				last--; //���� ������� ������ 0 �� �� �����. ��� ����� ������ ��� ����� 0 ��� ����� �� �����
					
		}
		else //���� ������ ���� 0 ��� ����� ������ ��� ������
		{
			count++; //���� ��� ����� � -0
			i++;
		}
	}
	if (size == 1) //����� ����� ��� �� �� ���� �����
		return (arr[0] != 0); // ����� 1 �� ���� ���� �-0 �� ����� 0 �� ���� ���� �-0
	return count; 
}
