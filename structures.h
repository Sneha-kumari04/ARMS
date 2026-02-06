#ifndef STRUCTURE_H
#define STRUCTURE_H

//professor.c and admin.c shares their functions with each other

// main.c
void student_dashboard();
void professor_dashboard();
void admin_dashboard();
void printbye();

// login.c
int student_login();
int professor_login();
int admin_login();


// student.c
void greet_student();
void view_student_profile();
void view_student_branch_sem();
void view_student_attendance();
void view_student_sgpa_cgpa();

// professor.c
void greet_professor();
void view_professor_profile(void);
void view_my_subjects_and_semester(void);
void view_student_analytics(void);

//utils.c
void printline();
void logout_to_dashboard();
int logout_to_main_menu();
int back();


//global used data variables
extern long long int input_registration_number;
extern char input_admin_id[50];
extern char input_professor_id[50];


// admin.c
void view_admin_profile();
void student_management();
void professor_management();
void system_settings();

//student_management
void add_new_student();
void view_all_students();
void view_all_students();
void search_student();

//professor management
void add_professor();
void assign_subject_semester();
void search_professor();
void search_professor_subject();
void view_all_professors();
void view_all_professor_subject();

//admin management
void view_system_summary();
void reset_system_data();
void reset_data();

#endif