
#include "graphe.h"

// affichage des successeurs du sommet num
void afficher_successeurs(Graphe graphe, int num){
    int degre = 0;
    pArc arc=graphe.pSommet[num]->arc;
    printf(" sommet %d :\n",num );
    while(arc!=NULL){
        printf("%d ",arc->sommet);
        arc=arc->arc_suivant;
        degre++;
    }
    graphe.pSommet[num]->degre = degre;
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


/* La construction du réseau peut se faire à partir d'un fichier dont le nom est passé en paramètre
Le fichier contient : ordre, taille et liste des arcs */

Graphe * lire_graphe(char * nomFichier, int sommet_initial){
    Graphe* graphe;
    int compteur = 0; // compteur pour déterminer si le sommet_initial choisi correspond au graphe
    FILE * ifs = fopen(nomFichier,"r"); // ouverture du fichier choisi
    int taille, ordre, s1, s2,poids;


    if (!ifs){
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(ifs,"%d",&ordre); // ordre du graphe

    ordre = ordre; // le plus petit sommet est ajouté l'ordre pour évité les bugs des fichiers ou le graphe
    // ne commance pas à zéro
    int tableau_sommets[ordre];
    for (int i = 0; i < ordre; ++i) {
        fscanf(ifs,"%d",&tableau_sommets[i]);
    }
    graphe=CreerGraphe(ordre); // créer le graphe d'ordre sommets et mets pp_sommet en premier

    fscanf(ifs,"%d",&taille); // taille du fichier

    graphe->ordre=ordre;
    graphe->taille=taille;

    // créer les arêtes du graphe

    for (int i=0; i<taille; ++i){
        fscanf(ifs,"%d%d%d",&s1,&s2,&poids);
        if(sommet_initial == s1 || sommet_initial == s2){
            compteur++;
        }
        graphe->pSommet=CreerArete(graphe->pSommet, s1, s2, poids);
        graphe->pSommet=CreerArete(graphe->pSommet, s2, s1, poids);

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
        afficher_successeurs(*graphe, i);
        printf("\n");
    }
}