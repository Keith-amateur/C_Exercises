#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "17.12_3_list.h"

void InitializeList(List *plist) {
    plist->items = 0;
    memset(plist->entries, 0, sizeof(plist->entries));
}

bool ListIsEmpty(const List* plist) {
    if (plist->items == 0) {
        return true;
    } else {
        return false;
    }
}

bool ListIsFull(const List *plist) {
    if (plist->items == MAXSIZE) {
        return true;
    } else {
        return false;
    }
}

unsigned int ListItemCount(const List *plist) {
    return (unsigned int)plist->items;
}

bool AddItem(Item item, List *plist) {
    if (ListIsFull(plist)) {
        puts("List is full");
        return false;
    }
    int i;
    for (i = 0; i < plist->items; i++) {
        continue;
    }
    plist->entries[i] = item;
    plist->items++;
    return true;
}

void Traverse(const List *plist, void (*pfun)(Item item)) {
    int i;
    for (i = 0; i < plist->items; i++) {
        (*pfun)(plist->entries[i]);
    }
}

void EmptyTheList(List *plist) {
    return;
}