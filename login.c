#include<stdio.h>
#include<string.h>
#include "structures.h"


//admin login
char input_admin_id[50];
int admin_login(){
    //defining data types
    
    char input_admin_password[50];
    char original_admin_id[50];
    char original_admin_password[50];
    int id_matched = 0, is_login = 0,file_exist=0;
    printline();

    //Read login credentials
    printf("             Login\n");
    printline();
    printf("Enter Admin ID: ");
    scanf("%s",input_admin_id);
    printf("Enter password: ");
    scanf("%s",input_admin_password);
    printline();

    //opening file in read mode
    FILE *fp;
    fp = fopen("login_credential/admin_credential.txt", "r");

    //checking if file exist or not
    if(fp == NULL){
        file_exist = 1;
        printline();
        // return file_exist;
    }

    //checking if credentials is correct or not
    while(fscanf(fp, "%49s %49s", original_admin_id, original_admin_password)==2)
    {
        if(strcmp(original_admin_id,input_admin_id) == 0){
            id_matched = 1;
            if (strcmp(original_admin_password,input_admin_password)==0){
                is_login = 1;
            }
        }
    }

    if(!id_matched){
        printf("Invalid Admin ID..!!\n");
        printline();
    }
    else if(!is_login){
        printf("Invalid password..!!\n");
        printline();
    }
    else{
        printf("Login successful..!!\n");
        printline();
    }
    return is_login;
}


//student login
//global data definition
long long int input_registration_number;
int student_login(){
    //defining data types
    
    char input_student_password[50];
    long long int original_registration_number;
    char original_admin_password[50];
    int registration_number_matched = 0, is_login = 0,file_exist=0;
    printline();

    //Read login credentials
    printf("             Login\n");
    printline();
    printf("Enter registration number: ");
    scanf("%lld",&input_registration_number);
    printf("Enter password: ");
    scanf("%s",input_student_password);
    printline();

    //opening file in read mode
    FILE *fp;
    fp = fopen("login_credential/student_credential.txt", "r");

    //checking if file exist or not
    if(fp == NULL){
        file_exist = 1;
        printline();
        // return file_exist;
    }

    //checking if credentials is correct or not
    while(fscanf(fp, "%lld %49s", &original_registration_number, original_admin_password)==2)
    {
        if(original_registration_number == input_registration_number){
            registration_number_matched = 1;
            if (strcmp(original_admin_password,input_student_password)==0){
                is_login = 1;
            }
        }
    }

    if(!registration_number_matched){
        printf("Invalid Username..!!\n");
        printline();
    }
    else if(!is_login){
        printf("Invalid password..!!\n");
        printline();
    }
    else{
        printf("Login successful..!!\n");
        printline();
    }
    return is_login;
}


//professor login
int professor_login(){
    //defining data types
    char input_professor_id[50];
    char input_professor_password[50];
    char original_professor_id[50];
    char original_professor_password[50];
    int id_matched = 0, is_login = 0,file_exist=0;
    printline();

    //Read login credentials
    printf("             Login\n");
    printline();
    printf("Enter Admin ID: ");
    scanf("%s",input_professor_id);
    printf("Enter password: ");
    scanf("%s",input_professor_password);
    printline();

    //opening file in read mode
    FILE *fp;
    fp = fopen("login_credential/professor_credential.txt", "r");

    //checking if file exist or not
    if(fp == NULL){
        file_exist = 1;
        printline();
        // return file_exist;
    }

    //checking if credentials is correct or not
    while(fscanf(fp, "%49s %49s", original_professor_id, original_professor_password)==2)
    {
        if(strcmp(original_professor_id,input_professor_id) == 0){
            id_matched = 1;
            if (strcmp(original_professor_password,input_professor_password)==0){
                is_login = 1;
            }
        }
    }

    if(!id_matched){
        printf("Invalid Username..!!\n");
        printline();
    }
    else if(!is_login){
        printf("Invalid password..!!\n");
        printline();
    }
    else{
        printf("Login successful..!!\n");
        printline();
    }
    return is_login;
}