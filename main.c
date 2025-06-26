#include <stdio.h>
#include <stdlib.h>
#include"function.h"
#include"menu.h"

int main(){
   int choice1 = menu();

   system("clear");
   switch (choice1)
   {
   case 1:
     printf(">>>>> Bienvenu dans votre espace Client <<<<<\n");
     printf("---------------------------------------------\n");
     system("read -p 'Press enter to continue'");
     break;
   case 2:
     int stat;
     system("clear");
     printf("> Bienvenu dans votre espace Administrateur <\n");
     printf("---------------------------------------------\n");
     system("read 1 -s -r -p 'Appuyez sur une touche pour continuer'");
     system("clear");

     
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
    break;
   }
    

}