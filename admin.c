#include <stdio.h>
#include "structures.h"

void admin_dashboard(void)
{
    char admin_id[50];
    char name[100];
    char designation[100];
    int choice;

    //print admin dashboard
    printline();
    printf("ADMIN DASHBOARD\n1. View Admin Profile\n2. Student Management\n3. Professor Management\n4. Academic Records Control\n5. Analytics & Reports\n6. System Settings\n0. Logout\n");
    printline();
    printf("Enter Index: ");
    scanf("%d",&choice);
    printline();
    
    while(getchar()!= '\n');

    switch (choice)
    {
    case 1:
        view_admin_profile();
        break;
    //case 2: student_management();break;
    // case 3: professor_management(); break;
    // case 4: academic_records_control();break;
    // case 5: analytics_reports();break;
    // case 6: system_settings;break;
    case 0: if (logout_to_main_menu())
                return; // back to login
            break;
    default: printf("Invalid option\n");
        
    }

}


//function definition
void view_admin_profile(){
    printf("Hi");
}

