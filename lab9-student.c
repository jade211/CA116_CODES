/*
 Name: lab7.find-student.c
 Author: Jade Hudson
 Date: 28/10/2022

 Description: Program takes in info about 2 students and prints out the info while also allocating memory to accomodate the info.
 Returns: tabular strings.
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Student Student; 
struct Student
{
    char name[30];
    char programme[30];
    float grade;
};


/* Function Prototypes */
/* None */


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
    int capacity = 2;
    Student *pStudent;
    pStudent = (Student*)calloc(capacity, sizeof(Student));
    if(!pStudent)
    {
        free(pStudent);
        pStudent = NULL;
        printf("Not enough memory!");
        exit(0);
    }


    /*CODE*/
    if((arg_count / 3) == capacity)
    {
        Student *pTempStudent;
        capacity += 10;
        pTempStudent = (Student*)realloc(pStudent, capacity*sizeof(Student));
        if(!pTempStudent)
        {
            free(pTempStudent);
            pTempStudent = NULL;
            printf("Not enough memory!");
            exit(0);
        }
        pStudent = pTempStudent;
    }


    for(unsigned int i = 1; i < arg_count; i+=3)
    {
        strcpy(pStudent->name, argv[i]);
        strcpy(pStudent->programme, argv[i + 1]);
        pStudent->grade = atof(argv[i + 2]);
        printf("%s, %s, %.2f\n", pStudent->name, pStudent->programme, pStudent->grade);
    }


    free(pStudent);
    pStudent = NULL;
    return (0);

}
