
typedef struct drawer *Drawer;

Drawer newDrawer(int width, int height);

void drawPlayground(Drawer drawer);

int getwidth(Drawer drawer);

int getheight(Drawer drawer);

void changeDrawer(Drawer drawer, Drawer delta);

void draw(Drawer drawer, char c);

Drawer clone(Drawer d);

void resetcursor();
