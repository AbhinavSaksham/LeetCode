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
    void preorder(TreeNode* root, vector<int>& ans) {
                // Base case
        if (root == NULL) {
            return;
        }
        //PREORDER - node->left->RIGHT

        ans.push_back(root->val); // Node
        preorder(root->left, ans); // Left
        preorder(root->right, ans); // Right
    }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;
        preorder(root, ans); //if only root or inorder traversal

        return ans;
    }
};

