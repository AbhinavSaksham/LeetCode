/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Serialize tree using level order traversal
    string serialize(TreeNode* root) {

        if(root == NULL) {
            return "";
        }

        string ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* curr = q.front();
            q.pop();

            // Store NULL node
            if(curr == NULL) {

                ans += "N,";
                continue;
            }

            // Store current value
            ans += to_string(curr->val) + ",";

            // Push children
            q.push(curr->left);
            q.push(curr->right);
        }

        return ans;
    }

    // Deserialize tree using level order traversal
    TreeNode* deserialize(string data) {

        if(data.empty()) {
            return NULL;
        }

        vector<string> nodes;
        string temp;

        // Split string by comma
        for(char ch : data) {

            if(ch == ',') {
                nodes.push_back(temp); 
                temp.clear();
            }
            else {
                temp += ch;
            }
        }

        // Create root
        TreeNode* root =
        new TreeNode(stoi(nodes[0]));

        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while(!q.empty() && i < nodes.size()) {

            TreeNode* curr = q.front();
            q.pop();

            // Left child
            if(nodes[i] != "N") {

                curr->left =
                new TreeNode(stoi(nodes[i]));

                q.push(curr->left);
            }
            i++;

            // Right child
            if(i < nodes.size() && nodes[i] != "N") {

                curr->right =
                new TreeNode(stoi(nodes[i]));

                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));