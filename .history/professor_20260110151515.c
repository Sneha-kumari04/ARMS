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
    char id[50], name[100], branch[50], subject[100];
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

    while (fscanf(fp, "%49[^,], %99[^,], %49[^,], %49[^\n]\n",
                  id, name, branch, subject) == 4)
    {
        if (strcmp(id, professor_id) == 0)
        {
            printf("\nName: %s", name);
            printf("\nID: %s", id);
            printf("\nBranch: %s", branch);
            printf("\nSubject: %s\n", subject);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Professor not found\n");

    fclose(fp);
}

}
