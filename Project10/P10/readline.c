#include <stdio.h>
#include <ctype.h>
#include "readline.h"

int read_line(char str[], int n) //reads a string 
{
  int ch, i = 0; //i set to index 0 

  while (isspace(ch = getchar())) //loop does nothing if there is whitespace 
    ;
  str[i++] = ch; //index is incremented and whitespace is saved 
  while ((ch = getchar()) != '\n') { //reads the characters and stores them into the array while the user has not hit space 
    if (i < n)
      str[i++] = ch; 
    
   }
   str[i] = '\0'; //terminates string 
   return i; //number of characters stored 
}
