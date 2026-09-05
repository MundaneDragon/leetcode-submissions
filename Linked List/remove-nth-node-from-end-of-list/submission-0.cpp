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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        auto cur = head;
        auto length = 0;
        while (cur != nullptr) {
            length += 1;
            cur = cur->next;
        }

        cur = head;
        auto prev = static_cast<ListNode*>(nullptr);
        while (cur != nullptr) {
            if (prev != nullptr && length == n) {
                prev->next = cur->next;
                break;
            } else if (prev == nullptr && length == n) {
                head = cur->next;
                break;
            }

            length--;
            prev = cur;
            cur = cur->next;
        }
        
        return head;
    }
};