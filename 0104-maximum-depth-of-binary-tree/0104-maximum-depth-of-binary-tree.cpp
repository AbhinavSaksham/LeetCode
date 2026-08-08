class Solution {
public:
    int maxDepth(TreeNode* root) {

        // Base case
        if (root == NULL) {
            return 0;
        }

        // Find depth of left and right subtree
        int ansL = maxDepth(root->left);
        int ansR = maxDepth(root->right);

        // Current node adds 1
        int ans = 1 + max(ansL, ansR); //+1 because of root node

        return ans;
    }
};