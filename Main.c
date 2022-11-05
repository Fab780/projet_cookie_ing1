#include <stdio.h>
#include <stdlib.h>
#include "Constante.h"
#include "Carte.h"
#include "CarteAndMovement.h"
#include "StartGame.h"

int ExistFile(char Nomfichier[]){
    FILE* fichier = fopen(Nomfichier, "r+");  
    if (fichier == NULL){// Le fichier n'existe pas
        return 0;
    }else{// Le fichier existe  
        fclose(fichier);
        return 1;
    }
}

void createFile(char Nomfichier[]){
    FILE* fichier = fopen(Nomfichier, "w+");  
        fclose(fichier);
}

int SupprFile(char Nomfichier[]){
    int A = ExistFile(Nomfichier);
    if (A == 0){// Le fichier n'existe pas, on ne peut donc pas le supprimer
        return 0;
    }else{// Le fichier existe, on le supprime
        remove(Nomfichier);
        return 1;
    }
}

// Test
// int main(){
//     int a = SupprFile("bonjour");
//     printf("%d \n", a);
//     return 0;
// }