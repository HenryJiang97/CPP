// Bridge-Finding Algo

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Build the adjacent map
        unordered_map<int, unordered_set<int>> graph;
        for (auto& connection : connections) {
            graph[connection[0]].insert(connection[1]);
            graph[connection[1]].insert(connection[0]);
        }
        
        vector<int> dis(n, -1);    // Save the discover time of a node
        vector<int> low(n, -1);    // Save the lowest discover time of its neighbour except for its parent
        
        for (int i = 0; i < n; i++) {
            if (dis[i] != -1)    continue;    // Visited
            dfs(graph, dis, low, i, -1);
        }

        return res;
    }
    
private:
    int time = 0;
    
    void dfs(unordered_map<int, unordered_set<int>>& graph, vector<int>& dis, vector<int>& low, int cur, int parent) {
        dis[cur] = time;    low[cur] = time;    time++;
        
        if (graph.find(cur) == graph.end())    return;
        for (int next : graph[cur]) {
            if (next == parent)    continue;
            
            if (dis[next] == -1) {    // Next not visited
                dfs(graph, dis, low, next, cur);
                low[cur] = min(low[cur], low[next]);
                if (low[next] > dis[cur]) {
                    res.push_back({cur, next});
                }
            }
            else {    // Next visited
                low[cur] = min(low[cur], dis[next]);
            }
        }
    }
};