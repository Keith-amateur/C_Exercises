// Queue类型的实现
#include <stdio.h>
#include <stdlib.h>
#include "17.12_4_queue.h"

// 局部函数
static void CopyToNode(Item item, Node *pn);
static void CopyToItem(Node *pn, Item *pi);

void InitializeQueue(Queue *pq) {
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsFull(const Queue *pq) {
    return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue *pq) {
    return pq->items == 0;
}

int QueueItemCount(const Queue *pq) {
    return pq->items;
}

bool Enqueue(Item item, Queue *pq) {
    Node *pnew;
    if (QueueIsFull(pq)) {
        return false;
    }
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL) {
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(1);
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (QueueIsEmpty(pq)) {
        pq->front = pnew;
    } else {
        pq->rear->next = pnew;
    }
    pq->rear = pnew;
    pq->items++;

    return true;
}

bool Dequeue(Item *pitem, Queue *pq) {
    Node *pt;
    if (QueueIsEmpty(pq)) {
        return false;
    }
    pt = pq->front;
    CopyToItem(pt, pitem);
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if (pq->items == 0) {
        pq->rear = NULL;
    }

    return true;
}

void EmptyTheQueue(Queue *pq) {
    Item dummy;
    while (!QueueIsEmpty(pq)) {
        Dequeue(&dummy, pq);
    }
}

// 局部函数
static void CopyToNode(Item item, Node *pn) {
    pn->item = item;
}

static void CopyToItem(Node *pn, Item *pi) {
    *pi = pn->item;
}