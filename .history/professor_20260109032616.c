#include<stdio.h>
#include"structures.h"
void professor_dashboard()
{
    int selected_option;
    printline();
    printf("PROFFESOR DASHBOARD\n1. View My Profile\n2. View My Subjects & Semester\n3. View My Students\n4. Update Students Attendance\n7. Logout\n");
    printline();
    printf("Enter Index: ");
    scanf("%d",&selected_option);
    switch(selected_option){
    case 1: view_proffesor_profile(); break;
    case 2: view_student_subjects_sem(); break;
    case 3: view_student_attendance(); break;
    case 4: view_student_sgpa(); break;
    default:
    break;
}
}

//function definition
void view_proffesor_profile(){
    FILE *fp;
    fp = fopen("proffesor.txt","r");
}
