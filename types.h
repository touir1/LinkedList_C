#ifndef _TYPES_LINKEDLIST_H
#define _TYPES_LINKEDLIST_H_
#define MAX 100
#define MAXSTR (MAX+1)
#define TRUE 1
#define FALSE 0
typedef int boolean;

typedef enum {INTEGER=0, FLOAT=1, STRING=2, OTHER=3} TYPES;

typedef struct _Node{
    void* value;
    struct _Node* next;
} Node;

typedef struct _Tree{
    Node* head;
    TYPES type;
    int listSize;
    char* name;
} LinkedList;

#endif // _TYPES_LINKEDLIST_H
