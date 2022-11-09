#ifndef MOVEMENTS_H
#define MOVEMENTS_H

#include <stdio.h>
#include <stdlib.h>
#include "Constant.h"
#include "Miscellanous.h"




#include <stdio.h>
#include <termios.h>

static struct termios old, current;

int main() {
    FILE* flux = stdin;
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    current = old; /* make new settings same as old settings */
    current.c_lflag &= ~ICANON; /* disable buffered i/o */
    current.c_lflag &= ~ECHO; /* set no echo mode */
    tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */

    int ch;
    ch = getc(flux);
    printf("Vous avez appuyé sur la touche %d.\n", ch);

    switch(ch) {
    case UP_ARROW:
        printf("UP WAS PRESSED\n");
        break;
    case DOWN_ARROW:
        printf("DOWN WAS PRESSED\n");
        break;
    case LEFT_ARROW:
        printf("LEFT WAS PRESSED\n");
        break;
    case RIGHT_ARROW:
        printf("RIGHT WAS PRESSED\n");
        break;
    default:
        printf("SOME OTHER SCROLL KEY PRESSED: %d\n", ch);
        break;
    }
    current.c_lflag |= ECHO; /* set echo mode */
    tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
    return 0;
}




#endif
