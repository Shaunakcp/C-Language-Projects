/* 
Name: Shaunak Pandhare 
U63705561 
Description: Modifies project 2, problem 2 (validate words) so the word is a command line argument and 
            checks if the command line argument contains all alphabetic letters and if all letters 
            are either lowercase or uppercase. 
*/

#include <stdio.h>

#include <stdlib.h>


int validate(char *word); //declaration 

int main(int argc, char *argv[])
{
    
    if (argc > 1 && argc < 3) // checks if count of arguement is always 2 as "./a.out" is the first argument and the word is the second argument 
        if(validate(argv[1])) // if validate returns 1 
            printf("\nValid.\n");
        else 
            printf("\nInvalid.\n");
    else // if the count of arguments is not 2 
        printf("\nIncorrect number of arguements. Usage: ./a.out word\n");

	return 0;
}


int validate (char *word) //declaration 
{
    char *p;
    p = word; //takes the first letter of the word, like a[0] for an array a 

        if (*p >= 'A' && *p <= 'Z') //checks if first letter of argument is uppercase 
	    {
            for (p = word + 1; *p != '\0'; p++) { //goes through argument starting from second letter 
                if (!(*p >= 'A' && *p <= 'Z')) // if not uppercase 
                    return 0;
                
            }
	    }
	
        if (*p >= 'a' && *p <= 'z') //checks if first letter of argument is lowercase 
        {
            for (p = word + 1; *p != '\0'; p++){ //goes through argument starting from second letter 
                if (!(*p >= 'a' && *p <= 'z')) //if not lowercase 
                    return 0;
                
            }		
		}
	
	    if (!((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))) //checks if it is a digit 
	    {
            while (*p != '\0'){
                return 0;
                
		    }
	    }
    
    return 1; 
}