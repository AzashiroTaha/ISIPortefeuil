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


void getting_account(char num, int id_cli, CLIENT cl){
    Account acc;
    system("clear");
    system("read -p 'Appuyez sur une touche pour continuer'");
    printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("|~~~~~~~~~~~~ VOTRE PORTE FEUILLE ~~~~~~~~~~~~|\n");
    printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");

    // account number
    unsigned long long num = 100000000000000 + (random() % 999999999999999);

    sprintf(acc.acc_num, "%s*%llu",cl.pr,num);
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
    
    
    

    
}