#include "include/InitGame.h"
#include "include/Display.h"
#include "include/Movements.h"

int main(void)
{
    float float_diffRate = ChooseDifficulty();
    int int_mapSize = ChooseMapSize();
    PlayerInfo s_playerInfo_player = SetupPlayer(); 
    s_playerInfo_player.int_energy = InitEnergy(int_mapSize, s_playerInfo_player.int_energy);
    int int_victory = 0;

    int **matrice_Map = AllocMatriceMap(int_mapSize);
    matrice_Map = InitMatriceMap(matrice_Map, int_mapSize);
    int*** matrice_Distance= AllocMatriceDistance(int_mapSize);

    srand(time(NULL)); //init RNG
    
    int bool_mapDoable = 0;
    while(!bool_mapDoable)  //Generation d'une Map Faisable
    {
        matrice_Map = InitMatriceMap(matrice_Map, int_mapSize);
        matrice_Map = GenerateMap(matrice_Map, int_mapSize, float_diffRate, &s_playerInfo_player);
        bool_mapDoable = CheckMapDoable(matrice_Map, s_playerInfo_player.int_x, s_playerInfo_player.int_y, int_mapSize);
    }
    
    matrice_Distance = GenerateMatriceDistance(int_mapSize, matrice_Distance);

    DisplayMap(matrice_Map, int_mapSize);
    // DebugDisplayMatriceDistance(int_mapSize, matrice_Distance);
    printf("Votre energie : %d\n",s_playerInfo_player.int_energy);

    int key_pressed;
    int int_wanted_x;
    int int_wanted_y;
    while(int_victory == 0){
        key_pressed = ListenKeyboard();
        ChangePosition(key_pressed, &int_wanted_x, &int_wanted_y, &s_playerInfo_player); 
        matrice_Map = AfterMovement(matrice_Map, int_wanted_x, int_wanted_y, &s_playerInfo_player, int_mapSize, &int_victory);
        printf("\n"); 
        DisplayMap(matrice_Map, int_mapSize); 
        printf("Votre energie : %d\n",s_playerInfo_player.int_energy);
    }
    // DebugDisplayMap(matrice_Map, int_mapSize);  

    UnallocMatriceMap(matrice_Map, int_mapSize);
    UnallocMatriceDistance(matrice_Distance, int_mapSize);
    return 0;
}
