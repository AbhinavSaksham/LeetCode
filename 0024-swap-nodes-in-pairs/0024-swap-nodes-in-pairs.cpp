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
            ListNode* n1 = curr;
            ListNode* n2 = curr->next; // swaping values selected
            
            curr = n2->next; // +1 for next iteration

            n1->next = n2->next;// Swapping the data
            n2->next = n1;

            if (prev != NULL)  // connect to 3rd
            {
                prev->next = n2;
            }

            prev = n1;  // Incrementing the prev

        }
        return head;
    }
};

// -----recursion------
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {

//         // Base case
//         if (head == nullptr || head->next == nullptr)
//             return head;

//         ListNode* first = head;
//         ListNode* second = head->next;

//         // Recursively swap remaining list
//         first->next = swapPairs(second->next);

//         // Swap current pair
//         second->next = first;

//         return second;
//     }
// };