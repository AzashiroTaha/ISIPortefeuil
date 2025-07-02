#include<stdio.h>
#include<string.h>
#include"function.h"

//After loging in, Admin_menu
int admin_menu(){
    int choice;
        printf("|=========================================|\n");
        printf("|[1]Creer un compte admin                 |\n");
        printf("|[2]Creer un compte client                |\n");
        printf("|[3]Retrait pour un client                |\n");
        printf("|[4]Depot  pour un client                 |\n");
        printf("|[5]Faire un virement                     |\n");
        printf("|[6]Deconnecter & Quitter                 |\n");
        printf("|=========================================|\n");
        printf(">>>>>");
        scanf("%d", &choice);
        
        return choice;
 }   


/*typedef struct 
{
    char Id[15], pr[20], nm[20], role[20], login[100], passwd[100];
    int age;
}ADMIN;
*/
int auto_id_admin() {
    static int admin_id = 110000; // Initial value
    return admin_id++;
}

//ID yi sonal nagn ma sheuttttt
// int admin_id(char file[]){
//     int last_id, id1, reid;
//     //getting the current id
//     FILE *f = fopen(file, "r");

//     if (f == NULL)
//     {
//         printf("Fichier inexistant!\n");
//     }else{
//         while (fscanf(f,"%d", &last_id) != 0)
//         {
//             id1 = last_id;
//         }
//         fclose(f);
//     }

//     reid = id1+1;
    
//     f = fopen(file, "w");
//     if (f == NULL)
//     {
//         printf("Fichier inexistant!\n");
//     }else
//     {
//         fprintf(f,"%d", reid);
//     }
    
//     return reid;
// }


int admin_id( char file[]) {
    int last_id = 0;
    int reid;

    // Ouvre le fichier en lecture
    FILE *f = fopen(file, "r");
    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", file);
        return -1;
    }

    // Lis le dernier ID (supposé être le seul ou le dernier dans le fichier)
    if (fscanf(f, "%d", &last_id) != 1) {
        printf("Erreur : impossible de lire l'ID dans le fichier %s\n", file);
        fclose(f);
        return -1;
    }
    fclose(f);

    // Incrémente l'ID
    reid = last_id + 1;

    // Ouvre le fichier en écriture pour enregistrer le nouvel ID
    f = fopen(file, "w");
    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s en écriture\n", file);
        return -1;
    }
    fprintf(f, "%d", reid);
    fclose(f);

    return reid;
}

ADMIN getAdmin(){
    ADMIN ad;

    printf("Entrer votre Prenom\n");
    scanf("%s", ad.pr);

    printf("Entrer votre Nom\n");
    scanf("%s", ad.nm);

    printf("Entrer votre Login\n");
    scanf("%s", ad.login);

    printf("Entrer votre mot de passe\n");
    scanf("%s", ad.passwd);

    do {
        printf("Entrer votre age\n");
        scanf("%d", &ad.age);
    } while (ad.age <= 0);

    ad.ID_admin = admin_id("file_admin_id");
    return ad;
}

void newAdmin(char adminfile[], ADMIN ad){
    FILE *f = fopen(adminfile, "a");
    if (f == NULL)
    {
        printf("[X]Il y a eu un souci. Veillez reessayer\n");
    }else{
        ad = getAdmin();
        fprintf(f,"%d %s %s %s %s %d\n", ad.ID_admin,ad.pr, ad.nm, ad.login, ad.passwd, ad.age);
        fclose(f);
    }
    
}

int adminlog(char adminfile[], char login[], char password[]){
    ADMIN ad;
    int found = 0;
    FILE *f = fopen(adminfile, "r");
    if (f == NULL) {
        printf("[X]Il y a eu un souci dans l'ouverture du fichier\n");
    } else {
        while (fscanf(f, "%d %s %s %s %s %d", &ad.ID_admin, ad.pr, ad.nm, ad.login, ad.passwd, &ad.age) == 6) {
            if (strcmp(ad.login, login) == 0 && strcmp(ad.passwd, password) == 0) {
                found = 1;
                break;
            }
        }
        fclose(f);
    }
    return found;
}






