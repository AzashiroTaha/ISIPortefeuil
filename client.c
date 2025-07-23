#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "function.h"


//After login, client_menu
int client_menu(){
    int choice;
        printf(">>>>>>>>>>> CONNEXION REUSSIE <<<<<<<<<<<<|\n");
        printf("\n");
        // system("recl -p 'Appuyez sur une touche pour continuer'");
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
    char ID_client, pr[20], nm[20], cldresse[50], login[100], passwd[100];
    DATE datenaiss;
    int tel[9];
}CLIENT;
*/

// Fonction pour vérifier si le numéro est valide (format et opérateur)
int check_num(char numero[]){
    if (strlen(numero) != 9) {
        return 0; // Longueur invalide
    }
    
    // Vérifier que tous les caractères sont des chiffres
    for (int i = 0; i < 9; i++) {
        if (!isdigit(numero[i])) {
            return 0; // Contient des caractères non-numériques
        }
    }

    if ((numero[0] == '7' && numero[1] == '7') ||  // 77
        (numero[0] == '7' && numero[1] == '8') ||  // 78
        (numero[0] == '7' && numero[1] == '6') ||  // 76
        (numero[0] == '7' && numero[1] == '5')) {  // 75
        return 1; 
    }
    
    return 0; 
}

int unique_num(char file[], char num[]){
    FILE *f = fopen(file, "r");
    if (f == NULL) {
        printf(RED "[x]Erreur dans l'ouverture du fichier\n" RESET);
        return 0; // Considérer comme unique si le fichier n'existe pas
    }else
    {
        CLIENT cl;
        while (fscanf(f, "%d %s %s %s %s %s %d/%d/%d\n", 
                      &cl.ID_client, cl.pr, cl.nm, cl.login, 
                      cl.passwd, cl.tel, &cl.datenaiss.j, 
                      &cl.datenaiss.m, &cl.datenaiss.a) == 9) {
            if (strcmp(num, cl.tel) == 0) {
                fclose(f);
                return 1; // Numéro trouvé (pas unique)
            }
        }
    }
    
    
    fclose(f);
    return 0; // Numéro unique
}

CLIENT getClient(){
    CLIENT cl;
    char pass[30];
    printf("Entrer votre Prenom\n");
    scanf("%s", cl.pr);
    printf("Entrer votre Nom\n");
    scanf(" %s", cl.nm);
    printf("Entrer votre clresse\n");
    wipebuffer();
    fgets(cl.addresse, sizeof(cl.addresse ), stdin);
    
    printf(">>>>> Votre date de naissance <<<<<\n");
    do {
        printf("Jour\n>");
        scanf(" %d", &cl.datenaiss.j);
    } while (cl.datenaiss.j < 1 || cl.datenaiss.j > 31);
    
    do {
        printf("Mois\n>");
        scanf(" %d", &cl.datenaiss.m);
    } while (cl.datenaiss.m < 1 || cl.datenaiss.m > 12);
    
    do {
        printf("Annee\n>");
        scanf(" %d", &cl.datenaiss.a);
    } while (cl.datenaiss.a > 2025);
    
    // CORRECTION de la logique de validation du numéro
    int chek, uno;
    do {
        printf("[+]Numero de telephone\n>");
        scanf(" %s", cl.tel);
        
        chek = check_num(cl.tel);
        uno = unique_num("client_file.txt", cl.tel);
        if(chek == 0 || uno == 1)
            printf("[X]Numero Saisie invalide\n");
        
        
    } while (chek == 0 || uno == 1);
    
    printf("[+]Nemuro valide!!\n");
    
    printf("Entrer votre Login\n");
    scanf(" %s", cl.login);
    printf("Entrer votre mot de passe\n");
    scanf(" %s", pass);
    hash_password(pass, cl.passwd);
 
    cl.ID_client = auto_id("ids_file");


    return cl;
}



CLIENT newClient(char cl_file[], CLIENT cl){
    cl.ID_client = -1;
      FILE *f = fopen(cl_file, "a");
    if (f == NULL)
    {
        printf("[X]Il y a eu un souci. Veillez reessayer\n");
    }else{
        cl = getClient();
        fprintf(f,"%d %s %s %s %s %s %s %d/%d/%d \n", cl.ID_client,cl.pr, cl.nm, cl.addresse, cl.login, cl.passwd, cl.tel, cl.datenaiss.j, cl.datenaiss.m, cl.datenaiss.a);
        fclose(f);
    }

    return cl;
}

int clientlog(char clientfile[], char login[], char password[]){
    CLIENT cl;
    int found = 0;
    FILE *f = fopen(clientfile, "r");
    if (f == NULL) {
        printf("[X]Il y a eu un souci dans l'ouverture du fichier\n");
    } else {
        while (fscanf(f,"%d %s %s %s %s %s %s %d/%d/%d \n", &cl.ID_client, cl.pr, cl.nm, cl.addresse, cl.login, cl.passwd, cl.tel, &cl.datenaiss.j, &cl.datenaiss.m, &cl.datenaiss.a) == 10) {
            if (strcmp(cl.login, login) == 0 && strcmp(cl.passwd, password) == 0) {
                found = 1;
                break;
            }
        }
        fclose(f);
    }
    return found;
}

CLIENT return_cl(char clientfile[], char login[], char password[]){
    CLIENT cl;
    FILE *f = fopen(clientfile, "r");
    if (f == NULL) {
        printf("[X]Il y a eu un souci dans l'ouverture du fichier\n");
    } else {
        while (fscanf(f,"%d %s %s %s %s %s %s %d/%d/%d \n", &cl.ID_client, cl.pr, cl.nm, cl.addresse, cl.login, cl.passwd, cl.tel, &cl.datenaiss.j, &cl.datenaiss.m, &cl.datenaiss.a) == 10) {
            if (strcmp(cl.login, login) == 0 && strcmp(cl.passwd, password) == 0) {
                return cl;
                break;
            }
        }
        fclose(f);
    }
    return cl;
}

void showclient(CLIENT cl){
    printf("[+]Prenom : %s\n", cl.pr);
    printf("[+]Nom : %s\n", cl.nm);
    printf("[+]Date de naissance : %d/%d/%d\n", cl.datenaiss.j, cl.datenaiss.m, cl.datenaiss.a);
    printf("[+]Adresse : %s", cl.addresse);
    printf("[+]Numero de telephone : " BRIGHT_CYAN "%s\n" RESET, cl.tel);
    printf("[+]Mot de passe hashe : " LIGHT_GRAY "%s\n" RESET, cl.passwd);
}