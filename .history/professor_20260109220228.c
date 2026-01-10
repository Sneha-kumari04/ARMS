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