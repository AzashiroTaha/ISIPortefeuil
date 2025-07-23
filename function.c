#include <stdio.h>
#include "function.h"
#include <string.h>
#include "function.h"
#include <stdint.h>
#include <mbedtls/sha256.h>
#include <gcrypt.h>
#include <openssl/sha.h>

int auto_id(char file[])
{
    int last_id = 0;
    int reid;

    // Ouvre le fichier en lecture
    FILE *f = fopen(file, "r");
    if (f == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", file);
        return -1;
    }

    // Lis le dernier ID (supposé être le seul ou le dernier dans le fichier)
    if (fscanf(f, "%d", &last_id) != 1)
    {
        printf("Erreur : impossible de lire l'ID dans le fichier %s\n", file);
        fclose(f);
        return -1;
    }
    fclose(f);

    // Incrémente l'ID
    reid = last_id + 1;

    // Ouvre le fichier en écriture pour enregistrer le nouvel ID
    f = fopen(file, "w");
    if (f == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier %s en écriture\n", file);
        return -1;
    }
    fprintf(f, "%d", reid);
    fclose(f);

    return reid;
}

void hash_password(char password[], char result[])
{
    int len = strlen(password);
    unsigned long hash = 5381;

    // Calcul du hash basé sur les caractères clés sans boucle
    hash = hash * 33 + len; // Facteur longueur

    if (len >= 1)
        hash ^= (unsigned long)password[0] << 8; // Premier caractère
    if (len >= 2)
        hash ^= (unsigned long)password[1] << 16; // Deuxième caractère
    if (len >= 3)
        hash ^= (unsigned long)password[len - 1] << 24; // Dernier caractère
    if (len >= 4)
        hash ^= (unsigned long)password[len / 2]; // Caractère du milieu

    hash *= (len + 1); // Multiplication finale

    sprintf(result, "%016lx", hash);
}

// disable accounte
void disableacc(char num[], char accfile[])
{
    Account acc;
    int found = 0;
    FILE *f = fopen(accfile, "r");
    FILE *tmp = fopen("tmp.txt", "w");
    if (f == NULL || tmp == NULL)
    {
        printf("[X]Il y a eu un souci dans l'ouverture du fichier\n");
    }
    else
    {
        while (fscanf(f, "%s %s %s %d %d %f %d %s %s %s", acc.acc_num, acc.type, acc.status, &acc.ceiling, &acc.balance, &acc.interest, &acc.ID_client, acc.cl_name, acc.tel, acc.creation_date) == 10)
        {
            if (strcmp(acc.tel, num) == 0)
            {
                found = 1;
                if (strcmp(acc.status, "Actif") == 0)
                {
                    strcpy(acc.status, "Innactif");
                    printf(GREEN "[✓]Votre compte a ete desactive avec succes\n" RESET);
                }
                else
                {
                    printf(GOLD "\n[!]Votre compte a deja ete desactive avec succes au paravant\n" RESET);
                }
            }
            // saving it to in the account file!
            fprintf(tmp, "%s %s %s %d %d %.2f %d %s %s %s\n", acc.acc_num, acc.type, acc.status, acc.ceiling, acc.balance, acc.interest, acc.ID_client, acc.cl_name, acc.tel, acc.creation_date);
        }
        fclose(f);
        fclose(tmp);

        if (found == 1)
        {
            remove(accfile);
            rename("tmp.txt", accfile);
        }
        else
        {
            remove("tmp.txt");
            printf(RED "[X]Aucun compte avec ce numéro trouvé.\n" RESET);
        }
    }
}

void checkbalance(char num[], char accfile[])
{
    Account acc;
    FILE *f = fopen(accfile, "r");
    if (f == NULL)
    {
        printf("[X]Il y a eu un souci dans l'ouverture du fichier\n");
    }
    else
    {
        while (fscanf(f, "%s %s %s %d %d %f %d %s %s %s", acc.acc_num, acc.type, acc.status, &acc.ceiling, &acc.balance, &acc.interest, &acc.ID_client, acc.cl_name, acc.tel, acc.creation_date) == 10)
        {
            if (strcmp(acc.tel, num) == 0)
            {
                printf(GREEN "[+]Votre solde est : %dFCFA\n" RESET, acc.balance);
                break;
            }
        }
        fclose(f);
    }
}

void put_money(char num[], char accfile[], int amount)
{
    Account acc;
    int found = 0;
    FILE *f = fopen(accfile, "r");
    FILE *tmp = fopen("tmp.txt", "w");
    if (f == NULL || tmp == NULL)
    {
        printf("[X]Il y a eu un souci dans l'ouverture du fichier\n");
    }
    else
    {
        while (fscanf(f, "%s %s %s %d %d %f %d %s %s %s", acc.acc_num, acc.type, acc.status, &acc.ceiling, &acc.balance, &acc.interest, &acc.ID_client, acc.cl_name, acc.tel, acc.creation_date) == 10)
        {
            if (strcmp(acc.tel, num) == 0)
            {
                found = 1;
                if (strcmp(acc.type, "Epargne") == 0)
                {
                    acc.balance = acc.balance + amount;
                    printf(GREEN "[✓] Nouveau solde: %dFCFA\n" RESET, acc.balance);
                }
                else if (strcmp(acc.type, "Courant") == 0)
                {
                    if ((acc.balance + amount) > acc.ceiling)
                    {
                        printf(RED "[X]Depot impossible! Deplafoner votre Compte\n" RESET);
                    }
                    else if ((acc.balance + amount) <= acc.ceiling)
                    {
                        acc.balance = acc.balance + amount;
                        printf(GREEN "[✓] Nouveau solde: %dFCFA\n" RESET, acc.balance);
                    }
                }
            }
            // saving it to in the account file!
            fprintf(tmp, "%s %s %s %d %d %.2f %d %s %s %s\n", acc.acc_num, acc.type, acc.status, acc.ceiling, acc.balance, acc.interest, acc.ID_client, acc.cl_name, acc.tel, acc.creation_date);
        }
        fclose(f);
        fclose(tmp);

        if (found == 1)
        {
            remove(accfile);
            rename("tmp.txt", accfile);
        }
        else
        {
            remove("tmp.txt");
            printf(RED "[X]Aucun compte avec ce numéro trouvé.\n" RESET);
        }
    }
}

void get_money(char num[], char accfile[], int amount)
{
    Account acc;
    int found = 0;
    FILE *f = fopen(accfile, "r");
    FILE *tmp = fopen("tmp.txt", "w");
    if (f == NULL || tmp == NULL)
    {
        printf("[X]Il y a eu un souci dans l'ouverture du fichier\n");
    }
    else
    {
        while (fscanf(f, "%s %s %s %d %d %f %d %s %s %s", acc.acc_num, acc.type, acc.status, &acc.ceiling, &acc.balance, &acc.interest, &acc.ID_client, acc.cl_name, acc.tel, acc.creation_date) == 10)
        {
            if (strcmp(acc.tel, num) == 0)
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
            // saving it to in the account file!
            fprintf(tmp, "%s %s %s %d %d %.2f %d %s %s %s\n", acc.acc_num, acc.type, acc.status, acc.ceiling, acc.balance, acc.interest, acc.ID_client, acc.cl_name, acc.tel, acc.creation_date);
        }
        fclose(f);
        fclose(tmp);

        if (found == 1)
        {
            remove(accfile);
            rename("tmp.txt", accfile);
        }
        else
        {
            remove("tmp.txt");
            printf(RED "[X]Aucun compte avec ce numéro trouvé.\n" RESET);
        }
    }
}

void transfer(char sender_tel[], char receiver_tel[], char accfile[], int amount)
{
    Account acc;
    int sender_found = 0, receiver_found = 0;
    Account sender, receiver;

    FILE *f = fopen(accfile, "r");
    FILE *tmp = fopen("tmp.txt", "w");

    if (f == NULL || tmp == NULL)
    {
        printf("[X]Erreur d'ouverture du fichier.\n");
        return;
    }

    // Étape 1 : lire les comptes et capturer sender + receiver
    while (fscanf(f, "%s %s %s %d %d %f %d %s %s %s", acc.acc_num, acc.type, acc.status, &acc.ceiling, &acc.balance, &acc.interest, &acc.ID_client, acc.cl_name, acc.tel, acc.creation_date) == 10)
    {

        if (strcmp(acc.tel, sender_tel) == 0 && strcmp(acc.status, "Actif") == 0)
        {
            sender = acc;
            sender_found = 1;
        }

        if (strcmp(acc.tel, receiver_tel) == 0 && strcmp(acc.status, "Actif") == 0)
        {
            receiver = acc;
            receiver_found = 1;
        }
    }

    fclose(f);

    // Vérifications
    if (!sender_found)
    {
        printf(RED "[X]Expéditeur introuvable ou inactif.\n" RESET);
        remove("tmp.txt");
        return;
    }
    if (!receiver_found)
    {
        printf(RED "[X]Destinataire introuvable ou inactif.\n" RESET);
        remove("tmp.txt");
        return;
    }
    if (sender.balance < amount)
    {
        printf(RED "[X]Solde insuffisant pour le transfert.\n" RESET);
        remove("tmp.txt");
        return;
    }

    // Transfert
    sender.balance -= amount;

    if (strcmp(receiver.type, "Courant") == 0 && receiver.balance + amount > receiver.ceiling)
    {
        printf(RED "[X]Plafond du destinataire dépassé !\n" RESET);
        remove("tmp.txt");
        return;
    }
    receiver.balance += amount;

    // Réécriture complète avec mise à jour
    f = fopen(accfile, "r");
    while (fscanf(f, "%s %s %s %d %d %f %d %s %s %s", acc.acc_num, acc.type, acc.status, &acc.ceiling, &acc.balance, &acc.interest, &acc.ID_client, acc.cl_name, acc.tel, acc.creation_date) == 10)
    {

        if (strcmp(acc.tel, sender_tel) == 0)
        {
            acc = sender;
        }
        else if (strcmp(acc.tel, receiver_tel) == 0)
        {
            acc = receiver;
        }

        fprintf(tmp, "%s %s %s %d %d %.2f %d %s %s %s\n", acc.acc_num, acc.type, acc.status, acc.ceiling, acc.balance, acc.interest, acc.ID_client, acc.cl_name, acc.tel, acc.creation_date);
    }
    fclose(f);
    fclose(tmp);

    remove(accfile);
    rename("tmp.txt", accfile);

    printf(GREEN "[✓] Transfert de %d FCFA effectué avec succès !\n" RESET, amount);
}

// edit profile
void edit_info(char num[], char accfile[])
{
    Account acc;
    int found = 0;
    FILE *f = fopen(accfile, "r");
    FILE *tmp = fopen("tmp.txt", "w");
    if (f == NULL || tmp == NULL)
    {
        printf("[X]Il y a eu un souci dans l'ouverture du fichier\n");
    }
    else
    {
        while (fscanf(f, "%s %s %s %d %d %f %d %s %s %s", acc.acc_num, acc.type, acc.status, &acc.ceiling, &acc.balance, &acc.interest, &acc.ID_client, acc.cl_name, acc.tel, acc.creation_date) == 10)
        {
            if (strcmp(acc.tel, num) == 0)
            {
                found = 1;
                printf("[-]Votre pre")
            }
            // saving it to in the account file!
            fprintf(tmp, "%s %s %s %d %d %.2f %d %s %s %s\n", acc.acc_num, acc.type, acc.status, acc.ceiling, acc.balance, acc.interest, acc.ID_client, acc.cl_name, acc.tel, acc.creation_date);
        }
        fclose(f);
        fclose(tmp);

        if (found == 1)
        {
            remove(accfile);
            rename("tmp.txt", accfile);
        }
        else
        {
            remove("tmp.txt");
            printf(RED "[X]Aucun compte avec ce numéro trouvé.\n" RESET);
        }
    }
}