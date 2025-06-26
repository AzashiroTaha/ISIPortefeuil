#include<stdio.h>
#include<string.h>
#include"function.h"

//After loging in, Admin_menu
void admin_menu(){
    printf("|=========================================|\n");
    printf("|[1]Creer un compte admin                 |\n");
    printf("|[2]Creer un compte client                |\n");
    printf("|[3]Retrait pour un client                |\n");
    printf("|[4]Depot  pour un client                 |\n");
    printf("|[5]Faire un virement                     |\n");
    printf("|[6]Deconnexion                           |\n");
    printf("|=========================================|\n");
}


/*typedef struct 
{
    char Id[15], pr[20], nm[20], role[20], login[100], passwd[100];
    int age;
}ADMIN;
*/

ADMIN getAdmin(){
    ADMIN ad;
    printf("Entrer votre Prenom\n");
    fgets(ad.pr, sizeof(ad.pr), stdin);
    printf("Entrer votre Nom\n");
    fgets(ad.nm, sizeof(ad.nm ), stdin);
    //ID is generated automatically

    printf("Entrer votre Login\n");
    fgets(ad.login, sizeof(ad.login ), stdin);
    printf("Entrer votre mot de passe\n");
    fgets(ad.passwd, sizeof(ad.passwd), stdin);
    do
    {
        printf("Entrer votre age\n");
        scanf("%d", &ad.age);
    } while (ad.age <= 0);
    


    return ad;
}

void newAdmin(char filename[], ADMIN ad){
    FILE *f = fopen(filename, "a");
    if (f = NULL)
    {
        printf("[X]Il y a eu un souci. Veillez reessayer\n");
    }else{
        fprintf(f,"%s %s %s %s %d\n",ad.pr, ad.nm, ad.login, ad.passwd);
        fclose(f);
    }
    
}

int adminlog(char filename[], char login, char password){
    
}
