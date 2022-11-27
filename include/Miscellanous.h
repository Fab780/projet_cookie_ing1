#ifndef MISCELLANOUS_H
#define MISCELLANOUS_H
    #define square(a)  (a)*(a)
    #include <stdlib.h>
    #include <math.h>
    #include <stdio.h>
    #include <time.h>
    #include <string.h>
    #include <time.h>   

    typedef struct coordonnees coordonnees;
    struct coordonnees{ // Structure contenant les coordonnées du joueur 
        int int_x;
        int int_y;
    };

    typedef struct Node{ // enregistre les coordonnées dans une pile
        coordonnees coordonnees_player;
        struct Node *next;
    }List, Node;

    typedef struct PlayerInfo PlayerInfo; 
    struct PlayerInfo{ // Structure contennant les informations du joueur
        coordonnees coordonnees_player;
        int int_energy;
        int int_distance;
        int int_gain_energy;
        int int_lost_energy;
        int int_backward;
    };

    int RNG(int min, int max);

    int CoordCompare(int** matrice_map, int int_x, int int_y, char constant_rep);

    int IsBetween(int int_Comp, int int_min, int int_max);

    void printf_center(const char* str);

    void InitRNG();
    
    Node *createNode(coordonnees coordonnees_player);

    List *emptyList(void);

    int isEmpty(List *List_L);

    long lengthList(List *List_L);

    List *addnode(List *List_L, coordonnees coordonnees_player);

    List *freeLastCoord(List *List_L);

    List *freeList(List *List_L);

    void printList(List *List_L);

#endif
