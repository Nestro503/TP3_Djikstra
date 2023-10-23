
#include "graphe.h"

/// SOURCES : Les fonctions de graphe.c proviennent des informations données pour le TP n°2

// affichage des successeurs du sommet
void afficher_successeurs(Graphe graphe, int num){
    pArc arc=graphe.pSommet[num]->arc;
    printf(" sommet %d :\n",num );
    while(arc!=NULL){
        printf("%d ",arc->sommet);
        arc=arc->arc_suivant;
    }
}

// créer le graphe
Graphe* CreerGraphe(int ordre){

    Graphe * Newgraphe=(Graphe*)malloc(sizeof(Graphe));
    Newgraphe->pSommet = (pSommet*)malloc(ordre*sizeof(pSommet));

    for(int i=0; i<ordre; i++){
        Newgraphe->pSommet[i]=(pSommet)malloc(sizeof(struct Sommet));
        Newgraphe->pSommet[i]->valeur=i;
        Newgraphe->pSommet[i]->arc=NULL;
    }
    return Newgraphe;
}

pSommet* CreerArete(pSommet* sommet,int s1,int s2,  int poids){

    if(sommet[s1]->arc==NULL){
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;
        sommet[s1]->arc=Newarc;
        Newarc->poids=poids;
        return sommet;
    }

    else{
        pArc temp=sommet[s1]->arc;
        while(temp->arc_suivant!=NULL){
            temp=temp->arc_suivant;
        }
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->poids=poids;
        Newarc->arc_suivant=NULL;

        if(temp->sommet>s2){
            Newarc->arc_suivant=temp->arc_suivant;
            Newarc->sommet=temp->sommet;
            Newarc->poids=poids;
            temp->sommet=s2;
            temp->arc_suivant=Newarc;
            return sommet;
        }

        temp->arc_suivant=Newarc;
        return sommet;
    }
}



// Fonction qui prend en parametre un fichier contenant : ordre, taille et liste des arcs avec leurs poids respectifs

Graphe * lire_graphe(char * nomFichier, int sommet_initial){
    Graphe* graphe;
    int compteur = 0; // compteur qui va permettre de déterminer si le sommet_initial choisi correspond au graphe
    FILE * ifs = fopen(nomFichier,"r"); // ouverture du fichier choisi
    int taille, ordre, s1, s2, poids;


    if (!ifs){
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(ifs,"%d",&ordre); // ordre du graphe


    int tableau_sommets[ordre];
    for (int i = 0; i < ordre; ++i) {
        fscanf(ifs,"%d",&tableau_sommets[i]);
    }

    graphe=CreerGraphe(ordre); // créer le graphe

    fscanf(ifs,"%d",&taille);

    // assignation des valeurs apres lecture du fichier
    graphe->ordre=ordre;
    graphe->taille=taille;

    // lecture des arêtes du graphe ainsi que leurs poids
    for (int i=0; i<taille; ++i){
        fscanf(ifs,"%d%d%d",&s1,&s2,&poids);
        if(sommet_initial == s1 || sommet_initial == s2){
            compteur++;
        }

        graphe->pSommet=CreerArete(graphe->pSommet, s1, s2, poids); // graphe non oriente donc relation symetrique entre les sommets
        graphe->pSommet=CreerArete(graphe->pSommet, s2, s1, poids);

    }
    if(compteur == 0){ // si le compteur est a 0 c'est que le sommet_initial choisi ne correspond a aucun sommets du graphe
        printf("Le sommet choisi n'est pas valable");
        exit(-1); // fin du programme
    }

    return graphe;
}



/*affichage des differentes infos du graphe receuilli a l'aide du fichier */
void graphe_afficher(Graphe* graphe){

    printf("\ngraphe :");
    printf("ordre = %d\n",graphe->ordre);
    printf("taille = %d\n",graphe->taille);
    printf("listes d'adjacence :\n");

    for (int i=0; i<graphe->ordre; i++){
        afficher_successeurs(*graphe, i);
        printf("\n");
    }
}