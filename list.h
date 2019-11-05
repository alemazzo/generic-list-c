
#include <stdlib.h>
#include <string.h>

#ifndef LISTMANAGER
#define LISTMANAGER

#define LIST struct List
#define LIST_ELEMENT struct ListElement
#define TO_INT(element) _to_int(element);
#define TO_CHAR(element) _to_char(element);
#define TO_STRING(element) _to_string(element);

struct List{
    //variabili
    LIST_ELEMENT *head;
    LIST_ELEMENT *coda;

    //funzioni
    void (*insert)(LIST *l, void * element);
    void *(*getElement)(LIST *l, int index);

};


struct ListElement{
    LIST_ELEMENT *prev;
    void * value;
    LIST_ELEMENT *next;
};

LIST List();
void _list_insert(LIST *l,void * element);
void * _list_element(LIST *l, int index);


LIST List(){
    LIST *l = (LIST *) malloc(sizeof(LIST));
    l->coda = NULL;
    l->head = NULL;

    l->insert = _list_insert;
    l->getElement = _list_element;
    return *l;
};

void _list_insert(LIST *l, void * element){

    LIST_ELEMENT *el;
    el  = (LIST_ELEMENT *) malloc(sizeof(LIST_ELEMENT));
    int dimension = sizeof(element) / sizeof(*element);
    el->value = malloc(dimension + 1);
    memset(el->value, '\0', dimension + 1);
    memcpy(el->value, element, dimension);
    el->prev = l->coda;
    el->next = NULL;

    if(l->head == NULL) l->head = el;

    if(l->coda != NULL){
        l->coda->next = el;
    }

    l->coda = el;
    
};

void * _list_element(LIST *l, int index){
    LIST_ELEMENT *el = l->head;
    for(int i = 0; i < index; i++) el = el->next;
    return el->value;
}


int _to_int(void * element){
    return *((int *) element);
}

char _to_char(void * element){
    return *((char *) element);
}

char * _to_string(void * element){
    return ((char *) element);
}

#endif