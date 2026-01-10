#include<stdio.h>
#include<stdlib.h>
#include "structures.h"

int main()
{
    int selected_option;
    
    printline();
    printf("1. Student Login\n2. Professor login\n3. Admin login\n4. Exit\n");
    printline();
    printf("Enter Index: ");
    scanf("%d",&selected_option);
    while(getchar() !='\n');

    
    switch (selected_option)
    {
    case 1: student_dashboard(); break;
    case 2: Professor_dashboard(); break;
    // case 3: Admin_dashboard() ; break;
    case 4: printbye(); break;
    default:
        break;
    }
    
}


//function definition
void printbye()
{
    printf("Thank You for using ARMS.\n");
}
