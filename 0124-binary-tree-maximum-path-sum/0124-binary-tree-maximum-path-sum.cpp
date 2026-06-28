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
        int maxPathSum(TreeNode* root) {

        dfs(root);
        return ans;
    }

    int ans = INT_MIN;

    int dfs(TreeNode* root) {

        if (root == NULL)
            return 0;

        int left = max(0, dfs(root->left)); // Maximum gain from left subtree      
        int right = max(0, dfs(root->right)); // Maximum gain from right subtree

        ans = max(ans, left + right + root->val);  // Path passing through current node

        return root->val + max(left, right);  // Return one side to parent
    } 
};