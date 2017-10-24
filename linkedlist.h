#ifndef _LINKEDLIST_
#define _LINKEDLIST_
#include "types.h"

LinkedList* createLinkedList(char* name,TYPES type);
void printLinkedList(LinkedList* L);
void destroyLinkedList(LinkedList* L);
Node* createNode(void* value);
boolean addToList(LinkedList* L, Node* node, int pos);
boolean removeNode(LinkedList* L, int pos);
boolean removeFirstWithValue(LinkedList* L, void* value);
boolean removeLastWithValue(LinkedList* L, void* value);
boolean addBeforeFirstValue(LinkedList* L, Node* node, void* value);
boolean addAfterLastValue(LinkedList* L, Node* node, void* value);

#endif // _LINKEDLIST_
