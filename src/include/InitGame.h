#ifndef INITGAME_H
#define INITGAME_H
#define square(a)  (a)*(a)

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include "Constant.h"
#include "Miscellanous.h"


PlayerInfo SetupPlayer() //Initialise des valeurs par défaut pour le joueur
{
    PlayerInfo playerInfo_player;
    playerInfo_player.int_x=0;
    playerInfo_player.int_y=0;
    playerInfo_player.int_energy=0;
    playerInfo_player.int_distance=0;
    playerInfo_player.int_gain_energy=0;
    playerInfo_player.int_lost_energy=0;
    playerInfo_player.int_backward=6;
    return playerInfo_player;
}

float ChooseDifficulty()
{
    int int_scanDiff;
    printf("Choose a Difficulty :\n1: Easy\n2: Normal\n3: Hard\n>");
    scanf("%d", &int_scanDiff);
    switch (int_scanDiff) 
    {
    case 1:
        return (TAUX_DIFF_EZ);
        break;
    case 3:
        return (TAUX_DIFF_HARD);
        break;
    default:
        return (TAUX_DIFF_NORMAL);
        break;
    }
}

int ChooseMapSize()
{
    int int_scanMapS;
    printf("Choose the map size :\n1: Little\n2: Average\n3: Big\n>");
    scanf("%d", &int_scanMapS);
    switch (int_scanMapS)
    {
    case 1:
        return (TAILLE_LIL_MAP);
        break;
    case 3:
        return (TAILLE_BIG_MAP);
        break;
    default:
        return (TAILLE_AVE_MAP);
        break;
    }
}

int InitEnergy(int int_mapSize, PlayerInfo *playerInfo_player) // Initialise l'énergie de base du joueur en fonction de la taille de la carte
{
    playerInfo_player->int_energy = BASE_ENERGY * int_mapSize;
    return(playerInfo_player->int_energy);
}

void UnallocMatriceMap(int** matrice_Map, int int_mapSize)
{
    for(int i = 0; i<int_mapSize ; i++){
        free(matrice_Map[i]);
    }
    free(matrice_Map);
    return;
}   

int** AllocMatriceMap(int int_mapSize)
{
    int** matrice_Map = malloc(int_mapSize * sizeof(*matrice_Map));   
    if(matrice_Map == NULL){
        exit(EXIT_FAILURE);
    }

    for(int i=0 ; i < int_mapSize ; i++){
        matrice_Map[i] = malloc(int_mapSize * sizeof(**matrice_Map) );
        if(matrice_Map[i] == NULL){  
            for(i = i-1 ; i >= 0 ; i--) {   
              free(matrice_Map[i]);
            }                                 
            free(matrice_Map);
            exit(EXIT_FAILURE);
        }
    }
    return (matrice_Map);
}

void UnallocMatriceDistance(int*** matrice_Distance, int int_mapSize)
{
    for(int i = 0; i<int_mapSize ; i++){
        for(int j = 0; j< int_mapSize; j++)
        {
            free(matrice_Map[i][j]);
        }
    }
    for(int p = 0; p<int_mapSize ; p++){
        free(matrice_Map[p]);
    }
    free(matrice_Map);
    return;
}  



int*** AllocMatriceDistance(int int_mapSize)
{
    int*** matrice_Distance = malloc(int_mapSize * int_mapSize *  sizeof(*matrice_Distance));       
    if(matrice_Distance == NULL){
        exit(EXIT_FAILURE);
    } 
    for(int i=0 ; i < int_mapSize ; i++)
    {
        matrice_Distance[i] = malloc(int_mapSize * int_mapSize * sizeof(**matrice_Distance) );      
        if(matrice_Distance[i] == NULL){  
            for(i = i-1 ; i >= 0 ; i--) {   
              free(matrice_Distance[i]);
            }                                 
            free(matrice_Distance);
            exit(EXIT_FAILURE);
        }       
        for(int j = 0 ; j < int_mapSize; j++)
        { 
            matrice_Distance[i][j] = malloc(int_mapSize * sizeof(***matrice_Distance) );
            if(matriceDistance[i][j] == NULL) 
            {
                for(i = i-1 ; i >= 0 ; i--) 
                {
                    for(j=j-1;j>=0;j--)
                    {
                        free(matrice_Distance[i][j];
                    }
                    free(matrice_Distance[i]);
                 }
                free(matrice_Distance);
                exit(EXIT_FAILURE);
            } 
        }
    }
    return (matrice_Distance);
}




int** InitMatriceMap(int** matrice_Map, int int_mapSize)
{
    
    for(int i=0; i<int_mapSize ; i++){
        for(int j=0; j<int_mapSize ; j++){
            matrice_Map[i][j] = REP_DEFAULT;
        }
    }
    return (matrice_Map);
}

int ** PlaceObstacle(int** matrice_Map, int int_row, int int_col, int int_mapSize, float float_diffRate, int int_distBase, int constant_rep) // place un obstacle et en fonction du difficulty rate, de la taille de la map et de la RNG crée une "fillon" d'obstacles
{   
    matrice_Map[int_row][int_col] = constant_rep ;

    if( (RNG(0, ( ( 80  * int_distBase  * (RNG(10, 15) / 10) ) / ( float_diffRate * (int_mapSize / 10) ) ) ) < 50) || int_distBase - 1 > (int_mapSize / 10 ) * float_diffRate  ){
        switch (RNG(1,4))
        {
            case 1:
                if( int_col + 1 < int_mapSize && CoordCompare(matrice_Map, int_row, int_col + 1, REP_DEFAULT) ) {
                    matrice_Map = PlaceObstacle(matrice_Map, int_row, int_col + 1, int_mapSize, float_diffRate, int_distBase + 1, constant_rep);
                } else {
                    return matrice_Map;
                }
                break;
            case 2:
                if( int_row + 1 < int_mapSize && CoordCompare(matrice_Map, int_row + 1, int_col, REP_DEFAULT) ) {
                    matrice_Map = PlaceObstacle(matrice_Map, int_row + 1, int_col, int_mapSize, float_diffRate, int_distBase + 1, constant_rep);
                } else {
                    return matrice_Map;
                }
                break;
            case 3:
                if( int_row - 1 >= 0 && CoordCompare(matrice_Map, int_row - 1, int_col, REP_DEFAULT) ) {
                    matrice_Map = PlaceObstacle(matrice_Map, int_row - 1, int_col, int_mapSize, float_diffRate, int_distBase + 1, constant_rep);
                } else {
                    return matrice_Map;
                }
                break;
            case 4:
                if( int_col - 1 >= 0 && CoordCompare(matrice_Map, int_row, int_col - 1, REP_DEFAULT) ) {
                    matrice_Map = PlaceObstacle(matrice_Map, int_row, int_col - 1, int_mapSize, float_diffRate, int_distBase + 1, constant_rep);
                } else {
                    return matrice_Map;
                }
                break;
        }
    }
    return (matrice_Map);
}

int** GenerateMap(int** matrice_Map, int int_mapSize, float float_diffRate, PlayerInfo *playerInfo_player) //Work In Progress
{
    float int_nbObstacles = int_mapSize * float_diffRate ;
    float int_nbBonus = ( ( int_mapSize / (12 * float_diffRate) ) * ( 2 - float_diffRate ) ) + (RNG(0,12)/(5*float_diffRate));

    int int_maxCoord = int_mapSize - 1 ;
    int int_qrtCoord = int_mapSize/ 4 ;
    int int_rdmRow;
    int int_rdmCol = int_mapSize;
         
    switch ( RNG(1,4) ) //Placement du personnages aleatoirement dans un des 4 coins de la map, et placement du drapeau en consequence semi-aléatoirement
    {
    case 2:
        matrice_Map[int_maxCoord][0]= REP_CHARACTER;
        playerInfo_player->int_x = int_maxCoord; //on donne les informations du placement du personnage dans le récapitulatif des informations du joueur
        int_rdmRow = RNG( 0, int_qrtCoord );
        int_rdmCol = RNG( int_maxCoord - int_qrtCoord + int_rdmRow - int_qrtCoord, int_maxCoord);
        break;
    case 3:
        matrice_Map[0][int_maxCoord]= REP_CHARACTER;
        playerInfo_player->int_y = int_maxCoord;
        int_rdmRow = RNG( int_maxCoord - int_qrtCoord, int_maxCoord );
        int_rdmCol = RNG( 0, int_rdmRow - int_maxCoord + int_qrtCoord );
        break;
    case 4:
        matrice_Map[int_maxCoord][int_maxCoord]= REP_CHARACTER;
        playerInfo_player->int_x = int_maxCoord;
        playerInfo_player->int_y = int_maxCoord;
        int_rdmRow = RNG( 0, int_qrtCoord );
        int_rdmCol = RNG( 0, int_qrtCoord - int_rdmRow );
        break;
    default:
        matrice_Map[0][0]= REP_CHARACTER;
        int_rdmRow = RNG( int_maxCoord - int_qrtCoord, int_maxCoord );
        int_rdmCol = RNG( int_maxCoord - int_rdmRow + int_qrtCoord, int_maxCoord );
        break;
    } 
    matrice_Map[int_rdmRow][int_rdmCol] = REP_END ;
    
    while( int_nbObstacles > 0 ) { //Placement des Obstacles
        int_rdmRow = RNG(0,int_maxCoord);
        int_rdmCol = RNG(0,int_maxCoord);
        if( CoordCompare(matrice_Map, int_rdmRow, int_rdmCol, REP_DEFAULT) ) {
            switch (RNG(1,10) < 2)
            {
                case 0:
                    matrice_Map = PlaceObstacle(matrice_Map, int_rdmRow, int_rdmCol, int_mapSize, float_diffRate, 1, REP_OBSTACLE1);
                    break;
                case 1:
                    matrice_Map = PlaceObstacle(matrice_Map, int_rdmRow, int_rdmCol, int_mapSize, float_diffRate, 1, REP_OBSTACLE2);
                    break;
            }
            int_nbObstacles-- ;
        }
    }
    while( int_nbBonus > 0 ) { //Placement des Bonus
        int_rdmRow = RNG(0,int_maxCoord);
        int_rdmCol = RNG(0,int_maxCoord);
        printf("%d,%d\n", int_rdmRow, int_rdmCol);
        if( CoordCompare(matrice_Map, int_rdmRow, int_rdmCol, REP_DEFAULT) ) {
            int_nbBonus--;
            switch (RNG(1,2))
            {
                case 1:
                    matrice_Map[int_rdmRow][int_rdmCol] = REP_BONUS1;
                    break;
                case 2:
                    matrice_Map[int_rdmRow][int_rdmCol] = REP_BONUS2;
                    break;
            }
        }
    }

    for( int i = 0 ; i<int_mapSize; i++) { //fill the left empty space 
       for( int j = 0 ; j<int_mapSize ; j++){
            if( CoordCompare(matrice_Map, i, j, REP_DEFAULT) ){
                matrice_Map[i][j] = REP_VOID;
            }
        }
    }
    return (matrice_Map);
}



int*** Generatematrice_Distance(int int_mapSize, int*** matrice_Distance)
{
    for ( int i = 0; i < int_mapSize; i++)
    {
        for(int j = 0;j<int_mapSize;j++)
        {
        matrice_Distance[i][j][1] = RNG(1,10);
        matrice_Distance[i][j][3] = RNG(1,10);
        matrice_Distance[i][j][5] = RNG(1,10);
        matrice_Distance[i][j][7] = RNG(1,10);
        matrice_Distance[i][j][0] = sqrt(square(matrice_Distance[i][j][1]) + square(matrice_Distance[i][j][7]));
        matrice_Distance[i][j][2] = sqrt(square(matrice_Distance[i][j][1]) + square(matrice_Distance[i][j][3]));
        matrice_Distance[i][j][4] = sqrt(square(matrice_Distance[i][j][3]) + square(matrice_Distance[i][j][5]));
        matrice_Distance[i][j][6] = sqrt(square(matrice_Distance[i][j][5]) + square(matrice_Distance[i][j][7]));
        }
    }
    return (matrice_Distance);
}

void DisplayMatriceDistance(int int_mapSize, int*** matrice_Distance)
{
    for(int p = 0; p < int_mapSize; p++)
    {
        for ( int m = 0; m < int_mapSize; m++)
        {
            printf("[");
            for ( int n = 0; n < 8; n++)
            {
                printf("%d,", matrice_Distance[p][m][n]);
            }
            printf("],");
        }
    printf("\n");
    }
}


#endif

