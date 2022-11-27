#ifndef MOVEMENTS_H
#define MOVEMENTS_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <termios.h>
    #include "Constant.h"
    #include "Miscellanous.h"

    static struct termios old, current; //Structure qui permet de garder les deux états paramètres du terminal
    
    //Verifie la touche pressée
    int KeyAvailable(int key);

    //Change les valeur des variables dans UpdatePosition pour changer la position du personnage dans la matrice map
    void ChangePosition(int key, int* x, int* y, PlayerInfo *s_playerInfo_player);

    //Affiche les touches pour les coups dispos (et leur coup en distance)
    void ShowKeyAvailable();

    //Permet de lire la touche pressé. Le programme est en pause tant que utilisateur appuie touche
    int ListenKeyboard();

    int** UpdatePosition(int** matrice_map, int int_wanted_x, int int_wanted_y, PlayerInfo *s_playerInfo_player); // Met à jour les informations de la map en fonction du déplacement

    void UpdatePlayerInfo(int int_wanted_x, int int_wanted_y, PlayerInfo *s_playerInfo_player);//Met à jour les infos du joueur en fonction du déplacement

    void PlayerOnBonus(int** matrice_map, int int_wanted_x, int int_wanted_y, PlayerInfo *s_playerInfo_player);//Donne de l'énergie à un joueur lorsqu'il marche sur un bonus


    void PlayerOnObstacle(PlayerInfo *s_playerInfo_player); //retire de l'énergie au joueur lorsqu'il rentre dans un obstacle

    int** AfterMovement(int** matrice_map, int int_wanted_x, int int_wanted_y, PlayerInfo *s_playerInfo_player, int int_mapSize, int *int_victory);// Permet de déplacer ou non le joueur en fonction du déplacement demandé et de la carte

#endif
