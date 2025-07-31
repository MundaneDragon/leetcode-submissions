/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//     struct ListNode *l3 = malloc(sizeof(struct ListNode));
//     struct ListNode *head = l3;
//     struct ListNode *prev = NULL;
//     struct ListNode* l1_head = l1;
//     struct ListNode* l2_head = l2;

//     head->val = 0;
//     while (l1_head != NULL || l2_head != NULL) {
//         int quotient = 0;
//         if (l1_head != NULL) {
//             head->val += l1_head->val;
//             l1_head = l1_head->next;
//         }

//         if (l2_head != NULL) {
//             head->val += l2_head->val;
//             l2_head = l2_head->next;
//         }
//         quotient = head->val / 10;
//         head->val = head->val % 10;
//         head->next = malloc(sizeof(struct ListNode));
//         prev = head;
//         head = head->next;
//         head->val = 0;
//         if (quotient != 0) {
//             head->val = quotient;
//         }
//     }

//     if (head->val == 0) {
//         prev->next = NULL;
//         free(head);
//     } else {
//         head->next = NULL;
//     }

//     return l3;
// }

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int dirty = 0, temp = 0;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy -> next = l1;
    struct ListNode* prev = dummy;
    while(l1 && l2){
        temp = l1 -> val + l2 -> val + dirty;
        dirty = temp / 10;
        l1 -> val = temp % 10;
        prev = l1;
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    if(l2){
        prev -> next = l2;
        l1 = l2;
    }
    while(l1){
        temp = l1 -> val + dirty;
        dirty = temp / 10;
        l1 -> val = temp % 10;
        prev = l1;
        l1 = l1 -> next;
    }
    if (dirty) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode -> val = dirty;
        newNode -> next = NULL;
        prev -> next = newNode;
    }
    return dummy -> next;
}