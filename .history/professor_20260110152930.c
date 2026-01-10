#include <stdio.h>

#include "structures.h"
void Professor_dashboard()
{
    int selected_option;
    while(1)
    {
       printline();
       printf("PROFESSOR DASHBOARD\n 1. View My Profile\n 2. View My Subjects & Semester\n 3. View My Student\n 4. Update Student Attendance\n 5.Update Student SGPA\n 6.View Student Analytics\n 7. Logout\n ");
       printline();
       printf("Enter Index: ");
       scanf("%d", &selected_option);
       while(getchar() !='\n');
       switch (selected_option)
       {
          case 1: view_professor_profile(); break;

          //case 2: View_my_subjects_and_semester(); break;
          //case 3: view_my_student(); break;
          //case 4: update_student_attendance(); break;
          //case 5: update_student_SGPA(); break;
          //case 6: view_student_analytics(); break;
          //case 7: logout(); break; //return
        }
    }

    void view_professor_profile()
 {
    char professor_id[50];
    char line[256];
    char id[50], name[100], branch[50], designation[100];
    int found = 0;

    FILE *fp = fopen("professor.txt", "r");
    if (fp == NULL)
    {
        printf("File not found\n");
        return;
    }

    printf("Enter Professor ID: ");
    scanf("%s", professor_id);
    while (getchar() != '\n');

    while (fgets(line, sizeof(line), fp))
    {
        /*
           Expected line format:
           ID Name Branch Designation
           Example:
           P1401 Gopal Krishna ITW Associate Professor
        */

        sscanf(line,
               "%s %s 99[^A-Z] %49s %s99[^\n]",
               id, name, branch, designation);

        // Trim trailing spaces in name
        name[strcspn(name, " ")] = 0;

        if (strcmp(id, professor_id) == 0)
        {
            printf("\nName: %s", name);
            printf("\nID: %s", id);
            printf("\nBranch: %s", branch);
            printf("\nDesignation: %s\n", designation);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Professor not found\n");

    fclose(fp);
}

}
    