#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

void printTimesTable(int max_number);
void printTimesTableHex(int max_number);
void options(int max_number, int in_hex);

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printTimesTable(MAX);
	}
	// Checks are designed to print default table if arguments are wrong
	else if(argc > 1 && argc < 4) //checks if there are enough arguments
	{ // this block parses arguments between max and if -h is enabled
		int max_number = MAX;
		if(atoi(argv[1]) != 0)
		{
			max_number = atoi(argv[1]);
		}
		else if(argc > 2  && atoi(argv[2]) != 0 )
		{
			max_number = atoi(argv[2]);
		}
		int in_hex = 0;
		for(int i = 0; i < argc; i++)
		{
			if(strcmp(argv[i], "-h") == 0)
			{
				in_hex = 1;
			}
		}
		//options will wall the print functions
		options(max_number, in_hex);
	}
	else //catches if letters or numbers out of range are entered
	{
		printTimesTable(MAX);
	}
	return 0;
}

void options(int max_number, int in_hex)
{
	if((max_number && max_number <= 32 && max_number >= 1) || (in_hex == 1))
	//if checks that new_max is a number and between 1 and 32
	{
		if(in_hex == 0)
		{
			printTimesTable(max_number);
		}
		else
		{
			printTimesTableHex(max_number);
		}
	}
	else
	{
		printTimesTable(MAX);
	}
}

void printTimesTable(int max_number)
{
	//Nested for loops to print times tables
	printf("\t%s - Up to %d\n", "DEFAULT TABLE", max_number);
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

void printTimesTableHex(int max_number)
{
	//Nested for loops to print times tables
	printf("\t%s - Up to %d\n", "HEX TABLE", max_number);
	for(int i = 1; i <= max_number; i++)
	{
		if(i == 1)
		{
			printf("\t");
		}
		printf("%8x", i);
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
		printf("%7x|", i);
		for(int j = 1; j <= max_number; j++)
		{
			printf("%8x", i * j);
		}
		printf("\n");
	}
}
