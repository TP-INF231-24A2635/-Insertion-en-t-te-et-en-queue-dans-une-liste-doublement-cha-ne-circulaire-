//insertion en tete et en queue d'une liste doublement chainee circulaire.

#include<stdio.h>
#include<stdlib.h>

typedef struct element {
	int n;
	struct element *suiv;
	struct element *prec;
} *liste;

//declaration des fonctions
liste creerliste(liste);
liste insertete(liste , int);
liste inserqueue(liste , int);
void afficheliste(liste);

//fontion principale
int main(){
	int n,c;
	liste l;
	creerliste(l);
	do{
		printf("\n");
		printf("MENU\n");
		printf("1. Inserer en tete de liste. \n");
		printf("2. Inserer en queue de liste.\n");
		printf("3. afficher la liste.\n");
		printf("0.Quitter.\n");
		printf(".................\n");
		
		do{
			printf("\nVotre choix: ");
			scanf("%d",&c);
		}while(c<0 || c>3);
		
		switch(c){
			case 1:
				printf("\nentrer l'entier que vous voulez inserer en tete de liste: ");
				scanf("%d",&n);
				l = insertete(l , n);
			break;
			case 2:
				printf("\nentrer l'entier que vous voulez inserer en que de liste: ");
				scanf("%d",&n);
				l = inserqueue(l , n);
			break;
			case 3:
				afficheliste(l);
			break;
			default: break;

		}
	}while(c!=0);

return 0;
}

//definition des fonctions

liste creerliste(liste l){
	return NULL;
}

//n represente un element constituant de la liste
liste insertete(liste l, int n){
	liste p=NULL;
	//p=l;
	if(l != NULL){
		p=(liste)malloc(sizeof(struct element));
		p->n = n;
		p->prec = l->prec;
		p->suiv = l;
		l->prec->suiv = p;
		l->prec = p;
		l = p;
	}
	else{
		p=(liste)malloc(sizeof(struct element));
		p->n = n;
		p->prec = p;
		p->suiv = p;
		l = p;
	}
	return l;
}

liste inserqueue(liste l, int n){
	liste p=NULL;
	if(l != NULL){
		p=(liste)malloc(sizeof(struct element));
		p->n = n;
		p->prec = l->prec;
		l->prec->suiv = p;
		p->suiv = l;
		l->prec = p;
	}else{
		p=(liste)malloc(sizeof(struct element));
		p->n = n;
		p->prec = p;
		p->suiv = p;
		l = p;
	}
	return l;
}


void afficheliste(liste l){
	liste p=l;
	printf("\n");
	if(l == NULL){
		return;
	}
	
		do{
			printf(" %d ->",p->n);
			p = p->suiv;
		}while(p != l);
		printf("\n");
}





















