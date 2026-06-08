// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if(root == NULL) { //base case -success
            return true;
        }

        return helper(root->left, root->right); //call fn
    }

    bool helper(TreeNode* left, TreeNode* right) { //take node left, right

        if(left == NULL && right == NULL) { //3 base case check 
            return true;
        }

        if(left == NULL || right == NULL) {
            return false;
        }

        if(left->val != right->val) {
            return false;
        }

        return helper(left->left, right->right) && //recursion
               helper(left->right, right->left);
    }
};










// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (root == NULL){
//             return true;
//         }

//         if ((root->left == NULL && root->right != NULL) || 
//             (root->left != NULL && root->right == NULL)){
//             return false;
//         }

//         if(root->left->val != root->right->val) {
//             return false;
//         }
//         else return true;

//     }
// };