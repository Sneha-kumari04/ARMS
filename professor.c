#include <stdio.h>
#include <string.h>
#include "structures.h"

void professor_dashboard(void)
{
    greet_professor();
    int selected_option;
    while (1)
    {
        printline();
        printf("PROFESSOR DASHBOARD\n 1. View My Profile\n 2. View My Subjects & Semester\n 3. Search Student\n 4. View My All Students\n 5. View Student Analytics\n 0. Logout\n");
        printline();
        printf("Enter Index: ");
        scanf("%d", &selected_option);
        printline();
        // while (1);
        switch (selected_option)
        {
        case 1:
            view_professor_profile();
            break;
        case 2:
            view_my_subjects_and_semester();
            break;
        case 3:
            search_student();
            break;
        case 4: 
            view_all_students();
            break;
        case 5: view_student_analytics();break;
        case 0:
            if (logout_to_main_menu())
                return; // back to login
            break;
        default:
            printf("Invalid option\n");
        }
    }
}


void greet_professor(){
    char id[50];
    char name[100];
    char designation[100];
    int found = 0;
    FILE *fp = fopen("data/professor.txt", "r");
    if (fp == NULL)
    {
        printf("Error: file not found\n");
        printline();
        return;
    }
    // while (getchar() != '\n');

    while (fscanf(fp, "%49s %99s %99s", id, name, designation) == 3)
    {
        if (strcmp(id,input_professor_id) == 0)
        {
            printf("Hello %s\n", name);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("\nProfessor not found\n");
        printline();
    }
    fclose(fp);
    return;
}


void view_professor_profile(void)
{
    char id[50];
    char name[100];
    char designation[100];
    int found = 0;
    FILE *fp = fopen("data/professor.txt", "r");
    if (fp == NULL)
    {
        printf("Error: file not found\n");
        printline();
        return;
    }
    // while (getchar() != '\n');

    while (fscanf(fp, "%49s %99s %99s", id, name, designation) == 3)
    {
        if (strcmp(id,input_professor_id) == 0)
        {
            printf("Name         = %s\n", name);
            printf("Professor ID = %s\n", id);
            printf("Designation  = %s\n", designation);
            found = 1;
            printline();
            break;
        }
    }
    if (!found)
    {
        printf("\nProfessor not found\n");
        printline();
    }
    fclose(fp);
    logout_to_dashboard();
}


void view_my_subjects_and_semester(void)
{
    char id[50];
    char subject[50];
    char subject_code[100];
    int sem;
    char department[100];
    int found = 0;
    FILE *fp = fopen("data/professor_subjects.txt", "r");
    if (fp == NULL)
    {
        printf("Error: file not found\n");
        printline();
        return;
    }
    

    while (fscanf(fp, "%49s %49s %99s %d %99s", id, subject, subject_code, &sem, department) == 5)
    {
        if (strcmp(id, input_professor_id) == 0)
        {
            printf("Subject Name = %s\n", subject);
            printf("Subject Code = %s\n", subject_code);
            printf("Sem          = %d\n", sem);
            printf("Department   = %s\n", department);
            found = 1;
            printline();
            break;
        }
    }
    if (!found)
    {
        printf("\n Data not found\n");
        printline();
    }
    fclose(fp);
    logout_to_dashboard();
}


void view_student_analytics(void)
{
    // define data types
    long long int r;
    char name[100];
    char branch[50];
    char sem[50];
    char attendance[50];
    float sgpa, cgpa;
    int total_students = 0;
    float sgpa_sum = 0.0;
    float average_sgpa = 0.0;

    FILE *fp;
    fp = fopen("data/student.txt", "r"); // file open

    if (fp == NULL)
    {
        printf("File not found!!\n");
        printline();
        return;
    }
    while(fscanf(fp, "%lld %99s %49s %49s %49s %f %f", &r, name, branch, sem, attendance, &sgpa, &cgpa) == 7)
    {
        total_students++; //counting total students
        sgpa_sum += sgpa; // sum of sgpa
    }

    if(total_students > 0)
    {
        average_sgpa = sgpa_sum / total_students; // average of sgpa
    }
    printf("Total Students : %d\n", total_students);
    printf("Average SGPA   : %.2f\n", average_sgpa);
    printline();

    // closing file
    fclose(fp);

    // logout to professor dashboard
    logout_to_dashboard();    

}

