class Solution {
public:

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<int> path; // Start from node 0
        path.push_back(0);
        dfs(0, graph, path);
        return ans;
    }

    vector<vector<int>> ans;

private: 

    void dfs(int node, vector<vector<int>>& graph, vector<int>& path) {

        int n = graph.size();
        // Reached target node
        if(node == n - 1) {
            ans.push_back(path);
            return;
        }

        // Visit all neighbours
        for(auto neighbour : graph[node]) {

            path.push_back(neighbour); // Add neighbour to current path
            dfs(neighbour, graph, path); // Explore further
            path.pop_back(); // Backtrack: remove neighbour
        }
    }
};