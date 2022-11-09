#include "include/InitGame.h"
#include "include/Display.h"
#include "include/Movements.h"

int main(void)
{
    float float_diffRate = ChooseDifficulty();
    int int_mapSize = ChooseMapSize();

    int **matrice_Map = AllocMatriceMap(int_mapSize);
    matrice_Map = InitMatriceMap(matrice_Map, int_mapSize);

    srand(time(NULL)); //init RNG
    matrice_Map = GenerateMap(matrice_Map, int_mapSize, float_diffRate);

    DisplayMap(matrice_Map, int_mapSize); 

    // DebugDisplayMap(matrice_Map, int_mapSize);  

    UnallocMatriceMap(matrice_Map, int_mapSize);
    return 0;
}
