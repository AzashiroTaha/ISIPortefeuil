#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

// menus first
void asciiart();
int menu();
int client_menu();
int admin_menu();
int suscribe();
//END OF MENU

// clean up the buffer
void wipebuffer();

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
    char  pr[20], nm[20], role[20], login[100], passwd[100];
    int ID_admin,age;
}ADMIN;

typedef struct 
{
    char pr[20], nm[20], addresse[50], login[100], passwd[100];
    DATE datenaiss;
    int ID_client, tel[9];
}CLIENT;

//generate id
int admin_id(char file[]);

// int get_current_adminid(char id_adminfile[]);
// int nxt_id(char id_adminfile[]);

int auto_id_admin();
int auto_id_client();

//Admin's functions
ADMIN getAdmin();

void newAdmin(char adminfile[], ADMIN ad);//creer un admin

int adminlog(char filename[], char login[], char password[]);

//Client's functions
CLIENT getClient();
void newClient(char clientfile[], CLIENT cl);



#endif // FONCTION_H_INCLUDED