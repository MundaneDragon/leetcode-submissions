/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // auto dummy = ListNode(0, head);
        // auto fast =
        auto cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->val == cur->next->val) {
                auto temp = cur->next;
                while (temp->next != nullptr && temp->val == temp->next->val) {
                    temp = temp->next;
                }
                cur->next = temp->next;
            }
            cur = cur->next;
        }

        return head; 
    }
};