/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) 
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {

        if (root == NULL)
            return 0;

        int heightleft = maxDepth(root->left); //left
        int heightright = maxDepth(root->right); //right

        if (heightright > heightleft)
            return heightright + 1;

        else
            return heightleft +1;
    }
};
