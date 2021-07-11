#include <stdio.h>

int ByRef(int arr[], int n, int key, int *ref1, int *ref2);

void main()
{
	int arr[5] = {1,6,2,4,3};
	int n = 5;
	int key = 3;
	int ref1,ref2;
	int res;
	res=ByRef(arr, n, key, &ref1, &ref2);
	printf("res : %d \n ref1 :%d \n ref2:%d\n", res, ref1, ref2);
	system("pause");
}

int ByRef(int arr[], int n, int key, int *ref1, int *ref2)
{
	for (int i=0;i<n;i++)
		for (int j = i+1; j < n; j++)
		{
			if ((arr[i] + arr[j]) < key)
			{
				*ref1 = arr[i];
				*ref2 = arr[j];
				return 1;
			}
		}
	*ref1 = -2;
	*ref2 = -2;
	return 0;
}