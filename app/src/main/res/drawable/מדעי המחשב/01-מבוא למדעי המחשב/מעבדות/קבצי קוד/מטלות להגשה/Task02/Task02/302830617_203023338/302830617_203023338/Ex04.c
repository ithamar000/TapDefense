#include <stdio.h>
#include <assert.h>

int checkTmuraB(int arrA[], int arrB[], int n);
void Ex04();
int *input_array_dyn(int *n);
void merge_sort(int *a, int first, int last);
void merge(int *a, int p, int q, int r);
int checkTmuraA(int arrA[], int arrB[], int n);

void main()
{
	Ex04();
	system("pause");
}

void Ex04()
{
	int *A, *B;
	int n = 0;
	A = input_array_dyn(&n);
	B = input_array_dyn(&n);

	printf("%d\n", checkTmuraA(A, B, n));

	A = input_array_dyn(&n);
	B = input_array_dyn(&n);
	printf("%d\n", checkTmuraB(A, B, n));

	free(A); free(B);

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

void merge_sort(int *a, int first, int last)
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

void merge(int *a, int p, int q, int r)
{
	int i = p, j = q + 1, k = 0;
	int* temp = (int*)calloc(r - p + 1, sizeof(int));
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
הפונקציה בודקת האם הערכים במערך אחד הוא תמורה של הערכים במערך השני
ע"י מיון שני המערכים והשוואתם
*/
int checkTmuraA(int arrA[], int arrB[], int n)
{
	merge_sort(arrA, 0, n - 1); // מיון המערך הראשון
	merge_sort(arrB, 0, n - 1); // מיון המערך השני

	for (int i = 0; i < n; i++) // השוואת המערכים
	{
		if (arrA[i] != arrB[i]) // נמצא ערך שונה לכן המערכים אינם תמורה
			return 0;
	}

	return 1; // המערכים אכן תמורה אחד של השני
}

/*
הפונקציה בודקת האם הערכים במערך אחד הוא תמורה של הערכים במערך השני
ע"י שימוש במערך מונים לכל מערך והשוואת המערכים
*/
int checkTmuraB(int arrA[], int arrB[], int n)
{
	int *counterA = (int*)calloc(n, sizeof(int));// הקצאת זיכרון למערך מונים ראשון
	int *counterB = (int*)calloc(n, sizeof(int)); // הקצאת זיכרון למערך מונים שני

	for (int i = 1; i <= n; i++) // מילוי שני מערכי המונים
	{
		counterA[arrA[i]-1]++;
		counterB[arrB[i]-1]++;
	}

	for (int i = 0; i < n; i++) // השוואת מערכי המונים
	{
		if (counterA[i] != counterB[i]) //נמצא ערך שונה לכן המערכים אינם תמורה
		{
			free(counterA); 
			free(counterB);
			return 0;
		}
	}
	free(counterA);
	free(counterB);
	return 1; //המערכים אכן תמורה אחד של השני

}