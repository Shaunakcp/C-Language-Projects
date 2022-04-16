/*
Name: Shaunak Pandhare 
U63705561 
Description: Checks if two arrays of the same length match after some number of shifts on the first array.
*/

#include <stdio.h>

void shift(int a[], int n);
int main(){
    int i;
    int n;
    int num_shifts = 0; // number of shifts
    int is_valid = 0; // acts like a boolean operator 
    
    printf("Enter the length of the input array: \n");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the first array: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int b[n];
    printf("Enter the elements of the second array: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    shift(a, n); // calls the shift function 
    printf("Output: ");
    
    for (i = 0; i < n; i++){ 
        if (a[i] != b[i]) // if the two arrays don't have the same elements 
            is_valid = 1; // is_valid != 0 so it's false 
        while ((is_valid != 0)){ 
            shift(a, n); // call the shift function 
            num_shifts++; // increments the number of shifts array a needs 
            is_valid = 0; // is_valid goes back to 0

            for (i = 0; i < n; i++){ 
                if (a[i] != b[i]) // checks if the two arrays don't have the same elements 
                    is_valid++; // is_valid != 0 so it's false
            }

            if ((num_shifts == n) && (is_valid != 0)) // number of shifts has to be equal to n - 1, not n
                break;
            if ((is_valid != 0) || (num_shifts != n)) // keeps shifting until array a can equal array b after some number of shifts 
                continue;
            else
                break;
        }
    }
    if (is_valid == 0) //if is_valid == 0 then, then array a can be shifted a certain number of times 
        printf("True\n");
    else
        printf("False\n");
    
    return 0;
}
void shift(int a[], int n){
    int i;
    int temp;
 
    for (i = 0; i < n; i++){    
        temp = a[0];  //preserves the element of a[0]
        for(i = 0; i < n; i++)  
            a[i] = a[i + 1]; //shifts elements by one position to the left
  
        a[n - 1] = temp;    
        
    }
}
