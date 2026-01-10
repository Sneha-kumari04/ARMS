#ifndef STRUCTURE_H
#define STRUCTURE_H

//main.c
void student_dashboard();
void professor_dashboard(void);
void Admin_dashboard();
void printbye();


//utils.c
void printline();

//student functions
void view_student_profile();
void view_student_subjects_sem();
void view_student_attendance();
void view_student_sgpa();

//professor functions
void printline();
void view_professor_profile(void);
void View_my_subjects_and_semester();
void view_my_student();
void update_student_attendance();
void update_student_SGPA();
void view_student_analytics();
void logout();

