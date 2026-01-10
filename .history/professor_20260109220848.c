#include<stdio.h>
#include "structures.h"
void professor_dashboard(){
    int selected_option;
    printline();
    printf("PROFESSOR DASHBOARD\n1. View My Profile\n2. View My Subjects & Semester\n3. View My Student\n4. Update Student Attendance\n5.Update Student \n ");
    printline();
    printf("Enter Index: ");
    scanf("%d",&selected_option);
    switch(selected_option){
    case 1: view_professor_profile(); break;
    }
    fclose(fp);
    return;
}