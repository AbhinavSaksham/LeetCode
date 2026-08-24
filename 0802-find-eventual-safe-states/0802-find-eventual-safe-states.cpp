class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();

        vector<vector<int>> adjRev(V); // Reverse graph
        vector<int> indegree(V, 0); // Store number of outgoing edges

        // Build reverse graph
        for(int i = 0; i < V; i++) {

            for(auto it : graph[i]) {

                adjRev[it].push_back(i); // Reverse edge: it -> i
                indegree[i]++; // Original outgoing edge count
            }
        }

        queue<int> q;

        // Terminal nodes have no outgoing edges
        for(int i = 0; i < V; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safeNodes;

        // Topological Sort
        while(!q.empty()) {

            int node = q.front();
            q.pop();
            safeNodes.push_back(node); // This node is safe

            // Visit nodes pointing to this node
            for(auto neighbour : adjRev[node]) {
                
                indegree[neighbour]--; // One outgoing path is now confirmed safe

                // All outgoing paths lead to safe nodes
                if(indegree[neighbour] == 0) { 
                    q.push(neighbour);
                }
            }
        }

        // Return in ascending order
        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};