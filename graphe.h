
#ifndef TP3_DJIKSTRA_GRAPHE_H
#define TP3_DJIKSTRA_GRAPHE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// SOURCES : Bien que certaines fonctions ont été ajoutées la plupart des strcutures présentes est propirété
//              intelectuelle de Mr DEBIZE.


/* Structure d'un arc*/
struct Arc
{
    int sommet; // numéro de sommet d'un arc adjacent au sommet initial
    int poids;
    struct Arc* arc_suivant;
};

/* Alias de pointeur sur un Arc */
typedef struct Arc* pArc;

/* Structure d'un sommet*/
struct Sommet
{
    struct Arc* arc;
    int valeur;
    char couleur;
    int distance;
    int pred;
    int degre;
    int degre_modify;
    bool state;
};

/* Alias de pointeur sur un Sommet */
typedef struct Sommet* pSommet;

/* Alias d'un Graphe */
typedef struct Graphe
{
    int taille;
    int ordre;
    pSommet* pSommet;
} Graphe;


// créer le graphe
Graphe* CreerGraphe(int ordre);

/* La construction du réseau peut se faire à partir d'un fichier dont le nom est passé en paramètre
Le fichier contient : ordre, taille,orientation (0 ou 1)et liste des arcs */
Graphe * lire_graphe(char * nomFichier, int sommet_initial);

// Ajouter l'arête entre les sommets s1 et s2 du graphe
pSommet* CreerArete(pSommet* sommet,int s1,int s2, int poids);

/* affichage des successeurs du sommet num*/
void afficher_successeurs(Graphe graphe, int num);


/*affichage du graphe avec les successeurs de chaque sommet */
void graphe_afficher(Graphe* graphe);


#endif //TP3_DJIKSTRA_GRAPHE_H
