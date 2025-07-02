#include<stdio.h>





//Le mode r >> Lecture simple le fichier doit exister
//le mode r+ >> Lecture/Ecriture mais le fichier doit forcement exister sinn pas d'ouverture (f == NULL)

//Le mode w >> Ecriture simple le fichier doit exister sinn il le cree et parcontre si le fichier existe il ecrase son contenu
//Le mode w+ >> Ecriture/Lecture et mm chose poppur le mode w pour l'existance du fichier

//Le mode a >> ajout genre c'est comme ecriture mais lui si le fichier existe il n'ecrase pas son contenu
//Le mode a+ >> ajout et lecture c'est lecture et ecriture et si le fichier existe il ne l'ecrase pas aussi sinn il le cree


typedef struct{
  char nm[20], pr[20];
  int age;
}eleve;

eleve scaneleve(){
      eleve E;
      printf("Entrer votre prenom\n");
      scanf("%s", E.pr);
      printf("Entrer votre nom\n");
      scanf("%s", E.nm);
      printf("Entrer votre age\n");
      scanf("%d", &E.age);

      return E;
}

int main(){
    //FILE *f //= fopen("revision.txt", "a");
  //  //verifier si l'ouverture du fichier s'est bien passe
  //  if (f == NULL)
  //  {
  //    printf("Erreur dans l'ouverture du fichier!\n");
  //   }else
  //   {
  //     // eleve E;
  //     // printf("Entrer votre prenom\n");
  //     // scanf("%s", E.pr);
  //     // printf("Entrer votre nom\n");
  //     // scanf("%s", E.nm);
  //     // printf("Entrer votre age\n");
  //     // scanf("%d", &E.age);

  //     eleve E1 = scaneleve();

  //     fprintf(f,"%s %s %d\n", E1.pr,E1.nm,E1.age);
  //     fclose(f);
  //  } 

   FILE *f = fopen("revision.txt", "a+");

   if (f == NULL)
   {
    printf("Erreur dans l'ouverture du fichier!\n");
   }else{
    eleve E2;
    while (fscanf(f,"%s %s %d\n", &E2.pr, &E2.nm, &E2.age) != -1)
    {
       printf("%s %s %d\n" , E2.pr, E2.nm, E2.age);
    }
    fclose(f);
   }
   
   
}


// int main(){
//    FILE *f = fopen("revision.txt", "r");
//    //verifier si l'ouverture du fichier s'est bien passe
//    if (f == NULL)
//    {
//       printf("Erreur dans l'ouverture du fichier!\n");
//    }else
//    {
//     printf("Ouverture du fichier reussie!\n");
//    }
      // fclose(f);
   
// }

