class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<int>> dis(n, vector<int>(k + 1, INT_MAX));
        vector<vector<pair<int, int>>> adj(n);
        
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }
        
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> pq;
                       
        dis[0][1] = 0;
        pq.push({0, 0, 1});
        
        while (!pq.empty()) {
            auto [curr, node, count] = pq.top();
            pq.pop();
            
            // If we've found a strictly shorter path to this state already, skip it
            if (curr > dis[node][count]) continue;
            
            char ch = labels[node];
            
            for (auto& [v, w] : adj[node]) {
                if (labels[v] == ch) {
                    if (count + 1 <= k) {
                        if (curr + w < dis[v][count + 1]) {
                            dis[v][count + 1] = curr + w;
                            pq.push({curr + w, v, count + 1});
                        }
                    }
                } else {
                    if (curr + w < dis[v][1]) {
                        dis[v][1] = curr + w;
                        pq.push({curr + w, v, 1});
                    }
                }
            }
        }

        int ans = INT_MAX;
        for (int c = 1; c <= k; ++c) {
            ans = min(ans, dis[n - 1][c]);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};