#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_LENGTH 17

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

int main(){
    char mon_password[100] = "test";
    char hash_result[17];
    hash_password(mon_password, hash_result);

    printf("%s\n", hash_result);
}