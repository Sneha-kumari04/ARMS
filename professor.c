#include <stdio.h>
#include <string.h>
#include "structures.h"

void professor_dashboard(void)
{
    int selected_option;
    while (1)
    {
        printline();
        printf("PROFESSOR DASHBOARD\n 1. View My Profile\n 2. View My Subjects & Semester\n 3. View My Student\n  5. View Student Analytics\n 0. Logout\n");
        printline();
        printf("Enter Index: ");
        scanf("%d", &selected_option);
        printline();
        while (getchar() != '\n')
            ;
        switch (selected_option)
        {
        case 1:
            view_professor_profile();
            break;
        case 2:
            view_my_subjects_and_semester();
            break;
        case 3:
            view_my_student();
            break;
        case 4 : view_student_analytics(); 
        break;
        case 0:
            if (logout_to_main_menu())
                return; // back to login
            break;
        default:
            printf("Invalid option\n");
        }
    }
}
void view_professor_profile(void)
{
    char professor_id[50];
    char id[50];
    char name[100];
    char subject[50];
    char designation[100];
    int found = 0;
    FILE *fp = fopen("data/professor.txt", "r");
    if (fp == NULL)
    {
        printf("Error: file not found\n");
        printline();
        return;
    }
    printf("Enter Professor ID: ");
    scanf("%49s", professor_id);
    printline();
    while (getchar() != '\n')
        ;

    while (fscanf(fp, "%49s %99s %49s %99s", id, name, subject, designation) == 4)
    {
        if (strcmp(id, professor_id) == 0)
        {
            printf("Name         = %s\n", name);
            printf("Professor ID = %s\n", id);
            // printf("Subject     = %s\n", branch);
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
    return;
}
void view_my_subjects_and_semester(void)
{
    char professor_id[100];
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
    printf("Enter Professor ID: ");
    scanf("%99s", professor_id);
    printline();

    while (fscanf(fp, "%49s %49s %99s %d %99s", id, subject, subject_code, &sem, department) == 5)
    {
        if (strcmp(id, professor_id) == 0)
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
}
void view_student_analytics(void)
{
    long long int registration_number, r;
    char name[100];
    char branch[50];
    char sem[50];
    printf("Enter Registration Number: ");
    scanf("%lld", &registration_number);
    printline();
    int found = 0;
    FILE *fp;
    fp = fopen("data/student.txt", "r");
    if (fp == NULL)
    {
        printf("File not found!!\n");
        printline();
        return;
    }
    while (fscanf(fp, "%lld %99s %49s %49s ", &r, name, branch, sem) != EOF)
    {
        if (r == registration_number)
        {
            printf("Name = %s\n", name);
            printf("Registration number = %lld\n", r);
            printf("semester = %s\n", sem);
            printf("Branch = %s\n", branch);
            found = 1;
            printline();
            break;
        }
    }
    if (!found)
    {
        printf("Not found!!\n");
        printline();
    }
    fclose(fp);
    return;
} 
void View_student_analytics(void)
{
    // define data types
    long long int registration_number, r;
    char name[100];
    char branch[50];
    char sem[50];
    float sgpa;
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
    while(fscanf(fp, "lld %99s %49s %49s %f", &r, name, branch, sem, sgpa) == 5)
    {
        total_students++; //counting total students
        sgpa_sum += sgpa; // sum of sgpa
    }
    if(total_students > 0)
    {
        average_sgpa = sgpa_sum / total_students; // average of sgpa
    }
    printline();
    printf("Total Students : %d\n", total_students);
    printf("Average SGPA   : %.2f\n", average_sgpa);
    printline();

    // closing file
    fclose(fp);

    // logout to professor dashboard
    logout_to_dashboard();    

}

