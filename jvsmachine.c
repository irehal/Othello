#include "prototypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define Max 32


void enregistrer_partie(char m[8][8])
{
    FILE* f=NULL;
    f=fopen("jeu.txt","r+");
    if(f!=NULL)
    {
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                fprintf(f,"%c\n",m[i][j]);
        fclose(f);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void charger_partie(char m[8][8])
{
    char chaine[2],c;
    FILE* f=NULL;
    f=fopen("jeu.txt","r+");
    if(f!=NULL)
    {
        for(int i=0;i<8;i++)
            {
                for(int j=0;j<8;j++)
                {
                    char c;
                    fscanf(f,"%c",&c);
                    fgets(chaine,2,f);
                    m[i][j]=c;
                }
            }
            fclose(f);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void enregister_joueur(int a){
    FILE* f=NULL;
    f=fopen("joueur.txt","r+");
    if(f!=NULL)
    {
        fprintf(f,"%d\n",a);
        fclose(f);
    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int charger_joueur()
{
    int b;
    FILE* f=NULL;
    f=fopen("joueur.txt","r+");
    if(f!=NULL)
    {
        int b;
        fscanf(f,"%d",&b);
        fclose(f);
        return b;
      }
      return -1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void enregister_niveau(int a){
    FILE* f=NULL;
    f=fopen("niveau.txt","w");
    if(f!=NULL)
    {

       fprintf(f,"%d",a);
       fclose(f);
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int charger_niveau()
{
    int b;
    FILE* f=NULL;
    f=fopen("niveau.txt","r+");
    if(f!=NULL)
    {
        fscanf(f,"%d",&b);
        fclose(f);
        return b;
      }
      return -1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

coup_possible* Cree_coup(int l,int c)
{
    coup_possible* coup=(coup_possible*)malloc(sizeof(coup_possible));
    coup->ligne=l;
    coup->colonne=c;
    coup->suiv=NULL;
    return coup;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

liste_coups* Creeliste()
{
    liste_coups* l=(liste_coups*)malloc(sizeof(liste_coups));
    l->der=NULL;
    l->prem=NULL;
    l->nb_elem=0;
    return l;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int EstVide(liste_coups* l)
{
    return l->prem==NULL?1:0;
}

void ajouter(liste_coups* l,int li,int c)
{
    coup_possible* coup=Cree_coup(li,c);
    if(EstVide(l))
    {
        l->prem=coup;
        l->der=coup;
    }
    else
    {
        coup->suiv=l->prem;
        l->prem=coup;
    }
    l->nb_elem++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int coups(char m[8][8],liste_coups* l,int joueur)
{
    int coups=0;
    for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(coup_valide(i,j,m,joueur))
                    {
                        ajouter(l,i,j);
                        coups++;
                    }
            }
        }
        return coups;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void copier(char src[8][8],char dest[8][8])
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            dest[i][j]=src[i][j];
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int evaluation(char m[8][8],int joueur)
{
    int nb_N=0,nb_B=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(m[i][j]=='B')
                nb_B++;
            if(m[i][j]=='N')
                nb_N++;
        }
    }
    if(joueur==1)
        return nb_N-nb_B;
    return nb_B-nb_N;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void minimax(char m[8][8],int profondeur,int joueur,int j,coup_possible* coup,int* score)
{
    coup_possible co;
    int S;
    int n;
    char temp[8][8];
    liste_coups* l=Creeliste();
    n=coups(m,l,joueur);
    if(n==0)
    {
        if(coup_possibles(m,3-joueur)==0)
        {
            *score=evaluation(m,j);
            return;
        }
    }
    if(joueur==j)
       *score=-Max;
    else
        *score=Max;
    profondeur--;
    coup_possible* e;
    e=l->prem;
    while(e!=NULL)
    {
        copier(m,temp);
        jouer_coup(e->ligne,e->colonne,temp,joueur);
        if(profondeur!=0)
            minimax(temp,profondeur,3-joueur,j,&co,&S);
        else
            S=evaluation(temp,j);
         if (joueur==j)
            { if (S >= *score) {
                *score = S;
                *coup = *e;
            }
            }
       else
       if(S <= *score){
            *score = S;
            *coup=*e;
       }
       e=e->suiv;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void niveau_facile(char m[8][8],int joueur,coup_possible* co)
{
    liste_coups* l=Creeliste();
    int n=coups(m,l,joueur);
    coup_possible* e=l->prem;
    char temp[8][8];
    int S=Max;
    while(e)
    {
        copier(m,temp);
        jouer_coup(e->ligne,e->colonne,temp,joueur);
        if(S >= evaluation(temp,joueur))
        {
            S=evaluation(temp,joueur);
            *co=*e;
        }
        e=e->suiv;
    }
}

void jvsmchine(int niveau_difficulte,int nouv_partie)
{
    int a=1;
    char m[8][8];
    int l,ic;
    char c,q;
    int joueur=1,jou1=1,jou2=2;
	if(nouv_partie==1)
        {
            jou1=charger_joueur();
            jou2=3-jou1;
            if(jou1!=1)
                a=2;
            joueur=jou1;
            pos_init(m);
            charger_partie(m);
        }
    else
        pos_init(m);
	system("cls");
	setcolor(15,0);
	char j1[9],j2[9],j[9];
	strcpy(j2,"machine");
	printf("entrer votre nom:\n");
	scanf("%s",j1);
	strcpy(j,j1);
    if(nouv_partie==0)
    {
        srand(time(NULL));
        a=1+rand()%2;
        if(a==1)

            {
                printf("c'est %s qui va commencer\n",j1);
                strcpy(j,j1);
            }
        else
            {
                printf("c'est %s qui va commencer\n",j2);
                strcpy(j,j2);
                jou1=2;
                jou2=1;
            }
    }
    puts("appuyer sur une touche pour commencer:");
    getch();
    system("cls");
    coup_possible co;
    int S,i=0;
    while(!fin_partie(m))
    {
        if(joueur==jou1)
        {
            do{
                    system("cls");
                    grille(m);
                    if(i!=0)
                        printf("\n\n\nla machine a joue:\n%d %c\n",co.ligne,co.colonne+65);
                    printf("\nA vous de jouer:%s\n",j1);
                    printf("appuyer sur une touche\n(q:quitter):");
                    fflush(stdin);
                    q=(char)getchar();
                    if(q=='q' || q=='Q')///le joueur veut quitter la partie
                    {
                        enregistrer_partie(m);
                        enregister_joueur(jou1);
                        enregister_niveau(niveau_difficulte);
                        system("cls");
                        exit(NULL);
                    }
                    printf("donner la ligne:");
                    scanf("%d",&l);
                    fflush(stdin);
                    printf("donner la colonne:");
                    scanf(" %c",&c);
                    if(c=='A' || c=='a'){ic=0;}
                    else if(c=='B' || c=='b'){ic=1;}
                    else if(c=='C' || c=='c'){ic=2;}
                    else if(c=='D' || c=='d'){ic=3;}
                    else if(c=='E' || c=='e'){ic=4;}
                    else if(c=='F' || c=='f'){ic=5;}
                    else if(c=='G' || c=='g'){ic=6;}
                    else if(c=='H' || c=='h'){ic=7;}
            }while(!coup_valide(l,ic,m,joueur));
        jouer_coup(l,ic,m,joueur);
        }
        else{
            if(niveau_difficulte==0)
                niveau_facile(m,joueur,&co);
            else
                minimax(m,niveau_difficulte,joueur,joueur,&co,&S);
               jouer_coup(co.ligne,co.colonne,m,joueur);
            i++;
        }
        if(coup_possibles(m,suivant(joueur,j1,j2,j))!=0)
            joueur=suivant(joueur,j1,j2,j);
    }
    system("cls");
    grille(m);
    getch();
    system("cls");
    score(m);
    if(a==1)
    {
        if(gagnant(m)==1)
           {
               printf("Felicitations %s!",j1);
           }
        else if(gagnant(m)==2)
            {
                printf("Pas de chance %s a gagne!",j2);
            }
        else
            {
                printf("Egalite!");
            }
    }
    else{
        if(gagnant(m)==1)
            {
                printf("Pas de chance %s a gagne!",j2);
            }
        else if(gagnant(m)==2)
            {
                printf("Felicitations %s!",j1);
            }
        else
            {
                printf("Egalite!");
            }
        getch();
    }
    system("cls");
    bienvenue();
    init();
    gestion();
}

