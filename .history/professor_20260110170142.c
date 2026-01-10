#include <stdio.h>
#include <string.h>
#include "structures.h"

void professor_dashboard(void)
{
    int selected_option;
   while (1)
    {
        printline();
        printf("PROFESSOR DASHBOARD\n");
        printf("1. View My Profile\n");
        printf("2. View My Subjects & Semester\n");
        printf("3. View My Student\n");
        printf("4. Update Student Attendance\n");
        printf("5. Update Student SGPA\n");
        printf("6. View Student Analytics\n");
        printf("7. Logout\n");
        printline();

        printf("Enter Index: ");
        scanf("%d", &selected_option);
        while (getchar() != '\n');
    switch (selected_option)
    {
          case 1:view_professor_profile();break;
          //case 2: View_my_subjects_and_semester(); break;
          //case 3: view_my_student(); break;
          //case 4: update_student_attendance(); break;
          //case 5: update_student_SGPA(); break;
          //case 6: view_student_analytics(); break;
          case 7: printf("Logging out...\n");
          return;
          default:printf("Invalid option\n");
    }  
}
void view_professor_profile(void)
{
    char professor_id[50];
    char id[50]; 
    char name[100]; 
    char branch[50]; 
    char designation[100];
    int found = 0;
    FILE *fp = fopen("professor.txt", "r");
    if (fp == NULL)
    {
        printf("Error: file not found\n");
        return;
    }
    printf("Enter Professor ID: ");
    scanf("%49s", professor_id);
    while (getchar() != '\n');

    while (fscanf(fp, "%49s %99s %49s %99s", id, name, branch, designation) == 4)
    {
    if (strcmp(id, professor_id) == 0)
    {
        printf("Name        = %s\n", name);
        printf("Professor ID= %s\n", id);
        printf("Branch      = %s\n", branch);
        printf("Designation = %s\n", designation);
        found = 1;
        break;
    }
}
    if (!found)
    {
        printf("\nProfessor not found\n");
    }

    fclose(fp);
}
