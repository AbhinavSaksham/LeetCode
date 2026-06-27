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
    int kthSmallest(TreeNode* root, int k) {

        vector<int> ans; 

        inorder(root, ans); // Store BST values in sorted order
        return ans[k - 1]; // k is 1-based indexing
    }

    void inorder(TreeNode* root, vector<int>& ans) {

        if (root == NULL)
            return;

        inorder(root->left, ans);  // Left
        ans.push_back(root->val); // Node
        inorder(root->right, ans); // Right
    }
};