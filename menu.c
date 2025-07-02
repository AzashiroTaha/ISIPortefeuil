#include<stdio.h>
#include<string.h>
#include <stdlib.h>



//Principal MENU
int menu() {
    int choix;
    printf("|=========================================|\n");
    printf("|[1] Connexion Client                     |\n");
    printf("|[2] Connexion Administrateur             |\n");
    printf("|[3] Inscription                          |\n");
    printf("|[4] Quitter                              |\n");
    printf("|=========================================|\n");
    printf(">>>>> ");
    scanf("%d", &choix);
    return choix;
}



// int menu(){
//     int choice;

//     do
//     {
//         printf("\n|=========================================|\n");
//         printf("|[1]Connexion Client                      |\n");
//         printf("|[2]Connexion Administrateur              |\n");
//         printf("|[3]Inscription                           |\n");
//         printf("|=========================================|\n");
//         printf(">>>>>");
//         scanf("%d", &choice);
//         system("clear");
//         if (choice < 1 || choice > 4)
//             printf("\n[X]Attention! Choix %d invalide", choice);
//         system("clear");
//     } while (choice <1 || choice > 3);
    
//     return choice;
// }


void wipebuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
//set IDs automatically


// int get_next_id() {
//     FILE *file;
//     int last_id = 0;
//     int new_id;
    
//     // Lire le dernier ID depuis le fichier
//     file = fopen("last_id.txt", "r");
//     if (file != NULL) {
//         fscanf(file, "%d", &last_id);
//         fclose(file);
//     }
    
//     // Calculer le nouvel ID
//     new_id = last_id + 1;
    
//     // Sauvegarder le nouvel ID dans le fichier
//     file = fopen("last_id.txt", "w");
//     if (file != NULL) {
//         fprintf(file, "%d", new_id);
//         fclose(file);
//     }
    
//     return new_id;
// }

// // Fonction pour réinitialiser le compteur
// void reset_id(int start_value) {
//     FILE *file = fopen("last_id.txt", "w");
//     if (file != NULL) {
//         fprintf(file, "%d", start_value);
//         fclose(file);
//     }
// }

// // Fonction pour obtenir l'ID actuel sans l'incrémenter
// int get_current_id() {
//     FILE *file;
//     int current_id = 0;
    
//     file = fopen("last_id.txt", "r");
//     if (file != NULL) {
//         fscanf(file, "%d", &current_id);
//         fclose(file);
//     }
    
//     return current_id;
// }

