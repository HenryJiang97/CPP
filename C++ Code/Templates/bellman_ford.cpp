class vex {
public:
    int node;    int price;
    vex(int node, int price) {this->node = node;    this->price = price;}
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Generate an unordered_map based on the graph
        unordered_map<int, vector<vex*>> map;
        for (int i = 0; i < flights.size(); i++) {
            if (map.find(flights[i][0]) != map.end()) {
                map[flights[i][0]].push_back(new vex(flights[i][1], flights[i][2]));
            } else {
                vector<vex*> vec;
                vec.push_back(new vex(flights[i][1], flights[i][2]));
                map[flights[i][0]] = vec;
            }
        }
        
        // Bellman-Ford
        vector<vector<int>> dp(K + 2, vector<int>(n, INT_MAX));
        dp[0][dst] = 0;
        
        for (int k = 1; k < K + 2; k++) {
            for (int i = 0; i < n; i++) {
                dp[k][i] = dp[k - 1][i];
                for (auto& edge : map[i]) {
                    if (dp[k - 1][edge->node] == INT_MAX)    continue;
                    dp[k][i] = min(dp[k][i], dp[k - 1][edge->node] + edge->price);
                }
            }
        }
        
        return dp[K + 1][src] == INT_MAX ? -1 : dp[K + 1][src];
    }
};