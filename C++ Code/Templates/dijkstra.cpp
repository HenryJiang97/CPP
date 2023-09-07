    int swimInWater(vector<vector<int>>& grid) {
        const int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> MIN(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        
        while (!pq.empty()) {
            auto out = pq.top();    pq.pop();
            int i = out[1], j = out[2], time = out[0];
            
            if (out[1] == m - 1 && out[2] == n - 1)
                return time;
            
            // Go four directions
            for (auto& d : dir) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n)    continue;
                int newTime = max(time, grid[ni][nj]);
                if (newTime < MIN[ni][nj]) {
                    MIN[ni][nj] = newTime;
                    pq.push({newTime, ni, nj});
                }
            }
        }
        
        return 0;
    }