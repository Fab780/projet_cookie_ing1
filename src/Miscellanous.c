#include "Miscellanous.h"

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


Node *createNode(coordonnees coordonnees_player)
{
    Node *node = malloc(sizeof(Node));
    if(!node){
        return NULL;
    }
    node->coordonnees_player = coordonnees_player;
    node->next = NULL;
    return node;
}


List *emptyList(void)
{
    return NULL;
}

int isEmpty(List *List_L)
{
    return List_L == NULL;
}

long lengthList(List *List_L)
{
    long long_taille = 0;
    while(List_L){
        long_taille++;
        List_L = List_L->next;
    }
    return long_taille;
}

List *addnode(List *List_L, coordonnees coordonnees_player)
{       
    Node *node = createNode(coordonnees_player);
    if(isEmpty(List_L)){
        return node;
    }
    node->next = List_L;
    return node;
}

List *freeLastCoord(List *List_L)
{
    List *tmp = List_L;
    if(isEmpty(List_L)){
        return NULL;
    }
    List_L = List_L->next;
    free (tmp);
    return List_L;
}

List *freeList(List *List_L)
{
    List *tmp = NULL;
    while(List_L){
        tmp = List_L->next;
        free(List_L);
        List_L = tmp;
    }
    return List_L;
}

void printList(List *List_L) // affiche les coordonées contenues dans la pile, les premières coordonnées sont affichées en bout de ligne
{
    while(!isEmpty(List_L)){
        printf(" x = %d, y = %d ", List_L->coordonnees_player.int_x, List_L->coordonnees_player.int_y);
        List_L = List_L->next;
    }
    printf("\n");
}