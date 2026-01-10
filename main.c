#include<stdio.h>
#include<stdlib.h>
#include "structures.h"

int main(){
    main_menu();
}
//void main()
void main_menu(){
    int selected_option;
    while(1){
        printline();
        printf("1. Student Login\n2. Professor login\n3. Admin login\n0. Exit\n");
        printline();
        printf("Enter Index: ");
        scanf("%d",&selected_option);

        
        switch (selected_option)
        {
        case 1: student_dashboard(); break;
        // case 2: Professor_dashboard(); break;
        // case 3: Admin_dashboard() ; break;
        case 0: printbye(); return;
        default:
            break;
        }
    }
}
//function definition
void printbye(){
    printline();
    printf("Thank You for using ARMS.\n");
    printline();
    return;
}
