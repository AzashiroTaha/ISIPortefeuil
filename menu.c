#include<stdio.h>
#include<string.h>
#include <stdlib.h>



//Principal MENU
int menu() {
    int choix;
    printf("|=========================================|\n");
    printf("|[1] Connexion Client                     |\n");
    printf("|[2] Connexion Administrateur             |\n");
    printf("|[3] Inscription                          |\n");
    printf("|[4] Quitter                              |\n");
    printf("|=========================================|\n");
    printf(">>>>> ");
    scanf("%d", &choix);
    return choix;
}



void wipebuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
//set IDs automatically
