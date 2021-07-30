#include <stdio.h>
#include <stdlib.h>

typedef struct _ListNode {
    int val;
    struct ListNode* next;
} ListNode;

typedef struct node Node;



/*
input example
3 
3 1 4 6
3 1 3 5
2 2 6

*/

int main() {
    int k; // k means listsSize
    int m; // 每个 list 有 m 个元素
    int e; 
    scanf("%d", &k); 
    ListNode** lists = (ListNode**) malloc(sizeof(ListNode*) * k); // 
    for(int i = 0; i < k; i++) {
        scanf("%d", &m);
        // 新建链表
        ListNode** cur = lists + i;
        // lists + i <=> &list[i]
        for(int j = 0; j < m; j++) { 
            // 插入到链表中
            scanf("%d", &e);
            ListNode* node = (ListNode*)malloc(sizeof(ListNode));
            node->val = e;
            node->next = NULL;
            *cur = node;
            cur = &(node->next);
        }
    }

    for(int i = 0; i < k; i++) {
        // printf listNode[i]
        for (ListNode* cur = lists[i]; cur != NULL; cur = cur->next) {
            printf("%d ", cur->val);
        }
        puts("");
    }

    return 0;
}
