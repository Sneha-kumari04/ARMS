#include <stdio.h>
#include "structures.h"
void professor_dashboard()
{
    int selected_option;
    printline();
    printf("PROFESSOR DASHBOARD\n1. View My Profile\n2. View My Subjects & Semester\n3. View My Student\n4. Update Student Attendance\n5.Update Student SGPA\n6.View Student Analytics\n7. Logout\n ");
    printline();
    printf("Enter Index: ");
    scanf("%d", &selected_option);
    switch (selected_option)
    {
    case 1:
        view_professor_profile();
        break;
    }

    void view_professor_profile()
    {
        char_professor_id;
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
        while (fscanf(fp, "%c %99c %49s %49c ", &c, name, branch, subject) != EOF)
    {
        if (r == registration_id)
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

    }



    return;
}