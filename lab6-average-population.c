/*
 Name: lab6-average-population.c
 Author: Jade Hudson
 Date: 21/10/2022

 Description: Program takes in info about multiple countries and returns all of their info in a tabular form as well as the average of the populations overall.
 Returns: strings
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
/* Function Population_Average returns complete num of populations*/
float Population_Average(struct Country country, int average);

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
    char arg_list[arg_count];
    float average = 0;
    struct Country country;

    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");



    for(unsigned int i = 1; i < arg_count; i+=4)
    {
        strcpy(country.name, argv[i]);
        strcpy(country.capital, argv[i + 1]);
        country.population = atof(argv[i + 2]);
        average = average + country.population;
        country.size = atoi(argv[i + 3]);
    	printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country.name, country.capital, country.size, country.population);
    }

    printf("Population average: %.2f\n", average / (arg_count / 4));

return (0);
}


float Population_Average(struct Country country, int average)
{
    return (average + country.population);
}
