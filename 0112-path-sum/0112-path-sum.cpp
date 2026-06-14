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

    bool hasPathSum(TreeNode* root, int targetSum) {

        
        if(root == NULL) { // Empty tree
            return false;
        }

        // If leaf node, check if remaining sum matches
        if(root->left == NULL && root->right == NULL) {  

            if(targetSum == root->val) {
                return true;
            }

            return false;
        }

       
        targetSum = targetSum - root->val;  // remaining sum after reducing current node value from it

        // Check left or right subtree - recc
        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};