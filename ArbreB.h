#ifndef ARBRE_H_
#define ARBRE_H_

typedef struct noeud{
	struct noeud *pere;
	char etiquette;
	int num;
	struct noeud *filsG, *filsD;
}noeud;
noeud *nouvNoeud(char c);
noeud *rechercheNoeud(noeud *n,int numNoeud);
void insererFG(noeud *ndInsert,noeud *a,int numN);
void insererFD(noeud *ndInsert,noeud *a,int numN);
void parcoursPrefixe(noeud *n,char c);
void parcoursInfixe(noeud *n,char c);
void parcoursPostfixe(noeud *n,char c);
void supprimeArbre(noeud *n);
void choixMenu(void);
#endif /* ARBRE_H_ */

