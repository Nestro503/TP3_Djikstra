
#include <stdio.h>
#include <limits.h>
#include "djikstra.h"
#include "../graphe.h"

void begin_djikstra(Graphe graphe, int premier_sommet){
    for (int i = 0; i < graphe.ordre; ++i) {
        graphe.pSommet[i]->state = 0;
        graphe.pSommet[i]->distance = INT_MAX; // permet de représenter l'infini
    }
    graphe.pSommet[premier_sommet]->state = 1;
    graphe.pSommet[premier_sommet]->distance = 0;
}

void algo_djikstra(Graphe graphe, int premier_sommet, int dernier_sommet){;
    begin_djikstra(graphe, premier_sommet);
    do{

    }while();
    // pour tous les sommets :
    // mettre la distance a l'inf
    // predecesseur a nulle
    // marqueur a 0
}