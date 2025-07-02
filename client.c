#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"function.h"


//After login, client_menu
int client_menu(){
    int choice;
        printf(">>>>>>>>>>> CONNEXION REUSSIE <<<<<<<<<<<<|\n");
        printf("\n");
        // system("read -p 'Appuyez sur une touche pour continuer'");
        // system("clear");
        printf("|=========================================|\n");
        printf("|[1]Modifier Informations                 |\n");
        printf("|[2]Consulter mon solde                   |\n");
        printf("|[3]Retrait                               |\n");
        printf("|[4]Depot                                 |\n");
        printf("|[5]Virement                              |\n");
        printf("|[6]Desactiver mon compte                 |\n");
        printf("|[7]Deconnecter & Quitter                 |\n");
        printf("|=========================================|\n");
        printf(">>");
        scanf("%d", &choice);
        return  choice;
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
    void wipebuffer();
    fgets(cl.pr, sizeof(cl.pr), stdin);
    printf("Entrer votre Nom\n");
    void wipebuffer();
    fgets(cl.nm, sizeof(cl.nm ), stdin);
    printf("Entrer votre adresse\n");
    void wipebuffer();
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
    void wipebuffer();
    printf("Entrer votre mot de passe\n");
    void wipebuffer();
    fgets(cl.passwd, sizeof(cl.passwd), stdin);
}

void newClient(char cl_file[], CLIENT cl){
      FILE *f = fopen(cl_file, "a");
    if (f == NULL)
    {
        printf("[X]Il y a eu un souci. Veillez reessayer\n");
    }else{
        cl = getClient();
        fprintf(f,"%d %s %s %s %s %d/%d/%d\n", cl.ID_client,cl.pr, cl.nm, cl.login, cl.passwd, cl.datenaiss.j, cl.datenaiss.m, cl.datenaiss.a);
        fclose(f);
    }
}