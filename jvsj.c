#include "prototypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>


void jvsj(){
	char tab[8][8];
    int l,ic;
    char c;
    int joueur=1;
	pos_init(tab);
	system("cls");
	setcolor(15,0);
	char j1[9],j2[9],j[9];
	int a;
	printf("entrer le nom du premier joueur\n");
	scanf("%s",&j1);
	printf("entrer le nom du deuxieme joueur\n");
	scanf("%s",&j2);
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
        }
 	puts("appuyer sur une touche pour commencer:");
    getch();
    system("cls");
    setcolor(2,0);
    while(!fin_partie(tab))
    {
        do{
        system("cls");
        grille(tab);
        printf("\n\n\nA vous de jouer:%s\n",j);
        printf("donner la ligne:");
        fflush(stdin);
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
        }while(!coup_valide(l,ic,tab,joueur));
        jouer_coup(l,ic,tab,joueur);
        if(coup_possibles(tab,3-joueur) > 0)
            joueur=suivant(joueur,j1,j2,j);
    }
    system("cls");
    grille(tab);
    getch();
    system("cls");
    score(tab);
    if(a==1)
    {
        if(gagnant(tab)==1)
            printf("Felicitations %s vous avez gagne!",j1);
        else if(gagnant(tab)==2)
            printf("Felicitations %s vous avez gagne!",j2);
        else
            printf("Egalite!");
    }
    else{
        if(gagnant(tab)==1)
            printf("Felicitations %s!",j2);
        else if(gagnant(tab)==2)
            printf("Felicitations %s!",j1);
        else
            printf("Egalite!");
    system("cls");
    bienvenue();
    init();
    gestion();
    }
}
