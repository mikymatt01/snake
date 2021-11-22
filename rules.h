#include "drawer.h"

int getch();
void move(Drawer h, char cmd, char ch);
void movequeue(Drawer h, char cmd, char ch);
int controller(Drawer h, Drawer i);
int out(Drawer h, Drawer d);
Drawer createapple(Drawer d);
void wait();