/*
Name: Shaunak Pandhare 
U63705561 
Description: Reads an input file containing a list of cars and creates an output file containing the top 10 cars with the highest city mpg 
*/

#include <stdio.h>
#define MAX_CARS 6000 //Assume that there are no more than 6000 cars in the file.
#define MAX 150 //Assume that each field is no more than 150 characters 

struct car { //declaring structure car and components of car 
    char identification[MAX + 1]; 
    char classification[MAX + 1];
    char engine[MAX + 1];
    char transmission[MAX + 1];
    int city_mpg;
    char fuel[MAX + 1];
    int hw_mpg; //highway mpg 
} top[MAX_CARS]; //top[] is an array of the strcuture 

void sort_city_mpg(struct car list[], int n); //declaration


int main()
{
    char filename[MAX + 1];
    char name[MAX + 1] = "TOP10_city_mpg.csv"; //initializes 
    int num = 0; //initializes num to 0 for index 
    

    printf("Enter the input file name: ");
    scanf("%s", filename);

    FILE *rFile = fopen(filename, "r"); //opens the input file for reading
    FILE *wFile = fopen(name, "w"); //opens the output file for writing 

    //invalidation check
    if (rFile == NULL)
    {
        printf("\nError opening file\n");
        return 1; //abnormal termination
    }

    while(!feof(rFile) && !ferror(rFile)) //while it hasn't reached the end of the file and there is no error in the file  
    {
        fscanf(rFile, "%[^,], %[^,], %[^,], %[^,], %d, %[^,], %d\n", top[num].identification, top[num].classification, top[num].engine,
                top[num].transmission, &top[num].city_mpg, top[num].fuel, &top[num].hw_mpg); //reads the data from the cars.csv file 
        num += 1; //increases the index by 1 
    }

    int i;
    sort_city_mpg(top, num); //calling the sort function in main 
    for(i = 0; i < 10; i++) // for loop to print the file items; i < 10 so that it prints the top 10 city mpgs 
    {
        fprintf(wFile, "%s %s %s %s %d %s %d\n", top[i].identification, top[i].classification, top[i].engine,
                top[i].transmission, top[i].city_mpg, top[i].fuel, top[i].hw_mpg); //prints the sorted list in the output file 
    }

    //close the input and output files  
    fclose(rFile); 
    fclose(wFile);
    return 0;

}


void sort_city_mpg(struct car list[], int n) //sorts the cars from highest city mpg to lowest city mpg 
{
    int i; //declare i as an int to be used in the for loop 
    int lowest = 0; //index of the lowest city mpg
    struct car temp; //establish temp as a struct so that i can save the structures 

    if (n == 1) //function does nothing and finishes 
        return;
    
    //had to use "<" because the function would print the file from lowest to highest city mpg 
    for (i = 1; i < n; i++)
        if(list[i].city_mpg < list[lowest].city_mpg) //using componnet city_mpg for comparison 
            lowest = i; //lowest index changes to i index 

    if(lowest < n - 1) //checking if index of lowest is not last 
    {
        temp = list[lowest]; //saves the full structure in temp 
        list[lowest] = list[n - 1]; //places the last structure in list to the index of the current lowest 
        list[n - 1] = temp; //lowest city_mpg is placed at the end of the list 
    }
    sort_city_mpg(list, n - 1); //recursion 
}