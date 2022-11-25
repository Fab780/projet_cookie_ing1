#ifndef CONSTANT_H
#define CONSTANT_H

    #define LARGEUR_CONSOLE 80
    #define MALLOC(x)((x * ) malloc(sizeof(x)))

    #define TAILLE_BIG_MAP 30
    #define TAILLE_AVE_MAP 20
    #define TAILLE_LIL_MAP 10

    #define TAUX_DIFF_EZ 0.7
    #define TAUX_DIFF_NORMAL 1.15
    #define TAUX_DIFF_HARD 1.9

    #define BASE_ENERGY 20
    #define GAIN_ENERGY 10
    #define LOST_ENERGY 10

    #define REP_CHARACTER 'P'
    #define REP_BONUS1 'b'
    #define REP_BONUS2 'B'
    #define REP_OBSTACLE1 'o'
    #define REP_OBSTACLE2 'O'
    #define REP_VOID '0'
    #define REP_END 'D'
    #define REP_DEFAULT 'X'

    #define BONUS_COOKIE "\U0001f36a"
    #define BONUS_APPLE "\U0001f34e"
    #define CHARACTERE "\U0001f57a"
    #define OBSTACLE_TREE "\U0001f384"
    #define OBSTACLE_BEE "\U0001f41d"
    #define VOID "  "
    #define END "\U0001f3c1"
    #define START "\U0001F43e"
    #define ERROR "\U0001F232"


    #define CORNER_LEFT " "//"\uff3b"
    #define CORNER_RIGHT " "//"\uff3d"
    #define DOWNBAR "\uff3f"
    #define UPBAR "\uffe3"

    #define UP_ARROW "\U00002191"
    #define DOWN_ARROW "\U00002193"
    #define LEFT_ARROW "\U00002190"
    #define RIGHT_ARROW "\U00002192"
    #define UP_LEFT_ARROW "\U00002196"
    #define UP_RIGHT_ARROW "\U00002197"
    #define DOWN_LEFT_ARROW "\U00002199"
    #define DOWN_RIGHT_ARROW "\U00002198"
    #define STEP_BACK_ICON "\U000027f2"
    #define SAVE_ICON "\U0001f4be"


    #define UP 122
    #define DOWN  120
    #define LEFT  113
    #define RIGHT 100
    #define UP_LEFT 97
    #define UP_RIGHT  101
    #define DOWN_LEFT  119
    #define DOWN_RIGHT 99
    #define STEP_BACK 114
    #define SAVE 112

#endif
