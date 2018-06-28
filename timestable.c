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
		{
			printTimesTable(new_max);
		}
		else
		{
			printf("Invalid selection\n");
		}
	}
	return 0;
}

void printTimesTable(int max_number)
{
	for(int i = 1; i <= max_number; i++)
	{
		if(i == 1)
		{
			printf("\t");
		}
		printf("%8d", i);
	}
	printf("\n");
	for(int i = 1; i <= max_number; i++)
	{
		printf("%8d", i);
		for(int j = 1; j <= max_number; j++)
		{
			printf("%8d", i * j);
		}
		printf("\n");
	}
}
