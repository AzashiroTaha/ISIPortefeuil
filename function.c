#include<stdio.h>
#include "function.h"
#include<string.h>
#include "function.h"
#include <stdint.h>
#include <mbedtls/sha256.h>
#include <gcrypt.h>
#include <openssl/sha.h>


int auto_id( char file[]){
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



void hash_password(char password[], char result[]) {
    int len = strlen(password);
    unsigned long hash = 5381;
    
    // Calcul du hash basé sur les caractères clés sans boucle
    hash = hash * 33 + len;  // Facteur longueur
    
    if (len >= 1) hash ^= (unsigned long)password[0] << 8;      // Premier caractère
    if (len >= 2) hash ^= (unsigned long)password[1] << 16;     // Deuxième caractère  
    if (len >= 3) hash ^= (unsigned long)password[len-1] << 24; // Dernier caractère
    if (len >= 4) hash ^= (unsigned long)password[len/2];       // Caractère du milieu
    
    hash *= (len + 1);  // Multiplication finale
    
    sprintf(result, "%016lx", hash);
}


void checkbalance(char num[], char accfile[]){
    Account acc;
    FILE *f = fopen(accfile, "r");
    if (f == NULL) {
        printf("[X]Il y a eu un souci dans l'ouverture du fichier\n");
    } else {
        while (fscanf(f, "%s %s %s %d %.2f %d %s %d %s %s\n", acc.acc_num, acc.type, acc.status, &acc.ceiling, &acc.interest, &acc.balance, acc.creation_date, &acc.ID_client, acc.cl_name, acc.tel) == 10) {
            if (strcmp(acc.tel, num) == 0) {
                printf(GREEN "[+]Votre solde est : %d", acc.balance);
                break;
            }
        }
        fclose(f);
    }
}

void get_money(char num[], char accfile[], int amount){
    Account acc;
    FILE *f = fopen(accfile, "r");
    if (f == NULL) {
        printf("[X]Il y a eu un souci dans l'ouverture du fichier\n");
    } else {
        while (fscanf(f, "%s %s %s %d %.2f %d %s %d %s %s\n", acc.acc_num, acc.type, acc.status, &acc.ceiling, &acc.interest, &acc.balance, acc.creation_date, &acc.ID_client, acc.cl_name, acc.tel) == 10) {
            if (strcmp(acc.tel, num) == 0) {
                if (strcmp(acc.type, "Epargne"))
                {
                    acc.balance = acc.balance + amount;
                }else
                {
                    if ((acc.balance + amount) > acc.ceiling)
                    {
                        printf(RED "[X]Depot impossible! Deplafoner votre Compte\n" RESET);
                    }else
                    acc.balance = acc.balance + amount;
                }
                break;
            }
            fclose(f);
        }
    }
}