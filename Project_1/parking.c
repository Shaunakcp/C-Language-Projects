/*
 * Name: Shaunak Pandhare 
 * U63705561
 * Description: This program calculates and prtintsthe total charge for parking at a parking garage
 */



#include <stdio.h>
#include <math.h>

int main()
{
	int hours, minutes, total_min, total_amount, days_amt, hours_remain;

	printf("Enter hours parked: ");
	scanf("%d", &hours);
	
	printf("Enter minutes parked: ");
	scanf("%d", &minutes);

	total_min = (hours * 60) + minutes;
	
	while (hours < 0 || minutes < 0 || minutes > 60)
	{	
		printf("Hours cannot be negative.\n");
		printf("Minutes have to be in range 0 - 60.\n"); 
		break;
	}

	if (total_min <= 30)
	{
		total_amount = 0;
		printf("Amount due ($): %d\n", total_amount);
	}

	if (total_min > 30 && total_min < 270)
	{	
		total_amount = ceil((double)(total_min - 30)/20);
		printf("Amount due ($): %d\n", total_amount);
	}

	if (hours <= 24 && total_min > 270) 
	{
		total_amount = 12; 
		printf("Amount due ($): %d\n", total_amount);
	}
	
	else if (hours > 24 && total_min > 270)
	{
		days_amt = ((hours/24) * 12);
		hours_remain = (hours % 24) * 60 + minutes;
		if (hours_remain > 270)
		{	
			total_amount = 12 + days_amt;
			printf("Amount due ($): %d\n", total_amount);
		}
		else if (hours_remain < 270)
		{	
			total_amount = ceil((double)(hours_remain - 30)/20) + days_amt;
			printf("Amount due ($): %d\n", total_amount);			
		}
	}

	return 0;
} 

