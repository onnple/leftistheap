//
// Created by Once on 2019/8/29.
//

#ifndef DATALGORITHM_LEFTISTHEAP_H
#define DATALGORITHM_LEFTISTHEAP_H

// 左式堆实现优先队列（最小堆）

// 实体数据
typedef struct label{
    int color;
    char title[128];
} Label;

// 左式堆结点
typedef struct lnode{
    int key;
    int dist;
    Label label;
    struct lnode *left;
    struct lnode *right;
} LNode;

// 左式堆对外ADT
typedef struct leftistheap{
    int size;
    LNode *root;
} LeftistHeap;

// 左式堆操作函数声明（参考优先队列的基本操作）
extern LeftistHeap *lheap_init();
extern int lheap_is_full(LeftistHeap *heap);
extern int lheap_is_empty(LeftistHeap *heap);
extern int lheap_push(LeftistHeap *heap, int key, Label *label);
extern LNode *lheap_top(LeftistHeap *heap);
extern int lheap_pop(LeftistHeap *heap);
extern void lheap_traverse(LeftistHeap *heap);
extern int lheap_clear(LeftistHeap *heap);

#endif //DATALGORITHM_LEFTISTHEAP_H
