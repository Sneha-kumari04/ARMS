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
        while (getchar() != '\n');   // clear input buffer

        switch (selected_option)
        {
          case 1:view_professor_profile();break;
          //case 2: View_my_subjects_and_semester(); break;
          //case 3: view_my_student(); break;
          //case 4: update_student_attendance(); break;
          //case 5: update_student_SGPA(); break;
          //case 6: view_student_analytics(); break;
          //case 7: logout(); break; //return
          default: printf("Invalid option\n");
        }  
    }
}
void view_professor_profile(void)
{
    char professor_id[50];
    char id[50], name[100], branch[50], designation[100];
    char line[256];
    int found = 0;

    FILE *fp = fopen("professor.txt", "r");
    if (fp == NULL)
    {
        printf("Error: professor.txt not found\n");
        printf("Press Enter to return...");
        getchar();
        return;
    }

    printf("Enter Professor ID (e.g. P1401): ");
    scanf("%49s", professor_id);
    while (getchar() != '\n');

    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%49s %99s %49s %99s",
                   id, name, branch, designation) == 4)
        {
            if (strcmp(id, professor_id) == 0)
            {
                printf("\n--- PROFESSOR PROFILE ---\n");
                printf("ID          : %s\n", id);
                printf("Name        : %s\n", name);
                printf("Branch      : %s\n", branch);
                printf("Designation : %s\n", designation);
                found = 1;
                break;
            }
        }
    }

    if (!found)
    {
        printf("\nProfessor not found\n");
    }

    fclose(fp);

    printf("\nPress Enter to return to dashboard...");
    getchar();
}
