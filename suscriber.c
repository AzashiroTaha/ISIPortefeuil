#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "function.h"
#include<time.h>



// suscribe_menu
int suscribe(){
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
/*
typedef struct
{
    char status[20], type[20], tel[20];
    int interest, balance, acc_num, ID_client;
    DATE creation_date;
}Account;
*/


Account getting_account(char num[], int id_cli, CLIENT cl){
    Account acc;
    system("clear");
    system("read -p 'Appuyez sur une touche pour continuer'");
    printf("\t\t\t\t\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("\t\t\t\t\t\t\t\t\t|~~~~~~~~~~~~ VOTRE PORTE FEUILLE ~~~~~~~~~~~~|\n");
    printf("\t\t\t\t\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");

    // account number
    unsigned long long acc_num_gen = 100000000000000ULL + (random() % 900000000000000ULL);
    sprintf(acc.acc_num, "%s*%llu", cl.pr, acc_num_gen);
    // the account type
    printf("++++++++++++++++++++++++++++++++++++++++\n");
    printf("++++++++++++ TYPE DE COMPTE ++++++++++++\n");
    printf("++++++++++++++++++++++++++++++++++++++++\n");

    int type;
    do
    {
        printf("[1]Courant\n");
        printf("[2]Epargne\n");
        scanf("%d", &type);
    } while (type < 1 || type > 2);

    if (type == 1)
    {
        strcpy(acc.type, "Courant");
        acc.ceiling = 2000000;
        acc.interest = 0;
    }else
    {
        strcpy(acc.type, "Epargne");
        acc.ceiling = 0;
        acc.interest = 0.4;
    }
    
    strcpy(acc.status, "Actif");
    acc.balance = 0;
    time_t current_time;
    time(&current_time);
    sprintf(acc.creation_date, "%s", ctime(&current_time));

    // Enregistrement dans un fichier
    FILE *f = fopen("accounts.txt", "a");
    if (f != NULL) {
        fprintf(f, "%s %s %s %d %d %s %d %s/n", acc.acc_num, acc.type, acc.status, acc.ceiling, acc.balance, acc.creation_date, acc.ID_client, cl.pr);
        fclose(f);
    } else {
        printf("[X]Erreur lors de l'ouverture du fichier accounts.txt\n");
    }

    return acc;
}