/*
Name: Shaunak Pandhare 
U63705561 
Description: The program checks if an email address read from an input file is a USF email, an email which contains the address usf.edu. 
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 //length of input file name is no more than 100 characters
#define EMAIL_LENGTH 2000 //length of email address is no more than 2000 characters

int is_USF_email(char *email); 

int main()
{
    char filename[MAX_LENGTH + 1]; //input file 
    char email[EMAIL_LENGTH + 1]; //second file that will be part of the output file 
    char new_name[MAX_LENGTH + 1] = {"USF_"}; //create a new file with the USF emails with the name of the file starting with USF_

    printf("Enter input file: ");
   
    scanf("%s", filename);

    strcat(new_name, filename); //concatenates USF_ and the filename from the input file 

    FILE* pFile = fopen(filename, "r"); //open input file to read the contents 
    
    //invalidation check
    if (pFile == NULL)
    {
        printf("\nError opening file\n");
        return 1; //abnormal termination
    }

     FILE *fw = fopen(new_name, "w"); //output file that contains all the USF emails from the input file 

     if (fw == NULL) //invalidation check 
    {
        printf("\nError opening file");
        return 1; //abnormal termination 
    }

    while (fgets(email, EMAIL_LENGTH + 1, pFile) != NULL){ //reads a line from the specified stream and stores it into the string pointed to by email
        if (is_USF_email(email) == 1) //if the function returns 1 
            fputs(email, fw); //puts the usf emails into the file fw 
    }

    fclose(pFile); //close the file
    fclose(fw); //close the file 
    return 0;
}

int is_USF_email(char *email) //The function is_USF_email expects email to point to a string containing an email address
{

    char *p;  
    p = email;
    
    //could do strtr(email...) instead of using p 
    if (strstr(p, "usf.edu")) //strstr finds the substring "usf.edu" in email
        return 1; //returns 1 if usf.edu is in the email address
    else
        return 0; //returns 0 if usf.edu is not in the email address 

    
}