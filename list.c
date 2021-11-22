#include "list.h"
#include "drawer.h"
#include "list.h"
#include "rules.h"

#include <stdlib.h>
#include <stdio.h>

struct node{
    char value;
    Node next;
};

struct list{
    Node head;
    int length;
};

List newList(){
    List l= malloc(sizeof(struct list));
    l->head=NULL;
    l->length=0;

    return l;
}

void print(List l, Drawer d, char ch){
    char c=ch;
    Drawer f=clone(d);
    Node n = malloc(sizeof(struct node));

    for(n=l->head; n!= NULL; n=n->next){
        movequeue(f, n->value, c);
        f=clone(f);
    }
}

void addHead(List l, char c){
    Node n = malloc(sizeof(struct node));
    n->value=c;
    n->next = l->head;
    l->head = n;
    l->length++;
}
void removeHead(List l){
    Node n = malloc(sizeof(struct node));
    n=l->head;
    n=n->next;
    free(l->head);
    l->head=n;
    l->length--;
}
void removeLast(List l){
    if(l->length==1)
        removeHead(l);
    else{
        Node n = malloc(sizeof(struct node));
        Node prev = malloc(sizeof(struct node));
        
        for(n=l->head; n->next!=NULL ;prev=n, n=n->next);
        free(n);
        prev->next=NULL;
        l->length--;
    }
}

int length(List l){
    return l->length;
}

int isempty(List l){
    if(l->head == NULL)
        return 1;
    return 0;
}