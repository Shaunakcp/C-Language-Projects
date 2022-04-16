/*
 * Name: Shaunak Pandhare 
 * U63705561
 * Description: Checks if the user inputs a word with all characters being alphabetic letters and that the word is valid if all letters are uppercase or lowercase letters.
 */ 



#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch;
	int is_valid = 1;
	printf("Enter a word: ");
	ch = getchar();
	
	if (ch >= 'A' && ch <= 'Z')
	{
		while (ch != '\n') { 
			if (!(ch >= 'A' && ch <= 'Z')) 
				is_valid = 0;
			printf("%c", ch);
			ch = getchar();
		}
	}
	
	if (ch >= 'a' && ch <= 'z')
	{
		while (ch != '\n'){ 
			if (!(ch >= 'a' && ch <= 'z'))
				is_valid = 1;
			printf("%c", ch);
			ch = getchar();

			
		}
	}

	
	if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')))
	{
		
		while (ch != '\n'){
			is_valid = 0;
			printf("%c", ch);
			ch = getchar();

		}
	
	}


	printf("\nHit enter to display output\n");
	printf("%c", ch);
	ch = getchar();

	if (is_valid)
		printf("Output: Valid\n");
	else
		printf("Output: Invalid\n");

	return 0;
}
