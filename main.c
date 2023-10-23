#include <stdio.h>

#include "graphe.h"
#include "djikstra/djikstra.h"


int main() {

    ///initialisation des variables
    Graphe * g;
    char nom_fichier[50]; // le nom du fichier pourra faire au maximum 50 caracteres
    int sommet_initial, sommet_final; // sommet remarquable de notre parcours pour lesquels on va evaluer la distance

    ///validation du fichier utilisé
    printf("Entrer le nom du fichier du labyrinthe:");
    scanf("%s",nom_fichier); // atribution du nom du fichier

    ///saisie du numéro des sommets remarquables
    printf("Numero du sommet initial :");
    scanf("%d", &sommet_initial); // atribution du sommet initial
    printf("Numero du sommet final :");
    scanf("%d", &sommet_final);

    /// creation du graphe
    g = lire_graphe(nom_fichier,sommet_initial);

    /// affichage du graphe
    graphe_afficher(g);

    /// lancement de l'algo de Djikstra qui va retourner la distance minimale entre sommet_initial et sommet_final
    algo_djikstra(*g,sommet_initial, sommet_final);


    return 0;
}
