#include <stdio.h>

#define MAX 10

int main(int argc, char *argv[])
{
	int header[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	if(argc == 1)
	{
		for(int i = 0; i < MAX; i++)
		{
			if(i == 0)
			{
				printf("\t");
			}
			printf("%8d", header[i]);
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

	}
	return 0;
}
