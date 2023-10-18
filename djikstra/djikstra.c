
#include <stdio.h>
#include "djikstra.h"

void begin_djikstra(){
    int init_S =0;
    int final_S =0;
    printf("Choisissez votre sommet de départ :\n");
    scanf("%d",&init_S);
    printf("Choisissez votre sommet de final :\n");
    scanf("%d",&final_S);
}

void algo_djikstra(){
    // pour tous les sommets :
    // mettre la distance a l'inf
    // predecesseur a nulle
    // marqueur a 0
}