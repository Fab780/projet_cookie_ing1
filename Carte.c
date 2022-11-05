#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define MALLOC(x)((x * ) malloc(sizeof(x)))

#define TAILLE_BIG_MAP 50
#define TAILLE_AVE_MAP 25
#define TAILLE_LIL_MAP 10

#define TAUX_DIFF_EZ 0.2
#define TAUX_DIFF_NORMAL 0.4
#define TAUX_DIFF_HARD 0.7

char** AllocMap(int int_mapSize)
{
    char** matrice_Map = malloc(int_mapSize * sizeof(char*));
    for(int i = 0 ; i < int_mapSize ; i++ ) {
        matrice_Map[i] = malloc(int_mapSize * sizeof(char));
    }
    return matrice_Map;
}

char** GenerateMap(int int_mapSize, char** matrice_Map) //Work In Progress
{
    for( int i = 0 ; i<int_mapSize; i++) { 
       for( int j = 0 ; j<int_mapSize ; j++){
            matrice_Map[i][j] = 'P';
        }
    }
    return matrice_Map;
}


int main(void)
{
    int int_mapSize = TAILLE_AVE_MAP;
    char** matrice_Map = AllocMap(int_mapSize);
    matrice_Map = GenerateMap(int_mapSize, matrice_Map);
    

    for( int i = 0 ; i<int_mapSize; i++) { 
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

    return 0;
}



// void CalcNbBonusAndBonus()

// int int_mapSize = 5;
//     char** matrice_Map = GenerateMap(int_mapSize);
//     printf("test");
//     for( int i = 0 ; i<int_mapSize ; i++) { 
//         for( int j = 0 ; j<int_mapSize ; j++){
//             printf("%c,", matrice_Map[i][j]);
//         }
//         printf(";"); 
//     }

// char matrice_Map[int_mapSize][int_mapSize];
//     for( int i = 0 ; i<int_mapSize; i++) { 
//         for( int j = 0 ; j<int_mapSize ; j++){
//             matrice_Map[i][j] = '0';
//             printf("gjnrio \n");
//         }
//          printf("test\n");
//     }
//     printf("test2");
//     return &matrice_Map;