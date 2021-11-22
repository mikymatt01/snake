#include "drawer.h"

typedef struct list *List;
typedef struct node *Node;


List newList();
void print(List l, Drawer d, char ch);
void addHead(List l, char c);
void removeHead(List l);
void removeLast(List l);
int length(List l);
int isempty(List l);