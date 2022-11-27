#include "Display.h"

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
}



//Fonctions de DEBUG pour dev, ne serons pas utiliser dans le process final

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

void DebugDisplayMatriceDistance(int int_mapSize, int*** matrice_Distance)
{
    for(int p = 0; p < int_mapSize; p++)
    {
        printf("ligne %d :", p);
        for ( int m = 0; m < int_mapSize; m++)
        {
            printf(" %d :[", m);
            for ( int n = 0; n < 8; n++)
            {
                if(n != 7) {
                    printf("%d,", matrice_Distance[p][m][n]);
                } else {
                    printf("%d", matrice_Distance[p][m][n]);
                }
                
            }
            printf("],");
        }
        printf("\n");
    }
}

void DebugInfoPlayer(PlayerInfo s_playerInfo_player)
{   
    printf("Votre position x : %d\n",s_playerInfo_player.coordonnees_player.int_x);
    printf("Votre position y : %d\n",s_playerInfo_player.coordonnees_player.int_y);
    printf("Votre energie : %d\n",s_playerInfo_player.int_energy);
    printf("Votre distance parcourue : %d\n",s_playerInfo_player.int_distance);
    printf("Votre energie gagnée : %d\n",s_playerInfo_player.int_gain_energy);
    printf("Votre energie perdue : %d\n",s_playerInfo_player.int_lost_energy);
    printf("Vos retour en arrière disponible : %d\n",s_playerInfo_player.int_backward);
}


void EditTerminal()
{
    system("\
coX=`xdpyinfo | grep dimensions | sed -r 's/^[^0-9]*([0-9]+x[0-9]+).*$/\\1/' | cut -d 'x' -f1`;\n\
coY=`xdpyinfo | grep dimensions | sed -r 's/^[^0-9]*([0-9]+x[0-9]+).*$/\\1/' | cut -d 'x' -f2`;\n\
resize -s `echo \"$(( $coY / 10 )) $(( $coX / 8 ))\"`>/dev/null;\n\
");

}