/*
 Name: lab11.load-binary.c
 Author: Jade Hudson
 Date: 25/11/2022

 Description: Program reads information on students from a binary file and prints it out.
 Returns: struct instance(s) with strings, ints and floats.
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student Student; 
struct Student
{
    int namelength;
    char name[50];
    int collegelength;
    char college[40];
    int age;
    float grade;
};


/* Function Prototypes */
/* Function Read_Student_Info takes in empty instance of structure Student and also takes in binary file. Function then fills in student instance with information binary file and prints it out. */
void Read_Student_Info(Student *pstudent, FILE *pfile);


/* Main function */
int main(int argc, char *argv[])
{

    /* VARIABLES */
    struct Student student;
    Student *pstudent = &student;

    // char buffer[100];
    FILE *pfile = NULL;
    char *filename = "studentBinary.bin";

    /* CODE */
    pfile = fopen(filename, "rb");
    if(!pfile)
    {
        printf("Failed to open %s.\n,", filename);
    }
    Read_Student_Info(pstudent, pfile);
    fclose(pfile);
    return 0;
}

/* FUNCTIONS */
void Read_Student_Info(Student *pstudent, FILE *pfile)
{
    fread(&pstudent->namelength, sizeof(int), 1, pfile);
    fread(pstudent->name, sizeof(char), pstudent->namelength, pfile);
    printf("Name: %s\n", pstudent->name);

    fread(&pstudent->collegelength, sizeof(int), 1, pfile);
    fread(pstudent->college, sizeof(char), pstudent->collegelength, pfile);
    printf("College: %s\n", pstudent->college);
    
    fread(&pstudent->age, sizeof(int), 1, pfile);
    printf("Age: %d\n", pstudent->age);

    fread(&pstudent->grade, sizeof(float), 1, pfile);
    printf("Grade: %.2f\n", pstudent->grade);
}
