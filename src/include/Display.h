#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include "Constant.h"
#include "Miscellanous.h"

void DebugDisplayMap(int** matrice_Map, int int_mapSize)
{
    for( int i = 0 ; i<int_mapSize; i++) { 
        printf("%d> ", i);
       for( int j = 0 ; j<int_mapSize; j++){
            printf("%c", matrice_Map[i][j]);
            if(j != int_mapSize - 1) {
                printf(",");
            } else {
                printf("\n");
            }
        }
        if(i != int_mapSize - 1) {
            printf(";");
        } else {
            printf("\n");
        }
    }
    return;
}

void DisplayMap(int** matrice_Map, int int_mapSize)
{
    int int_curseur = 0;
    char* constant_caseDisplay = ERROR;

    system("clear");
    for(int i=0; i<int_mapSize*3; i++)
    {
        printf("%s", DOWNBAR);
    }
    printf("\n");
    for(int int_curseurBis = 0; int_curseurBis < int_mapSize; int_curseurBis++)
    {
        while ( (int_curseur+1)%(int_mapSize+1) != 0 )
        {
            switch (matrice_Map[int_curseurBis][int_curseur])
            {
                case REP_CHARACTER :
                    constant_caseDisplay = CHARACTERE;
                    break;
                
                case REP_END :
                    constant_caseDisplay = END;
                    break;
                
                case REP_BONUS1 :
                    constant_caseDisplay = BONUS_COOKIE;
                    break;
                
                case REP_BONUS2 :
                    constant_caseDisplay = BONUS_APPLE;
                    break;
                
                case REP_OBSTACLE1 :
                    constant_caseDisplay = OBSTACLE_TREE;
                    break;

                case REP_OBSTACLE2 :
                    constant_caseDisplay = OBSTACLE_BEE;
                    break;
                
                case REP_VOID :
                    constant_caseDisplay = VOID;
                    break;

                case REP_DEFAULT :
                    constant_caseDisplay = ERROR;
                    break;
                
                default :
                    constant_caseDisplay = ERROR;
                    break;
            
            }
            printf("%s%s%s", CORNER_LEFT, constant_caseDisplay, CORNER_RIGHT);
            int_curseur++;
        }
        printf("\n");
        int_curseur = 0;
    }
    for(int i=0; i<int_mapSize*3; i++)
    {
        printf("%s", UPBAR);
    }
    printf("\n");
    // printf_center("TESTETSTETETETDVGEYGUA\n");
}

#endif