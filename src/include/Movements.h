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

void ChangePosition(int key, int* x, int* y, PlayerInfo *s_playerInfo_player) 
{
    *x=s_playerInfo_player->int_x;
    *y=s_playerInfo_player->int_y;
    switch (key)
    {
    case GAUCHE:
        *y=*y-1;
        break;
    case DROITE:
        *y=*y+1;
        break;
    case HAUT:
        *x=*x-1;
        break;
    case BAS:
        *x=*x+1;
        break;
    case HAUT_GAUCHE:
        *x=*x-1;
        *y=*y-1;
        break;
    case BAS_GAUCHE:
        *x=*x+1;
        *y=*y-1;
        break;
    case HAUT_DROITE:
        *x=*x-1;
        *y=*y+1;
        break;
    case BAS_DROITE:
        *x=*x+1;
        *y=*y+1;
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

int ** UpdatePosition(int** matrice_map, int int_wanted_x, int int_wanted_y, PlayerInfo *s_playerInfo_player) // Met à jour les informations de la map en fonction du déplacement
{   
    matrice_map[s_playerInfo_player->int_x][s_playerInfo_player->int_y] = REP_VOID;
    matrice_map[int_wanted_x][int_wanted_y] = REP_CHARACTER;
    return (matrice_map);
}

void UpdatePlayerInfo(int int_wanted_x, int int_wanted_y, PlayerInfo *s_playerInfo_player)//Met à jour les infos du joueur en fonction du déplacement
{
    s_playerInfo_player->int_x = int_wanted_x;
    s_playerInfo_player->int_y = int_wanted_y;
    s_playerInfo_player->int_energy = (s_playerInfo_player->int_energy) - LOST_ENERGY;
    s_playerInfo_player->int_distance = s_playerInfo_player->int_distance + 1;
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

int ** AfterMovement(int** matrice_map, int int_wanted_x, int int_wanted_y, PlayerInfo *s_playerInfo_player, int int_mapSize, int *int_victory)// Permet de déplacer ou non le joueur en fonction du déplacement demandé et de la carte
{
    if(int_wanted_x>=0 && int_wanted_x<int_mapSize && int_wanted_y>=0 && int_wanted_y<int_mapSize){
      switch(matrice_map[int_wanted_x][int_wanted_y])
        {
        case REP_OBSTACLE1 :
            PlayerOnObstacle(s_playerInfo_player);
            printf("Test obstacle");
            break;

        case REP_OBSTACLE2 :
            PlayerOnObstacle(s_playerInfo_player);
            printf("Test obstacle");
            break;
        
        case REP_BONUS1 :
            PlayerOnBonus(matrice_map, int_wanted_x, int_wanted_y, s_playerInfo_player);
            matrice_map = UpdatePosition(matrice_map, int_wanted_x, int_wanted_y, s_playerInfo_player);
            UpdatePlayerInfo(int_wanted_x, int_wanted_y, s_playerInfo_player);
            printf("Test bonus");
            break;

        case REP_BONUS2 :
        PlayerOnBonus(matrice_map, int_wanted_x, int_wanted_y, s_playerInfo_player);
        matrice_map = UpdatePosition(matrice_map, int_wanted_x, int_wanted_y, s_playerInfo_player);
        UpdatePlayerInfo(int_wanted_x, int_wanted_y, s_playerInfo_player);
        printf("Test bonus");
        break;
    
        case REP_END :
            matrice_map = UpdatePosition(matrice_map, int_wanted_x, int_wanted_y, s_playerInfo_player);
            UpdatePlayerInfo(int_wanted_x, int_wanted_y, s_playerInfo_player);
            *int_victory = 1;
            break;
        
        default :
            matrice_map = UpdatePosition(matrice_map, int_wanted_x, int_wanted_y, s_playerInfo_player);
            UpdatePlayerInfo(int_wanted_x, int_wanted_y, s_playerInfo_player);
            break;
       }
     
    }
    return (matrice_map);
}
#endif
