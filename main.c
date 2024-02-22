#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <pthread.h>

#include "drawer.h"
#include "rules.h"
#include "messages.h"
#include "list.h"

#define WIDTH 60
#define HEIGHT 30

struct arg1{
    char *cmd;
    Drawer h;
    Drawer d;
};

struct arg2{
    char *cmd;
    Drawer h;
    Drawer d;
    Drawer a;
    List queue;
};

void* input(void *arg){
    struct arg1 *argument = arg;
    char *cmd = argument->cmd;
    Drawer h = argument->h;
    Drawer d = argument->d;
    while(out(h, d)){
        *cmd = getch();
    }
}

void* play(void *arg){
    struct arg2 * argument= arg;
    char *cmd = argument->cmd;
    Drawer h = argument->h;
    Drawer d = argument->d;
    Drawer a = argument->a;
    List queue = argument->queue;
    while(out(h, d)){
        resetcursor();
        fflush(stdout);
        waitFor();
        print(queue, h, ' ');
        addHead(queue, *cmd);
        removeLast(queue);
        move(h, *cmd, 'o');
        print(queue, h, '+');
        if(controller(h,a))
        {
            print(queue, h, ' ');
            addHead(queue, *cmd);
            draw(a, 'o');
            a=createapple(d);
            print(queue, h, '+');
        }
    }
    Drawer c = newDrawer((WIDTH/2)-6, HEIGHT/2);
    lose(c, "you are lose\n");
    c = newDrawer((WIDTH/2)-7, (HEIGHT/2)+1);
    lose(c, "your score is: ");
    printf("%d\n",length(queue));
    c = newDrawer((WIDTH/2)-11, (HEIGHT/2)+2);
    lose(c, "press a key to continue");
}

int main(int argc, char* argv[]) {
    
    char match='y';
    
    while(match == 'y'){

        List queue = newList();
        Drawer d = newDrawer(WIDTH, HEIGHT);
        Drawer h = newDrawer(WIDTH/2,HEIGHT/2);
        Drawer a;
        char cmd = 'w';
        drawPlayground(d);
        draw(h, 'o');
        a=createapple(d);

        struct arg1 ar1;
        ar1.cmd=&cmd;
        ar1.h=h;
        ar1.d=d;
        struct arg2 ar2;
        ar2.cmd=&cmd;
        ar2.h=h;
        ar2.d=d;
        ar2.a=a;
        ar2.queue=queue;

        pthread_t th1, th2;

        pthread_create(&th1, NULL, input, (void *)&ar1);
        pthread_create(&th2, NULL, play, (void *)&ar2);

        pthread_join(th1, NULL);
        pthread_join(th2, NULL);

        pthread_cancel(th1);
        pthread_cancel(th2);
        
        Drawer c = newDrawer((WIDTH/2)-11, (HEIGHT/2)+3);
        lose(c, "do you want to replay? ");
        match=getchar();
    }

        Drawer c = newDrawer(1, HEIGHT+1);
        draw(c,' ');
    return 0;
}
