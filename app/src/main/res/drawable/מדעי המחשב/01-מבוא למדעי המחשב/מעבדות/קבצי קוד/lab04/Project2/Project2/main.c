#include <stdio.h>
void main()
{
	int num;

		printf("enter number\n");
		scanf_s("%d", num);

	while (!(num == 5))
	{
		printf("eror, enter number again\n");
		scanf_s("%d", num);
	}

	getch();
}
