#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
#define MIN 1

void printTimesTable(
    int min_number,
    int max_number);
void printTimesTableHex(
    int min_number,
    int max_number);
void options(
    int min_number,
    int max_number,
    int in_hex);
int isValidNumber(
    char argv[]);

int main(
    int argc,
    char *argv[])
{
    if (argc == 1)
    {
        printTimesTable(MIN, MAX);
    }
    // Checks are designed to print default table if arguments are wrong
    else if (argc > 1 && argc <= 4) //checks if there are enough arguments
    {                           // this block parses arguments between max and if -h is enabled
        int max_number = MAX;
        int min_number = MIN;
        int in_hex = 0;
        int valid_nums[2];
        int number_of_nums = 0;

        //for loop validates arguments
        for (int i = 0; i < argc; i++)
        {
            if (strcmp(argv[i], "-h") == 0)
            {
                in_hex = 1;
            }
            else
            {
                if (isValidNumber(argv[i]))
                {
                    valid_nums[number_of_nums++] = atoi(argv[i]);

                }
            }
        }
        if (number_of_nums == 1)    //Found 1 valid number in args
        {
            max_number = valid_nums[0];
            if (max_number == 0)
            {
                min_number = 0;
            }
        }
        else if (number_of_nums == 2)   //Found 2 valid numbers in args
        {
            if (valid_nums[0] < valid_nums[1])
            {
                min_number = valid_nums[0];
                max_number = valid_nums[1];
            }
        }
        options(min_number, max_number, in_hex);
    }
    else                        //Will catch if to many args are present
    {
        printf("\tWRONG AMOUNT OF ARGUMENTS\n");
        printTimesTable(MIN, MAX);
    }
    return 0;
}

int isValidNumber(
    char argv[])
//Function is used to determine if args are valid numbers
{
    int is_valid = 1;

    for (unsigned int i = 0; i < strlen(argv); i++)
    {
        if (argv[i] < '0' || argv[i] >= '9')
        {
            is_valid = 0;
            break;
        }
    }
    return is_valid;
}

void options(
    int min_number,
    int max_number,
    int in_hex)
{
    if ((max_number <= 32 && min_number >= 0 && max_number >= 0))
        //if checks that new_max is a number and between 0 and 32
    {
        if (in_hex == 0)
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
        printf("\tNUMBERS TOO LOW OR HIGH\n");
        printTimesTable(MIN, MAX);
    }
}

void printTimesTable(
    int min_number,
    int max_number)
{
    //Nested for loops to print times tables
    printf("USAGE = ./timestable [-h] [[<min>] <max>] Between 0 and 32.\n");
    printf("\t%s - %d to %d\n", "BASE 10 TABLE", min_number, max_number);
    printf("\t");
    for (int i = min_number; i <= max_number; i++)
    {
        printf("%8d", i);
    }
    printf("\n");
    for (int i = 0; i <= max_number - min_number + 1; i++)
    {
        if (i != 0)
        {
            printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550");
        }
        else
        {
            printf("%10s", "\u2554");
        }
    }
    printf("\n");
    for (int i = min_number; i <= max_number; i++)
    {
        printf("%7d\u2551", i);
        for (int j = min_number; j <= max_number; j++)
        {
            printf("%8d", i * j);
        }
        printf("\n");
    }
}

void printTimesTableHex(
    int min_number,
    int max_number)
{
    //Nested for loops to print times tables
    printf("\t%s - %d to %d\n", "HEX TABLE", min_number, max_number);
    printf("\t");
    for (int i = min_number; i <= max_number; i++)
    {
        printf("%8x", i);
    }
    printf("\n");
    for (int i = 0; i <= max_number - min_number + 1; i++)
    {
        if (i != 0)
        {
            printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550");
        }
        else
        {
            printf("%10s", "\u2554");
        }
    }
    printf("\n");
    for (int i = min_number; i <= max_number; i++)
    {
        printf("%7x\u2551", i);
        for (int j = min_number; j <= max_number; j++)
        {
            printf("%8x", i * j);
        }
        printf("\n");
    }
}
