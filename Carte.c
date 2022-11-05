#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

#define MALLOC(x)((x * ) malloc(sizeof(x)))

#define TAILLE_BIG_MAP 30
#define TAILLE_AVE_MAP 20
#define TAILLE_LIL_MAP 10

#define TAUX_DIFF_EZ 0.2
#define TAUX_DIFF_NORMAL 0.4
#define TAUX_DIFF_HARD 0.7

#define REP_CHARACTER 'P'
#define REP_BONUS 'B'
#define REP_OBSTACLE 'C'
#define REP_VOID '0'
#define REP_END 'D'

int RNG(int min, int max)
{
    return ( ( rand() % (max + min - 1) ) + min );
}

void UnallocMap(int** matrice_Map, int int_mapSize)
{
    for(int i = 0; i<int_mapSize ; i++){
        free( matrice_Map[i]);
    }
    free(matrice_Map);
    return;
}   

int** AllocMap(int int_mapSize)
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

int** GenerateMap(int** matrice_Map, int int_mapSize) //Work In Progress
{
    int int_maxCoord = int_mapSize - 1 ;
    int int_qrtCoord = int_mapSize / 4 ;
    int int_rdmRow;
    int int_rdmCol = int_mapSize;
    int rdm = RNG(1,4) ;                
    switch ( rdm ) //Placement du personnages aleatoirement dans un des 4 coins de la map, et placement du drapeau en consequence semi-aléatoirement
    {
    case 2:
        matrice_Map[int_maxCoord][0]= REP_CHARACTER;
        int_rdmRow = RNG( 0, int_qrtCoord );
        while ( int_rdmCol >= int_maxCoord + ( int_maxCoord - int_qrtCoord - int_rdmRow ) )
        {
            int_rdmCol = RNG( int_maxCoord - int_qrtCoord, int_maxCoord );
        }
        break;
    case 3:
        matrice_Map[0][int_maxCoord]= REP_CHARACTER;
        int_rdmRow = RNG( int_qrtCoord, int_maxCoord );
        while ( int_rdmCol <= int_rdmRow - int_qrtCoord )
        {
            int_rdmCol = RNG( 0, int_qrtCoord );
        }
        break;
    case 4:
        matrice_Map[int_maxCoord][int_maxCoord]= REP_CHARACTER;
        int_rdmRow = RNG( 0, int_qrtCoord );
        while ( int_rdmCol <= int_maxCoord - int_qrtCoord - int_rdmRow + 1)
        {
            int_rdmCol = RNG( 0, int_qrtCoord );
        }
        break;
    default:
        matrice_Map[0][0]= REP_CHARACTER;
        int_rdmRow = RNG( int_qrtCoord, int_maxCoord );
        while ( int_rdmCol >= int_maxCoord - int_rdmRow + int_qrtCoord + 1)
        {
            int_rdmCol = RNG( int_qrtCoord, int_maxCoord );
        }
        break;
    } 
    printf("%d: %d,%d\n", rdm ,int_rdmRow,int_rdmCol);
    matrice_Map[int_rdmRow][int_rdmCol] = REP_END ;

    for( int i = 0 ; i<int_mapSize; i++) { 
       for( int j = 0 ; j<int_mapSize ; j++){
            if( matrice_Map[i][j] == NULL ){
                matrice_Map[i][j] = '0';
            }
        }
    }
    return (matrice_Map);
}

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

int main(void)
{
    srand(time(NULL)); //initialisation d'un tier pour la RNG
    int int_mapSize = TAILLE_AVE_MAP;
    int **matrice_Map = AllocMap(int_mapSize);
    matrice_Map = GenerateMap(matrice_Map, int_mapSize);
    DebugDisplayMap(matrice_Map, int_mapSize);  
    UnallocMap(matrice_Map, int_mapSize);

    
    

  

    return 0;
}

