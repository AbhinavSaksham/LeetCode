class Solution {
public:

    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL) { // Empty or single node is palindromeso true
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {  // middle of the LL

            slow = slow->next;
            fast = fast->next->next;
        }


        ListNode* prev = NULL;          // Reverse second half

        while(slow != NULL) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        ListNode* first = head;  // Compare both halves
        ListNode* second = prev;

        while(second != NULL) {

            if(first->val != second->val) {
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }
};