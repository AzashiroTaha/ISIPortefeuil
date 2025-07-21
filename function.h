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
    char status[20], type[20], tel[20], acc_num[20];
    int ceiling, ID_client, balance;
    float interest;
    char creation_date[50];
}Account;

typedef struct 
{
    char  pr[20], nm[20], role[20], login[100], passwd[100];
    int ID_admin,age;
}ADMIN;

typedef struct 
{
    char pr[20], nm[20], addresse[50], login[100], passwd[100], tel[20];
    DATE datenaiss;
    int ID_client;
}CLIENT;

//generate id
int auto_id( char file[]);

//password hash
void md5_to_string(unsigned char *md5_hash, char *output);
void hash_password_md5(const char *password, char *hash_string);


//Admin's functions
ADMIN getAdmin();

void newAdmin(char adminfile[], ADMIN ad);//creer un admin

int adminlog(char filename[], char login[], char password[]);

//Client's functions
CLIENT getClient();
CLIENT newClient(char clientfile[], CLIENT cl);
int check_num(char numero[]);
int unique_num(char file[], char num[]);
CLIENT clientlog(char login[], char password[]);

//Shared functions like retrieving money, transfering, putting moyen in a account

void get_money(int Id_client);
void put_money(int Id_client);
void transfert_money(char numA[], char numB[]);



//Accout part
Account getting_account(char num[], int id_cli, CLIENT cl);


//for the password encryption
#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define EP1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define SIG0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ ((x) >> 3))
#define SIG1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ ((x) >> 10))

void sha256_openssl(const char* input, char* output);
void sha256_custom(const char* input, char* output);


#endif // FONCTION_H_INCLUDED