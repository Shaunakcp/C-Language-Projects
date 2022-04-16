/*
Name: Shaunak Pandhare 
U63705561 
Description: Calculates the indices of the two numbers in an array such that they add up to key. 
*/

#include <stdio.h>

void find_indices(int a[], int n, int key, int * index1, int *index2); //declaration of function

int main()
{
    int n, i; 
    

    printf("\nEnter the length of the array: ");
    scanf("%d", &n);

    int a[n];

    printf("\nEnter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int key;
    int index1, index2; 

    printf("\nEnter the key value: ");
    scanf("%d", &key);

    find_indices(a, n, key, &index1, &index2); //calling the function

    return 0;
}

void find_indices(int a[], int n, int key, int * index1, int *index2) //definition of function 
{
    int i, j; 

    for (i = 0; i < n; i++){
        for (j = i+1; j < n; j++) //i already starts at index 0 so j starts at the index right after index 0
            if (a[i] + a[j] == key){
                *index1 = i; //index1 points to index i
                *index2 = j; //index2 points to index j
            }
    } 
        printf("Output: %d %d\n", *index1, *index2); //prints the indices of the two numbers that add up to the key 
}