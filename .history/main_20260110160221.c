#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

int main(void)
{
    int selected_option;

    while (1)
    {
        printline();
        printf("1. Student Login\n");
        printf("2. Professor Login\n");
        printf("3. Admin Login\n");
        printf("4. Exit\n");
        printline();

        printf("Enter Index: ");
        scanf("%d", &selected_option);
        while (getchar() != '\n'); // clear buffer

        switch (selected_option)
        {
            case 1:student_dashboard();break;
            case 2:professor_dashboard();break;
            case 3:Admin_dashboard();break;

            case 4:printbye();exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}

// function definition
void printbye(void)
{
    printf("Thank You for using ARMS.\n");
}

