#ifndef STRUCTURE_H
#define STRUCTURE_H

//main.c
void student_dashboard();
void professor_dashboard();
void Admin_dashboard();
void printbye();

//utils.c
void printline();
void logout_to_dashboard();
int logout_to_main_menu();

//student.c
void view_student_profile();
void view_student_branch_sem();
void view_student_attendance();
void view_student_sgpa_cgpa();


// professor.c
void view_professor_profile(void);
void view_my_subjects_and_semester(void);
void view_my_student(void);
void update_student_attendance(void);
void update_student_SGPA(void);
void view_student_analytics(void);
void logout(void);

// admin.c

#endif
