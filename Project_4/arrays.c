/*
Name: Shaunak Pandhare 
U63705561
Description: Displays all integers that appear twive in a given an array of n integers.
*/

#include <stdio.h>

void find_duplicates(int *a, int n, int *b, int *size); //declaration

int main()
{
    int n, i;
    int length; 

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int a[n];
    printf("\nEnter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int b[n/2];
    find_duplicates(a, n, b, &length);

    printf("\nOutput: ");
    for (i = 0; i < length; i++)
        printf("%d ", b[i]);

    return 0;
}
 
void find_duplicates(int *a, int n, int *b, int *size) //definition 
{
    int *p, *q;
    for (p = a; p < a + n; p++)
        for (q = p + 1; q < a + n; q++) // p already starts at index a so q starts at the index right after p
            if (*p == *q) //checks for duplicate integers in array a 
            {
				*b = *p; // or *b = *q
                b++; // adds the duplicate to array b
                *size += 1; //increases the length of array b
            }
}