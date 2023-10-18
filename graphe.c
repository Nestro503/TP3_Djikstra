
#include "graphe.h"

// affichage des successeurs du sommet num
void afficher_successeurs(pSommet * sommet, int num){
    pArc arc=sommet[num]->arc;
    printf(" sommet %d :\n",num );
    while(arc!=NULL){
        printf("%d ",arc->sommet);
        arc=arc->arc_suivant;
    }
}

//
void pp_sommet2(int* ppsommet, char * nomFichier){      // fonction reprise de lire_graph / pp_sommet = PlusPetit_sommet
    FILE * ifs = fopen(nomFichier,"r");                 // fonction qui recherche le plus petit sommet du graphe afin de le rajouter
    int taille, s1, s2;                                 // dans l'ordre du graphe pour ne pas avoir d'erreur d'adresse pour les graphes
    int temp;                                           // commencant par autre chode que 0

    if (!ifs){printf("Erreur de lecture fichier\n");exit(-1);}
    fseek(ifs, 1* sizeof(int), SEEK_SET);
    fscanf(ifs, "%d",&taille);
    fseek(ifs, 3* sizeof(int), SEEK_SET);

    int ppsommet_prev;

    // créer les arêtes du graphe
    for (int i=0; i<taille; ++i){ // on parcourt le fichier après la ligne designant l'orientation
        ppsommet_prev = *ppsommet;
        fscanf(ifs,"%d%d",&s1,&s2);
        if(s1 < s2){ // si le sommet 1 de la ligne est plus petit alors on garde le sommet 1 sinon on garde le sommet 2
            temp = s1;
        }else{
            temp = s2;
        }
        if(temp < ppsommet_prev){ // si le sommet gardé est plus petit que le sommet d'avant alors on le met dans la varaible ppsommet
            *ppsommet = temp;
        }
    }
}

// Ajouter l'arête entre les sommets s1 et s2 du graphe
pSommet* CreerArete(pSommet* sommet,int s1,int s2){

    if(sommet[s1]->arc==NULL){
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;
        Newarc->valeur=1;   // valeur par défaut d'une arete pondere est 1
        sommet[s1]->arc=Newarc;
        return sommet;
    }

    else{
        pArc temp=sommet[s1]->arc;
        while(temp->arc_suivant!=NULL){
            temp=temp->arc_suivant;
        }
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;

        if(temp->sommet>s2){
            Newarc->arc_suivant=temp->arc_suivant;
            Newarc->sommet=temp->sommet;
            temp->sommet=s2;
            temp->arc_suivant=Newarc;
            return sommet;
        }

        temp->arc_suivant=Newarc;
        return sommet;
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


/* La construction du réseau peut se faire à partir d'un fichier dont le nom est passé en paramètre
Le fichier contient : ordre, taille et liste des arcs */

Graphe * lire_graphe(char * nomFichier, int ppsommet, int force_orientation, int sommet_initial){
    Graphe* graphe;
    int compteur = 0; // compteur pour déterminer si le sommet_initial choisi correspond au graphe
    FILE * ifs = fopen(nomFichier,"r"); // ouverture du fichier choisi
    int taille, ordre, s1, s2;


    if (!ifs){
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(ifs,"%d",&ordre); // ordre du graphe

    ordre = ordre + ppsommet; // le plus petit sommet est ajouté l'ordre pour évité les bugs des fichiers ou le graphe
    // ne commance pas à zéro

    graphe=CreerGraphe(ordre); // créer le graphe d'ordre sommets et mets pp_sommet en premier

    fscanf(ifs,"%d",&taille); // taille du fichier

    graphe->ordre=ordre;
    graphe->taille=taille;

    // créer les arêtes du graphe

    for (int i=0; i<taille; ++i){
        fscanf(ifs,"%d%d",&s1,&s2);
        if(sommet_initial == s1 || sommet_initial == s2){
            compteur++;
        }
        graphe->pSommet=CreerArete(graphe->pSommet, s1, s2);

    }
    if(compteur == 0){ // si le compteur est a 0 c'est que le sommet_initial choisi ne correspond a aucun sommets du graphe
        printf("Le sommet choisi n'est pas valable");
        exit(-1); // fin du programme
    }

    return graphe;
}



/*affichage du graphe avec les successeurs de chaque sommet */
void graphe_afficher(Graphe* graphe){

    printf("\ngraphe :");
    printf("ordre = %d\n",graphe->ordre);
    printf("taille = %d\n",graphe->taille);
    printf("listes d'adjacence :\n");

    for (int i=0; i<graphe->ordre; i++){
        afficher_successeurs(graphe->pSommet, i);
        printf("\n");
    }
}