#include <stdio.h>

#include "graphe.h"
#include "djikstra/djikstra.h"
#include "bfs/bfs.h"


int main() {

    ///initialisation des variables
    Graphe * g; // graphe servant pour le parcours BSF/DSF (peut etre oriente ou non)
    int force_orientation = 0;  // initialisation de force d'orientation à 0 (il ne sera pas pris en compte par lire_graphe)
    int ppsommet = 100; // on met une valeur arbitraire du plus petit sommet à 100 au départ
    char nom_fichier[50]; // le nom du fichier pourra faire au maximum 50 caracteres
    int sommet_initial; // sommet par lequel nous allons commencé notre parcours

    ///validation du fichier utilisé
    printf("Entrer le nom du fichier du labyrinthe:");
    scanf("%s",nom_fichier); // atribution du nom du fichier

    ///saisie du numéro du sommet initial pour lancer un BFS puis un DSF
    printf("Numero du sommet initial :");
    scanf("%d", &sommet_initial); // atribution du sommet initial

    /// creation des graphes g1 et g2 en fonction du fichier choisi
    pp_sommet2(&ppsommet,nom_fichier); //
    g = lire_graphe(nom_fichier, ppsommet,force_orientation,sommet_initial); // creation et affichage du graphe g1

    ///parcours de graphe
    //algo_bsf(*g, sommet_initial);   // Fonction générale pour le parcours en largeur

    /// afficher le graphe
    graphe_afficher(g);

    return 0;
}
