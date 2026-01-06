#include<stdio.h>
#include "structures.h"

int main(){
    int selected_option;
    printf("1. Student Login\n2. Professor login\n3. Admin login\n4. Exit\n");
    scanf("%d",&selected_option);

    switch (selected_option)
    {
    // case 1: student_dashboard(); break;
    // case 2: Professor_dashboard(); break;
    // case 3: Admin_dashboard() ; break;
    case 4: printbye(); break;
    default:
        break;
    }
}

//function definition
void printbye(){
    printf("Thank You for using ARMS.\n");
}