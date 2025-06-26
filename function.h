#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

// menus first
void asciiart();
int menu();
int client_menu();
int admin_menu();
int suscribe();
//END OF MENU

//choice & redirection
int choix();



typedef struct 
{
    int j,m,a;
}DATE;


typedef struct
{
    char account_name[20], status[20], type[20], tel[9], ID_client[15];
    int interest, balance;
    DATE creation_date;


}Account;

typedef struct 
{
    char Id[15], pr[20], nm[20], role[20], login[100], passwd[100];
    int age;
}ADMIN;

typedef struct 
{
    char ID_client[15], pr[20], nm[20], addresse[50], login[100], passwd[100];
    DATE datenaiss;
    int tel[9];
}CLIENT;

//generate id
int id_counter = 1234;
void setID(char firstname[], char name[]);

//Admin's functions

ADMIN getAdmin();

void newAdmin(char filename[], ADMIN ad);


#endif // FONCTION_H_INCLUDED