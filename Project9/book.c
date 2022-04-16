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

  struct book *p;
  int flag = 0; //intialize flag to 0 
  for (p = list; p != NULL; p = p->next)
  {
    if ((strcmp(input_book->title, p->title) == 0) && (strcmp(input_book->first, p->first) == 0) &&  //compare the strings of the input to the existing structures 
        (strcmp(input_book->last, p->last) == 0) && (strcmp(input_book->classroom, p->classroom) == 0))
          flag = 1; //if the strings are equal flag is set to 1
    
  }

  if (flag == 1) //if the condition is  true 
  {
    printf("Book already exists.\n");
    return list;
  }

  printf("Enter the price:\n "); //input for the price of the book 
  scanf("%lf", &input_book->price); //price is a float and the input is stored as the price of input_book 

  if (list == NULL){ //if list is empty
    list = input_book; //list points to the structure 
  }
  else //if list contains structures 
  {
    struct book *temp; //pointer to the temp node which moves through list 
    temp = list; //temp points to the first element in the structure list 
    while (temp->next != NULL) //the loop stops when temp gets to the last structure 
      temp = temp->next; //moves to next structure 
    temp->next = input_book; //makes the next value of the last element the new structure when the loop ends 
  }

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

