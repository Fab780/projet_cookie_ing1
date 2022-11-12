#ifndef MISCELLANOUS_H
#define MISCELLANOUS_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void printf_center(const char* str)
{
    unsigned int n;
    for (n = 0; n < (LARGEUR_CONSOLE-strlen(str)) / 2; n++)
    {
        putchar(' ');
    }
    printf("%s", str);
}

int RNG(int min, int max)
{
    return ( ( rand() % (max - min + 1) ) + min );
}

int CoordCompare(int** matrice_map, int int_x, int int_y, char constant_rep)
{
    return (matrice_map[int_x][int_y] == constant_rep);
}


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

void DebugInfoPlayer(PlayerInfo s_playerInfo_player)
{   
    printf("Votre position x : %d\n",s_playerInfo_player.int_x);
    printf("Votre position y : %d\n",s_playerInfo_player.int_y);
    printf("Votre energie : %d\n",s_playerInfo_player.int_energy);
    printf("Votre distance parcourue : %d\n",s_playerInfo_player.int_distance);
    printf("Votre energie gagnée : %d\n",s_playerInfo_player.int_gain_energy);
    printf("Votre energie perdue : %d\n",s_playerInfo_player.int_lost_energy);
    printf("Vos retour en arrière disponible : %d\n",s_playerInfo_player.int_backward);
}
#endif