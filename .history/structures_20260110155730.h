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
void view_student_profile(void);
void view_student_subjects_sem(void);
void view_student_attendance(void);
void view_student_sgpa(void);

//professor functions
void view_professor_profile(void);
void view_my_subjects_and_semester(void);
void view_my_student(void);
void update_student_attendance(void);
void update_student_SGPA(void);
void view_student_analytics(void);
void logout(void);

#endif