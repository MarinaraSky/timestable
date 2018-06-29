#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
#define MIN 1

void printTimesTable(int min_number, int max_number);
void printTimesTableHex(int min_number, int max_number);
void options(int min_number, int max_number, int in_hex);

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printTimesTable(MIN, MAX);
	}
	// Checks are designed to print default table if arguments are wrong
	else if(argc > 1 && argc <= 4) //checks if there are enough arguments
	{ // this block parses arguments between max and if -h is enabled
		int max_number = MAX;
		int min_number = MIN;
		int in_hex = 0;
		if(argc == 2 && atoi(argv[1]) != 0)
		{
			max_number = atoi(argv[1]);
		}
		else if((argc == 4) && (atoi(argv[1]) < atoi(argv[2])))
		{
			min_number = atoi(argv[1]);
			max_number = atoi(argv[2]);
		}
		else if((argc == 4) && (atoi(argv[2]) < atoi(argv[3])))
		{
			printf("test");
			min_number = atoi(argv[2]);
			max_number = atoi(argv[3]);
		}
		else if(argc == 3  && (atoi(argv[2]) != 0 && in_hex == 1))
		{
			max_number = atoi(argv[2]);
		}
		for(int i = 0; i < argc; i++)
		{
			if(strcmp(argv[i], "-h") == 0)
			{
				in_hex = 1;
			}
		}
		//options will call the print functions
		options(min_number, max_number, in_hex);
	}
	else //catches if letters or numbers out of range are entered
	{
		printTimesTable(MIN, MAX);
	}
	return 0;
}

void options(int min_number, int max_number, int in_hex)
{
	if((max_number && max_number <= 32 && max_number >= 1) || (in_hex == 1))
	//if checks that new_max is a number and between 1 and 32
	{
		if(in_hex == 0)
		{
			printTimesTable(min_number, max_number);
		}
		else
		{
			printTimesTableHex(min_number, max_number);
		}
	}
	else
	{
		printTimesTable(MIN, MAX);
	}
}

void printTimesTable(int min_number, int max_number)
{
	//Nested for loops to print times tables
	printf("\t%s - %d to %d\n", "DEFAULT TABLE",min_number,  max_number);
	printf("\t");
	for(int i = min_number; i <= max_number; i++)
	{
		printf("%8d", i);
	}
	printf("\n");
	for(int i = 0; i <= max_number - min_number + 1; i++)
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
	for(int i = min_number; i <= max_number; i++)
	{
		printf("%7d|", i);
		for(int j = min_number; j <= max_number; j++)
		{
			printf("%8d", i * j);
		}
		printf("\n");
	}
}

void printTimesTableHex(int min_number, int max_number)
{
	//Nested for loops to print times tables
	printf("\t%s - %d to %d\n", "HEX TABLE",min_number, max_number);
	printf("\t");
	for(int i = min_number; i <= max_number; i++)
	{
		printf("%8x", i);
	}
	printf("\n");
	for(int i = 0; i <= max_number - min_number + 1; i++)
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
	for(int i = min_number; i <= max_number; i++)
	{
		printf("%7x|", i);
		for(int j = min_number; j <= max_number; j++)
		{
			printf("%8x", i * j);
		}
		printf("\n");
	}
}
