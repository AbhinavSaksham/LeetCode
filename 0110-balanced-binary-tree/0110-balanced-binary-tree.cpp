class Solution {
public:
    bool isBalanced(TreeNode* root) {

        return height(root) != -1;
    }

private:
    int height(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        // If subtree is unbalanced
        if (left == -1 || right == -1) {
            return -1;
        }

        // If current node is unbalanced
        if (abs(left - right) > 1) {
            return -1;
        }

        // Return height of current node
        return 1 + max(left, right);
    }
};