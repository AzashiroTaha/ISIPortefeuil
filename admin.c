#include<stdio.h>
#include<string.h>
#include"function.h"

//After loging in, Admin_menu
int admin_menu(){
    int choice;
    do
    {
        printf("|=========================================|\n");
        printf("|[1]Creer un compte admin                 |\n");
        printf("|[2]Creer un compte client                |\n");
        printf("|[3]Retrait pour un client                |\n");
        printf("|[4]Depot  pour un client                 |\n");
        printf("|[5]Faire un virement                     |\n");
        printf("|[6]Deconnexion                           |\n");
        printf("|=========================================|\n");
        printf(">>");
        scanf("%d", &choice);
    } while (choice < 1 || choice >6);
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

ADMIN getAdmin(){
    ADMIN ad;
    ad.ID_admin = auto_id_admin();

    printf("Entrer votre Prenom\n");
    scanf("%19s", ad.pr);

    printf("Entrer votre Nom\n");
    scanf("%19s", ad.nm);

    printf("Entrer votre Login\n");
    scanf("%99s", ad.login);

    printf("Entrer votre mot de passe\n");
    scanf("%99s", ad.passwd);

    do {
        printf("Entrer votre age\n");
        scanf("%d", &ad.age);
    } while (ad.age <= 0);

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




