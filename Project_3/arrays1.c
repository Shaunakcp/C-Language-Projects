/*
Name: Shaunak Pandhare
U63705561
Description: Takes an input array length and elements and finds range of the inputs and the outputs the integers that don't appear in the input array
*/


#include <stdio.h>

void find(int a[],int n, int b[]);

int main(){
    int n; //length of the array
    int i;
    printf("Enter the length of the input array: \n");
    scanf("%d", &n);
    
    int a[n];
    int b[n];

    printf("Enter the elements of the input array: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    find(a, n, b);
    printf("Output: ");
    for (i = 0; i < n; i++) //prints values not in array a
    {
        if (b[i] == 0)
            printf("%d ", i + 1);
        
    }
    
    return 0; 
}

void find(int a[],int n, int b[]) // make array b 0s and 1s 
{
    int i;
    
    for (i = 0; i < n; i++){
        b[i] = 0; // initializes array b to 0
    }        
                
    for (i = 0; i < n; i++){
        b[a[i] - 1] = 1; 
    }
    
}