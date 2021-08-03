#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};


/*
input example
3 
3 1 4 6
3 1 3 5
2 2 6

*/

struct ListNode* heap[11111]; // heap 的每个元素是指向链表的指针，
int heapSize;

// void swap(int a, int b) {
//     ListNode* t = heap[a];  
//     heap[a] = heap[b];
//     heap[b] = t;
// }


void swap(struct ListNode* *a, struct ListNode* *b) { 
    struct ListNode* t = *a; // a位置存放的是地址，所以要声明 t 是存放地址的变量，把a位置存放的地址赋值给 t位置
    *a = *b;
    *b = t;
}


void swim(struct ListNode** heap, int x) { // 把全局变量 heap 当参数传进来，就在函数里可以使用了， x 是下标， heap里的元素是指针（链表）
    if (x == 1) {
        return;
    }
    int fa = x>>1;
    if ((heap[fa]->val) > (heap[x]->val)) {
        swap(&heap[fa], &heap[x]);
        // swap(fa, x);
        swim(heap, fa);
    }
}

void sink(struct ListNode** heap, int x, int heapSize) {
    int l = x<<1;
    int r = x<<1|1;
    if (l > heapSize) {
        return;
    } else if (r > heapSize) {
        if ((heap[x]->val) > (heap[l]->val)) {
            swap(&heap[l], &heap[x]);
        }
    } else {
        int t = l;
        if ((heap[l]->val) > (heap[r]->val)) {
            t = r;
        }
        if ((heap[t]->val) < (heap[x]->val)){
            swap(&heap[t], &heap[x]);
            sink(heap, t, heapSize);
        }
    }
}




struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    heapSize = 0;
    for (int i = 0; i < listsSize; i++) {
        if (lists[i] != NULL) {
            heapSize++;
            heap[heapSize] = lists[i];
            swim(heap, heapSize);
        }
    }
    //  新建链表放堆顶值
    struct ListNode** head = (struct ListNode**) malloc(sizeof(struct ListNode*));
    struct ListNode** cur = head; 

    while (heapSize > 0) {
        struct ListNode* top = heap[1];
        if (heap[1]->next == NULL) {
            swap(&heap[1], &heap[heapSize]);
            heapSize--;
            sink(heap, 1, heapSize);
        } else {
            heap[1] = heap[1]->next;
            sink(heap, 1, heapSize);
        }
        *cur = top;
        cur = &(top->next);
    }
    *cur = NULL;
    return *head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// 递归 merge two lists

// struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
//     if (l1 == NULL) {
//         return l2;
//     }else if (l2 == NULL){
//         return l1;
//     }else if (l1->val < l2->val){
//         l1->next = mergeTwoLists(l1->next, l2);
//         return l1;
//     }else{
//         l2->next = mergeTwoLists(l1, l2->next);
//         return l2;
//     }
// }

// // merge k lists

// struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
//     if (listsSize == 0) {
//         return NULL;
//     }
//     if (listsSize == 1) {
//         return (lists[0]);
//     }
//     for (int k = 0; k < listsSize - 1; k++) {
//         lists[k] = mergeTwoLists(lists[k],lists[listsSize -1]);
//         listsSize--;
//     }
//     return mergeKLists(lists, listsSize);
// }




int main() {
    int k; // k means listsSize
    int m; // 每个 list 有 m 个链表元素
    int e; 
    scanf("%d", &k); 
    struct ListNode** lists = (struct ListNode**) malloc(sizeof(struct ListNode*) * k);
    // 读取数据 
    for(int i = 0; i < k; i++) {
        scanf("%d", &m);
        // 新建 k 个链表
        struct ListNode** cur = lists + i; // cur 指向地址，通过修改 cur， 可以修改 链表 的值 
        // lists + i <=> &list[i]  取地址，如cur = lists[0] <=> 1->4->6 的地址 
        for(int j = 0; j < m; j++) { 
            // 插入到链表中
            scanf("%d", &e);
            struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
            node->val = e;
            node->next = NULL;
            *cur = node; //  node 是指针，cur 是指针的指针， cur 解引用后是指针 
            cur = &(node->next);
        }
    }

    for(int i = 0; i < k; i++) {
        // printf listNode[i]
        for (struct ListNode* cur = lists[i]; cur != NULL; cur = cur->next) {
            printf("%d ", cur->val);
        }
        puts("");
    }

    struct ListNode* result = mergeKLists(lists, k);
    while(result != NULL) {
        printf("%d ", result->val);
        result = result->next;
    }

    // for (struct ListNode* result = mergeKLists(lists, k); result != NULL; result = result->next) {
    //     printf("%d ", result->val);
    // }



    return 0;
}
