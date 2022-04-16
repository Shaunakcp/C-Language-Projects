/*
Name: Shaunak Pandhare 
U63705561 
Description: Reads an input file containing a list of cars and creates an output file containing the top 10 cars with the highest city mpg 
*/

#include <stdio.h>
#include <stdlib.h>
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


int compare(const void *p, const void *q); //declaration of compare function 

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
    qsort(top, num, sizeof(struct car), compare); //qsort call
    int i;
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


int compare(const void *p, const void *q) //compares case elements from two strucutures 
{
    if (((struct car *) p)->city_mpg > ((struct car *) q)->city_mpg) //if *p is greater than *q 
        return -1; //return a negative and gets a descending order that has largest city mpg at top 
    else if (((struct car *) p)->city_mpg < ((struct car *) q)->city_mpg) 
        return 1;
    else 
        return 0; //returning 0 when city mpgs are the same 
}