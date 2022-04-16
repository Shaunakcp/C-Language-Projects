/*
 * Name: Shaunak Pandhare
 * U63705561
 * Description: Calculates the total price of selected items that is evenly divided amoung 10 people
 */





#include <stdio.h> 

int main()
{
	int selection, energy, candy, chips, pretzels, popcorn, drinks;
	double price1, price2, price3, price4, price5, price6, cost_per_person, total_cost;  
	printf("Please select from the list: \n 1. Energy bars - $3.99 / box,\n 2. Candy bars - $2.39/ box,\n 3. Chips - $4.79 / bag, \n 4. Pretzels - $2.99 / bag, \n 5. Popcorns - $3.50 / bag, \n 6. Energy drinks - $4.99 / half dozen \n");
	
	printf("\nEnter selection: \n");
	scanf("%d", &selection); 
	
	total_cost = 0;

	while(selection >= 1 && selection <= 6){
		switch (selection)	
		{
			case 1: 
				printf("\nEnter number of boxes: \n");
				scanf("%d", &energy);
				price1 = 3.99 * energy;
				total_cost += price1;
				break;	
			case 2: 
				printf("\nEnter number of boxes: \n");
				scanf("%d", &candy);
				price2 = 2.39 * candy;
				total_cost += price2;
				break;
			case 3: 
				printf("\nEnter number of bags: \n");
				scanf("%d", &chips);
				price3 = 4.79 * chips;
				total_cost += price3;
				break;
			case 4: 
				printf("\nEnter number of bags: \n");
				scanf("%d", &pretzels);
				price4 = 2.99 * pretzels;
				total_cost += price4;
				break;
			case 5: 
				printf("\nEnter number of bags: \n");
				scanf("%d", &popcorn);
				price5 = 3.50 * popcorn;
				total_cost += price5;
				break;
			case 6:
				printf("\nEnter number of drinks as multiples of six (6, 12, 18...): \n");
				scanf("%d", &drinks);
				price6 = (4.99 * drinks)/6;
				total_cost += price6;
				break;
			default:
				printf("Enter selection: \n");
				scanf("%d", &selection);
				break;
		}
		printf("\nEnter another selection: \n ");
		scanf("%d", &selection);
		
		if(selection == 0)
		{
			break;
		}	
	}

	cost_per_person = total_cost / 10;
	printf("\nCost per person ($): %.2f\n", cost_per_person);

	return 0;

}
