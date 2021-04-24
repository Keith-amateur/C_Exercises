// Stack 类型的实现
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "17.12_5_stack.h"

// 局部函数
static void CopyToNode(Item item, Node *pn);
static void CopyToItem(Node *pn, Item *pi);

void InitializeStack(Stack *ps) {
    ps->head = NULL;
    ps->size = 0;
}

bool StackIsFull(const Stack *ps) {
    return ps->size == MAXSTACK;
}

bool StackIsEmpty(const Stack *ps) {
    return ps->size == 0;
}

int StackItemCount(const Stack *ps) {
    return ps->size;
}

bool push(Item item, Stack *ps) {
    if (StackIsFull(ps)) {
        puts("Stack is full");
        return false;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));

    CopyToNode(item, new_node);
    new_node->next = NULL;
    if (StackIsEmpty(ps)) {
        ps->head = new_node;
    } else {
        new_node->next = ps->head;
        ps->head = new_node;
    }
    ps->size++;
    return true;
}

bool pop(Item *pitem, Stack *ps) {
    if (StackIsEmpty(ps)) {
        puts("No item entered");
        return false;
    }
    CopyToItem(ps->head, pitem);
    Node *temp;
    temp = ps->head;
    ps->head = ps->head->next;
    free(temp);
    ps->size--;
    return true;
}

void Traverse(const Stack *ps, void (*pfun)(Item item)) {
    Node *pnode = ps->head;
    while (pnode != NULL) {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

void EmptyTheStack(Stack *ps) {
    Node *temp;
    while (ps->head != NULL) {
        temp = ps->head->next;
        free(ps->head);
        ps->head = temp;
    }
    ps->size = 0;
}

// 局部函数
// 添加用
static void CopyToNode(Item item, Node *pn) {
    pn->item = item;
}
// 删除用
static void CopyToItem(Node *pn, Item *pi) {
    *pi = pn->item;
}