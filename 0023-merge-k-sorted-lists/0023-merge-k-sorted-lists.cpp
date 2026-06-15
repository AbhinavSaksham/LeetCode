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

    // Merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while(list1 != NULL && list2 != NULL) {

            if(list1->val <= list2->val) {

                curr->next = list1;
                list1 = list1->next;
            }
            else {

                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }
       
        if(list1 != NULL) {  // Attach remaining nodes
            curr->next = list1;
        }
        else {
            curr->next = list2;
        }
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0) {
            return NULL;
        }

        ListNode* ans = lists[0]; 
                    // Merge one list at a time
        for(int i = 1; i < lists.size(); i++) {

            ans = mergeTwoLists(ans, lists[i]);
        }

        return ans;
    }
};