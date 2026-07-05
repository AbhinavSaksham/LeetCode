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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node to simplify list creation
        ListNode* dummy = new ListNode(0);

        // Pointer to build the answer list
        ListNode* tail = dummy;

        // Carry from previous addition
        int carry = 0;

        // Continue until both lists and carry are finished
        while (l1 != NULL || l2 != NULL || carry != 0) {

            // Get value from l1 (0 if list ended)
            int num1 = (l1 != NULL) ? l1->val : 0;

            // Get value from l2 (0 if list ended)
            int num2 = (l2 != NULL) ? l2->val : 0;

            // Add digits and carry
            int sum = num1 + num2 + carry;

            // New digit
            int digit = sum % 10;

            // New carry
            carry = sum / 10;

            // Add digit to answer list
            tail->next = new ListNode(digit);

            // Move tail
            tail = tail->next;

            // Move both lists
            if (l1 != NULL)
                l1 = l1->next;

            if (l2 != NULL)
                l2 = l2->next;
        }

        // Return answer (skip dummy node)
        return dummy->next;
    }
};