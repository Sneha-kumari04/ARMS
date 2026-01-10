#include <stdio.h>
#include "structures.h"
void professor_dashboard()
{
    int selected_option;
    printline();
    printf("PROFESSOR DASHBOARD\n 1. View My Profile\n 2. View My Subjects & Semester\n 3. View My Student\n 4. Update Student Attendance\n 5.Update Student SGPA\n 6.View Student Analytics\n 7. Logout\n ");
    printline();
    printf("Enter Index: ");
    scanf("%d", &selected_option);
    switch (selected_option)
    {
    case 1:
        view_professor_profile();
        break;
    case 2:
        view_professor_profile();
        break;
    case 3:
        view_professor_profile();
        break;
    case 3:
        view_professor_profile();
        break;
    case 4:
        view_professor_profile();
        break;


    }

    int  view_professor_profile();
    {
        int professor_id, id;
        char name[100];
        char branch[50];
        char subject[100];
        printf("Enter Professor ID: ");
        scanf("%c", &professor_id);
        int found = 0;
        FILE *fp;
        fp = fopen("professor.txt", "r");
        if (fp == NULL)
        {
        printf("File not found!!\n");
        return;
        }
        while (fscanf(fp, "%d %99s %49s %49s ", &id,  name, branch, subject) != EOF)
    {
        if (id == professor_id)
        {
            printf("Name = %s\n", name);
            printf("Professor id = %d\n", id);
            printf("Branch = %s\n", branch);
            printf("Subject = %s\n", subject);
            found = 1;
            break;


        } 
    }
    if (!found)
    {
        printf(" Professor not found!!\n");
    }
    fclose(fp);
    return;
}
}
