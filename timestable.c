#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void printTimesTable(int max_number);

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printTimesTable(MAX);
	}
	if(argc == 2)
	{
		int new_max = atoi(argv[1]);
		if(new_max && new_max <= 32 && new_max >= 1)
		//if checks that new_max is a number and between 1 and 32
		{
			printTimesTable(new_max);
		}
		else //catches if letters or numbers out of range are entered
		{
			printf("Invalid selection\n");
		}
	}
	else
	{
		printf("Invalid selection\n");
	}
	return 0;
}

void printTimesTable(int max_number)
{
	//Nested for loops to print times tables
	for(int i = 1; i <= max_number; i++)
	{
		if(i == 1)
		{
			printf("\t");
		}
		printf("%8d", i);
	}
	printf("\n");
	for(int i = 0; i <= max_number; i++)
	{
		if(i != 0)
		{
			printf("%8s", "********");
		}
		else
		{
			printf("\t");
		}
	}
	printf("\n");
	for(int i = 1; i <= max_number; i++)
	{
		printf("%7d|", i);
		for(int j = 1; j <= max_number; j++)
		{
			printf("%8d", i * j);
		}
		printf("\n");
	}
}
