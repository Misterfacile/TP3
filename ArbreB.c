
#include <stdio.h>
#include <stdlib.h>
#include "ArbreB.h"
noeud *nouvNoeud(char c){
	noeud *p = NULL;
	static int numero; //var rémanente auto initialisée à 0
	p = (noeud*)malloc(sizeof(noeud));
	if (p==NULL){
		printf("Prob d'allocation dynamique du noeud\n");
		exit(1);
	}
	p->pere = NULL;
	p->etiquette = c;
	p->num = ++numero;
	p->filsG = NULL;
	p->filsD = NULL;
	return p;
}

noeud *rechercheNoeud(noeud *n,int numNoeud){
	noeud *tmpNoeud = NULL;
	if (n==NULL)
		return NULL;
	if (n->num==numNoeud)
		return n;
	tmpNoeud = rechercheNoeud(n->filsG,numNoeud);
	if(tmpNoeud!=NULL)
		return(tmpNoeud);
	return(rechercheNoeud(n->filsD,numNoeud));
}

void insererFG(noeud *ndInsert,noeud *a,int numN){
	noeud *plInsert = NULL;
	plInsert = rechercheNoeud(a,numN);
	if (plInsert==NULL){
		printf("Pas de noeud trouvé a la place %d\n",numN);
		return;
	}
	ndInsert->pere = plInsert;
	if (plInsert->filsG!=NULL){
		ndInsert->filsG = plInsert->filsG;
		plInsert->filsG->pere = ndInsert;
	}
	plInsert->filsG = ndInsert;

}

void insererFD(noeud *ndInsert,noeud *a,int numN){
	noeud *plInsert = NULL;
	plInsert = rechercheNoeud(a,numN);
	if (plInsert==NULL){
		printf("Pas de noeud trouvé a la place %d\n",numN);
		return;
	}
	ndInsert->pere = plInsert;
	if (plInsert->filsD!=NULL){
		ndInsert->filsD = plInsert->filsD;
		plInsert->filsD->pere = ndInsert;
	}
	plInsert->filsD = ndInsert;
}

void parcoursPrefixe(noeud *n, char c){
	if (n==NULL)
		return;
	if(n->pere == NULL){
		printf("%c(RACINE)\t",n->etiquette);
	}else{
		printf("%c(%d)(%c)\t",n->etiquette,n->pere->num,c);
	}
	parcoursPrefixe(n->filsG,'G');
	parcoursPrefixe(n->filsD,'D');

}

void parcoursInfixe(noeud *n, char c){
	if(n->filsG != NULL){
		parcoursInfixe(n->filsG,'G');
	}
	if(n->pere == NULL){
		printf("%c(RACINE) ",n->etiquette);
	}else{
		printf("%c(%d)(%c) ",n->etiquette,n->pere->num,c);
	}
	if(n->filsD !=NULL){
		parcoursInfixe(n->filsD,'D');
	}
}

void parcoursPostfixe(noeud *n, char c){
	if(n->filsG != NULL){
		parcoursPostfixe(n->filsG,'G');
		if(n->filsD !=NULL){
			parcoursPostfixe(n->filsD,'D');
		}
		if(n->pere == NULL){
			printf("%c(RACINE) ",n->etiquette);
		}else{
			printf("%c(%d)(%c) ",n->etiquette,n->pere->num,c);
		}

	}else if(n->filsD !=NULL){
		parcoursPostfixe(n->filsD,'D');
		printf("%c(%d)(%c) ",n->etiquette,n->pere->num,c);
	}else{
		printf("%c(%d)(%c) ",n->etiquette,n->pere->num,c);
	}
}
void supprimeArbre(noeud *n){
	if (n==NULL)
		return;
	supprimeArbre(n->filsG);
	supprimeArbre(n->filsD);
	if (n->pere!=NULL){
		if (n->pere->filsG==n)
			n->pere->filsG = NULL;
		else
			n->pere->filsD = NULL;
	}
	free(n);
	printf("suppression\t");
}

void choixMenu(void){
	fflush(stdin);
    printf("\n************ Gestion de l'arbre ************\n");
    printf("Insérer des noeuds :\t\tI\n");
    printf("Supprimer un noeud :\t\tS\n");
    printf("Afficher l'arbre :\t\tA\n");
    printf("Quitter :\t\t\tQ\n");
    printf("choix > ");
}


