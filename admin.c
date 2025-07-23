#include <stdio.h>
#include <string.h>
#include "function.h"

// After loging in, Admin_menu
int admin_menu()
{
    int choice;
    printf("|=========================================|\n");
    printf("|[1]Creer un compte AD,OM                 |\n");
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
// int get_current_adminid(char id_adminfile[]);
// int nxt_id(char id_adminfile[]);

int auto_id_admin();
int auto_id_client();
int auto_id_admin()
{
    static int admin_id = 110000; // Initial value
    return admin_id++;
}

// ID yi sonal nagn ma sheuttttt
//  int admin_id(char file[]){
//      int last_id, id1, reid;
//      //getting the current id
//      FILE *f = fopen(file, "r");

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

ADMIN getAdmin()
{
    ADMIN ad;
    char pass[20];

    printf("Entrer votre Prenom\n");
    scanf("%s", ad.pr);

    printf("Entrer votre Nom\n");
    scanf("%s", ad.nm);

    printf("Entrer votre Login\n");
    scanf("%s", ad.login);

    printf("Entrer votre mot de passe\n");
    scanf("%s", pass);
    hash_password(pass, ad.passwd);

    do
    {
        printf("Entrer votre age\n");
        scanf("%d", &ad.age);
    } while (ad.age <= 0);

    ad.ID_admin = auto_id("ids_file");
    return ad;
}

void newAdmin(char adminfile[], ADMIN ad)
{
    FILE *f = fopen(adminfile, "a");
    if (f == NULL)
    {
        printf("[X]Il y a eu un souci. Veillez reessayer\n");
    }
    else
    {
        ad = getAdmin();
        fprintf(f, "%d %s %s %s %s %d\n", ad.ID_admin, ad.pr, ad.nm, ad.login, ad.passwd, ad.age);
        fclose(f);
    }
}

int adminlog(char adminfile[], char login[], char password[])
{
    ADMIN ad;
    int found = 0;
    FILE *f = fopen(adminfile, "r");
    if (f == NULL)
    {
        printf("[X]Il y a eu un souci dans l'ouverture du fichier\n");
    }
    else
    {
        while (fscanf(f, "%d %s %s %s %s %d", &ad.ID_admin, ad.pr, ad.nm, ad.login, ad.passwd, &ad.age) == 6)
        {
            if (strcmp(ad.login, login) == 0 && strcmp(ad.passwd, password) == 0)
            {
                found = 1;
                break;
            }
        }
        fclose(f);
    }
    return found;
}

ADMIN return_ad(char adminfile[], char login[], char password[])
{
    ADMIN ad;
    FILE *f = fopen(adminfile, "r");
    if (f == NULL)
    {
        printf("[X]Il y a eu un souci dans l'ouverture du fichier\n");
    }
    else
    {
        while (fscanf(f, "%d %s %s %s %s %d", &ad.ID_admin, ad.pr, ad.nm, ad.login, ad.passwd, &ad.age) == 6)
        {
            if (strcmp(ad.login, login) == 0 && strcmp(ad.passwd, password) == 0)
            {
                return ad;
                break;
            }
        }
        fclose(f);
    }
    return ad;
}

// admin for client
void put_money_admin(char num[], char accfile[], int amount)
{
    Account acc;
    int found = 0;
    FILE *f = fopen(accfile, "r");
    FILE *tmp = fopen("tmp.txt", "w");

    if (f == NULL || tmp == NULL)
    {
        printf("[X]Erreur d'ouverture du fichier\n");
        return;
    }

    while (fscanf(f, "%s %s %s %d %d %f %d %s %s %s",
                  acc.acc_num, acc.type, acc.status,
                  &acc.ceiling, &acc.balance, &acc.interest,
                  &acc.ID_client, acc.cl_name, acc.tel, acc.creation_date) == 10)
    {

        if (strcmp(acc.tel, num) == 0)
        {
            if (strcmp(acc.status, "Innactif") == 0)
            {
                printf(RED "[X]Le compte %s est inactif\n" RESET, acc.acc_num);
            }
            else if (strcmp(acc.status, "Actif") == 0)
            {
                found = 1;

                if (strcmp(acc.type, "Epargne") == 0)
                {
                    acc.balance += amount;
                    printf(GREEN "[✓] Nouveau solde: %dFCFA\n" RESET, acc.balance);
                }
                else if (strcmp(acc.type, "Courant") == 0)
                {
                    if (acc.balance + amount > acc.ceiling)
                    {
                        printf(RED "[X]Dépôt impossible ! Plafond dépassé.\n" RESET);
                    }
                    else
                    {
                        acc.balance += amount;
                        printf(GREEN "[✓] Nouveau solde: %dFCFA\n" RESET, acc.balance);
                    }
                }
            }
        }

        // Écriture ligne (modifiée ou non)
        fprintf(tmp, "%s %s %s %d %d %.2f %d %s %s %s\n",
                acc.acc_num, acc.type, acc.status,
                acc.ceiling, acc.balance, acc.interest,
                acc.ID_client, acc.cl_name, acc.tel, acc.creation_date);
    }

    fclose(f);
    fclose(tmp);

    if (found)
    {
        remove(accfile);
        rename("tmp.txt", accfile);
    }
    else
    {
        remove("tmp.txt");
        printf(RED "[X]Aucun compte actif trouvé avec ce numéro.\n" RESET);
    }
}

void get_money_admin(char num[], char accfile[], int amount)
{
    Account acc;
    int found = 0;
    FILE *f = fopen(accfile, "r");
    FILE *tmp = fopen("tmp.txt", "w");

    if (f == NULL || tmp == NULL)
    {
        printf("[X]Erreur d'ouverture du fichier\n");
        return;
    }

    while (fscanf(f, "%s %s %s %d %d %f %d %s %s %s",
                  acc.acc_num, acc.type, acc.status,
                  &acc.ceiling, &acc.balance, &acc.interest,
                  &acc.ID_client, acc.cl_name, acc.tel, acc.creation_date) == 10)
    {

        if (strcmp(acc.tel, num) == 0)
        {
            if (strcmp(acc.status, "Innactif") == 0)
            {
                printf(RED "[X]Le compte %s est inactif\n" RESET, acc.acc_num);
            }
            else if (strcmp(acc.status, "Actif") == 0)
            {
                found = 1;

                if ((acc.balance - amount) < 0)
                {
                    printf(RED "[X]Retrait impossible!\n" RESET);
                }
                else
                {
                    acc.balance = acc.balance - amount;
                    printf(GREEN "[✓]Retrait effectue. Nouveau solde: %dFCFA\n" RESET, acc.balance);
                }
            }
        }

        // Écriture ligne (modifiée ou non)
        fprintf(tmp, "%s %s %s %d %d %.2f %d %s %s %s\n",
                acc.acc_num, acc.type, acc.status,
                acc.ceiling, acc.balance, acc.interest,
                acc.ID_client, acc.cl_name, acc.tel, acc.creation_date);
    }

    fclose(f);
    fclose(tmp);

    if (found)
    {
        remove(accfile);
        rename("tmp.txt", accfile);
    }
    else
    {
        remove("tmp.txt");
        printf(RED "[X]Aucun compte actif trouvé avec ce numéro.\n" RESET);
    }
}