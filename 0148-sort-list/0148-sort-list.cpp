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
    ListNode* sortList(ListNode* head) {

        vector<int> arr; //vector 

        ListNode* temp = head;  //traverse the list 

        while(temp != NULL) {

            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end()); //sort the arr

        temp = head; //insert to list again

        int i = 0;

        while(temp != NULL) {

            temp->val = arr[i];
            i++;

            temp = temp->next;
        }

        return head;
    }
};