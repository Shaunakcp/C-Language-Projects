/*
 * Name: Shaunak Pandhare
 * U63705561
 * Description: Find the Chinese zodiac sign based on a person's year of birth.
 *
 */

#include <stdio.h>

int main()
{
	int birth_year, remainder;
	printf("Enter the year of birth: ");
	scanf("%d", &birth_year);
	
	if (birth_year <= 0)
		printf("Year of birth cannot be 0 or less, try again.\n");

	remainder = (birth_year % 12); 
	
	switch (remainder)
	{
		case 0: 
			remainder = 0;
			printf("The Chinese animal sign for %d is Monkey.\n", birth_year);
			break;
		case 1:
			remainder = 1;
			printf("The Chinese animal sign for %d is Rooster.\n", birth_year);
			break;
		case 2:
			remainder = 2;
			printf("The Chinese animal sign for %d is Dog.\n", birth_year);
			break;
		case 3:
			remainder = 3;
			printf("The Chinese animal sign for %d is Pig.\n", birth_year);
			break;

		case 4:
			remainder = 4;
			printf("The Chinese animal sign for %d is Rat.\n", birth_year);
			break;

		case 5:
			remainder = 5;
			printf("The Chinese animal sign for %d is Ox.\n", birth_year);
			break;

		case 6:
			remainder = 6;
			printf("The Chinese animal sign for %d is Tiger.\n", birth_year);
			break;

		case 7:
			remainder = 7;
			printf("The Chinese animal sign for %d is Rabbit.\n", birth_year);
			break;

		case 8:
			remainder = 8;
			printf("The Chinese animal sign for %d is Dragon.\n", birth_year);
			break;

		case 9:
			remainder = 9;
			printf("The Chinese animal sign for %d is Snake.\n", birth_year);
			break;

		case 10:
			remainder = 10;
			printf("The Chinese animal sign for %d is Horse.\n", birth_year);
			break;

		case 11:
			remainder = 11;
			printf("The Chinese animal sign for %d is Sheep.\n", birth_year);
			break;

	}

	return 0;
}
