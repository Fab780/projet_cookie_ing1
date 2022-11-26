#include <stdio.h>
#include <stdlib.h>
#include <time.h>   
#include "Miscellanous.h"
#include "Display.h"
#include "Movements.h"
#include "InitGame.h"
#include "ManageFiles.h"

int main(void)
{
    // system("resize -s 0 0");
    system("wmctrl -r :ACTIVE: -b add,maximized_vert,maximized_horz");

    float float_diffRate = ChooseDifficulty();
    int int_mapSize = ChooseMapSize();
    PlayerInfo s_playerInfo_player = SetupPlayer(); 
    s_playerInfo_player.int_energy = InitEnergy(int_mapSize, s_playerInfo_player.int_energy);
    int int_victory = 0;

    srand(time(NULL)); //init RNG
    int** matrice_Map = InitMap(int_mapSize, 
                                float_diffRate,
                                &s_playerInfo_player);
    int*** matrice_Distance = InitDistance(int_mapSize);
 
    DisplayMap(matrice_Map, int_mapSize);
    //DebugDisplayMatriceDistance(int_mapSize, matrice_Distance);
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
