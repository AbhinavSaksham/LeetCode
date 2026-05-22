class Solution {
public:

    void inorder(TreeNode* root, vector<int>& ans) {

        // Base case
        if (root == NULL) {
            return;
        }
        //INORDER - LEFT->NODE->RIGHT

        inorder(root->left, ans); // Left
        ans.push_back(root->val); // Node
        inorder(root->right, ans); // Right
    }

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        inorder(root, ans);

        return ans;
    }
};