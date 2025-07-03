#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "menu.h"

int main() {
    int choice1;
    char adfile[] = "admin_file.txt", clfile[] = "client_file.txt", accfile[] = "account_file.txt";
    int running = 1;

    do {
        choice1 = menu();
        system("clear");

        switch (choice1) { // Main menu
            case 1: {
                ADMIN ad;
                printf(">>>>> Bienvenu dans votre espace Client <<<<<\n");
                printf("---------------------------------------------\n");
                system("read -p 'Press enter to continue'");
                system("clear");

                int back = 1;
                        do
                        {
                            int choice = client_menu();
                            system("clear");            
                            switch (choice)
                            {
                            case 1:
                                /* code */
                                break;
    
                            case 2:
                                /* code */
                                break;
                            case 3:
                                /* code */
                                break;
    
                            case 4:
                                /* code */
                                break;
    
                            case 5:
                                /* code */
                                break;

                            case 6:
                                /* code */
                                break;
    
                            case 7:
                                back = 0;
                                printf(">>>>> AU REVOIR <<<<<\n");
                                break;
                            
                            default:
                                printf("[X]Option non valide!!\n");
                                printf("\n");
                                break;
                            }
                        } while (back);
                        


                // newAdmin("admin_file.txt", ad);
                // Process finished, back to main menu automatically
                break;
            }
            case 2: { //ADMINNN
                char login[30], passwd[30];
                printf("----- SE CONNECTER A VOTRE COMPTE -----\n");
                printf("[?]Pseudo: ");
                scanf("%30s", login);
                printf("[?]Mot de passe: ");
                scanf("%30s", passwd);

                int response = adminlog("admin_file.txt", login, passwd);

                switch (response) { // Admin authentication
                    case 1:
                        
                        // system("clear");
                        printf("[+]Connexion reussie\n");
                        system("read -p 'Appuyez sur une touche pour continuer'");
                        system("clear");
                        printf("> Bienvenu dans votre espace Administrateur <\n");
                        printf("---------------------------------------------\n");
                        system("read -p 'Appuyez sur une touche pour continuer'");
                        system("clear");

                        int back = 1;
                        do
                        {   
                            
                            int choice = admin_menu();
                            system("clear");            
                            switch (choice)
                            {
                            case 1:
                                ADMIN ad;
                                newAdmin(adfile, ad);
                                break;
                            case 2:
                                CLIENT cl;
                                newClient(clfile, cl);
                                break;
                            case 3:
                                printf("Faire un retrait\n");
                                break;
    
                            case 4:
                                 printf("Faire un DEpot\n");
                                break;
    
                            case 5:
                                 printf("Faire un VIrement\n");
                                break;
    
                            case 6:
                                back = 0;
                                printf(">>>>> AU REVOIR <<<<<\n");
                                break;
                            
                            default:
                            // After finishing, go back to main menu automatically
                            printf("---------------------------------------------\n");
                            printf("Pseudo ou Mot de passe incorrecte\n");
                            break;
                            }
                        } while (back);
                        
                }
                break;
            }
            case 3: { //Suscription
                
                system("clear");
                printf(">>  Bienvenu dans votre espace Inscription <<\n");
                printf("---------------------------------------------\n");
                system("read -p 'Appuyez sur une touche pour continuer'");
                //system("clear");
                int choice3 = suscribe();
                // Process finished, back to main menu automatically
                break;
            }
            case 4: { // Option to exit
                running = 0;
                printf("Merci d'avoir utilisé notre programme. Au revoir!\n");
                break;
            }
            default:
                printf("Cette option n'est pas valide\n");
                break;
        }

    } while (running);

    return 0;
}
