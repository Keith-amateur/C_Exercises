#ifndef _STACK_H_
    #define _STACK_H_
    #include <stdbool.h>

    #define MAXSTACK 10

    typedef char Item;

    typedef struct node {
        Item item;
        struct node *next;
    } Node;

    typedef struct stack {
        Node *head;
        int size;
    } Stack;



    // 操作: 初始化栈
    void InitializeStack(Stack *ps);

    // 操作: 检查栈是否已满
    bool StackIsFull(const Stack *ps);

    // 操作: 检查栈是否为空
    bool StackIsEmpty(const Stack *ps);

    // 操作: 确定栈的项数
    int StackItemCount(const Stack *ps);

    // 操作: 在队列开头添加项
    bool push(Item item, Stack *ps);

    // 操作: 在队列开头弹出项
    bool pop(Item *pitem, Stack *ps);

    // 操作: 在函数应用在栈中的每一项
    void Traverse(const Stack *ps, void (*pfun)(Item item));

    // 操作: 清空栈
    void EmptyTheStack(Stack *ps);

#endif