#ifndef MOVEMENTS_H
#define MOVEMENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "Constant.h"
#include "Miscellanous.h"



static struct termios old, current; //Je ne sais pas encore si on peut deplacer cette struct (si execution de l'ensemble du prog)

int KeyAvailable(int key)
{
    if (key == HAUT || key == BAS || key == GAUCHE || key == DROITE || key == HAUT_GAUCHE || key == HAUT_DROITE || key == BAS_GAUCHE || key == BAS_DROITE || key == RETOUR_ARRIERE || key == SAUVEGARDER) {
        return 1;
    }
    else {
        printf("Touche invalide : appuyez sur h pour afficher l'aide");
        return 0;
    }
}

void ChangePosition(int key, int* x, int* y) 
{
    switch (key)
    {
    case HAUT:
        x=0;
        y=1;
        break;
    case BAS:
        x=0;
        y=-1;
        break;
    case GAUCHE:
        x=-1;
        y=0;
        break;
    case DROITE:
        x=1;
        y=0;
        break;
    case HAUT_GAUCHE:
        x=-1;
        y=1;
        break;
    case HAUT_DROITE:
        x=1;
        y=1;
        break;
    case BAS_GAUCHE:
        x=-1;
        y=-1;
        break;
    case BAS_DROITE:
        x=1;
        y=-1;
        break;
    default:
        break; //Retournez dans la fonction ListenKeybooard ? Normaement le default est impossible car gerer par la fonction KeyAvailable()
    }
}

int ListenKeyboard()
{
    FILE* flux = stdin;
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    current = old; /* make new settings same as old settings */
    current.c_lflag &= ~ICANON; /* disable buffered i/o */
    current.c_lflag &= ~ECHO; /* set no echo mode */
    tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
    int ch;

    do
    {
        ch = getc(flux);
    } while (!KeyAvailable(ch));

    current.c_lflag |= ECHO; /* set echo mode */
    tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
    return ch;
}

//int key_pressed;
//key_pressed = ListenKeyboard()
//ChangePosition(key_pressed, &int_wanted_x, &int_wanted_y); APPELLE DE FONCTION POUR JORDAN C'EST CE QUE TU VEUX ????????????????????????????
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
