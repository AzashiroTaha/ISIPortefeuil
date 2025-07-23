#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "function.h"
#include "menu.h"

int main()
{
    srandom(time(NULL));
    int choice1;
    char adfile[] = "admin_file.txt", clfile[] = "client_file.txt", accfile[] = "accounts.txt";
    int running = 1;

    do
    {
        choice1 = menu();
        system("clear");

        switch (choice1)
        { // Main menu
        case 1:
        { // CONNEXION CLIENT
            char login[30], passwd[30], hashed[HASH_LENGTH];
            printf("----- SE CONNECTER A VOTRE COMPTE CLIENT -----\n");
            printf("[?]Pseudo: ");
            scanf("%29s", login);
            printf("[?]Mot de passe: ");
            scanf("%29s", passwd);
            hash_password(passwd, hashed);

            int response = clientlog(clfile, login, hashed);

            switch (response)
            {
            case 1:
                CLIENT cl = return_cl(clfile, login, hashed);
                Account acc = return_acc(accfile, cl.tel);
                { // success
                    system("clear");
                    printf("[+]Connexion reussie\n");
                    system("read -p 'Appuyez sur une touche pour continuer'");
                    print_acc(acc);

                    printf("> Bienvenu dans votre espace CLIENT %s %s<\n", cl.pr, cl.nm);
                    printf("---------------------------------------------\n");
                    int back = 1;
                    do
                    {
                        int choice = client_menu();
                        system("clear");

                        switch (choice)
                        {
                        case 1:
                            if (strcmp(acc.status, "Actif") == 0)
                            {
                                printf("Consultation de solde\n");
                                // Ajouter la logique de consultation de solde
                                system("read -p 'Appuyez sur une touche pour continuer'");
                                break;
                            }
                            else
                            {
                                printf(RED "[X]VOTRE COMPTE N'EST PAS ACTIF\n" RESET);
                                break;
                            }
                            break;
                        case 2:
                            if (strcmp(acc.status, "Actif\0") == 0)
                            {
                                checkbalance(cl.tel, accfile);
                                break;
                            }
                            else
                            {
                                printf(RED "[X]VOTRE COMPTE N'EST PAS ACTIF\n" RESET);
                                break;
                            }
                        case 3:
                            if (strcmp(acc.status, "Actif") == 0)
                            {
                                int xaliss;
                                do
                                {
                                    printf("[+]Entrer la somme que vous voulez deposer(FCFA)\n >>");
                                    scanf("%d", &xaliss);
                                } while (xaliss <= 0);
                                get_money(cl.tel, accfile, xaliss);
                                break;
                            }
                            else
                            {
                                printf(RED "[X]VOTRE COMPTE N'EST PAS ACTIF\n" RESET);
                                break;
                            }
                            break;

                        case 4:
                            if (strcmp(acc.status, "Actif") == 0)
                            {
                                // putting some pesos
                                int xaliss;
                                do
                                {
                                    printf("[+]Entrer la somme que vous voulez deposer(FCFA)\n >>");
                                    scanf("%d", &xaliss);
                                } while (xaliss <= 0);
                                put_money(cl.tel, accfile, xaliss);
                                break;
                            }
                            else
                            {
                                printf(RED "[X]VOTRE COMPTE N'EST PAS ACTIF\n" RESET);
                                break;
                            }
                            break;

                        case 5:
                            if (strcmp(acc.status, "Actif") == 0)
                            {
                                char tel_receiver[10];
                                printf("[+]Entrer le numero de telephone du destinataire\n >>");
                                scanf("%9s", tel_receiver);
                                int xaliss;
                                do
                                {
                                    printf("\n[+]Entrer la somme que vous voulez deposer(FCFA)\n >>");
                                    scanf("%d", &xaliss);
                                } while (xaliss <= 0);
                                transfer(acc.tel,tel_receiver,accfile,xaliss);
                                break;
                            }
                            else
                            {
                                printf(RED RED "[X]VOTRE COMPTE N'EST PAS ACTIF\n" RESET RESET);
                                break;
                            }
                            break;
                        case 6:
                            printf(YELLOW "[!]Attention votre compte va etre desactive\n");
                            printf("Appuyez sur Entrée pour continuer...");
                            getchar();

                            disableacc(acc.tel, accfile);
                            print_acc(acc);
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

        case 2:
        { // CONNEXION ADMIN
            char login[30], passwd[30], hashed[HASH_LENGTH];
            printf("----- SE CONNECTER A VOTRE COMPTE ADMIN -----\n");
            printf("[?]Pseudo: ");
            scanf("%29s", login);
            printf("[?]Mot de passe: ");
            scanf("%29s", passwd);
            hash_password(passwd, hashed);

            int response = adminlog(adfile, login, hashed);

            switch (response)
            {
            case 1:
                ADMIN ad = return_ad(adfile, login, hashed);
                { // Connexion réussie
                    system("clear");
                    printf("[+]Connexion reussie\n");
                    system("read -p 'Appuyez sur une touche pour continuer'");

                    printf("> Bienvenu dans votre espace Administrateur %s %s<\n", ad.pr, ad.nm);
                    printf("---------------------------------------------\n");
                    // system("read -p 'Appuyez sur une touche pour continuer'");
                    // system("clear");

                    int back = 1;
                    do
                    {
                        int choice = admin_menu();
                        system("clear");

                        switch (choice)
                        {
                        case 1:
                        {
                            ADMIN ad;
                            newAdmin(adfile, ad);
                            break;
                        }
                        case 2:
                        {
                            CLIENT cl;
                            Account acc;
                            cl = newClient(clfile, cl);
                            acc = getting_account(cl.tel, cl.ID_client, cl);
                            system("read -p 'Appuyez sur une touche pour continuer'");
                            showclient(cl);
                            break;
                        }
                        case 3:
                            char tel_client[10];
                            int amount;
                            printf("[+]Entrer le numero de telephone du client\n >>");
                            scanf("%9s", tel_client);
                            do
                            {
                                printf("\n[+]Entrer le montant\n >");
                                scanf("%d", &amount);
                            } while (amount <= 0);
                            get_money_admin(tel_client, accfile, amount);
                            getchar();
                            break;

                        case 4:
                        {
                            char tel_client[10];
                            int amount;
                            printf("[+]Entrer le numero de telephone du client\n >>");
                            scanf("%9s", tel_client);
                            do
                            {
                                printf("\n[+]Entrer le montant\n >");
                                scanf("%d", &amount);
                            } while (amount <= 0);
                            put_money_admin(tel_client, accfile, amount);
                            printf("Appuyez sur Entrée pour continuer...");
                            getchar();

                            break;
                        }

                        case 5:{
                            char tel_client[10];
                            int amount;
                            printf("[+]Entrer le numero de telephone du client\n >>");
                            scanf("%9s", tel_client);
                            do
                            {
                                printf("\n[+]Entrer le montant\n >");
                                scanf("%d", &amount);
                            } while (amount <= 0);
                            get_money_admin(tel_client, accfile, amount);
                            getchar();
                            break;
                        }
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

        case 3:
        { // INSCRIPTION
            system("clear");
            printf(">>  Bienvenu dans votre espace Inscription <<\n");
            printf("---------------------------------------------\n");
            system("read -p 'Appuyez sur une touche pour continuer'");
            system("clear");

            CLIENT cl;
            Account acc;
            cl = newClient(clfile, cl);
            acc = getting_account(cl.tel, cl.ID_client, cl);

            // Gérer le résultat de l'inscription
            if (cl.ID_client != -1)
            {
                printf("Inscription réussie !\n");
                system("read -p 'Appuyez sur une touche pour continuer'");
                showclient(cl);
            }
            else
            {
                printf("Erreur lors de l'inscription.\n");
            }
            system("read -p 'Appuyez sur une touche pour continuer'");
            break;
        }

        case 4:
        { // QUITTER
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