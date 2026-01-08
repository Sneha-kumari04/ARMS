#include<stdio.h>
#include "structures.h"
void student_dashboard(){
    int selected_option;
    printline();
    printf("STUDENT DASHBOARD\n1. View My Profile\n2. View My Subjects & Semester\n3. View My attendance\n4. View My SGPA\n5. Logout\n");
    printline();
    printf("Enter Index: ");
    scanf("%d",&selected_option);
    switch(selected_option){
    case 1: view_student_profile(); break;
    // case 2: view_student_subjects_sem(); break;
    // case 3: view_student_attendance(); break;
    // case 4: view_student_sgpa(); break;
    default:
    break;
}
}

//function definition
void view_student_profile(){
    long long int registration_number,r;
    char name[100];
    printf("Enter Registration Number: ");
    scanf("%lld",&registration_number);
    int found = 0;
    FILE *fp;
    fp = fopen("student.txt","r");
    if (fp == NULL){
        printf("File not found!!\n");
        return; 
    }
    while(fscanf (fp , "%lld %s",&r,name)!= EOF) {
        if( r == registration_number){
            printf("Registration Number = %lld\nName = %s\n",r,name);
            found = 1;
            printf("byeeee");
            break;
        }
    }
    if (found==0){
        printf("Not found!!\n");
    }
    fclose(fp);
    return;
}