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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        // Empty tree
        if(root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;

        // Start BFS from root
        q.push(root);

        while(!q.empty()) {

            int size = q.size();

            // Traverse one level
            for(int i = 0; i < size; i++) {

                TreeNode* curr = q.front();
                q.pop();

                // Last node of current level
                if(i == size - 1) {
                    ans.push_back(curr->val);
                }

                // Push left child
                if(curr->left != NULL) {
                    q.push(curr->left);
                }

                // Push right child
                if(curr->right != NULL) {
                    q.push(curr->right);
                }
            }
        }

        return ans;
    }
};