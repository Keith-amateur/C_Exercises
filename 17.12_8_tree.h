// 二叉查找树
/* 树中不允许有重复的项 */

#ifndef _TREE_H_
    #define _TREE_H_
    #include <stdbool.h>

    // 根据具体情况重新定义Item
    #define SLEN 20
    typedef struct item {
        char petname[SLEN];
        char petkinds[10][SLEN];
        int count;
    } Item;

    #define MAXITEMS 10

    typedef struct trnode {
        Item item;
        struct trnode *left;
        struct trnode *right;
    } Trnode;

    typedef struct tree {
        Trnode *root;
        int size;
    } Tree;

    // 函数原型
    
    // 把树初始化为空
    void InitializeTree(Tree *ptree);

    // 确定树是否为空
    bool TreeIsEmpty(const Tree *ptree);

    // 确定树是否已满
    bool TreeIsFull(const Tree *ptree);

    // 确定树的项数
    int TreeItemCount(const Tree *ptree);

    // 在树中添加一个项
    bool AddItem(const Item *pi, Tree *ptree);

    // 在树中查找一个项
    bool InTree(const Item *pi, const Tree *ptree, int *count, Item *find);

    // 从树中删除一个项
    bool DeleteItem(const Item *pi, Tree *ptree);

    // 把函数应用于树中的每一项
    void Traverse(const Tree *ptree, void (*pfun)(Item item));

    // 删除树中的所有内容
    void DeleteAll(Tree *ptree);
    

#endif