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
    void recoverTree(TreeNode* root) {

        inorder(root);
        // Swap required nodes
        swap(first->val, second->val);
    }

    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {

        if(root == NULL) {
            return;
        }

        inorder(root->left);        // Traverse left subtree

        // Check BST violation
        if(prev != NULL && prev->val > root->val) {

            // First violation
            if(first == NULL) {
                first = prev;
            }

            second = root;  // Update second every time
        }

        prev = root;

        // Traverse right subtree
        inorder(root->right);
    }

};