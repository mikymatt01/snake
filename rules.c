#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <time.h>
#include <stdlib.h>
#include "drawer.h"

#define SLEEP 10000

int getch() {
   struct termios oldtc;
   struct termios newtc;
   int ch;
   do{
        tcgetattr(STDIN_FILENO, &oldtc);
        newtc = oldtc;
        newtc.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newtc);
        ch=getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldtc);
    }while(ch!='w' && ch!='a' && ch!='s' && ch!='d');
   return ch;
}

void move(Drawer h, char cmd, char ch){
    Drawer delta;
    if(cmd=='w')
        delta=newDrawer(0,-1);
    else if(cmd=='s')
        delta=newDrawer(0,1);
    else if(cmd=='a')
        delta=newDrawer(-1,0);
    else if(cmd=='d')
        delta=newDrawer(1,0);
    draw(h, ' ');
    changeDrawer(h, delta);
    draw(h, ch);
}

void movequeue(Drawer h, char cmd, char ch){
    Drawer delta;
    if(cmd=='w')
        delta=newDrawer(0,1);
    else if(cmd=='s')
        delta=newDrawer(0,-1);
    else if(cmd=='a')
        delta=newDrawer(1,0);
    else if(cmd=='d')
        delta=newDrawer(-1,0);
    //draw(h, ' ');
    changeDrawer(h, delta);
    draw(h, ch);
}

int controller(Drawer h, Drawer i){
    if((getwidth(h) == getwidth(i)) && (getheight(h) == getheight(i)))
        return 1;
    return 0;   
}

int out(Drawer h, Drawer d){
    if(getwidth(h) == 0)
        return 0;
    if(getheight(h) == 0)
        return 0;
    if(getwidth(h) == getwidth(d))
        return 0;
    if(getheight(h) == getheight(d))
        return 0;
    return 1;   
}
Drawer createapple(Drawer d){
    int x,y;
    srand(time(NULL)); 
    do{  // Initialization, should only be called once.
        x = rand() % getwidth(d);
        y = rand() % getheight(d);
    }while((x<=1) || (y<=1));
    Drawer apple = newDrawer(x,y);
    draw(apple,'@');
    return apple;
}

void waitFor(){
    for(int j=0; j<SLEEP; j++)
        for(int i=0;i<SLEEP;i++);
}