/*
 Name: lab7.sort-countries.c
 Author: Jade Hudson
 Date: 28/10/2022

 Description: Program takes in info about multiple countries and returns them sorted in descending order based on population.
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Country Country; 
struct Country
{
    char name[30];
    char capital[30];
    float population;
    int size;
};


/* Function Prototypes */
/* Function Size_Countries returns countries in descending order based on population. */
void Sort_Population(struct Country * country, int n);

/* Main function */
int main(int argc, char *argv[])
{

    /* COMMAND LINE CODE */
    if (argc == 1)  /* ensures command line input is given */
    {
        printf("invalid\n");
        return 1;
    }

    /* VARIABLES */
    int arg_count = argc - 1;
    int n = arg_count / 4;
    int count = 0;
    struct Country country[n];

    /*CODE*/
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    for(unsigned int i = 1; i < arg_count; i+=4)
    {
        strcpy(country[count].name, argv[i]);
        strcpy(country[count].capital, argv[i + 1]);
        country[count].population = atof(argv[i + 2]);
        country[count].size = atoi(argv[i + 3]);
        count ++;
    }

    Sort_Population(country, n);

    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country[i].name, country[i].capital, country[i].size, country[i].population);
    }

    return (0);
}

/* FUNCTIONS*/
void Sort_Population(Country country[], int n)
{
    struct Country temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(country[i].population < country[j].population)
            {
                temp = country[i];
                country[i] = country[j];
                country[j] = temp;
            }
        }
    }
}
