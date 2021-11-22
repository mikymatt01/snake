#include "drawer.h"
#include <stdio.h>
#include <stdlib.h>

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))//x righe e y colonne
#define put(c) putc((c),stdout)

struct drawer {
    int width;
    int height;
    //int tileset[][];
};

Drawer newDrawer(int width, int height) {
    Drawer drawer = malloc(sizeof(struct drawer));
    drawer->width=width;
    drawer->height=height;
    return drawer;
}

void drawPlayground(Drawer draw) {
	int i,j, width ,height;
	width=draw->width;
	height=draw->height;
	clear();
	for(i=0; i<=height; i++)
	        for(j=1; j<=width; j++)
	        {
	                gotoxy(j,i);
	                if((i==1 || i==height) && (j==1 || j==width))
	                        put('+');
	                else if(i==1 || i==height)
	                        put('-');
	                else if(j==1 || j==width)
	                        put('|');
	        }

}

int getwidth(Drawer drawer) {
    return drawer->width;
}

int getheight(Drawer drawer) {
    return drawer->height;
}

void changeDrawer(Drawer drawer, Drawer delta){
	drawer->width+=delta->width;
	drawer->height+=delta->height;
}

void draw(Drawer drawer, char c){
	gotoxy(drawer->width, drawer->height);
	put(c);
}

Drawer clone(Drawer d){
	Drawer f=newDrawer(d->width, d->height);
	return f;
}

void resetcursor(){
	gotoxy(0,0);
}
