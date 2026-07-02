class Solution {
public:

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));

        queue<vector<int>> q;

        // Initial health
        int startHealth = health - grid[0][0];

        if(startHealth <= 0)
            return false;

        q.push({0, 0, startHealth});
        best[0][0] = startHealth;

        vector<pair<int,int>> dir = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        while(!q.empty()){

            auto curr = q.front();
            q.pop();

            int x = curr[0];
            int y = curr[1];
            int h = curr[2];

            // Destination reached
            if(x == m-1 && y == n-1)
                return true;

            for(auto d : dir){

                int nx = x + d.first;
                int ny = y + d.second;

                if(nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int newHealth = h - grid[nx][ny];

                // Health must remain positive
                if(newHealth <= 0)
                    continue;

                // Already reached with better health
                if(best[nx][ny] >= newHealth)
                    continue;

                best[nx][ny] = newHealth;
                q.push({nx, ny, newHealth});
            }
        }

        return false;
    }
};