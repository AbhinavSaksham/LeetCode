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
    ListNode* swapPairs(ListNode* head) {
        
        // Base condition to return
        if ((head == NULL) || (head->next == NULL))
            return head;

        ListNode* curr  = head;
        ListNode* prev  = NULL;

        // Since we know 2nd element will be first one later on
        head = head->next;

        while((curr != NULL) && (curr->next != NULL))
        {
            // Selecting first two element which need to be swapped
            ListNode* n1 = curr;
            ListNode* n2 = curr->next;
            
            // Just incrementing for next iteration
            curr = n2->next;

            // Swapping the data
            n1->next = n2->next;
            n2->next = n1;

            // connecting logic
            if (prev != NULL)
            {
                prev->next = n2;
            }

            // Incrementing the prev
            prev = n1;

        }

        return head;
    }
};
/*
dummy = 0

ListNode* prev  = dummy;
ListNode* first = head; 

while (prev->next != NULL and first->next-> != NULL)

first  = prev->next;
second = first->next;

second->next = first;

first->next  = second->next;

prev->next   = second;

prev = first;

return dummy->next;*/

 