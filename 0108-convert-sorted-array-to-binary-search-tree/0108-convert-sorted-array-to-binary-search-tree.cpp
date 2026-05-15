/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) 
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    TreeNode* sortedArrayToBST(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;

        return BST(nums, start, end);
    }

    TreeNode* BST(vector<int>& nums, int start, int end) {

        if (start > end)
            return NULL;

        int mid = start + (end - start) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        // left subtree
        root->left = BST(nums, start, mid - 1);

        // right subtree
        root->right = BST(nums, mid + 1, end);

        return root;
    }

};


 //int start = 0;
//         int end = nums.size()-1;

//         while (start<end)
//         mid = start + (end-start)/2;

//         root = mid;
        
//         if (root->left < mid)
//         {
//             while (start<end)
//         mid = start + (end-start)/2;
//         root = mid;
            
//         } 
         
//         if (root->right > mid)
//         {
//             while (start<end)
//         mid = start + (end-start)/2;
//         root = mid;
            
//         } 
//         return 