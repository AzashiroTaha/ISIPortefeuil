#include<stdio.h>
#include<string.h>
#include <stdlib.h>



//Principal MENU
int menu(){
    int choice;

    do
    {
        printf("\n|=========================================|\n");
        printf("|[1]Connexion Client                      |\n");
        printf("|[2]Connexion Administrateur              |\n");
        printf("|[3]Inscription                           |\n");
        printf("|=========================================|\n");
        printf(">>>>>");
        scanf("%d", &choice);
        system("clear");
        if (choice <1 || choice > 3)
            printf("\n[X]Attention! Choix %d invalide", choice);
        system("clear");
    } while (choice <1 || choice > 3);
    
    return choice;
}
