#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		for(int i = 1; i <= MAX; i++)
		{
			if(i == 1)
			{
				printf("\t");
			}
			printf("%8d", i);
		}
		printf("\n");
		for(int i = 1; i <= MAX; i++)
		{
			printf("%8d", i);
			for(int j = 1; j <= MAX; j++)
			{
				printf("%8d", i * j);
			}
			printf("\n");
		}

	}
	if(argc == 2)
	{
		int new_max = atoi(argv[1]);
		if(new_max && new_max <= 32 && new_max >= 1)
		{
			int new_max = atoi(argv[1]);
			for(int i = 1; i <= new_max; i++)
			{
				if(i == 1)
				{
					printf("\t");
				}
				printf("%8d", i);
			}
			printf("\n");
			for(int i = 1; i <= new_max; i++)
			{
				printf("%8d", i);
				for(int j = 1; j <= new_max; j++)
				{
					printf("%8d", i * j);	
				}
				printf("\n");
			}
		}
		else
		{
			printf("Invalid selection\n");
		}
	}
	return 0;
}
