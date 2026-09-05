class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        int target = (1 << n) - 1; // All nodes visited        
        queue<pair<int, int>> q; // {node, visited mask}

        // visited[node][mask] = already visited state
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        for(int i = 0; i < n; i++) { // Start BFS from every node
            int mask = 1 << i;

            q.push({i, mask});
            visited[i][mask] = true;
        }

        int steps = 0;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto it = q.front();
                q.pop();

                int node = it.first;
                int mask = it.second;
                
                if(mask == target) // All nodes are visited
                    return steps;

                // Visit all neighbours
                for(auto neighbour : graph[node]) {
                    int newMask = mask | (1 << neighbour);

                    // Visit this state only once
                    if(!visited[neighbour][newMask]) {
                        visited[neighbour][newMask] = true;
                        q.push({neighbour, newMask});
                    }
                }
            }

            steps++;
        }
        return -1;
    }
};