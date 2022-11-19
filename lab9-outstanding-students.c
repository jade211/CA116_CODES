/*
 Name: lab9-outstanding-students.c
 Author: Jade Hudson
 Date: 13/11/2022

 Description: Program accepts information and prints all CSCE students who have a higher grade than the average grade of all students and prints them out.
 Returns: string and float
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student Student;

struct Student
{
    char name[20];
    char programme[20];
    float grade;

};

/* Function Prototypes */
/* Prints the CSCE student(s) who have a higher grade than the average grade of all students */
void print_OutstandingStudent(struct Student pStudent[], int *arg_count, float *average);

/* Main function */
int main(int argc, char *argv[])
{
    /* COMMAND LINE CODE */
    if (argc < 2)  /* ensures command line input is given */
    {
        printf("invalid\n");
        return 1;
    }

    /* VARIABLES */
    int arg_count = argc - 1;
    // Student student[arg_count];
    int capacity = 2;
    float average;

    Student *pStudent;
    pStudent = (Student*)calloc(capacity, sizeof(Student));
    if(!pStudent)
    {
        free(pStudent);
        pStudent = NULL;
        printf("Not enough memory!");
        exit(0);
    }


    /* MAIN CODE*/
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
        strcpy(pStudent[i].name, argv[i]);
        strcpy(pStudent[i].programme, argv[i + 1]);
        pStudent[i].grade = atof(argv[i + 2]);
        average = average + pStudent[i].grade;
        // printf("%s, %s, %.2f\n", pStudent->name, pStudent->programme, pStudent->grade);
    }

    print_OutstandingStudent(pStudent, &arg_count, &average);
    free(pStudent);
    pStudent = NULL;
    return 0;
}

/* FUNCTIONS */
void print_OutstandingStudent(struct Student pStudent[], int *arg_count, float *average)
{
    /* CODE */
    int info = (*arg_count / 3);
    *average = *average / info;
    for (int i = 1; i < *arg_count ; i++)
    {
        if (pStudent[i].grade > *average)
        {
            if(strcmp(pStudent[i].programme, "CSCE") == 0)
            {
                printf("%s, %.2f\n", pStudent[i].name, pStudent[i].grade);
            }
        }
    }
    printf("Average grade: %.2f\n", *average);
}
