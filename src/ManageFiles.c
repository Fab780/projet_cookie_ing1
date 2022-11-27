#include "ManageFiles.h"

int ExistFile(char char_NameFile[])
{
    FILE* File = fopen(char_NameFile, "r+");  
    if (File == NULL){// Le fichier n'existe pas
        return 0;
    }else{// Le fichier existe  
        fclose(File);
        return 1;
    }
}

void createFile(char char_NameFile[])
{
    FILE* File = fopen(char_NameFile, "w+");  
        fclose(File);
}

int SupprFile(char char_NameFile[])
{
    int int_A = ExistFile(char_NameFile);
    if (int_A == 0){// Le fichier n'existe pas, on ne peut donc pas le supprimer
        return 0;
    }else{// Le fichier existe, on le supprime
        remove(char_NameFile);
        return 1;
    }
}

