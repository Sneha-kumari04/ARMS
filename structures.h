#ifndef STRUCTURE_H
#define STRUCTURE_H

//main.c
void main_menu();
void student_dashboard();
void Professor_dashboard();
void Admin_dashboard();
void printbye();
#endif

//utils.c
void printline();
void logout_to_dashboard();
int logout_to_main_menu();

//student.c
void view_student_profile();
void view_student_branch_sem();
void view_student_attendance();
void view_student_sgpa_cgpa();
