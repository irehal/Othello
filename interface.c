#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include "prototypes.h"
#define RET 13
#define MAX 200
//char tab[8][8];

char *menu1[]={"1.Jouer","2.Regles de jeu","3.Quitter"};
char *menu2[]={"1.J vs J","2.J vs M","3.Retour","4.Quitter"};
char *menu3[]={"1.Nouvelle partie","2.Partie enregistree"};
char *menu4[]={"1.Facile","2.Moyen","3.Difficile"};
int larg,haut,l,h,dx,dy,clf,clc,clt,clf_m,clc_m,clt_m,x0,y0,nbr_tache,nbr_tache2,nbr_tache3;

void setcolor(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setcurseur(int x,int y){ //fonction de positionner le curseur
	COORD pos;
	pos.X=x;
	pos.Y=y;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdOut,pos);
	return;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init(void){
	int k;
	nbr_tache=3;
	x0=45,y0=10;
	dx=2,dy=1;
	l=20,h=3;
	larg=l+(2*dx);
	haut=(nbr_tache*h)+((nbr_tache+1)*dy);
	clc=11,clf=0,clt=13;
	clc_m=14,clf_m=0,clt_m=3;

	fen2d(x0,y0,larg,haut,clf,clc,1,"  ",1);

	for(k=0;k<nbr_tache;k++)
		fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu1[k],1);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init2(void){
	int k;
	nbr_tache2=4;
	x0=45,y0=10;
	dx=2,dy=1;
	l=20,h=3;
	larg=l+(2*dx);
	haut=(nbr_tache2*h)+((nbr_tache2+1)*dy);
	clc=11,clf=0,clt=13;
	clc_m=14,clf_m=0,clt_m=3;

	fen2d(x0,y0,larg,haut,clf,clc,1,"  ",1);

	for(k=0;k<nbr_tache2;k++)
		fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu2[k],1);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init3(void){
	int k;
    nbr_tache3=2;
	x0=45,y0=10;
	dx=2,dy=1;
	l=25,h=3;
	larg=l+(2*dx);
	haut=(nbr_tache3*h)+((nbr_tache3+1)*dy);
	clc=11,clf=0,clt=13;
	clc_m=14,clf_m=0,clt_m=3;

	fen2d(x0,y0,larg,haut,clf,clc,1,"  ",1);

	for(k=0;k<nbr_tache3;k++)
		fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu3[k],1);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init4(void){
	int k;
    nbr_tache3=3;
	x0=45,y0=10;
	dx=2,dy=1;
	l=25,h=3;
	larg=l+(2*dx);
	haut=(nbr_tache3*h)+((nbr_tache3+1)*dy);
	clc=11,clf=0,clt=13;
	clc_m=14,clf_m=0,clt_m=3;

	fen2d(x0,y0,larg,haut,clf,clc,1,"  ",1);

	for(k=0;k<nbr_tache3;k++)
		fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu4[k],1);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void fen1d(int x,int y,int l,int h,int clf,int clc,int clt, char c){
	int i,j,n;
	setcolor(clf,clf);
	for(i=0;i<l;i++){
		for(j=1;j<h;j++){
			setcurseur(x+i,y+j);
			printf(" ");
		}
	}
	setcolor(clc,clf);
	for(i=0;i<l-1;i++){
		setcurseur(x+i,y);
	    printf("%c",205);
		setcurseur(x+i,y+h-1);
	    printf("%c",205);}

	for(j=1;j<h-1;j++){
			setcurseur(x,y+j);
			printf("%c",186);
			setcurseur(x+l-1,y+j);
			printf("%c",186);
		}
	setcurseur(x,y);
	printf("%c",201);
	setcurseur(x,y+h-1);
	printf("%c",200);
	setcurseur(x+l-1,y);
	printf("%c",187);
	setcurseur(x+l-1,y+h-1);
	printf("%c",188);
	setcolor(clt,clf);
	setcurseur(x+(int)((l)/2),y+h/2);
	printf("%c",c);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void fen2d(int x,int y,int l,int h,int clf,int clc,int clt, char ch[20],int choix){
	int i,j,n;
	setcolor(clf,clf);
	for(i=0;i<l;i++){
		for(j=1;j<h;j++){
			setcurseur(x+i,y+j);
			printf(" ");
		}
	}
	setcolor(clc,clf);
	for(i=0;i<l-1;i++){
		setcurseur(x+i,y);
	    printf("%c",205);
		setcurseur(x+i,y+h-1);
	    printf("%c",205);}

	for(j=1;j<h-1;j++){
			setcurseur(x,y+j);
			printf("%c",186);
			setcurseur(x+l-1,y+j);
			printf("%c",186);
		}
	setcurseur(x,y);
	printf("%c",201);
	setcurseur(x,y+h-1);
	printf("%c",200);
	setcurseur(x+l-1,y);
	printf("%c",187);
	setcurseur(x+l-1,y+h-1);
	printf("%c",188);
	setcolor(clt,clf);
	n=strlen(ch);
	switch(choix){
		case 0: setcurseur(x+1,y+1);
		        printf("%s",ch);
		        break;
		case 1: setcurseur(x+(int)((l-n)/2),y+h/2);
		        printf("%s",ch);
				break;
		case 2: setcurseur(x,y+h/2);
		        printf("%s",ch);
				break;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void bienvenue(void){
	setcurseur(0,1);
	setcolor(9,0);
	printf("\n\n");
	printf("                           _/_/    _/_/_/_/  _/    _/   _/_/_/  _/        _/         _/_/                       \n");
	printf("                        _/     _/    _/     _/    _/   _/      _/        _/       _/     _/                     \n");
	printf("                       _/     _/    _/     _/_/_/_/   _/_/_/  _/        _/       _/     _/                      \n");
	printf("                      _/     _/    _/     _/    _/   _/      _/        _/       _/     _/                       \n");
	printf("                        _/_/      _/     _/    _/   _/_/_/  _/_/_/_/  _/_/_/_/    _/_/                          \n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Quitter()
{
    system("cls");
    exit("NULL");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void jouer(void){
	init2();
	gestion2();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////::
void jouer2(void){
    setcolor(1,0);
    system("cls");
    bienvenue();
	init3();
	gestion3();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void jouer3(void){
    setcolor(1,0);
    system("cls");
    bienvenue();
	init4();
	gestion4();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void retour()
{
    setcolor(1,0);
    system("cls");
    bienvenue();
    init();
    gestion();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void regles_de_jeu(void){
    setcolor(0,0);
    system("cls");
    setcolor(4,0);
    FILE* fichier=NULL;
    char chaine[MAX]="";
    fichier = fopen("regles-Othello.txt","r");
    if (fichier != NULL)
    {
        while (fgets(chaine,MAX,fichier) != NULL)
        {
            printf("%s", chaine);
            getch();
        }

        fclose(fichier);
    }
    puts("appuyer sur une touche pour revenir au menu principale:");
    getch();
    system("cls");
    bienvenue();
    init();
    gestion();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pos_init(char tab[8][8]){
	int k,i;
	nbr_tache=3;
	x0=45,y0=10;
	dx=2,dy=1;
	l=20,h=3;
	larg=l+(2*dx);
	haut=(nbr_tache*h)+((nbr_tache+1)*dy);
	clc=10,clf=0,clt=15;
	clc_m=13,clf_m=0,clt_m=11;

	for(k=0;k<8;k++){
        for(i=0;i<8;i++)
			tab[k][i]=' ';
	}
	tab[3][3]='B';
	tab[4][4]='B';
	tab[3][4]='N';
	tab[4][3]='N';
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void grille(char tab[8][8]){
	int k,i,cx,cy,dx=0,dy=0,l=5,h=3,esx=2,esy=1,lt,ht,dx0=30,dy0=5;

	/* dx0 dy0 les positions de la grande fenetre
       l et h largeur et longueur des petites cases vertes
       esx et esy les distances entre la grande fenetre et la petite case
	   dx distance entre deux cases
	   */

	lt=(2*esx)+(8*l)+(9*dx); /// la longueur de la grande fenetre
	ht=(2*esy)+(8*h)+(9*dy); /// la hauteur de la grande fenetre

	fen1d(dx0,dy0,lt,ht,0,13,clt,' ');

	for(cy=0;cy<8;cy++){
		for(cx=0;cx<8;cx++)
			fen1d(esx+dx0+cx*(l+dx),esy+dy0+cy*(h+dy),l,h,clf,clc,clt,tab[cy][cx]);
	}

	char ch[1],c;
	for(k=0;k<8;k++){
		strcpy(ch,itoa(k+1,ch,10));
		fen2d(dx0-l,dy0+esy+k*(h+dy),l,h,0,13,clt,ch,1);
	}

	c='A';
	for(k=0;k<8;k++){
		fen1d(dx0+esx+k*(l+dx),dy0-h,l,h,0,13,clt,c);
		c=c+1;
	}}

	/*cx=3,cy=3;
	fen1d(esx+dx0+cx*(l+dx),esy+dy0+cy*(h+dy),l,h,clf_m,clc_m,clt_m,tab[cx][cy]);
	do{
		c=getch();
		switch(c){
			case 'b': fen1d(esx+dx0+cx*(l+dx),esy+dy0+cy*(h+dy),l,h,clf,clc,clt,tab[cx][cy]);
					  cy++;
					  if(cy==8) cy=0;
					  fen1d(esx+dx0+cx*(l+dx),esy+dy0+cy*(h+dy),l,h,clf_m,clc_m,clt_m,tab[cx][cy]);
					  break;
			case 'h': fen1d(esx+dx0+cx*(l+dx),esy+dy0+cy*(h+dy),l,h,clf,clc,clt,tab[cx][cy]);
					  cy--;
					  if(cy<0) cy=7;
					  fen1d(esx+dx0+cx*(l+dx),esy+dy0+cy*(h+dy),l,h,clf_m,clc_m,clt_m,tab[cx][cy]);
					  break;
			case 'd': fen1d(esx+dx0+cx*(l+dx),esy+dy0+cy*(h+dy),l,h,clf,clc,clt,tab[cx][cy]);
					  cx++;
					  if(cx==8) cx=0;
					  fen1d(esx+dx0+cx*(l+dx),esy+dy0+cy*(h+dy),l,h,clf_m,clc_m,clt_m,tab[cx][cy]);
					  break;
			case 'g': fen1d(esx+dx0+cx*(l+dx),esy+dy0+cy*(h+dy),l,h,clf,clc,clt,tab[cx][cy]);
					  cx--;
					  if(cx<0) cx=7;
					  fen1d(esx+dx0+cx*(l+dx),esy+dy0+cy*(h+dy),l,h,clf_m,clc_m,clt_m,tab[cx][cy]);
					  break;
			case 'N': if(tab[cx][cy]==' '){
                        jouer_coup(4,5,tab,1);
                        grille(tab);//tab[cx][cy]='N';
					  	fen1d(esx+dx0+cx*(l+dx),esy+dy0+cy*(h+dy),l,h,clf_m,clc_m,clt_m,tab[cx][cy]);
					  }
					  else putchar(07);
					  break;
					  break;
			case 'B': if(tab[cx][cy]==' '){
					  	tab[cx][cy]='B';
					  	fen1d(esx+dx0+cx*(l+dx),esy+dy0+cy*(h+dy),l,h,clf_m,clc_m,clt_m,tab[cx][cy]);
					  }
					  else putchar(07);
					  break;
		}
	}while(c!='x');*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menuu1(void){
	int k;
	char c;
	k=0;
	fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu1[k],1);

	do{
		c=getch();
		switch(c){
			case 'P': fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu1[k],1);
					  k++;
					  if(k==nbr_tache) k=0;
					  fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu1[k],1);
					  break;
			case 'H': fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu1[k],1);
					  if(k==0) k=nbr_tache;
					  k--;
					  fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu1[k],1);
					  break;
			case RET: fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,"",1);
					  return k;
		}
	}while(c!='x');
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void gestion(){
	int a;
	do{
		a=menuu1();
		fen2d(x0+dx,y0+dy+a*(h+dy),l,h,clf,clc,clt,menu1[a],1);
		switch(a){
			case 0 : jouer();
					 break;
			case 1 :regles_de_jeu();
                    break;
			case 2 :setcolor(1,0);Quitter();
		  			 break;
		}
	}while(a!=nbr_tache);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menuu2(void){
	int k;
	char c;
	k=0;
	fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu2[k],1);

	do{
		c=getch();
		switch(c){
			case 'P': fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu2[k],1);
					  k++;
					  if(k==nbr_tache2) k=0;
					  fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu2[k],1);
					  break;
			case 'H': fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu2[k],1);
					  if(k==0) k=nbr_tache2;
					  k--;
					  fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu2[k],1);
					  break;
			case RET: return k;
		}
	}while(c!='x');
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void gestion2(){
	int a;
	do{
		a=menuu2();
		fen2d(x0+dx,y0+dy+a*(h+dy),l,h,clf,clc,clt,menu2[a],1);
		switch(a){
			case 0 : jvsj();
					 break;
			case 1 : jouer2();
		  			 break;
			case 2 :retour();
		  			 break;
			case 3 :setcolor(1,0);Quitter();
		  			 break;
		}
	}while(a!=nbr_tache2);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menuu3(void){
	int k;
	char c;
	k=0;
	fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu3[k],1);

	do{
		c=getch();
		switch(c){
			case 'P': fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu3[k],1);
					  k++;
					  if(k==nbr_tache3) k=0;
					  fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu3[k],1);
					  break;
			case 'H': fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu3[k],1);
					  if(k==0) k=nbr_tache3;
					  k--;
					  fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu3[k],1);
					  break;
			case RET: return k;
		}
	}while(c!='x');
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void gestion3(){
	int a,i;
	do{
		a=menuu3();
		fen2d(x0+dx,y0+dy+a*(h+dy),l,h,clf,clc,clt,menu3[a],1);
		switch(a){
			case 0 : jouer3();
					 break;
			case 1 :i=charger_niveau();jvsmchine(i,1);
		  			 break;

		}
	}while(a!=nbr_tache3);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menuu4(void){
	int k;
	char c;
	k=0;
	fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu4[k],1);

	do{
		c=getch();
		switch(c){
			case 'P': fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu4[k],1);
					  k++;
					  if(k==nbr_tache) k=0;
					  fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu4[k],1);
					  break;
			case 'H': fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu4[k],1);
					  if(k==0) k=nbr_tache;
					  k--;
					  fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu4[k],1);
					  break;
			case RET: fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,"",1);
					  return k;
		}
	}while(c!='x');
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void gestion4(){
	int a;
	do{
		a=menuu4();
		fen2d(x0+dx,y0+dy+a*(h+dy),l,h,clf,clc,clt,menu1[a],1);
		switch(a){
			case 0 :jvsmchine(0,0);
					 break;
			case 1 :jvsmchine(2,0);
                    break;
			case 2 :jvsmchine(5,0);
		  			 break;
		}
	}while(a!=nbr_tache);
}
