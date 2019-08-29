//
// Created by Once on 2019/8/29.
//

#include "leftistheap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

LeftistHeap *lheap_init(){
    LeftistHeap *heap = (LeftistHeap*)malloc(sizeof(LeftistHeap));
    if(!heap){
        perror("alloc memory for heap error");
        return NULL;
    }
    heap->size = 0;
    heap->root = NULL;
    return heap;
}

int lheap_is_full(LeftistHeap *heap){
    LNode *node = (LNode*)malloc(sizeof(LNode));
    if(!node)
        return 1;
    free(node);
    return 0;
}

int lheap_is_empty(LeftistHeap *heap){
    if(heap == NULL)
        return 0;
    return heap->size == 0;
}

static int distance(LNode *node){
    if(node == NULL)
        return -1;
    return node->dist;
}

static void swap_children(LNode *node){
    LNode *temp = node->left;
    node->left = node->right;
    node->right = temp;
}

static LNode *merge(LNode *h1, LNode *h2);
static LNode *merge_node(LNode *h1, LNode *h2);

static LNode *merge(LNode *h1, LNode *h2){
    if(h1->left == NULL)
        h1->left = h2;
    else{
        h1->right = merge_node(h1->right, h2);
        if(h1->left->dist < h1->right->dist)
            swap_children(h1);
        h1->dist = 1 + distance(h1->right);
    }
    return h1;
}

static LNode *merge_node(LNode *h1, LNode *h2){
    if(h1 == NULL)
        return h2;
    if(h2 == NULL)
        return h1;
    if(h1->key < h2->key)
        return merge(h1, h2);
    else
        return merge(h2, h1);
}

int lheap_push(LeftistHeap *heap, int key, Label *label){
    if(heap == NULL || label == NULL)
        return 0;
    LNode *node = (LNode*)malloc(sizeof(LNode));
    if(!node){
        perror("alloc memory for node error");
        return 0;
    }
    node->key = key;
    node->left = node->right = NULL;
    node->label.color = label->color;
    strcpy(node->label.title, label->title);
    node->dist = 1 + distance(node->right);
    heap->root = merge_node(heap->root, node);
    heap->size++;
    return 1;
}

LNode *lheap_top(LeftistHeap *heap){
    if(heap == NULL || heap->size == 0)
        return NULL;
    return heap->root;
}

int lheap_pop(LeftistHeap *heap){
    if(heap == NULL || heap->size == 0)
        return 0;
    LNode *root = heap->root;
    LNode *left = root->left;
    LNode *right = root->right;
    free(root);
    heap->size--;
    heap->root = merge_node(left, right);
    return 1;
}

static void traverse_node(LNode *node){
    if(node == NULL)
        return;
    traverse_node(node->left);
    printf("[%d %d] ", node->key, node->dist);
    traverse_node(node->right);
}

void lheap_traverse(LeftistHeap *heap){
    if(heap == NULL || heap->size == 0)
        return;
    traverse_node(heap->root);
    printf("\n");
}

static void clear_node(LNode *node){
    if(node == NULL)
        return;
    clear_node(node->left);
    clear_node(node->right);
    free(node);
}

int lheap_clear(LeftistHeap *heap){
    if(heap == NULL)
        return 0;
    clear_node(heap->root);
    free(heap);
    return 1;
}
