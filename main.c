#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
    LinkedList* L = NULL;
    L = createLinkedList("liste 1",INTEGER);
    printLinkedList(L);
    Node* node = createNode(10);
    if(addToList(L,node,0))
        printf("node with value %d added to list at position %d\n",10,0);
    else
        printf("error while adding to list\n");
    printLinkedList(L);
    node = createNode(25);
    if(addToList(L,node,0))
        printf("node with value %d added to list at position %d\n",25,0);
    else
        printf("error while adding to list\n");
    printLinkedList(L);
    node = createNode(-5);
    if(addToList(L,node,2))
        printf("node with value %d added to list at position %d\n",-5,2);
    else
        printf("error while adding to list\n");
    printLinkedList(L);
    node = createNode(2);
    if(addToList(L,node,1))
        printf("node with value %d added to list at position %d\n",2,1);
    else
        printf("error while adding to list\n");
    printLinkedList(L);
    node = createNode(2);
    if(addToList(L,node,3))
        printf("node with value %d added to list at position %d\n",2,3);
    else
        printf("error while adding to list\n");
    printLinkedList(L);
    node = createNode(2);
    if(addToList(L,node,3))
        printf("node with value %d added to list at position %d\n",2,3);
    else
        printf("error while adding to list\n");
    printLinkedList(L);
    node = createNode(2);
    if(addToList(L,node,6))
        printf("node with value %d added to list at position %d\n",2,6);
    else
        printf("error while adding to list\n");
    printLinkedList(L);
    printf("remove from position %d\n",1);
    removeNode(L,1);
    printLinkedList(L);
    printf("remove first with value %d\n",2);
    removeFirstWithValue(L,2);
    printLinkedList(L);
    printf("remove last with value %d\n",2);
    removeLastWithValue(L,2);
    printLinkedList(L);
    destroyLinkedList(L);
    return 0;
}
