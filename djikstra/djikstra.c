#include "djikstra.h"

/// Fonction qui permet d'initialiser les distances des sommets du graphe par rapport au premier_sommet
void begin_djikstra(Graphe graphe, int premier_sommet){
    for (int i = 0; i < graphe.ordre; ++i) {
        graphe.pSommet[i]->distance = INT_MAX; // met la distance de tous les sommets à l'infini
    }
    graphe.pSommet[premier_sommet]->distance = 0;
}

/// Parcours les successeurs de s et update leur distance, et modifie s le sommet avec la plus petite distance par adresse.
void parcours_successeur(Graphe graphe, int* s, int tab[]){
    pArc arc = graphe.pSommet[*s]->arc;
    pSommet temp = malloc(sizeof(pSommet)); // variable temporaire permettant de selectionné le sommet avec la plus petite distance
    temp->distance = INT_MAX; // mettre distance à l'infini
    int distance;
    while ((arc != NULL)){
        if(tab[arc->sommet] == 0){ // si le sucesseur du sommet s n'est pas marque
            distance = arc->poids + graphe.pSommet[*s]->distance;

            if(distance < graphe.pSommet[arc->sommet]->distance){ // si la distance mis a jour est plus petite que la precedente
                graphe.pSommet[arc->sommet]->distance = distance;
                graphe.pSommet[arc->sommet]->pred = *s;
            }
            if(graphe.pSommet[arc->sommet]->distance < temp->distance){ // permet de detecter la plus petite dist des succeseurs de s
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

/// Affiche le plus court chemin a la fin de l'algo de Djikstra
void afficher_plus_court_chemin(Graphe graphe, int premier_sommet, int dernier_sommet){ // affiche le plus court chemin grace au prédécesseur de chaque sommet
    pSommet *parkour = graphe.pSommet;
    int pred;
    pred = dernier_sommet;
    printf("\nRESULTAT\nLe chemin le plus court entre %d et %d est egale a %d",premier_sommet, dernier_sommet,graphe.pSommet[dernier_sommet]->distance);

    printf("\nVoici ce chemin : %d",dernier_sommet);
    while(pred != premier_sommet){ // parcours jusqu'à que le sommet qui précessede soit égale au premier sommet
        printf(" <-- %d", parkour[pred]->pred);
        pred = parkour[pred]->pred;
    }
}

/// Condition de fin de l'algo de Djikstra / Retourne "vrai" si tous les sommets sont marqués
int tous_sommet_marque(int const tab[], int ordre){
    int compteur = 0;
    for (int i = 0; i < ordre; ++i) { // Si un sommet est detecte comme etant marque alors compteur augmente
        if(tab[i] == 0){
            compteur++;
        }
    }
    if(compteur > 0)
        return 0;
    else
        return 1;
}

/// Fonction principale qui prend 2 sommets et retourne la plus petite distance entre eux
void algo_djikstra(Graphe graphe, int premier_sommet, int dernier_sommet){
    int s;
    int tab[graphe.ordre]; // tableau qui recense les etats de chaque sommets
    for (int i = 0; i < graphe.ordre; ++i) { // initialiser le tableau des marquages à 0
        tab[i] = 0;
    }
    begin_djikstra(graphe, premier_sommet); // initialise toutes les distances
    s = premier_sommet;
    do{
        tab[s] = 1; // marque le sommet selectionné.
        parcours_successeur(graphe, &s, tab); //
    }while(!tous_sommet_marque(tab, graphe.ordre)); // condition de fin de l'algo
    afficher_plus_court_chemin(graphe,premier_sommet,dernier_sommet); // affichage du resultat final (chemin le plus court)
}