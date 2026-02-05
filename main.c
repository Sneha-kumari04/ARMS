#include <stdio.h>
#include <stdlib.h>
#include "structures.h"


int main(void){

    int selected_option = 3,is_login = 0;;
    while (1)
    {
        printline();
        printf("1. Student Login\n");
        printf("2. Professor Login\n");
        printf("3. Admin Login\n");
        printf("0. Exit\n");
        printline();

        printf("Enter Index: ");
        scanf("%d", &selected_option);
        while (getchar() != '\n')
            ; // clear buffer

        switch (selected_option)
        {
        case 1:
            is_login = student_login();
            if(is_login == 1){
                student_dashboard();
            }
            break;
        case 2:
            is_login = professor_login();
            if(is_login == 1){
                professor_dashboard();
            }
            break;
        case 3:
            is_login = admin_login();
            if(is_login == 1){
                admin_dashboard();
            }
            break;
        case 0:
            printbye();
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}


