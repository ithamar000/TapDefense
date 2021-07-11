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
	int *arr = input_array_dyn(&n); // קליטת מערך

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
פונקציה המקבלת מערך של מספרים שלמים ומעבירה את האפסים לסופו.
בנוסף הפונקציה מחזירה את מספר האיברים השונים מ-0
*/
int moveZero(int arr[], int size)
{
	int i = 0, last = (size - 1), count=0;
	while (last >= i) //הלולאה רצה עם מצביע על התחלת המערך ומצביע על סופו
	{
		if (arr[i] == 0) //התגלה 0 במערך
		{
			if (arr[last] != 0) //הערך באינדקס הימני אינו אפס לכן דרושה החלפה 
			{
				arr[i] = arr[last]; 
				arr[last] = 0;
				i++; //קידום האינדקס השמאלי כי כרגע אינו מכיל 0
				last--; //הורדת האינדקס הימני כי כרגע מכיל 0
				count++; // נמצא ערך השונה מ-0
			}
			else 
				last--; //הערך באינדקס השמאלי 0 אך גם בימני. לכן נמשיך בחיפוש ערך שאינו 0 בצד הימני של המערך
					
		}
		else //הערך השמאלי אינו 0 לכן נמשיך בחיפוש בצד השמאלי
		{
			count++; //נמצא ערך השונה מ -0
			i++;
		}
	}
	if (size == 1) //טיפול במקרה קצה בו לא נכנס ללואה
		return (arr[0] != 0); // תחזיר 1 אם הערך שונה מ-0 או תחזיר 0 אם הערך שווה ל-0
	return count; 
}
