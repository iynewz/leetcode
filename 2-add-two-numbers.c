/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum = 0;
    int carry = 0; // 用 carry 表示进位
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode)); // 动态分配空间
    l3->val = 0;
    l3->next = NULL;
    struct ListNode* curr = l3; //新建 curr 指针指向头部
    while(l1 != NULL || l2 != NULL || carry != 0) {
        sum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + carry;
        carry = sum / 10;
        sum = sum % 10;
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->next->val = sum;
        curr->next->next = NULL;
        curr = curr->next;
        l1 = (l1 == NULL ? NULL : l1->next);
        l2 = (l2 == NULL ? NULL : l2->next);
    }
    return l3->next;
    
}