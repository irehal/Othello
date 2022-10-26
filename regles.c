#include "prototypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int case_valide(int ligne,int colonne)
{

    if((ligne<0) || (ligne>=8) || (colonne<0) || (colonne>=8)  )
            return 0;
    return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int coup_valide(int ligne,int colonne,char m[N][N],int joueur)
{   ligne=ligne-1;
    if(!case_valide(ligne,colonne) || (m[ligne][colonne]!=' '))
        return 0;
    char cj='B',ca='N';
    int i,j,test=0;
    if(joueur==1)
    {
        cj='N';
        ca='B';
    }
    ///tester sur la colonne
    for(i=ligne+1;case_valide(i,colonne) && m[i][colonne]==ca;i++)
        test=1;
    if(case_valide(i,colonne)&& test && m[i][colonne]==cj)
        return 1;
    for(test=0,i=ligne-1;case_valide(i,colonne)&&m[i][colonne]==ca;i--)
        test=1;
    if(case_valide(i,colonne)&&test&&m[i][colonne]==cj)
        return 1;
    ///tester sur ligne
    for(test=0,j=colonne+1;case_valide(ligne,j)&&m[ligne][j]==ca;j++)
        test=1;
    if(case_valide(ligne,j)&&test&&m[ligne][j]==cj)
        return 1;
    for(test=0,j=colonne-1;case_valide(ligne,j)&&m[ligne][j]==ca;j--)
        test=1;
    if(case_valide(ligne,j)&&test&&m[ligne][j]==cj)
        return 1;
    ///diag en haut à droite
    for(test=0,i=ligne+1,j=colonne-1;case_valide(i,j)&&m[i][j]==ca;i++,j--)
        test=1;
    if(case_valide(i,j)&&test&&m[i][j]==cj)
        return 1;
    ///diag en haut à gauche
    for(test=0,i=ligne+1,j=colonne+1;case_valide(i,j)&&m[i][j]==ca;i++,j++)
        test=1;
    if(case_valide(i,j)&&test&&m[i][j]==cj)
        return 1;
    ///diag en bas a droite
    for(test=0,i=ligne-1,j=colonne-1;case_valide(i,j)&&m[i][j]==ca;i--,j--)
        test=1;
    if(case_valide(i,j)&&test&&m[i][j]==cj)
        return 1;
    ///diag en bas a gauche
    for(test=0,i=ligne-1,j=colonne+1;case_valide(i,j)&&m[i][j]==ca;i--,j++)
        test=1;
    if(case_valide(i,j)&& test &&m[i][j]==cj)
        return 1;
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void jouer_coup(int ligne,int colonne,char m[N][N],int joueur)
{   ligne=ligne-1;
    char cj='B',ca='N';
    int i,j;
    if(joueur==1)
    {
        cj='N';
        ca='B';
    }
    ///sur la colonne
    for(i=ligne-1;case_valide(i,colonne) && m[i][colonne]==ca;i--)
        {}
    if(case_valide(i,colonne)&& m[i][colonne]==cj)
        {

            m[ligne][colonne]=cj;
            for(i=ligne-1;m[i][colonne]==ca;i--)
                m[i][colonne]=cj;
        }
    for(i=ligne+1;case_valide(i,colonne)&&m[i][colonne]==ca;i++)
        {}
    if(case_valide(i,colonne)&&m[i][colonne]==cj)
        {
            m[ligne][colonne]=cj;
            for(i=ligne+1;m[i][colonne]==ca;i++)
                m[i][colonne]=cj;
        }
    ///sur ligne
    for(j=colonne+1;case_valide(ligne,j)&&m[ligne][j]==ca;j++)
        {}
    if(case_valide(ligne,j)&& m[ligne][j]==cj)
        {
            m[ligne][colonne]=cj;
            for(j=colonne+1;m[ligne][j]==ca;j++)
                m[ligne][j]=cj;
        }
    for(j=colonne-1;case_valide(ligne,j)&&m[ligne][j]==ca;j--)
        {}
    if(case_valide(ligne,j)&&m[ligne][j]==cj)
        {
            m[ligne][colonne]=cj;
            for(j=colonne-1;m[ligne][j]==ca;j--)
                {
                    m[ligne][j]=cj;
                }
        }
    ///diag en haut à gauche
    for(i=ligne+1,j=colonne+1;case_valide(i,j)&&m[i][j]==ca;i++,j++)
        {}
    if(case_valide(i,j)&&m[i][j]==cj)
        {
            m[ligne][colonne]=cj;
            for(i=ligne+1,j=colonne+1;m[i][j]==ca;i++,j++)
                m[i][j]=cj;
        }
    ///diag en haut à droite
    for(i=ligne+1,j=colonne-1;case_valide(i,j)&&m[i][j]==ca;i++,j--)
        {}
    if(case_valide(i,j)&&m[i][j]==cj)
        {
            m[ligne][colonne]=cj;
            for(i=ligne+1,j=colonne-1;m[i][j]==ca;i++,j--)
                m[i][j]=cj;
        }
    ///diag en bas a droite
    for(i=ligne-1,j=colonne-1;case_valide(i,j)&&m[i][j]==ca;i--,j--)
        {}
    if(case_valide(i,j)&&m[i][j]==cj)
        {
            m[ligne][colonne]=cj;
            for(i=ligne-1,j=colonne-1;m[i][j]==ca;i--,j--)
                m[i][j]=cj;
        }
    ///diag en bas a gauche
    for(i=ligne-1,j=colonne+1;case_valide(i,j)&&m[i][j]==ca;i--,j++)
        {}
    if(case_valide(i,j)&&m[i][j]==cj)
        {
            m[ligne][colonne]=cj;
            for(i=ligne-1,j=colonne+1;m[i][j]==ca;i--,j++)
                m[i][j]=cj;

       }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// passer la main au joueur suivant...
int suivant(int joueur,char* j1,char* j2,char* j){
    if(strcmp(j,j1)==0)
       strcpy(j,j2);
    else
        strcpy(j,j1);
    if(joueur==1)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int coup_possibles(char m[8][8],int joueur)
{
    int coups=0;
    for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(coup_valide(i,j,m,joueur))
                    coups++;
            }
        }
        return coups;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int fin_partie(char m[8][8]){
    int s=0;
    for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(m[i][j] != ' ')
                    s+=1;
            }
    }
    if(s==64)
        return 1;///la partie est terminée
    if(coup_possibles(m,1) ==0 && coup_possibles(m,2) ==0)
        return 1;///la partie est terminée
    return 0;///la partie n'est pas encore terminée
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int gagnant(char m[8][8])
{
    int nb_B=0,nb_N=0;
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++)
        {
          if(m[i][j]=='N')
                nb_N++;
          else if(m[i][j]=='B')
            nb_B++;
        }
    }
    if(nb_N>nb_B)
        return 1;
    else if(nb_N<nb_B)
        return 2;
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void score(char m[8][8]){

    int nb_B=0,nb_N=0;
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++)
        {
          if(m[i][j]=='N')
                nb_N++;
          else if(m[i][j]=='B')
            nb_B++;
        }

}
printf(" %d pions noirs pour %d pions blancs\n",nb_N,nb_B);
}

