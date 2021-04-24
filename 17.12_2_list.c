#include <stdio.h>
#include <stdlib.h>
#include "17.12_2_list.h"

void InitializeList(List *plist) {
    plist->head = NULL;
    plist->end = NULL;
}

bool ListIsEmpty(const List *plist) {
    if (plist->head == NULL && plist->end == NULL) {
        return true;
    } else {
        return false;
    }
}

bool ListIsFull(const List *plist) {
    Node *new_node;
    bool full;
    new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        full = true;
    } else {
        full = false;
    }
    free(new_node);
    return full;
}

unsigned int ListItemCount(const List *plist) {
    unsigned int count = 0;
    Node *pnode = plist->head;
    while (pnode != NULL) {
        count++;
        pnode = pnode->next;
    }
    return count;
}

bool AddItem(Item item, List *plist) {
    Node *new_node;
    if (ListIsFull(plist)) {
        puts("List is full");
        return false;
    }

    new_node = (Node *)malloc(sizeof(Node));
    new_node->item = item;
    new_node->next = NULL;
    if (ListIsEmpty(plist)) {
        plist->head = plist->end = new_node;
    } else {
        plist->end->next = new_node;
        plist->end = new_node;
    }
    return true;
}

void Traverse(const List *plist, void (*pfun)(Item item)) {
    Node *pnode = plist->head;
    while (pnode != NULL) {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

void EmptyTheList(List *plist) {
    Node *pnode;
    while (plist->head != NULL) {
        pnode = plist->head->next;
        free(plist->head);
        plist->head = pnode;
    }
}
