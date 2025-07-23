#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#define HASH_LENGTH 17

// menus first
void asciiart();
int menu();
int client_menu();
int admin_menu();
int suscribe();
//END OF MENU

// clean up the buffer
void wipebuffer();




typedef struct 
{
    int j,m,a;
}DATE;


typedef struct
{
    char status[100], type[100], tel[100], acc_num[100], cl_name[100];
    int ceiling, ID_client, balance;
    float interest;
    char creation_date[50];
}Account;

typedef struct 
{
    char  pr[20], nm[20], role[20], login[100], passwd[HASH_LENGTH];
    int ID_admin,age;
}ADMIN;

typedef struct 
{
    char pr[20], nm[20], addresse[100], login[100], passwd[HASH_LENGTH], tel[20];
    DATE datenaiss;
    int ID_client;
}CLIENT;

//generate id
int auto_id( char file[]);

//password hash
void hash_password(char password[], char result[]);


//Admin's functions
ADMIN getAdmin();

void newAdmin(char adminfile[], ADMIN ad);//creer un admin

int adminlog(char filename[], char login[], char password[]);
ADMIN return_ad(char adminfile[], char login[], char passwd[]);
void put_money_admin(char num[], char accfile[], int amount);
void get_money_admin(char num[], char accfile[], int amount);




//Client's functions
CLIENT getClient();
CLIENT newClient(char clientfile[], CLIENT cl);
int check_num(char numero[]);
int unique_num(char file[], char num[]);
int clientlog(char clientfile[], char login[], char password[]);
CLIENT return_cl(char clientfile[], char login[], char password[]);
void showclient(CLIENT cl);


//Shared functions like retrieving money, transfering, putting moyen in a account

void put_money(char num[], char accfile[], int amount);
void checkbalance(char num[], char accfile[]);
void get_money(char num[], char accfile[], int amount);
void transfer(char sender_tel[], char receiver_tel[], char accfile[], int amount);
void disableacc(char num[], char accfile[]);
void edit_info(char num[], char accfile[]);



//Accout part
Account getting_account(char num[], int id_cli, CLIENT cl);
Account return_acc(char accfile[], char num[]);
void print_acc(Account acc);


//COLORING
// Codes couleurs ANSI
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Couleurs vives
#define BRIGHT_BLACK   "\033[90m"  // Gris foncé
#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN    "\033[96m"
#define BRIGHT_WHITE   "\033[97m"

#define BEIGE_CLAIR "\033[38;5;230m"
#define RESET "\033[0m"
#define BRUN_130 "\033[38;5;130m"
#define BRUN_94 "\033[38;5;94m"
#define MARRON_CLAIR1 "\033[38;5;180m"

// Alias pour les gris
#define GRAY       "\033[90m"      // Gris foncé (même que BRIGHT_BLACK)
#define LIGHT_GRAY "\033[37m"      // Gris clair (même que WHITE)
#define DARK_GRAY  "\033[90m"      // Gris foncé

// Couleurs de fond (8 couleurs de base)
#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

// Couleurs de fond vives (codes 100-107)
#define BG_BRIGHT_BLACK   "\033[100m"  // Gris foncé
#define BG_BRIGHT_RED     "\033[101m"
#define BG_BRIGHT_GREEN   "\033[102m"
#define BG_BRIGHT_YELLOW  "\033[103m"
#define BG_BRIGHT_BLUE    "\033[104m"
#define BG_BRIGHT_MAGENTA "\033[105m"
#define BG_BRIGHT_CYAN    "\033[106m"
#define BG_BRIGHT_WHITE   "\033[107m"

// Alias pour les fonds gris
#define BG_GRAY       "\033[100m"  // Fond gris foncé
#define BG_LIGHT_GRAY "\033[47m"   // Fond gris clair

// Styles
#define BOLD      "\033[1m"
#define DIM       "\033[2m"        // Texte atténué
#define ITALIC    "\033[3m"        // Italique (pas supporté partout)
#define UNDERLINE "\033[4m"
#define BLINK     "\033[5m"        // Clignotant (pas supporté partout)
#define REVERSE   "\033[7m"        // Inverse (fond devient texte)
#define STRIKETHROUGH "\033[9m"    // Barré (pas supporté partout)

// Couleurs 256 (exemples courants)
#define ORANGE    "\033[38;5;208m"  // Orange
#define PURPLE    "\033[38;5;135m"  // Violet
#define PINK      "\033[38;5;205m"  // Rose
#define BROWN     "\033[38;5;94m"   // Marron
#define NAVY      "\033[38;5;17m"   // Bleu marine
#define LIME      "\033[38;5;154m"  // Vert lime
#define GOLD      "\033[38;5;220m"  // Or
#define SILVER    "\033[38;5;188m"  // Argent
#define MAROON    "\033[38;5;88m"   // Bordeaux
#define TEAL      "\033[38;5;30m"   // Turquoise
#define OLIVE     "\033[38;5;58m"   // Olive
#define CORAL     "\033[38;5;209m"  // Corail

// Couleurs de fond 256 (exemples)
#define BG_ORANGE "\033[48;5;208m"
#define BG_PURPLE "\033[48;5;135m"
#define BG_PINK   "\033[48;5;205m"
#define BG_BROWN  "\033[48;5;94m"
#define BG_NAVY   "\033[48;5;17m"
#define BG_LIME   "\033[48;5;154m"

// Couleurs RGB (True Color) - exemples
#define RGB_CRIMSON    "\033[38;2;220;20;60m"      // Rouge carmin
#define RGB_FOREST     "\033[38;2;34;139;34m"      // Vert forêt
#define RGB_ROYAL      "\033[38;2;65;105;225m"     // Bleu royal
#define RGB_VIOLET     "\033[38;2;138;43;226m"     // Violet
#define RGB_TURQUOISE  "\033[38;2;64;224;208m"     // Turquoise

// Fonds RGB
#define BG_RGB_CRIMSON "\033[48;2;220;20;60m"
#define BG_RGB_FOREST  "\033[48;2;34;139;34m"




#endif // FONCTION_H_INCLUDED