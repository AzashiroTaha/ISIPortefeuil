#include <stdio.h>
#include <stdlib.h>
#include"function.h"
#include"menu.h"

int main(){
   int choice1 = menu();
   char adfile[] = "admin_file.txt", clfile[] = "client_file.txt", accfile[] = "account_file.txt"; 

   system("clear");
   switch (choice1)
   {
   case 1:
    ADMIN ad;
     printf(">>>>> Bienvenu dans votre espace Client <<<<<\n");
     printf("---------------------------------------------\n");
     system("read -p 'Press enter to continue'");


     
     //newAdmin("admin_file.txt",ad);
     break;
   case 2:
          char login[30], passwd[30];
          printf("----- SE CONNECTER A VOTRE COMPTE -----\n");
          printf("Pseudo: \n");
          //fgets(login, sizeof(login), stdin);
          scanf("%30s", login);
          printf("Mot de passe: \n");
          fgets(passwd, sizeof(passwd), stdin);
          //int response = adminlog("admin_file.txt", login, passwd);
          scanf("%30s", passwd);
          int response = adminlog("admin_file.txt",login,passwd);
          switch (response)
          {
              // case 0:
              //   printf("Pseudo ou Mot de passe incorrecte");
              //   break;
              case 1:
                system("clear");
                printf("> Bienvenu dans votre espace Administrateur <\n");
                printf("---------------------------------------------\n");
                system("read 1 -s -r -p 'Appuyez sur une touche pour continuer'");
                system("clear");

                break;
              default:
                printf("---------------------------------------------\n");
                perror("Pseudo ou Mot de passe incorrecte");
                break;
          }
              int stat;

          
     break;
   case 3:
          system("clear");
          printf(">>  Bienvenu dans votre espace Inscription <<\n");
          printf("---------------------------------------------\n");
          system("read 1 -s -r -p 'Appuyez sur une touche pour continuer'");
          system("clear");
          int choice3 = suscribe();
          break;

   
   default:
          printf("Cette option n'est pas valide\n");
            break;
   }
    

}