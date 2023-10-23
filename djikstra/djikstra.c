#include "djikstra.h"


void begin_djikstra(Graphe graphe, int premier_sommet){
    for (int i = 0; i < graphe.ordre; ++i) {
        graphe.pSommet[i]->distance = INT_MAX; // met la distance de tous les sommets à l'infini
    }
    graphe.pSommet[premier_sommet]->distance = 0;
}

void parcours_successeur(Graphe graphe, int* s, int tab[]){ // parcours les successeurs de s et update leur distance, et modifie s le sommet avec la plus petite distance par adresse.
    pArc arc = graphe.pSommet[*s]->arc;
    pSommet temp = malloc(sizeof(pSommet)); // variable temporaire permettant de selectionné le sommet avec la plus petite distance
    temp->distance = INT_MAX; // mettre distance à l'infini
    int distance;
    while ((arc != NULL)){
        if(tab[arc->sommet] == 0){
            distance = arc->poids + graphe.pSommet[*s]->distance;

            if(distance < graphe.pSommet[arc->sommet]->distance){
                graphe.pSommet[arc->sommet]->distance = distance;
                graphe.pSommet[arc->sommet]->pred = *s;
            }
            if(graphe.pSommet[arc->sommet]->distance < temp->distance){
                temp = graphe.pSommet[arc->sommet];
            }
        }
        arc = arc->arc_suivant;
    }
    for (int i = 0; i < graphe.ordre; ++i) { // prend le sommet de la plus petite distance des sommets non-marqué
        if(tab[i] == 0){
            if(graphe.pSommet[i]->distance < temp->distance){
                temp = graphe.pSommet[i];
            }
        }
    }
    *s = temp->valeur;
    tab[*s] = 1;
}

void afficher_plus_court_chemin(Graphe graphe, int premier_sommet, int dernier_sommet){ // affiche le plus court chemin grace au prédécesseur de chaque sommet
    pSommet *parkour = graphe.pSommet;
    int pred;
    pred = dernier_sommet;
    printf("Le chemin le plus court est : ");
    printf("%d",dernier_sommet);
    while(pred != premier_sommet){ // parcours jusqu'à que le sommet qui précessede soit égale au premier sommet
        printf(" <-- %d", parkour[pred]->pred);
        pred = parkour[pred]->pred;
    }

    printf("\nla plus petite distance totale est de %d", graphe.pSommet[dernier_sommet]->distance);
}

int tous_sommet_marque(int const tab[], int ordre){ // retour si tous les sommets sont marqués
    int compteur = 0;
    for (int i = 0; i < ordre; ++i) {
        if(tab[i] == 0){
            compteur++;
        }
    }
    if(compteur > 0)
        return 0;
    else
        return 1;
}

void algo_djikstra(Graphe graphe, int premier_sommet, int dernier_sommet){
    int s;
    int tab[graphe.ordre];
    for (int i = 0; i < graphe.ordre; ++i) { // initialiser le tableau des marquages à 0
        tab[i] = 0;
    }
    begin_djikstra(graphe, premier_sommet);
    s = premier_sommet;
    do{
        tab[s] = 1; // marque le sommet selectionné.
        parcours_successeur(graphe, &s, tab);
    }while(!tous_sommet_marque(tab, graphe.ordre));
    afficher_plus_court_chemin(graphe,premier_sommet,dernier_sommet);
    // pour tous les sommets :
    // mettre la distance a l'inf
    // predecesseur a nulle
    // marqueur a 0
}