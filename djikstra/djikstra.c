


#include "djikstra.h"


void begin_djikstra(Graphe graphe, int premier_sommet){
    for (int i = 0; i < graphe.ordre; ++i) {
        graphe.pSommet[i]->state = 0;
        graphe.pSommet[i]->distance = INT_MAX; // permet de représenter l'infini
    }
    graphe.pSommet[premier_sommet]->state = 1;
    graphe.pSommet[premier_sommet]->distance = 0;
}

void parcours_arc(Graphe graphe, pSommet * sommet, int sommet_depart, int* s){
    int temp = INT_MAX;
    pArc arc=sommet[*s]->arc;
    while(arc!=NULL){
        if(!graphe.pSommet[arc->sommet]->state){
            if(graphe.pSommet[arc->sommet]->distance < temp)
                temp = graphe.pSommet[arc->sommet]->distance;
        }
        arc=arc->arc_suivant;
    }
    *s = temp;
}

void algo_djikstra(Graphe graphe, int premier_sommet, int dernier_sommet){
    int s;
    begin_djikstra(graphe, premier_sommet);
    do{
        graphe.pSommet[]
        while()
    }while();
    // pour tous les sommets :
    // mettre la distance a l'inf
    // predecesseur a nulle
    // marqueur a 0
}