#ifndef STRUCTURE_H
#define STRUCTURE_H

// dashboard
void student_dashboard(void);
void professor_dashboard(void);
void Admin_dashboard(void);
void printbye(void);

// utils.c
void printline(void);

// student.c
void view_student_profile(void);
void View_my_subjects_and_semester();
void view_student_attendance(void);
void view_student_sgpa(void);

// professor.c
void view_professor_profile(void);
void view_my_subjects_and_semester(void);
void view_my_student(void);
void update_student_attendance(void);
void update_student_SGPA(void);
void view_student_analytics(void);
void logout(void);



#endif