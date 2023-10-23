
#ifndef TP3_DJIKSTRA_DJIKSTRA_H
#define TP3_DJIKSTRA_DJIKSTRA_H

#include <stdio.h>
#include <limits.h>
#include "../graphe.h"

// Iinitialise les distances des sommets du graphe par rapport au premier_sommet (infini)
void begin_djikstra(Graphe graphe, int premier_sommet);

// Parcours les successeurs de s et update leur distance, et modifie s le sommet avec la plus petite distance par adresse
void parcours_successeur(Graphe graphe, int* s, int tab[]);

// Affiche le resultat final de l'algo (chemin le plus court entre sommet_initial et sommet_final)
void afficher_plus_court_chemin(Graphe graphe, int premier_sommet, int dernier_sommet);

// Fonction principale qui prend 2 sommets et retourne la plus petite distance entre eux
void algo_djikstra(Graphe graphe, int premier_sommet, int dernier_sommet);



#endif //TP3_DJIKSTRA_DJIKSTRA_H
