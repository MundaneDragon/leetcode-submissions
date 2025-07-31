/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *l3 = malloc(sizeof(struct ListNode));
    struct ListNode *head = l3;
    struct ListNode *prev = NULL;
    struct ListNode* l1_head = l1;
    struct ListNode* l2_head = l2;

    head->val = 0;
    while (l1_head != NULL || l2_head != NULL) {
        int quotient = 0;
        if (l1_head != NULL) {
            head->val += l1_head->val;
            l1_head = l1_head->next;
        }

        if (l2_head != NULL) {
            head->val += l2_head->val;
            l2_head = l2_head->next;
        }
        quotient = head->val / 10;
        head->val = head->val % 10;
        head->next = malloc(sizeof(struct ListNode));
        prev = head;
        head = head->next;
        head->val = 0;
        if (quotient != 0) {
            head->val = quotient;
        }
    }

    if (head->val == 0) {
        printf("testing\n");
        prev->next = NULL;
        free(head);
    } else {
        printf("testing 2\n");
        head->next = NULL;
    }

    return l3;
}