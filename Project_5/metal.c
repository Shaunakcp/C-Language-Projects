/*
Name: Shaunak Pandhare 
U63705561 
Description: Calculates how many of the metal bars you have in s2 are in s1.
*/



#include <stdio.h>

#define N 1000

int count(char *s1, char *s2);
int read_line(char *s1, int n);



int main()
{
    //printf("Enter s1: ");
    //scanf("%s", &a[i])
    char reads1[N+1];
    char reads2[N+1];
    // int n; //length of array 

    // char a[N + 1];
    printf("Enter s1: \n");
    read_line(reads1, N);
    
    printf("Enter s2: \n");
    read_line(reads2,N);

    // count(reads1, reads2); 
    printf("Ouput: %d\n", count(reads1, reads2));

    return 0;
}

int count(char *s1, char *s2) //returns the number of characters in s2 that are in s1 
//look at page 20 on week 8 ch 13_1 pptx 
{
    //int *p, *q;

    //for (p = a; p < a + n; p ++)
        //for (q = p + 1; q < a + n; q++)
            //if (*p == *q)
           // {   
                //*s2 = *p
                //*s2++;
                

           //}
    char *p, *q;
    int amt = 0;
    for (p = s1; *p != '\0'; p++)
        for (q = s2; *q != '\0'; q++)
            if (*p == *q)
                amt++; 
                // printf("Output: %d", amt);
    return amt;

}

int read_line(char *s1, int n)
{
    int ch; int i = 0;

	// while((ch = getchar()) == ' ')
	// 	;
	// *s1++ = ch; 
	// i++; 

    while ((ch = getchar()) != '\n')
    {  	
		if (i < n)
        { 	
			*s1++= ch;
	    	i++;
        }
	}
    *s1 = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}