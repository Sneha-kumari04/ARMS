#include <stdio.h>
#include "structures.h"
void Professor_dashboard()
{
    int selected_option;
    while(1)
    {
       printline();
       printf("PROFESSOR DASHBOARD\n 1. View My Profile\n 2. View My Subjects & Semester\n 3. View My Student\n 4. Update Student Attendance\n 5.Update Student SGPA\n 6.View Student Analytics\n 7. Logout\n ");
       printline();
       printf("Enter Index: ");
       scanf("%d", &selected_option);
       while(getchar() !='\n');
       switch (selected_option)
       {
          case 1: view_professor_profile(); break;

          //case 2: View_my_subjects_and_semester(); break;
          //case 3: view_my_student(); break;
          //case 4: update_student_attendance(); break;
          //case 5: update_student_SGPA(); break;
          //case 6: view_student_analytics(); break;
          //case 7: logout(); break; //return
        }
    }

    
}
