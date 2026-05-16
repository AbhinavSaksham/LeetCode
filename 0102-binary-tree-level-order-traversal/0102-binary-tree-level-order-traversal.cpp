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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans; //create vector 

        if (root == NULL)  //base case check done
            return ans;

        queue<TreeNode*> q; // create a queue

        q.push(root); //insert root value to queue

        while (!q.empty()) {  //main loop 

            int size = q.size();  //get each level size for traversal 

            vector<int> level; //store the current level

            for (int i = 0; i < size; i++) { //travese all nodes of that level

                TreeNode* node = q.front(); //front node
                q.pop();

                level.push_back(node->val);  //add to level

                if (node->left != NULL) //push all child values from curr level 
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);
            }

            ans.push_back(level);  //save level values
        }
        return ans;
    }
};