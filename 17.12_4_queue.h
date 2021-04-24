// Queue的接口
#ifndef _QUEUE_H_
    #define _QUEUE_H_
    #include <stdbool.h>

    // 在这里插入Item类型的定义
    // typedef int Item;
    typedef struct item {
        long arrive;            // 一位顾客加入队列的时间
        int processtime;        // 该顾客咨询时花费的时间
    } Item;

    #define MAXQUEUE 10

    typedef struct node {
        Item item;
        struct node *next;
    } Node;

    typedef struct queue {
        Node *front;    // 指向首节点
        Node *rear;     // 指向尾节点
        int items;       // 队列中的项数
    } Queue;

    /* 初始化队列 */
    void InitializeQueue(Queue *pq);

    /* 检查队列是否已满 */
    bool QueueIsFull(const Queue *pq);

    /* 检查队列是否为空 */
    bool QueueIsEmpty(const Queue *pq);

    /* 确定队列的项数 */
    int QueueItemCount(const Queue *pq);

    /* 在队列的末尾添加项 */
    bool Enqueue(Item item, Queue *pq);

    /* 从队列开头删除项 */
    bool Dequeue(Item *pitem, Queue *pq);

    /* 清空队列 */
    void EmptyTheQueue(Queue *pq);

#endif
