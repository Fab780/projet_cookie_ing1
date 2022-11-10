#ifndef MOVEMENTS_H
#define MOVEMENTS_H

#include <stdio.h>
#include <stdlib.h>
#include "Constant.h"
#include "Miscellanous.h"




#include <stdio.h>
#include <termios.h>

// static struct termios old, current;

// int main() {
//     FILE* flux = stdin;
//     tcgetattr(0, &old); /* grab old terminal i/o settings */
//     current = old; /* make new settings same as old settings */
//     current.c_lflag &= ~ICANON; /* disable buffered i/o */
//     current.c_lflag &= ~ECHO; /* set no echo mode */
//     tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */

//     int ch;
//     ch = getc(flux);
//     printf("Vous avez appuyé sur la touche %d.\n", ch);

//     switch(ch) {
//     case UP_ARROW:
//         printf("UP WAS PRESSED\n");
//         break;
//     case DOWN_ARROW:
//         printf("DOWN WAS PRESSED\n");
//         break;
//     case LEFT_ARROW:
//         printf("LEFT WAS PRESSED\n");
//         break;
//     case RIGHT_ARROW:
//         printf("RIGHT WAS PRESSED\n");
//         break;
//     default:
//         printf("SOME OTHER SCROLL KEY PRESSED: %d\n", ch);
//         break;
//     }
//     current.c_lflag |= ECHO; /* set echo mode */
//     tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
//     return 0;
// }

int ** UpdatePosition(int** matrice_map, int int_wanted_x, int int_wanted_y, PlayerInfo *s_playerInfo_player) // Met à jour les informations du joueur ainsi que la map en fonction du déplacement
{   
    matrice_map[s_playerInfo_player->int_x][s_playerInfo_player->int_y] = REP_VOID;
    matrice_map[int_wanted_x][int_wanted_y] = REP_CHARACTER;

    s_playerInfo_player->int_x = int_wanted_x;
    s_playerInfo_player->int_y = int_wanted_y;
    s_playerInfo_player->int_energy = (s_playerInfo_player->int_energy) - LOST_ENERGY;
    s_playerInfo_player->int_distance = s_playerInfo_player->int_distance + 1;
    return (matrice_map);
}

void PlayerOnBonus(int** matrice_map, int int_wanted_x, int int_wanted_y, PlayerInfo *s_playerInfo_player)//Donne de l'énergie à un joueur lorsqu'il marche sur un bonus
{
    s_playerInfo_player->int_energy = (s_playerInfo_player->int_energy) + GAIN_ENERGY;
    s_playerInfo_player->int_gain_energy = (s_playerInfo_player->int_energy) + GAIN_ENERGY;
}

void PlayerOnObstacle(PlayerInfo *s_playerInfo_player) //retire de l'énergie au joueur lorsqu'il rentre dans un obstacle
{
    s_playerInfo_player->int_energy = (s_playerInfo_player->int_energy) - LOST_ENERGY;
    s_playerInfo_player->int_lost_energy = (s_playerInfo_player->int_energy) - LOST_ENERGY;
}

int ** AfterMovement(int** matrice_map, int int_wanted_x, int int_wanted_y, PlayerInfo *s_playerInfo_player, int int_mapSize)// Permet de déplacer ou non le joueur en fonction du déplacement demandé et de la carte
{//switch(matrice_map[int_wanted_x][int_wanted_y])
// {
//     case (REP_OBSTACLE1 ||  REP_OBSTACL2){
//         PlayerOnObstacle(s_playerInfo_player);
//     }
// }
    if(int_wanted_x < 0 | int_wanted_x >= int_mapSize){//La case demandé n'existe pas, il ne se passe rien
        return 0;
    }
    else if(int_wanted_y < 0 | int_wanted_y >= int_mapSize){
        return 0;
    }
    else if(CoordCompare(matrice_map, int_wanted_x, int_wanted_y, REP_OBSTACLE1) == 1){
        PlayerOnObstacle(s_playerInfo_player);
    }
    else if(CoordCompare(matrice_map, int_wanted_x, int_wanted_y, REP_OBSTACLE2) == 1){
        PlayerOnObstacle(s_playerInfo_player);
    }
    else if(CoordCompare(matrice_map, int_wanted_x, int_wanted_y, REP_BONUS1) == 1){
        PlayerOnBonus(matrice_map, int_wanted_x, int_wanted_y, s_playerInfo_player);
        matrice_map = UpdatePosition(matrice_map, int_wanted_x, int_wanted_y, s_playerInfo_player);
    }
    else if(CoordCompare(matrice_map, int_wanted_x, int_wanted_y, REP_BONUS2) == 1){
        PlayerOnBonus(matrice_map, int_wanted_x, int_wanted_y, s_playerInfo_player);
        matrice_map = UpdatePosition(matrice_map, int_wanted_x, int_wanted_y, s_playerInfo_player);
    }else{
        matrice_map = UpdatePosition(matrice_map, int_wanted_x, int_wanted_y, s_playerInfo_player);
    }
    return (matrice_map);
}

#endif
