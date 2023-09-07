// Floyd

class Solution {
public:
    void floyd(int n, vector<vector<int>>& edges) {
        // Define and init dp
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++)    dis[i][i] = 0;
        for (auto& edge : edges) {
            dis[edge[0]][edge[1]] = edge[2];
            dis[edge[1]][edge[0]] = edge[2];
        }
        
        // Build dp
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
};