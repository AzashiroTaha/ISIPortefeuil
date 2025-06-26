#include<stdio.h>
#include<string.h>
#include"function.h"


//After login, client_menu
int client_menu(){
    int choice;
    do
    {
        printf("|=========================================|\n");
        printf("|[1]Modifier Informations                 |\n");
        printf("|[2]Consulter mon solde                   |\n");
        printf("|[3]Retrait                               |\n");
        printf("|[4]Depot                                 |\n");
        printf("|[5]Virement                              |\n");
        printf("|[6]Desactiver mon compte                 |\n");
        printf("|=========================================|\n");
        printf(">>");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 7);
}

/*
typedef struct 
{
    char ID_client, pr[20], nm[20], addresse[50], login[100], passwd[100];
    DATE datenaiss;
    int tel[9];
}CLIENT;
*/
 int auto_id_client(){
    static int client_id = 120000; // Initial value
    return client_id++;
}
CLIENT getClient(){
    CLIENT cl;
    cl.ID_client = auto_id_client();
    printf("Entrer votre Prenom\n");
    fgets(cl.pr, sizeof(cl.pr), stdin);
    printf("Entrer votre Nom\n");
    fgets(cl.nm, sizeof(cl.nm ), stdin);
    printf("Entrer votre adresse\n");
    fgets(cl.addresse, sizeof(cl.addresse), stdin);   
    
    printf(">>>>> Votre date de naissance <<<<<");
    do
    {
        printf("Jour\n>");
        scanf("%d", &cl.datenaiss.j);
    } while (cl.datenaiss.j < 1 || cl.datenaiss.j > 31);
    do
    {
        printf("Mois\n>");
        scanf("%d", &cl.datenaiss.m);
    } while (cl.datenaiss.m < 1 || cl.datenaiss.m > 12);
    do
    {
        printf("Annee\n>");
        scanf("%d", &cl.datenaiss.a);
    } while (cl.datenaiss.a > 2025);

        printf("Numero de telephoneahh \n");
        

    printf("Entrer votre Login\n");
    fgets(cl.login, sizeof(cl.login ), stdin);
    printf("Entrer votre mot de passe\n");
    fgets(cl.passwd, sizeof(cl.passwd), stdin);
}

void newClient(FILE clientfile[], CLIENT cl){
    
}