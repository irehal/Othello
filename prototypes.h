#define N 8


typedef struct coup_possible{
    int ligne;
    int colonne;
    struct coup_possible* suiv;
}coup_possible;

typedef struct liste_coups{
    coup_possible* prem;
    coup_possible* der;
    int nb_elem;
}liste_coups;


void setcolor(int couleurDuTexte,int couleurDeFond);
void setcurseur(int x,int y);
void init(void);
void init2(void);
void fen2d(int x,int y,int l,int h,int clf,int clc,int clt, char ch[20],int choix);
void bienvenue(void);
void jouer(void);
void regles_de_jeu(void);
int menuu1(void);
void gestion();
int menuu2(void);
void gestion2();
void retour();
void pos_init(char tab[8][8]);
void grille(char tab[8][8]);
int coup_valide(int ligne,int colonne,char m[N][N],int joueur);
void jouer_coup(int ligne,int colonne,char m[N][N],int joueur);
int coup_possibles(char m[N][N],int joueur);
int fin_partie(char m[8][8]);
int gagnant(char m[8][8]);
void score(char m[8][8]);
int suivant(int joueur,char* j1,char* j2,char* j);
liste_coups* Creeliste();
int coups(char m[8][8],liste_coups* l,int joueur);
//////////////////////////////////////////////////////////////
coup_possible* Cree_coup(int l,int c);
liste_coups* Creeliste();
void minimax(char m[8][8],int profondeur,int joueur,int j,coup_possible* coup,int* score);


