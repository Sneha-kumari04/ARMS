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
        // case 4: analytics_reports();break;
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
            break;
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
    back();
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

    back();
}


//professor management
void professor_management(){
    int selected_option;
    while(1){
        printf("PROFESSOR MANAGEMENT\n1. Add Professor\n2. View All Professors\n3. View Professor subject\n0. Back\n");
        printf("Enter index: ");
        scanf("%d",&selected_option);
        switch(selected_option)
        {
        case 1:
            // add_new_professor();
            break;
        

        
        default:
            break;
        }

    }
}

//add new professor
// void add_new_professor(){
//     printf("will add later\n");
// }

// void view_professor_subject()


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
        
        case 0: return;break;
        default:
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
    back();
}

void reset_system_data(){
    printf("As it's a dangerous function i'll add it at the end!!\n");
}
