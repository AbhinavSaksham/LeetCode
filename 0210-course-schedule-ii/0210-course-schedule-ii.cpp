class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses); // Create adjacency list
        vector<int> indegree(numCourses, 0); // Store indegree

        // Build graph
        for(auto it : prerequisites) {

            int course = it[0];
            int pre = it[1];

            adj[pre].push_back(course); // pre -> course
            indegree[course]++; // Increase indegree
        }
        queue<int> q;

        // Add nodes with indegree 0
        for(int i = 0; i < numCourses; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        // Topological Sort
        while(!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            // Visit neighbours
            for(auto neighbour : adj[node]) {
                
                indegree[neighbour]--; // Remove dependency
                if(indegree[neighbour] == 0) { // If no dependency left
                    q.push(neighbour);
                }
            }
        }

        // Cycle exists
        if(ans.size() != numCourses) {
            return {};
        }

        return ans;
    }
};