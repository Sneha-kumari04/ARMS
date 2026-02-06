#include <stdio.h>
#include "structures.h"

// student_dashboard() function defintion
void student_dashboard()
{
    int selected_option;
    greet_student();
    while (1)
    {
        printline();
        printf("STUDENT DASHBOARD\n1. View My Profile\n2. View My Branch & Semester\n3. View My attendance\n4. View My SGPA & CGPA\n0. Logout\n");
        printline();
        printf("Enter Index: ");
        scanf("%d", &selected_option);
        printline();
        switch (selected_option)
        {
        case 1:
            view_student_profile();
            break;
        case 2:
            view_student_branch_sem();
            break;
        case 3:
            view_student_attendance();
            break;
        case 4:
            view_student_sgpa_cgpa();
            break;
        case 0:
            if (logout_to_main_menu())
                return; // back to login
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    }
}


//greet student
void greet_student()
{
    // defining data types
    long long int r;
    char name[100];
    char branch[50];
    char sem[50];
    char attendance[50];
    float sgpa;
    float cgpa;

    int found = 0;

    // opening file as read mode
    FILE *fp;
    fp = fopen("data/student.txt", "r");

    // checking if file is there or not
    if (fp == NULL)
    {
        printf("File not found!!\n");
        printline();
        return;
    }

    // serching and printing data of user
    while (fscanf(fp, "%lld %99s %49s %49s %49s %f %f", &r, name, branch, sem, attendance, &sgpa, &cgpa) == 7)
    {
        if (r == input_registration_number)
        {
            printf("Hello %s\n",name);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Not found!!\n");
        printline();
    }

    // closing file
    fclose(fp);

    return;
}



//view student profile
void view_student_profile()
{
    // defining data types
    long long int r;
    char name[100];
    char branch[50];
    char sem[50];
    char attendance[50];
    float sgpa;
    float cgpa;

    int found = 0;

    // opening file as read mode
    FILE *fp;
    fp = fopen("data/student.txt", "r");

    // checking if file is there or not
    if (fp == NULL)
    {
        printf("File not found!!\n");
        printline();
        return;
    }

    // serching and printing data of user
    while (fscanf(fp, "%lld %99s %49s %49s %49s %f %f", &r, name, branch, sem, attendance, &sgpa, &cgpa) == 7)
    {
        if (r == input_registration_number)
        {
            printf("Name = %s\n", name);
            printf("Registration number = %lld\n", r);
            printf("SGPA = %.2f\n", sgpa);
            printf("CGPA = %.2f\n", cgpa);
            printf("Attendance = %s\n", attendance);
            printf("Semester = %s\n", sem);
            printf("Branch = %s\n", branch);
            printline();
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Not found!!\n");
        printline();
    }

    // closing file
    fclose(fp);

    // logout to student dashboard
    logout_to_dashboard();
}

void view_student_branch_sem()
{
    // defining data types
    long long int r;
    char name[100];
    char branch[50];
    char sem[50];
    char attendance[50];
    float sgpa;
    float cgpa;

    int found = 0;

    // opening file as read mode
    FILE *fp;
    fp = fopen("data/student.txt", "r");

    // checking if file is there or not
    if (fp == NULL)
    {
        printf("File not found!!\n");
        printline();
        return;
    }

    // serching and printing data of user
    while (fscanf(fp, "%lld %99s %49s %49s %49s %f %f", &r, name, branch, sem, attendance, &sgpa, &cgpa) == 7)
    {
        if (r == input_registration_number)
        {
            printf("Semester = %s\n", sem);
            printf("Branch = %s\n", branch);
            printline();
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Not found!!\n");
        printline();
    }

    // closing file
    fclose(fp);

    // logout to student dashboard
    logout_to_dashboard();
}

void view_student_attendance()
{
    // defining data types
    long long int r;
    char name[100];
    char branch[50];
    char sem[50];
    char attendance[50];
    float sgpa;
    float cgpa;
    int found = 0;

    // opening file as read mode
    FILE *fp;
    fp = fopen("data/student.txt", "r");

    // checking if file is there or not
    if (fp == NULL)
    {
        printf("File not found!!\n");
        printline();
        return;
    }

    // serching and printing data of user
    while (fscanf(fp, "%lld %99s %49s %49s %49s %f %f", &r, name, branch, sem, attendance, &sgpa, &cgpa) == 7)
    {
        if (r == input_registration_number)
        {
            printf("Attendance = %s\n", attendance);
            printline();
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Not found!!\n");
        printline();
    }

    // closing file
    fclose(fp);

    // logout to student dashboard
    logout_to_dashboard();
}

void view_student_sgpa_cgpa()
{
    // defining data types
    long long int r;
    char name[100];
    char branch[50];
    char sem[50];
    char attendance[50];
    float sgpa;
    float cgpa;

    int found = 0;

    // opening file as read mode
    FILE *fp;
    fp = fopen("data/student.txt", "r");

    // checking if file is there or not
    if (fp == NULL)
    {
        printf("File not found!!\n");
        printline();
        return;
    }

    // serching and printing data of user
    while (fscanf(fp, "%lld %99s %49s %49s %49s %f %f", &r, name, branch, sem, attendance, &sgpa, &cgpa) == 7)
    {
        if (r == input_registration_number)
        {
            printf("SGPA = %.2f\n", sgpa);
            printf("CGPA = %.2f\n", cgpa);
            printline();
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Not found!!\n");
        printline();
    }

    // closing file
    fclose(fp);

    // logout to student dashboard
    logout_to_dashboard();
}