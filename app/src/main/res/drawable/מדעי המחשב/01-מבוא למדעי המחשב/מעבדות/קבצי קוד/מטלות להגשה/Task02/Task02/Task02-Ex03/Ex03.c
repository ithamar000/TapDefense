/*
Assigned by:
Student1 Eliran Malka #302830617
Student2 Itamar Yacoby #203023338
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



void Ex3();
double *input_array_dyn(int *n);
void merge_sort(double *a, int first, int last);
void merge(double *a, int p, int q, int r);
double* arrayOfCommons(double arrayA[], double arrayB[], int sizeA, int sizeB, int* newArrSize);


void main()
{
	Ex3();
	system("pause");
}

void Ex3()
{
	int n, m, fSize;
	double *A, *B, *C;
	A = input_array_dyn(&n);
	B = input_array_dyn(&m);
	C = arrayOfCommons(A, B, n, m, &fSize);
	free(A);
	free(B);
	free(C);
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

void merge_sort(double *a, int first, int last)
{
	int middle;
	if (first < last)
	{
		middle = (first + last) / 2;
		merge_sort(a, first, middle);
		merge_sort(a, middle + 1, last);
		merge(a, first, middle, last);
	}
}

void merge(double *a, int p, int q, int r)
{
	int i = p, j = q + 1, k = 0;
	double* temp = (double*)calloc(r - p + 1, sizeof(double));
	while ((i <= q) && (j <= r))
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	while (j <= r)
		temp[k++] = a[j++];
	while (i <= q)
		temp[k++] = a[i++];

	for (i = p, k = 0; i <= r; i++, k++)
		a[i] = temp[k];
	free(temp);
}

/*
������� ������ ��� ������ ������� ���� ����� �� �� ������ �������� ��� ������ ������ �� �����.
�������� ������ �� ��� ������� ������ ��� ��� �� ��� ��� �������
�� �� ������ ����� ������� �������� ������ NULL
*/
double* arrayOfCommons(double arrayA[], double arrayB[], int sizeA, int sizeB, int* newArrSize)
{
	int indexA = 0, indexB = 0, indexC = 0;
	double* commonsArray; //���� ������ ��������
	commonsArray = (double*)calloc(1, sizeof(double)); 

	merge_sort(arrayA, 0, sizeA - 1); //���� ����� ������
	merge_sort(arrayB, 0, sizeB - 1);

	while (indexA < sizeA && indexB < sizeB) //������ ������� ���� ����� ���� ��� �������
	{
		if (arrayA[indexA] == arrayB[indexB]) //���� ��� �����
		{
			commonsArray = (double*)realloc(commonsArray, (indexC + 1) * sizeof(double)); //����� ���� ��������
			commonsArray[indexC] = arrayA[indexA];
			indexA++; indexB++; indexC++;	// ����� ��������� ��� �������
		}
		else
			if (arrayA[indexA] > arrayB[indexB]) //������� ������� ��� �� ���� ����� ������ ���� ���� ���� �� ����� ����� ����
				indexB++;
			else
				indexA++;
	}
	if (indexC == 0) // �� ������ ����� �������
	{
		free(commonsArray);
		return NULL;
	}
	*newArrSize = indexC; 
	return commonsArray;
}