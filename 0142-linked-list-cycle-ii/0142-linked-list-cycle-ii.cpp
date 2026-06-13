/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Detect cycle
        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            // Cycle found
            if(slow == fast) {

                // Start one pointer from head
                ListNode* ptr = head;

                // Move both one step
                while(ptr != slow) {

                    ptr = ptr->next;
                    slow = slow->next;
                }

                // Cycle starting node
                return ptr;
            }
        }

        // No cycle
        return NULL;
    }
};