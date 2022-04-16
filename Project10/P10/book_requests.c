/*
Name: Shaunak Pandhare 
U63705561 
Description: This program uses a dynamically allocated linked list to store book requests. 

*/

//contains only the main function and directives 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "book.h"

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct book *book_list = NULL;  
  printf("Operation Code: a for adding to the list, s for searching a book"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': book_list = add_to_end(book_list);
                break;
      case 's': search(book_list);
                break;
      case 'p': print_list(book_list);
                break;
      case 'q': clear_list(book_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}
