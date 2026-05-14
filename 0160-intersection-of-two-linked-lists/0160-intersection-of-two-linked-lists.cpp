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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        int L1 = 0;
        int L2 = 0;

        // Length of listA
        while (tempA != NULL) {
            L1++;
            tempA = tempA->next;
        }

        // Length of listB
        while (tempB != NULL) {
            L2++;
            tempB = tempB->next;
        }

        // Move longer list ahead
        if (L1 > L2) {

            int lengthNode = L1 - L2;
            while (lengthNode--) {
                headA = headA->next;
            }
        }
        else {

            int lengthNode = L2 - L1;
            while (lengthNode--) {
                headB = headB->next;
            }
        }

        // Find intersection
        while (headA != NULL && headB != NULL) {

            if (headA == headB)
                return headA;

            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};