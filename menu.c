#include<stdio.h>
#include<string.h>
#include <stdlib.h>



//Principal MENU
int menu(){
    int choice;

    do
    {
        printf("|=========================================|\n");
        printf("|[1]Connexion Client                      |\n");
        printf("|[2]Connexion Administrateur              |\n");
        printf("|[3]Inscription                           |\n");
        printf("|=========================================|\n");
        printf(">>>>>");
        scanf("%d", &choice);
        system("read -p 'Press enter to continue'");
    } while (choice <1 || choice > 3);
    
    return choice;
}
