#ifndef MISCELLANOUS_H
#define MISCELLANOUS_H
    #define square(a)  (a)*(a)

    typedef struct PlayerInfo PlayerInfo; 
    struct PlayerInfo{ // Structure contennant les informations du joueur
        int int_x;
        int int_y;
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

#endif
