#include <stdio.h>



void main() {
	int year, month, day;
	printf("enter date:\n");
	scanf_s("%d%d%d", &day, &month, &year);
	if (month < 12 && day < 31)
	{
			switch (month)
			{
			case 1:
					if (day<31)
						printf("date is: %d-%d-%d\n", ++day, month, year);
					else
						printf("date is: %d-%d-%d\n", day=1, ++month, year);
					break;
			case 2:
				
					if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
					{
						if (day < 29)
							printf("date is: %d-%d-%d\n", ++day, month, year);
						else
							printf("date is: %d-%d-%d\n", day=1, ++month, year);
					}
					else
					{
						if (day < 28)
							printf("date is: %d-%d-%d\n", ++day, month, year);
						else
							printf("date is: %d-%d-%d\n", day=1, ++month, year);
					}
					break;
			case 3:
				
					if (day < 31)
						printf("date is: %d-%d-%d\n", ++day, month, year);
					else
						printf("date is: %d-%d-%d\n", day=1, ++month, year); 
					break;
			case 4:
				
					if (day < 30)
						printf("date is: %d-%d-%d\n", ++day, month, year);
					else
						printf("date is: %d-%d-%d\n", day=1, ++month, year);
			case 5:
				
					if (day < 31)
						printf("date is: %d-%d-%d\n", ++day, month, year);
					else
						printf("date is: %d-%d-%d\n", day=1, ++month, year); 
					break;
			case 6:
				
					if (day < 30)
						printf("date is: %d-%d-%d\n", ++day, month, year);
					else
						printf("date is: %d-%d-%d\n", day=1, ++month, year);
					break;
			case 7:
				
					if (day < 31)
						printf("date is: %d-%d-%d\n", ++day, month, year);
					else
						printf("date is: %d-%d-%d\n", day=1, ++month, year);
					break;
			case 8:
				
					if (day < 31)
						printf("date is: %d-%d-%d\n", ++day, month, year);
					else
						printf("date is: %d-%d-%d\n", day=1, ++month, year);
					break;
			case 9:
				
					if (day < 30)
						printf("date is: %d-%d-%d\n", ++day, month, year);
					else
						printf("date is: %d-%d-%d\n", day=1, ++month, year);
					break;
			case 10:
				
					if (day < 31)
						printf("date is: %d-%d-%d\n", ++day, month, year);
					else
						printf("date is: %d-%d-%d\n", day=1, ++month, year);
					break;
			case 11:
				
					if (day < 30)
						printf("date is: %d-%d-%d\n", ++day, month, year);
					else
						printf("date is: %d-%d-%d\n", day=1, ++month, year);
					break;
			case 12:
				
				if (day < 31) 
						printf("date is: %d-%d-%d\n", ++day, month, year);
					else
						printf("date is: %d-%d-%d\n", day=1, month=1, ++year);
				break;
			default:
			break;
			}


		
	}
	else
		printf("wrong date");

		getch();
}