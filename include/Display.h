#ifndef DISPLAY_H
#define DISPLAY_H
    #include <stdio.h>
    #include <stdlib.h>
    #include "Constant.h"
    #include "Miscellanous.h"
    
    /*
        \brief Fonction d'affichage de la Map dans le terminal
    */
    void DisplayMap(int** matrice_Map, int int_mapSize);

    //Fonctions de DEBUG pour dev, ne serons pas utiliser dans le process final

    void DebugDisplayMap(int** matrice_Map, int int_mapSize);

    void DebugDisplayMatriceDistance(int int_mapSize, int*** matrice_Distance);

    void DebugInfoPlayer(PlayerInfo s_playerInfo_player);

    void EditTerminal(); //Agrandi le terminal ou le maximize si wmctrl est installer

#endif
