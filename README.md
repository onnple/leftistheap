# 左式堆（Leftist Heap）
左式堆(leftist heap)实现优先队列，原文地址：  


## 左式堆函数操作声明
### 1、左式堆初始化
extern LeftistHeap *lheap_init();

### 2、检测左式堆是否已满
extern int lheap_is_full(LeftistHeap *heap);

### 3、左式堆是否为空
extern int lheap_is_empty(LeftistHeap *heap);

### 4、左式堆入队或插入
extern int lheap_push(LeftistHeap *heap, int key, Label *label);

### 5、获取左式堆队头元素
extern LNode *lheap_top(LeftistHeap *heap);

### 6、左式堆释放顶部元素
extern int lheap_pop(LeftistHeap *heap);

### 7、左式堆遍历
extern void lheap_traverse(LeftistHeap *heap);

### 8、左式堆释放和清除
extern int lheap_clear(LeftistHeap *heap);

