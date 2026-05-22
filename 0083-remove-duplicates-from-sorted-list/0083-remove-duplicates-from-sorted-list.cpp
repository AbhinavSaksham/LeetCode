class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) { //curr and next check 

            if (curr->val == curr->next->val) { // it i = i+1
                curr->next = curr->next->next; // skip i+1 and point to next
            }
            else {
                curr = curr->next;
            }
        }

        return head;
    }
};