#include "Miscellanous.h"s

int RNG(int min, int max)
{
    return ( ( rand() % (max - min + 1) ) + min );
}

int CoordCompare(int** matrice_map, int int_x, int int_y, char constant_rep)
{
    return (matrice_map[int_x][int_y] == constant_rep);
}

int IsBetween(int int_Comp, int int_min, int int_max){
    return (int_Comp >= int_min && int_Comp <= int_max);
}

void printf_center(const char* str)
{
    unsigned int n;
    for (n = 0; n < (204-strlen(str)) / 2; n++)
    {
        putchar(' ');
    }
    printf("%s", str);
}

void InitRNG()
{
    srand(time(NULL)); //init RNG
}

