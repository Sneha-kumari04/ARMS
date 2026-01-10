#include<stdio.h>
#include "structures.h"
void student_dashboard()
{
    int selected_option;
    while(1)
    {
        printline();
        printf("STUDENT DASHBOARD\n1. View My Profile\n2. View My Subjects & Semester\n3. View My attendance\n4. View My SGPA\n5. Logout\n");
        printline();
        printf("Enter Index: ");
        scanf("%d",&selected_option);
        while (getchar() != '\n');
       
        switch(selected_option){
        case 1: view_student_profile(); break;
        // case 2: view_student_subjects_sem(); break;
        // case 3: view_student_attendance(); bre
       // case 4: view_student_sgpa(); break;
       case 5: printf("Logging out...\n");return;
       default:printf("Invalid option\n");
    }  
    

}

//function definition
void view_student_profile(){
    long long int registration_number,r;
    char name[100];
    char branch[50];
    char sem[50];
    char percentage[50];
    float sgpa;
    float cgpa;
    printf("Enter Registration Number: ");
    scanf("%lld",&registration_number);
    int found = 0;
    FILE *fp;
    fp = fopen("student.txt","r");
    if (fp == NULL){
        printf("File not found!!\n");
        return;
    }
    while(fscanf (fp , "%lld %99s %49s %49s %49s %f %f",&r,name,branch,sem,percentage,&sgpa,&cgpa) != EOF) {
        if( r == registration_number){
            printf("Name = %s\n",name);
            printf("Registration number = %lld\n",r);
            printf("SGPA = %.2f\n",sgpa);
            printf("CGPA = %.2f\n",cgpa);
            printf("Percentage = %s\n",percentage);
            printf("semester = %s\n",sem);
            printf("Branch = %s\n",branch);
            found = 1;
            break;
        }
    }
    if (!found){
        printf("Not found!!\n");
    }
    fclose(fp);
    return;
}