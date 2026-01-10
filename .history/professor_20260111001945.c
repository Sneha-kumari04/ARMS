#include <stdio.h>
#include <string.h>
#include "structures.h"

void professor_dashboard(void)
{
    int selected_option;
    while (1)
    {
        printline();
        printf("PROFESSOR DASHBOARD\n 1. View My Profile\n 2. View My Subjects & Semester\n 3. View My Student\n 4. Update Student Attendance\n 5.Update Student SGPA\n 6.View Student Analytics\n 7. Logout\n ");
        printline();
        printf("Enter Index: ");
        scanf("%d", &selected_option);
        while (getchar() != '\n')
            ;

        switch (selected_option)
        {
        case 1:
            view_professor_profile();
            break;
        case 2:
            View_my_subjects_and_semester();
            break;
        case 3: view_my_student(); break;
            //   case 4: update_student_attendance(); break;
            //   case 5: update_student_SGPA(); break;
            //   case 6: view_student_analytics(); break;
        case 7:
            printf("Logging out...\n");
            return;
        default:
            printf("Invalid option\n");
        }
    }
}
void view_professor_profile(void)
{
    long long int registration_number, r;
    char name[100];
    char branch[50];
    char sem[50];
    int found = 0;
    FILE *fp = fopen("student.txt", "r");
    if (fp == NULL)
    {
        printf("Error: file not found\n");
        return;
    }
    printf("Enter Student Registration Number: ");
    scanf("%lld", &registration_number);
    while (getchar() != '\n');

    while (fscanf(fp, "%lld %99s %49s %49s %49s %f %f", &r, name, branch, sem, percentage, &sgpa, &cgpa) != EOF)
    {
        if (r == registration_number)
        {
            printf("Name = %s\n", name);
            printf("Registration number = %lld\n", r);
            printf("SGPA = %.2f\n", sgpa);
            printf("CGPA = %.2f\n", cgpa);
            printf("Percentage = %s\n", percentage);
            printf("semester = %s\n", sem);
            printf("Branch = %s\n", branch);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("\nProfessor not found\n");
    }
    fclose(fp);
    return;
}
void View_my_subjects_and_semester(void)
{
    char professor_id[100];
    char id[50];
    char subject[100];
    char subject_code[100];
    int sem;
    char department[100];
    int found = 0;
    FILE *fp = fopen("professor_subjects.txt", "r");
    if (fp == NULL)
    {
        printf("Error: file not found\n");
        return;
    }
    printf("Enter Professor ID: ");
    scanf("%99s", professor_id);

    while (fscanf(fp, "%49s %99S %99s %d %99s", id, subject, subject_code, &sem, department) == 5)
    {
        if (strcmp(id, professor_id) == 0)
        {
            printf("Subject Name = %s\n", subject);
            printf("Subject Code = %s\n", subject_code);
            printf("Sem          = %d\n", sem);
            printf("Department   = %s\n", department);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("\n Data not found\n");
    }
    fclose(fp);
}
void view_my_student(void)
{
    char professor_id[100];
    char id[50];
    char subject[100];
    char subject_code[100];
    int sem;
    char department[100];
    int found = 0;
    FILE *fp = fopen("professor_subjects.txt", "r");
    if (fp == NULL)
    {
        printf("Error: file not found\n");
        return;
    }
    printf("Enter Professor ID: ");
    scanf("%99s", professor_id);

    while (fscanf(fp, "%49s %99S %99s %d %99s", id, subject, subject_code, &sem, department) == 5)
    {
        if (strcmp(id, professor_id) == 0)
        {
            printf("Subject Name = %s\n", subject);
            printf("Subject Code = %s\n", subject_code);
            printf("Sem          = %d\n", sem);
            printf("Department   = %s\n", department);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("\n Data not found\n");
    }
    fclose(fp);
    return;
}
