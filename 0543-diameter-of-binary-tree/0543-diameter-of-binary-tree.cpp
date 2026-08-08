class Solution {
public:

    int ans = 0;
    int height(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        int ansL = height(root->left);
        int ansR = height(root->right);

        // Update maximum diameter
        ans = max(ans, ansL + ansR);

        // Return height
        return 1 + max(ansL, ansR);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        height(root);
        return ans;
    }
};