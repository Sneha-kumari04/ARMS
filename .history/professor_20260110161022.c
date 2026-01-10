#include <stdio.h>
#include <string.h>
#include "structures.h"

/* ================= PROFESSOR DASHBOARD ================= */
void professor_dashboard(void)
{
    int selected_option;

    while (1)
    {
        printline();
        printf(
            "PROFESSOR DASHBOARD\n"
            "1. View My Profile\n"
            "2. Logout\n"
        );
        printline();

        printf("Enter Index: ");
        scanf("%d", &selected_option);
        while (getchar() != '\n');   // clear input buffer

        switch (selected_option)
        {
        case 1:
            view_professor_profile();
            break;

        case 2:
            return;   // logout → back to main menu

        default:
            printf("Invalid option\n");
        }
    }
}

/* ================= VIEW PROFESSOR PROFILE ================= */
void view_professor_profile(void)
{
    char professor_id[50];
    char id[50], name[100], branch[50], designation[100];
    char line[256];
    int found = 0;

    FILE *fp = fopen("professor.txt", "r");
    if (fp == NULL)
    {
        printf("Error: professor.txt not found\n");
        printf("Press Enter to return...");
        getchar();
        return;
    }

    printf("Enter Professor ID (e.g. P1401): ");
    scanf("%49s", professor_id);
    while (getchar() != '\n');

    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%49s %99s %49s %99s",
                   id, name, branch, designation) == 4)
        {
            if (strcmp(id, professor_id) == 0)
            {
                printf("\n--- PROFESSOR PROFILE ---\n");
                printf("ID          : %s\n", id);
                printf("Name        : %s\n", name);
                printf("Branch      : %s\n", branch);
                printf("Designation : %s\n", designation);
                found = 1;
                break;
            }
        }
    }

    if (!found)
    {
        printf("\nProfessor not found\n");
    }

    fclose(fp);

    printf("\nPress Enter to return to dashboard...");
    getchar();
}
