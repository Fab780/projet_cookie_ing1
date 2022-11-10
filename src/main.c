#include "include/InitGame.h"
#include "include/Display.h"
#include "include/Movements.h"

int main(void)
{
    float float_diffRate = ChooseDifficulty();
    int int_mapSize = ChooseMapSize();
    PlayerInfo s_playerInfo_player = SetupPlayer(); 
    int int_energy = InitEnergy(int_mapSize, &s_playerInfo_player);

    int **matrice_Map = AllocMatriceMap(int_mapSize);
    matrice_Map = InitMatriceMap(matrice_Map, int_mapSize);

    srand(time(NULL)); //init RNG
    matrice_Map = GenerateMap(matrice_Map, int_mapSize, float_diffRate, &s_playerInfo_player);

    DisplayMap(matrice_Map, int_mapSize); 
    printf("Votre energie : %d\n",s_playerInfo_player.int_energy);
    printf("Vos coordonnées: %d , %d\n",s_playerInfo_player.int_x,s_playerInfo_player.int_y);

    // matrice_Map = AfterMovement(matrice_Map, 4, 5, &s_playerInfo_player, int_mapSize);
    // DisplayMap(matrice_Map, int_mapSize); 
    // printf("Votre energie : %d\n",s_playerInfo_player.int_energy);
    // printf("Vos coordonnées: %d , %d\n",s_playerInfo_player.int_x,s_playerInfo_player.int_y);
    // DebugDisplayMap(matrice_Map, int_mapSize);  

    UnallocMatriceMap(matrice_Map, int_mapSize);
    return 0;
}
