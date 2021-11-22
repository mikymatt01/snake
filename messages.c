#include "drawer.h"
#include <stdio.h>
#include <stdlib.h>

#define SLEEP 50000000
void lose(Drawer d, char *s){
    int i;
    while(*s){
        draw(d,*(s++));
        changeDrawer(d, newDrawer(1,0));
        fflush(stdout);
        for(i=0;i<SLEEP;i++);
    }
}