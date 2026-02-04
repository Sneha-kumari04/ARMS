#include<stdio.h>


//printline
void printline(){
    printf("-------------------------------\n");
}

//logout to dashboard
void logout_to_dashboard(){
    int logout_input;
    printf("Enter 0 to exit: ");
    scanf(" %d",&logout_input);
    printline();
    if (logout_input == 0){
        printf("Logged out!!\n");
        return;
    }
    else{
        printf("Invalid input!!");
        
    }
}

//logout to main menu
int logout_to_main_menu(){
    char choice;
    printf("Are you confirm (y/n): ");
    scanf(" %c",&choice);
    printline();

    if (choice == 'y' || choice == 'Y'){
        printf("Logging out....\n");
        return 1;
    }
    else if (choice == 'n' || choice == 'N'){
        printf("Logout cancelled...\n");
        return 0;
    }
    else{
        printf("Invalid input!!!");
        return 0;
    }
}


// bye message print
void printbye(void)
{
    printline();
    printf("Thank You for using ARMS.\n");
    printline();
    return;
}