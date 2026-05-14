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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast!= NULL && fast->next!=NULL)

        {
            slow = slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
};

// if ((head == NULL) || (head->next == NULL))
//             return head; //base case

//         ListNode* temp = head;
//         int count = 0; //for lenght

//         while (temp != NULL) { //count
//             count++;
//             temp = temp->next;
//         }

//         int mid = (count / 2) + 1; // mid

//         temp = head;

//         while (temp != NULL) {

//             mid = mid - 1;

//             if (mid == 0)
//                 return temp;

//             else
//                 temp = temp->next;
//         }

//         return temp;