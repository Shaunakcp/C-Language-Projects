/* book.c contains the all the functions related to operations on the list of book requests
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "book.h"

struct book *add_to_end(struct book *list){ //adds the user inputted book information into the library 

  struct book *input_book; //pointer to the input_book node 

  input_book = malloc(sizeof(struct book)); //input_book now points to a block of memory just large enough to hold the book structure
  
  printf("\nEnter a book's title:\n "); //input for book's title 
  read_line(input_book->title, TITLE_LEN); //readline reads the input and stores it into the input_book node  

  printf("\nEnter author's first name:\n "); //input for author's first name 
  read_line(input_book->first, NAME_LEN);//readline reads the input and stores it into the input_book node  

  printf("\nEnter author's last name:\n "); //input for author's last name 
  read_line(input_book->last, NAME_LEN); 

  printf("\nEnter classroom:\n "); //input for classroom 
  read_line(input_book->classroom, ROOM_LEN);//readline reads the input and stores it into the input_book node  

  input_book->next = NULL; 

  if (input_book == NULL) //if the input_book node is empty 
  {
    printf("malloc failed in add_to_end\n");
    return list;
  }

  struct book *p, *prev; //declaring struct p and prev to use in the for loop

  int first_cmp, sec_cmp; //declaring int variables for strcmp

  for (prev = NULL, p = list; p != NULL; prev = p, p = p->next) //the for loop finds the position for the input_book to be placed
  {
    first_cmp = strcmp(input_book->last, p->last); //strcmp for last name 
    if (first_cmp < 0) //if input_book's last name is smaller than the one in list, break out of loop
      break;
    if (first_cmp == 0) //if last names are equal then move into block and compare first names 
    {
      sec_cmp = strcmp(input_book->first, p->first); //strcmp for fist name 
      if (sec_cmp < 0) //if input_book's first name is smaller than the one in list, break out of loop 
        break;
    }

    if ((strcmp(input_book->title, p->title) == 0) && (strcmp(input_book->first, p->first) == 0) 
    && (strcmp(input_book->last, p->last) == 0) && (strcmp(input_book->classroom, p->classroom) == 0)) //compares the input to exisiting list structures 
    {
      printf("Book already exists.\n");
      free(input_book); //frees the created node as the book already exists and won't be used 
      return list; //returns the curretn list
    }

  }

  printf("Enter the price:\n "); //input for the price of the book 
  scanf("%lf", &input_book->price); //price is a float and the input is stored as the price of input_book 

  input_book->next = p; //input_book's next will be the structure that is larger than it 

  if (prev == NULL) //if list is empty 
    list = input_book; //list points to the structure first
  
  else //if list contains structures 
    prev->next = input_book; //input_book is placed after the structure that is larger than it 

  return list; //returns an array of strings 

}

void search(struct book *list) //searches the library 
{
  char the_book[TITLE_LEN + 1]; //input string array that is the title 
  printf("Enter the title of the book:\n ");
  read_line(the_book, TITLE_LEN);

  struct book *p;
  int flag = 0; //initialize flag to 0 
  for (p = list; p != NULL; p = p->next) //iterates through the contents of the structure
  {
    if (strcmp(p->title, the_book) == 0) //if the title from the strucutre is the same as the input string  
    {
      printf("%s\t %s %s\t %s\t $%.2f", p->title, p->first, p->last, p->classroom, p->price); //prints the contents of the structure 
      flag = 1; 
    }
  }
  if (flag == 0) //if the input string for the title is not the same as the title from the strucutre
    printf("Book does not exist\n"); 
}
 

void print_list(struct book *list){ //prints the contents of the library 

  struct book *p; //pointer to the p node 
  for (p = list; p != NULL; p = p->next) 
    printf("%s\t %s %s\t $%.2f\t %s\n", p->title, p->first, p->last, p->price, p->classroom);

}
void clear_list(struct book *list) //clears the list so it frees each structure 
{
  struct book *p; //pointer to the p node 
  while(list != NULL) 
  {
    p = list; //p points to the element list is pointing at
    list = list->next; //list is moved to the next element in order for the other elements to be accessed when p is freed 
    if(p!= NULL) //frees the structure 
      free(p);
  }
}

