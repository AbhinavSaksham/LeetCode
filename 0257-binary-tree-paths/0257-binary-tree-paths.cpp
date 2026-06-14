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
    vector<string> binaryTreePaths(TreeNode* root) {

        solve(root, "");
        return ans;
    }

    vector<string> ans;

    void solve(TreeNode* root, string path) {

        if(root == NULL) {
            return;
        }

        // Leaf node
        if(root->left == NULL && root->right == NULL) {

            path += to_string(root->val);
            ans.push_back(path);
            return;
        }

        // Add current node to path
        path += to_string(root->val) + "->";

        solve(root->left, path);  // Traverse left
        solve(root->right, path); // Traverse right
    }

};