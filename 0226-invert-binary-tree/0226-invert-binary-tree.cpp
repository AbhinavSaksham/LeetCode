class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        // Base case
        if (root == NULL) {
            return NULL;
        }

        // Swap left and right child
        swap(root->left, root->right);

        // Recursively invert subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};