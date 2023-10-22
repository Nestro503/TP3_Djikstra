
#ifndef TP3_DJIKSTRA_DJIKSTRA_H
#define TP3_DJIKSTRA_DJIKSTRA_H

#include <stdio.h>
#include <limits.h>
#include "../graphe.h"

void begin_djikstra(Graphe graphe, int premier_sommet);
void parcours_successeur(Graphe graphe, int* s, int tab[]);
void afficher_plus_court_chemin(Graphe graphe, int premier_sommet, int dernier_sommet);
void algo_djikstra(Graphe graphe, int premier_sommet, int dernier_sommet);



#endif //TP3_DJIKSTRA_DJIKSTRA_H
