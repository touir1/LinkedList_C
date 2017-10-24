#include <stdio.h>
#include <string.h>
#include "types.h"

LinkedList* createLinkedList(char* name,TYPES type){
    LinkedList* result = (LinkedList*) malloc(sizeof(LinkedList));
    result->head = NULL;
    result->name = (char*) malloc(sizeof(char)*MAXSTR);
    strcpy(result->name, name);
    result->type = type;
    result->listSize = 0;
    return result;
}

Node* createNode(void* value){
    Node* node = (Node*) malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;
    return node;
}

boolean removeNode(LinkedList* L, int pos){
    if(0 <= pos < L->listSize){
        Node* n =L->head;
        if(!pos){
            L->head = L->head->next;
        }
        else{
            int now = 0;
            while(now<pos-1){
                n = n->next;
                now++;
            }
            Node* tmp = n->next;
            n->next = n->next->next;
            n = tmp;
        }
        free(n);
        L->listSize--;
        return TRUE;
    }
    else{
        return FALSE;
    }
}

boolean removeFirstWithValue(LinkedList* L, void* value){
    Node *last = NULL, *now = L->head;
    int count = 0;
    while(now->value != value && count < L->listSize){
        last = now;
        now = now->next;
        count++;
    }
    if(now->value == value){
        last->next = now->next;
        free(now);
        L->listSize--;
        return TRUE;
    }
    return FALSE;
}

boolean removeLastWithValue(LinkedList* L, void* value){
    Node *last = NULL, *now = L->head, *before = NULL, *after= NULL;
    int count = 0;
    while(count < L->listSize){
        while(count < L->listSize && now!=NULL && now->value != value){
            last = now;
            now = now->next;
            count++;
        }
        if(now!=NULL && now->value == value){
            before = last;
            after = now;
            last = now;
            now = now->next;
        }
        count++;

    }
    if(before != NULL && after != NULL){
        before->next = after->next;
        free(after);
        L->listSize--;
        return TRUE;
    }
    return FALSE;
}

boolean addBeforeFirstValue(LinkedList* L, Node* node, void* value){
    /***TODO*/
    return FALSE;
}

boolean addAfterLastValue(LinkedList* L, Node* node, void* value){
    /***TODO*/
    return FALSE;
}

boolean addToList(LinkedList* L, Node* node, int pos){
    if(!pos){
        node->next = L->head;
        L->head = node;
        L->listSize++;
        return TRUE;
    }
    else if(pos==L->listSize){
        Node* now = L->head;
        while(now->next!=NULL)
            now = now->next;
        now->next = node;
        L->listSize++;
        return TRUE;
    }
    else if(pos>0 && pos<L->listSize){
        Node* save = L->head;
        int now = 0;
        while(now<pos-1){
            save = save->next;
            now++;
        }
        node->next = save->next;
        save->next = node;
        L->listSize++;
        return TRUE;
    }
    else
        return FALSE;
}

void printLinkedList(LinkedList* L){
    Node* node = L->head;
    printf("%s: [",L->name);
    boolean first = TRUE;
    while(node!=NULL){
        switch(L->type){
            case FLOAT: if(first){ printf("%.2f",node->value); first = FALSE;} else printf(", %.2f",node->value); break;
            case INTEGER: if(first){ printf("%d",node->value); first = FALSE;} else printf(", %d",node->value); break;
            case STRING: if(first){ printf("%s",node->value); first = FALSE;} else printf(", %s",node->value); break;
            default: if(first){ printf("%x",node->value); first = FALSE;} else printf(", %x",node->value); break;
        }
        node = node->next;
    }
    printf("]\n");
}

void destroyLinkedList(LinkedList* L){
    Node* now = L->head;
    while(now != NULL){
        Node* next = now->next;
        free(now);
        now = next;
    }
    free(L->name);
    free(L);
}
