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
class Solution {
public:
    int sum;
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if (root == NULL)
            return 0;

            sum = 0;

        if ((root->val >= low) && (root->val <= high ))
        {
            //cout << "debug : " << root->val <<endl;
            sum = sum + root->val;
        }
        sum = sum + rangeSumBST(root->left, low, high);
        sum = sum + rangeSumBST(root->right, low, high);
        
        return sum;
        /* if (root->val > low)
        sum = rangeSumBST(root->left, low, high);//go left

        if (root->val >= low && root->val <= high)//sum if in range
        sum = sum + root->val;

        if (root->val < high)
        sum = rangeSumBST(root->right, low, high);//go right */

        //return sum;
    }
};