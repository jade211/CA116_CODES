/*
 Name: lab6.get-a-country.c
 Author: Jade Hudson
 Date: 21/10/2022

 Description: Program takes in info about multiple countries and returns all of their info in a tabular form.
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
/* Function Add_Countries adds the countries and their info to the struct. Function print prints out info */
// void Add_Countries(struct Country country, int arg_count, char *arg_list);

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
    struct Country country;

    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");



    for(unsigned int i = 1; i < arg_count; i+=4)
    {
        strcpy(country.name, argv[i]);
        strcpy(country.capital, argv[i + 1]);
        country.population = atof(argv[i + 2]);
        country.size = atoi(argv[i + 3]);
    	printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country.name, country.capital, country.size, country.population);
    }



    // for(unsigned int i = 0; i < arg_count; i+=4)
    // {
    //     char name;
    //     char capital;

    //     strcpy(name, argv[i + 1]);
    //     arg_list[i] = name;
    //     printf("%c\n", arg_list[i]);

    //     strcpy(capital, argv[i + 2]);
    //     arg_list[i + 1] = capital;
    //     printf("%c\n", arg_list[i + 1]);


    //     arg_list[i + 2] = atof(argv[i + 3]);
    //     printf("%d\n", arg_list[i + 2]);

    //     arg_list[i + 3] = atoi(argv[i + 4]);
    //     printf("%d\n", arg_list[i + 3]);
    // }
    
    
    // printf("%c\n", arg_list[3]);





return (0);
}
