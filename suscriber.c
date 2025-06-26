#include<stdio.h>
#include<string.h>
#include<stdlib.h>



// suscribe_menu
void suscribe(){
    int choice;
    do
    {
        printf("|=========================================|\n");
        printf("|[1]Creer un client                       |\n");
        printf("|[2]Quitter                               |\n");
        printf("|=========================================|\n");
        printf(">>>>>");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 2);
    
}