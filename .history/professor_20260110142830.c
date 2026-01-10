#include <stdio.h>
#include "structures.h"
void Professor_dashboard()
{
    int selected_option;
    while(1){

    }
    
    }

    int view_professor_profile();
    {
        char professor_id[50];
        char id[50];
        char name[100];
        char branch[50];
        char subject[100];
        char degisnation[100];
        printf("Enter Professor id: ");
        scanf("%9s", &professor_id);
        int found = 0;
        FILE *fp;
        fp = fopen("professor.txt", "r");
        if (fp == NULL)
        {
            printf("File not found!!\n");
            return;
        }
        while (fscanf(fp, "%9s %99s %49s %49s  ", &id, name, branch, subject, degisnation) != 4)
        {
            if (id == professor_id)
            {
                printf("Name = %s\n", name);
                printf("Professor id = %d\n", id);
                printf("Branch = %s\n", branch);
                printf("Subject = %s\n", branch);
                printf("Degisnation = %s\n", subject);
                found = 1;
                break;
            }
        }
        if (!found)
        {
            printf(" Professor not found!!\n");
        }
        fclose(fp);
        return;
    }
}
