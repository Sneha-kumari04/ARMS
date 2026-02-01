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
    printf("ADMIN DASHBOARD\n1. View Admin Profile\n2. Student Management\n3. Professor Management\n4. Academic Records Control\n5. Analytics & Reports\n6. System Settings\n7. Logout\n");
    printline();
    printf("Enter Index: ");
    scanf("%d",&choice);
    printline();
    
    while(getchar());
}
