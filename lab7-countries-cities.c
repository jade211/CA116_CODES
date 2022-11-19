/*
 Name: lab7.countries-cities.c
 Author: Jade Hudson
 Date: 28/10/2022

 Description: Program takes in info about multiple countries and their cities and returns the largest city of each.
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Country country; 
typedef struct City city;

struct City
{
    char name[30];
    float size;
};

struct Country
{
    char name[30];
    city list_of_cities[3];
};


/* Function Prototypes */
/* Function Sort_Size returns countries and their largest city in descending order.*/
void Sort_Size(struct Country * country, int n);

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
    int n = arg_count / 7;
    int count = 0;
    int j = 0;
    struct Country country[n];
    struct City city[n];


    /*CODE*/
    for(unsigned int i = 1; i < arg_count; i+=7)
    {
        strcpy(country[count].name, argv[i]);
        strcpy(country[count].list_of_cities[j].name, argv[i + 1]);
        country[count].list_of_cities[j].size = atof(argv[i + 2]);
        strcpy(country[count].list_of_cities[j + 1].name, argv[i + 3]);
        country[count].list_of_cities[j + 1].size = atof(argv[i + 4]);
        strcpy(country[count].list_of_cities[j + 2].name, argv[i + 5]);
        country[count].list_of_cities[j + 2].size = atof(argv[i + 6]);
        j = 0;
        count ++;
    }

    Sort_Size(&*country, n);

    for (int i = 0; i < n; i++)
    {
        printf("%s: %s\n", country[i].name, country[i].list_of_cities[0].name);
    }

    return (0);
}

/* FUNCTIONS*/
void Sort_Size(struct Country * country, int n)
{
    char temp[30];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < 3; k++)
            {
                if(country[i].list_of_cities[j].size < country[i].list_of_cities[k].size)
                {
                    strcpy(temp, country[i].list_of_cities[j].name);
                    strcpy(country[i].list_of_cities[j].name, country[i].list_of_cities[k].name);
                    strcpy(country[i].list_of_cities[k].name, temp);
                }
            }
        }
    }
}

