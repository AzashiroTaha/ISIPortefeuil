#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"
#include "menu.h"

int main() {
    srandom(time(NULL));
    int choice1;
    char adfile[] = "admin_file.txt", clfile[] = "client_file.txt", accfile[] = "account_file.txt";
    int running = 1;
    
    do {
        choice1 = menu();
        system("clear");
        
        switch (choice1) { // Main menu
            case 1: { // CONNEXION CLIENT
                char login[30], passwd[30];
                printf("----- SE CONNECTER A VOTRE COMPTE CLIENT -----\n");
                printf("[?]Pseudo: ");
                scanf("%29s", login);
                printf("[?]Mot de passe: ");
                scanf("%29s", passwd);
                
                  
                // Vérifier les identifiants du client
                //int response = clientlog(clfile, login, passwd); // Assumant qu'une fonction clientlog existe
                
                // if (response == 1) {
                //     printf("[+]Connexion reussie\n");
                //     system("read -p 'Appuyez sur une touche pour continuer'");
                //     system("clear");
                    
                //     printf(">>>>> Bienvenu dans votre espace Client <<<<<\n");
                //     printf("---------------------------------------------\n");
                //     system("read -p 'Appuyez sur une touche pour continuer'");
                //     system("clear");
                    
                    int back = 1;
                    do {
                        int choice = client_menu();
                        system("clear");
                        
                        switch (choice) {
                            case 1:
                                printf("Consultation de solde\n");
                                // Ajouter la logique de consultation de solde
                                system("read -p 'Appuyez sur une touche pour continuer'");
                                break;
                                
                            case 2:
                                printf("Faire un retrait\n");
                                // Ajouter la logique de retrait
                                system("read -p 'Appuyez sur une touche pour continuer'");
                                break;
                                
                            case 3:
                                printf("Faire un depot\n");
                                // Ajouter la logique de dépôt
                                system("read -p 'Appuyez sur une touche pour continuer'");
                                break;
                                
                            case 4:
                                printf("Faire un virement\n");
                                // Ajouter la logique de virement
                                system("read -p 'Appuyez sur une touche pour continuer'");
                                break;
                                
                            case 5:
                                printf("Historique des transactions\n");
                                // Ajouter la logique d'historique
                                system("read -p 'Appuyez sur une touche pour continuer'");
                                break;
                                
                            case 6:
                                printf("Modifier profil\n");
                                // Ajouter la logique de modification de profil
                                system("read -p 'Appuyez sur une touche pour continuer'");
                                break;
                                
                            case 7:
                                back = 0;
                                printf(">>>>> AU REVOIR <<<<<\n");
                                break;
                                
                            default:
                                printf("[X]Option non valide!!\n");
                                system("read -p 'Appuyez sur une touche pour continuer'");
                                break;
                        }
                    } while (back);
                // } else {s
                //     printf("---------------------------------------------\n");
                //     printf("Pseudo ou Mot de passe incorrecte\n");
                //     system("read -p 'Appuyez sur une touche pour continuer'");
                // }
                // break;
            }
            
            case 2: { // CONNEXION ADMIN
                char login[30], passwd[30];
                printf("----- SE CONNECTER A VOTRE COMPTE ADMIN -----\n");
                printf("[?]Pseudo: ");
                scanf("%29s", login);
                printf("[?]Mot de passe: ");
                scanf("%29s", passwd);
                
                int response = adminlog(adfile, login, passwd);
                
                switch (response) {
                    case 1: { // Connexion réussie
                        printf("[+]Connexion reussie\n");
                        system("read -p 'Appuyez sur une touche pour continuer'");
                        system("clear");
                        
                        printf("> Bienvenu dans votre espace Administrateur <\n");
                        printf("---------------------------------------------\n");
                        system("read -p 'Appuyez sur une touche pour continuer'");
                        system("clear");
                        
                        int back = 1;
                        do {
                            int choice = admin_menu();
                            system("clear");
                            
                            switch (choice) {
                                case 1: {
                                    ADMIN ad;
                                    newAdmin(adfile, ad);
                                    break;
                                }
                                case 2: {
                                    CLIENT cl;
                                    Account acc;
                                    cl = newClient(clfile, cl);
                                    acc = getting_account(cl.tel,cl.ID_client,cl);
                                    break;
                                }
                                case 3:
                                    printf("Faire un retrait (Admin)\n");
                                    // Ajouter la logique pour le retrait admin
                                    system("read -p 'Appuyez sur une touche pour continuer'");
                                    break;
                                    
                                case 4:
                                    printf("Faire un depot (Admin)\n");
                                    // Ajouter la logique pour le dépôt admin
                                    system("read -p 'Appuyez sur une touche pour continuer'");
                                    break;
                                    
                                case 5:
                                    printf("Faire un virement (Admin)\n");
                                    // Ajouter la logique pour le virement admin
                                    system("read -p 'Appuyez sur une touche pour continuer'");
                                    break;
                                    
                                case 6:
                                    back = 0;
                                    printf(">>>>> AU REVOIR <<<<<\n");
                                    break;
                                    
                                default:
                                    printf("Choix invalide. Veuillez réessayer.\n");
                                    system("read -p 'Appuyez sur une touche pour continuer'");
                                    break;
                            }
                        } while (back);
                        break;
                    }
                    case 0: // Connexion échouée
                        printf("---------------------------------------------\n");
                        printf("Pseudo ou Mot de passe incorrecte\n");
                        system("read -p 'Appuyez sur une touche pour continuer'");
                        break;
                        
                    default:
                        printf("Erreur de connexion\n");
                        system("read -p 'Appuyez sur une touche pour continuer'");
                        break;
                }
                break;
            }
            
            case 3: { // INSCRIPTION
                system("clear");
                printf(">>  Bienvenu dans votre espace Inscription <<\n");
                printf("---------------------------------------------\n");
                system("read -p 'Appuyez sur une touche pour continuer'");
                system("clear");
                
                CLIENT cl;
                Account acc;
                cl = newClient(clfile, cl);
                acc = getting_account(cl.tel,cl.ID_client,cl);
                
                // Gérer le résultat de l'inscription
                if () {
                    printf("Inscription réussie !\n");
                } else {
                    printf("Erreur lors de l'inscription.\n");
                }
                system("read -p 'Appuyez sur une touche pour continuer'");
                break;
            }
            
            case 4: { // QUITTER
                running = 0;
                printf("Merci d'avoir utilisé notre programme. Au revoir!\n");
                break;
            }
            
            default:
                printf("Cette option n'est pas valide\n");
                system("read -p 'Appuyez sur une touche pour continuer'");
                break;
        }
        
    } while (running);
    
    return 0;
}