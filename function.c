#include<stdio.h>
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



