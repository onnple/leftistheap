#include <stdio.h>
#include <string.h>
#include <stdlib.h>


static void leftist_heap(void){
    LeftistHeap *heap = lheap_init();
    Label label;
    label.color = 2;
    strcpy(label.title, "The Price Of The Salt");

    lheap_push(heap, 1, &label);
    lheap_push(heap, 7, &label);
    lheap_push(heap, 8, &label);
    lheap_push(heap, 11, &label);
    lheap_push(heap, 19, &label);
    lheap_push(heap, 20, &label);
    lheap_push(heap, 30, &label);
    lheap_push(heap, 3, &label);
    lheap_push(heap, 10, &label);
    lheap_push(heap, 5, &label);
    lheap_push(heap, 16, &label);
    lheap_traverse(heap);

    while (!lheap_is_empty(heap)){
        LNode *node = lheap_top(heap);
        printf("%d  %d\n", node->key, node->dist);
        lheap_pop(heap);
    }

    lheap_clear(heap);
}

int main(void) {
    leftist_heap();
    return 0;
}

