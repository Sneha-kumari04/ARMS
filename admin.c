#include <stdio.h>
#include <string.h>
#include "structures.h"

void admin_dashboard(void)
{
    int selected_option;
    while(1){
        //print admin dashboard
        printline();
        printf("ADMIN DASHBOARD\n1. View Admin Profile\n2. Student Management\n3. Professor Management\n4. Analytics & Reports\n5. System Settings\n0. Logout\n");
        printline();
        printf("Enter Index: ");
        scanf("%d",&selected_option);
        printline();
        

        switch (selected_option)
        {
        case 1:
            view_admin_profile();
            break;
        case 2: student_management();break;
        case 3: professor_management(); break;
        case 4: view_student_analytics();break;
        case 5: system_settings();break;
        case 0: if (logout_to_main_menu())
                    return; // back to login
                break;
        default: printf("Invalid option\n");
            
        }
    }

}


//view admin profile
void view_admin_profile(){
    //defining data types
    char original_admin_id[50];
    char admin_name[100];
    char admin_designation[100];
    int found = 0;

    //opening file
    FILE *fp;
    fp = fopen("data/admin.txt", "r");


    //checking if file exist or not
    if(fp == NULL){
        printf("File didn't exist...\n");
        printline();
        return;
    }

    //searching the data from the file
    while (fscanf(fp,"%49s %99s %99s",original_admin_id,admin_name,admin_designation)==3){
        if(strcmp(input_admin_id,original_admin_id)==0){
            printf("ID: %s\n",input_admin_id);
            printf("Name: %s\n",admin_name);
            printf("Designation: %s\n",admin_designation);
            printline();
            found = 1;
            break;
        }
    }
    //not found message
    if(!found){
        printf("Not found....\n");
        printline();
    }

    //closing file
    fclose(fp);

    //logout to student dashboard
    logout_to_dashboard();
}

//student management
void student_management(){
    //print student management options
    int selected_option;
    while(1){
        printf("STUDENT MANAGEMENT\n1. Add New Student\n2. View All Students\n3. Search Student\n0. Back\n");
        printline();
        printf("Enter Index: ");
        scanf("%d",&selected_option);
        printline();
        switch (selected_option)
        {
        case 1:
            add_new_student();
            break;
        case 2:view_all_students();break;
        case 3:search_student();break;
        case 0:
        return;
        break;

        default:
            printf("Invalid Input..!!\n");
        }
    }
}


//add_new_student
void add_new_student(){
    //defining data types for input
    long long int new_registration_number;
    char new_name[100];
    char new_branch[50];
    int new_sem;
    char new_attendance[50];
    float new_sgpa;
    float new_cgpa;
    char password[50];

    //defining data types for fetching data from txt tile
    long long int registration_number;
    char name[100];
    char branch[50];
    int sem;
    char attendance[50];
    float sgpa;
    float cgpa;

    //opening file in read mode
    FILE *fp;
    fp = fopen("data/student.txt","r");
    if(fp == NULL){
        printf("File didn't Exist...!!!\n");
        printline();
        return;
    }

    //taking input of new student
    printline();
    printf("Enter registration number: ");
    scanf("%lld",&new_registration_number);
    printf("Enter name of student: ");
    scanf("%99s",new_name);
    printf("Enter branch: ");
    scanf("%49s",new_branch);
    printf("Enter semester: ");
    scanf("%d",&new_sem);
    printf("Enter attendance(in %%): ");
    scanf("%49s",new_attendance);
    printf("Enter SGPA: ");
    scanf("%f",&new_sgpa);
    printf("Enter CGPA: ");
    scanf("%f",&new_cgpa);
    printf("Enter password for this student: \n");
    scanf("%49s",password);


    //checking if entered data is logical or not
    if (new_sem>8 || new_sem < 1){
        printf("Invalid semester...Please Retry..!!\n");
        printline();
        fclose(fp);
        return;
    }
    if (new_sgpa > 10 || new_sgpa < 0){
        printf("Invalid SGPA...Please Retry..!!\n");
        printline();
        fclose(fp);
        return;
    }
    if (new_cgpa > 10 || new_cgpa<0){
        printf("Invalid CGPA...Please Retry..!!\n");
        printline();
        fclose(fp);
        return;
    }
    //checking if every entered data satisfies the critaria or not
    while (fscanf(fp, "%lld %99s %49s %d %49s %f %f", &registration_number, name, branch, &sem, attendance, &sgpa, &cgpa) == 7)
    {
        if (new_registration_number==registration_number){
            printf("Registration number exist...!!\n");
            printline();
            fclose(fp);
            return;
        }
    }
    fclose(fp);

    //opening file as append mode 
    fp = fopen("data/student.txt","a");

    //checking if file exist or not
    if(fp == NULL){
        printf("File didn't Exist...!!!\n");
        return;
    }
    
    //adding student details in data
    fprintf(fp,"%lld %s %s %d %s %.2f %.2f\n",new_registration_number,new_name,new_branch,new_sem,new_attendance,new_sgpa,new_cgpa);
    fclose(fp);
    
    //adding student login details
    fp = fopen("login_credential/student_credential.txt","a");
    if(fp == NULL){
        printf("File didn't Exist...!!!\n");
        return;
    }
    fprintf(fp,"%lld %s\n",new_registration_number,password);
    fclose(fp);

    //printing success message
    printf("Student added successfully..!!");
    printline();

    logout_to_dashboard();
    
}

//view student
void view_all_students(){
    //defining data types
    long long int registration_number;
    char name[100],branch[50],attendance[50];
    char sem[50];
    float sgpa,cgpa;

    //opening file as read mode
    FILE *fp;
    fp = fopen("data/student.txt","r");

    //checking if file exist
    if(fp == NULL){
        printf("File didn't Exist...!!\n");
        return;
    }

    //fetching data and printing it
    while (fscanf(fp, "%lld %99s %49s %s %49s %f %f", &registration_number, name, branch, sem, attendance, &sgpa, &cgpa) == 7)
    {
        printf("Registration no.: %lld\tName: %s\tBranch: %s\tSemester: %s\tAttendance: %s\tSGPA: %.2f\tCGPA: %.2f\n",registration_number, name, branch, sem, attendance, sgpa, cgpa);
    }
    fclose(fp);
    printline();
    logout_to_dashboard();
}

//search student
void search_student()
{
    // defining data types
    long long int registration_number, r;
    char name[100];
    char branch[50];
    char sem[50];
    char attendance[50];
    float sgpa;
    float cgpa;

    // input of registration number
    printf("Enter Registration Number: ");
    scanf("%lld", &registration_number);
    printline();
    int found = 0;

    // opening file as read mode
    FILE *fp;
    fp = fopen("data/student.txt", "r");

    // checking if file is there or not
    if (fp == NULL)
    {
        printf("File not found!!\n");
        printline();
        return;
    }

    // serching and printing data of user
    while (fscanf(fp, "%lld %99s %49s %49s %49s %f %f", &r, name, branch, sem, attendance, &sgpa, &cgpa) == 7)
    {
        if (r == registration_number)
        {
            printf("Name = %s\n", name);
            printf("Registration number = %lld\n", r);
            printf("SGPA = %.2f\n", sgpa);
            printf("CGPA = %.2f\n", cgpa);
            printf("Attendance = %s\n", attendance);
            printf("Semester = %s\n", sem);
            printf("Branch = %s\n", branch);
            printline();
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Not found!!\n");
        printline();
    }

    // closing file
    fclose(fp);

    logout_to_dashboard();
}


//professor management
void professor_management(){
    int selected_option;
    while(1){
        printf("PROFESSOR MANAGEMENT\n 1. Add Professor\n 2. Assign Subject & Semester\n 3. Search professor\n 4. Search Professor Subject\n 5. View All Professors\n 6. View All Professor subject\n 0. Back\n");
        printline();
        printf("Enter index: ");
        scanf("%d",&selected_option);
        printline();
        switch(selected_option)
        {
        case 1:
            add_professor();
            break;
        case 2: assign_subject_semester();break;
        case 3: search_professor();break;
        case 4: search_professor_subject();break;
        case 5: view_all_professors();break;
        case 6: view_all_professor_subject();break;
        case 0: return; break; 
        
        default:
            printf("Invalid Input...!!\n");
            printline();
        }

    }
}

//add new professor
void add_professor(){
    //data types for fetching from txt file
    char id[50];
    char name[100];
    char designation[100];

    //credential
    char password[50];

    //data type to take input for new professor
    char new_id[50];
    char new_name[100];
    char new_designation[100];

    //opening file in read mode
    FILE *fp;
    fp = fopen("data/professor.txt","r");

    //checking if file exist or not
    if(fp == NULL){
        printf("File didn't exist\n");
        printline();
    }
    //Taking input for new professor
    printf("New Professor Form\n");
    printf("Enter Professor ID: ");
    scanf("%49s",new_id);
    //checking if new id exist or not
    while (fscanf(fp, "%49s %99s %99s", id, name, designation) == 4){
        if (strcmp(id,new_id)==0){
            printf("Professor ID exist.. please choose a new ID..!!\n");
            printline();
            fclose(fp);
            return;
        }
    }
    fclose(fp);
    //taking input for professor.txt
    printf("Enter Professor Name: ");
    scanf("%99s",new_name);
    
    printf("Enter Professor Designation: ");
    scanf("%99s",new_designation);

    //professor credential
    printf("Enter Password for the new Professor: ");
    scanf("%49s",password);
    printline();

    //opening file as append mode
    fp = fopen("data/professor.txt","a");
    //checking if file exist or not
    if (fp == NULL){
        printf("File didn't exist...!!\n");
        fclose(fp);
        printline();
        return;
    }
    //storing file in professor.txt
    fprintf(fp,"%s %s %s\n",new_id,new_name,new_designation);
    //closing file
    fclose(fp);

    //opening credential file as append mode
    fp = fopen("login_credential/professor_credential.txt","a");
    //checking if file exist or not 
    if (fp == NULL){
        printf("File didn't exist...!!\n");
        printline();
        fclose(fp);
        return;
    }
    //storing data in professor_credential.txt
    fprintf(fp,"%s %s\n",new_id,password);
    //closing file
    fclose(fp);

    printf("Professor added successfully..!!\n");
    printline();
    logout_to_dashboard();

}


void assign_subject_semester(){
    //defining data type to scan from original file
    char id[50];
    char name[100];
    char designation[100];

    //defining data types for taking input
    char new_id[50];
    char new_subject[50];
    char new_subject_code[50];
    int new_sem;
    char new_branch[100];

    //opening file as read mode
    FILE *fp;
    fp = fopen("data/professor.txt","r");

    //checking if file exist
    if(fp == NULL){
        printf("File didn't exist\n");
        printline();
    }

    //Taking input for assigning subject and sem
    printf("Assigning subject to new Professor\n");
    printf("Enter Professor ID: ");
    scanf("%49s",new_id);
    //checking if new id exist or not
    while (fscanf(fp, "%49s %99s %99s", id, name, designation) == 4){
        if (strcmp(id,new_id)==0){
            printf("This professor already have assigned subjects.\n");
            printline();
            fclose(fp);
            return;
        }
    }
    fclose(fp);

    //taking remaining input
    printf("Enter Professor Subject: ");
    scanf("%49s",new_subject);
    printf("Enter subject code: ");
    scanf("%49s",new_subject_code);
    printf("Enter new sem(1-8): ");
    scanf("%d",&new_sem);
    if (new_sem>8 || new_sem < 1){
        printf("Invalid semester...Please Retry..!!\n");
        printline();
        fclose(fp);
        return;
    }
    printf("Enter branch: ");
    scanf("%99s",new_branch);
    printline();

    //opening file in append mode 
    fp = fopen("data/professor_subjects.txt","a");
    //checking if file exist or not
    if(fp == NULL){
        printf("File didn't exist...!!\n");
        fclose(fp);
        printline();
        return;
    }
    //storing data in professor subject file
    fprintf(fp,"%s %s %s %d %s\n",new_id,new_subject,new_subject_code,new_sem,new_branch);
    //closing file
    fclose(fp);

    printf("Professor subject assigned successfully...!!\n");
    logout_to_dashboard();
}


void search_professor(){
    char professor_id[50];
    char id[50];
    char name[100];
    char designation[100];
    int found = 0;
    FILE *fp = fopen("data/professor.txt", "r");
    if (fp == NULL)
    {
        printf("Error: file not found\n");
        printline();
        return;
    }
    printf("Enter Professor ID: ");
    scanf("%49s", professor_id);
    printline();

    while (fscanf(fp, "%49s %99s %99s", id, name, designation) == 3)
    {
        if (strcmp(id, professor_id) == 0)
        {
            printf("Professor ID = %s\n", id);
            printf("Name         = %s\n", name);
            printf("Designation  = %s\n", designation);
            found = 1;
            printline();
            break;
        }
    }
    if (!found)
    {
        printf("Professor not found\n");
        printline();
    }
    fclose(fp);
    logout_to_dashboard();
}


void search_professor_subject(){
    char professor_id[100];
    char id[50];
    char subject[50];
    char subject_code[100];
    int sem;
    char department[100];
    int found = 0;
    FILE *fp = fopen("data/professor_subjects.txt", "r");
    if (fp == NULL)
    {
        printf("Error: file not found\n");
        printline();
        return;
    }
    printf("Enter Professor ID: ");
    scanf("%99s", professor_id);
    printline();

    while (fscanf(fp, "%49s %49s %99s %d %99s", id, subject, subject_code, &sem, department) == 5)
    {
        if (strcmp(id, professor_id) == 0)
        {
            printf("ID:          = %s\n",professor_id);
            printf("Subject Name = %s\n", subject);
            printf("Subject Code = %s\n", subject_code);
            printf("Sem          = %d\n", sem);
            printf("Department   = %s\n", department);
            found = 1;
            printline();
            break;
        }
    }
    if (!found)
    {
        printf("\n Data not found\n");
        printline();
    }
    fclose(fp);
    logout_to_dashboard();
}


void view_all_professors(){
    //defining data types to scan from file 
    char id[50];
    char name[100];
    char designation[100];
    int found = 0;

    //opening file
    FILE *fp = fopen("data/professor.txt", "r");
    if (fp == NULL)
    {
        printf("Error: file not found\n");
        printline();
        return;
    }

    //searching and printing the data
    while (fscanf(fp, "%49s %99s %99s", id, name, designation) == 3)
    {
        printf("Professor ID = %s\n", id);
        printf("Name         = %s\n", name);
        printf("Designation  = %s\n", designation);
        printline();
        found = 1;
    }

   // not found message print
    if (!found)
    {
        printf("\nProfessor not found\n");
        printline();
    }
  //  closing file
    fclose(fp);
    logout_to_dashboard();
}


//view all assigned subjects
void view_all_professor_subject(){
    //definig data types to store scanned data from file
    char id[50];
    char subject[100];
    char subject_code[50];
    char sem[50];
    char branch[100];
    int found = 0;
    //opening file 
    FILE *fp = fopen("data/professor_subjects.txt", "r");
    //checking if file exist
    if (fp == NULL)
    {
        printf("Error: file not found\n");
        printline();
        return;
    }

    while (fscanf(fp, "%49s %99s %49s %49s %99s",id,subject,subject_code, sem, branch) == 5)
    {
        printf("Professor ID = %s\n", id);
        printf("Subject      = %s\n", subject);
        printf("Subject code = %s\n", subject_code);
        printf("Semester     = %s\n", sem);
        printf("Branch       = %s\n", branch);
        found = 1;
        printline();
    }
    if (!found)
    {
        printf("\nProfessor not found\n");
        printline();
    }
    fclose(fp);
    logout_to_dashboard();
}



//system setting
void system_settings(){
    int selected_option;
    while (1)
    {
        printf("SYSTEM SETTINGS\n1. View System Summary\n2. Reset System Data\n0. Back\n");
        printline();
        printf("Enter index: ");
        scanf("%d",&selected_option);
        printline();
        switch (selected_option)
        {
        case 1:
            view_system_summary();
            break;
        case 2: reset_system_data(); break;
        case 0: return;break;
        default:printf("Invalid Input..!!\n");
            break;
        }
    }

}

//view system summary
void view_system_summary()
{
    printline();
    printf("SYSTEM SUMMARY\n");
    printline();

    printf("Application Name : ARMS\n");
    printf("Full Form        : Academic Record Management System\n");
    printf("Version          : v1.0.0\n");
    printf("Release Status   : Stable\n");
    printf("Developed By     : Krishna & Sneha\n\n");

    printf("Description:\n");
    printf("ARMS is a console-based academic management system\ndesigned to manage student records, admin controls,\nand secure login operations.\n\n");

    printf("Key Modules:\n");
    printf("- Admin Management\n");
    printf("- Student Management\n");
    printf("- Professor Management\n");
    printf("- Academic Records Control\n");
    printf("- Authentication System\n\n");

    printf("Current Version Capabilities:\n");
    printf("- Add / View records\n");
    printf("- Role-based dashboards\n");

    printline();
    logout_to_dashboard();
}


void reset_system_data(){

    int choose;
    printf("Warning: Choosing reset option will delete\nall the data stored in the ARMS sytem.\n");
    printline();
    printf("1. Reset\n0.Cancel reset\n");
    printf("Do you want to reset the data(1 or 0): ");
    scanf("%d",&choose);
    printline();

    //while(1){
        switch (choose)
        {
        case 1:
            reset_data();
            break;
        case 0: printf("Reset Cancelled....!!\n");
            printline();
            logout_to_dashboard();
            break;
        default:
            printf("Invalid choice...!!\n");
            break;
        }
    //}



}

//reset data
void reset_data(){
    //printing deleting data message
    printf("Deleting data.......\n");
    //opening admin.txt in w mode to clear it's content 
    FILE *admin_txt = fopen("data/admin.txt","w");

    FILE *student_txt = fopen("data/student.txt","w");

    FILE *professor_txt = fopen("data/professor.txt","w");

    FILE *professor_subjects_txt = fopen("data/professor_subjects.txt","w");

    FILE *admin_credential_txt = fopen("login_credential/admin_credential.txt","w");

    FILE *professor_credential_txt = fopen("login_credential/professor_credential.txt","w");

    FILE *student_credential_txt = fopen("login_credential/student_credential.txt","w");

    //closing file
    fclose(admin_txt);
    fclose(student_txt);
    fclose(professor_txt);
    fclose(professor_subjects_txt);
    fclose(admin_credential_txt);
    fclose(professor_credential_txt);
    fclose(student_credential_txt);

    //printing success message 
    printf("Reset completed..!!\n");
    printline();
}