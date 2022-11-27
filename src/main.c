#include "Miscellanous.h"
#include "Display.h"
#include "Movements.h"
#include "InitGame.h"
#include "ManageFiles.h"

int main(void)
{
    EditTerminal();

    float float_diffRate = ChooseDifficulty();
    int int_mapSize = ChooseMapSize();
    PlayerInfo s_playerInfo_player = SetupPlayer(); 
    int int_victory = 0;
    
    InitRNG();

    int** matrice_Map = InitMap(int_mapSize, 
                                float_diffRate,
                                &s_playerInfo_player);
    int*** matrice_Distance = InitDistance(int_mapSize);
    
    DisplayMap(matrice_Map, int_mapSize);
    //DebugDisplayMatriceDistance(int_mapSize, matrice_Distance);
    printf("Votre energie : %d\n",s_playerInfo_player.int_energy);

    // coordonnees coordonnees_player;
    // coordonnees_player.int_x = 0;
    // coordonnees_player.int_y = 1;
    // List *list = emptyList();
    // list = addnode(list, coordonnees_player);
    // printList(list);
    // coordonnees_player.int_x = 5;
    // coordonnees_player.int_y = 10;
    // list = addnode(list, coordonnees_player);
    // printList(list);
    // list = freeLastCoord(list);
    // printList(list);

    int key_pressed;
    int int_wanted_x;
    int int_wanted_y;
    while(int_victory == 0 && s_playerInfo_player.int_energy > 0){
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
