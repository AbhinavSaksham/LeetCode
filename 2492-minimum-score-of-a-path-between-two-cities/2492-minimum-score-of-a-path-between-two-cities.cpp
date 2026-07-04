class Solution {
public:

    int ans = INT_MAX; //whenever finding min

    void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<int>& vis){

        vis[node] = 1; //to flag visitied node 

        for(auto it : adj[node]){

            int next = it.first;
            int dist = it.second;

            // store minimum edge value 
            ans = min(ans, dist);

            if(!vis[next]){
                dfs(next, adj, vis);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        // Build graph
        for(auto road : roads){

            int u = road[0];
            int v = road[1];
            int d = road[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<int> vis(n + 1, 0);

        dfs(1, adj, vis);

        return ans;
    }
};