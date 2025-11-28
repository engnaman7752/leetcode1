class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;

    long long dfs(int node, int k, vector<int>& values, int &count) {
        vis[node] = 1;
        long long sum = values[node];
        for (auto nei : adj[node]) {
            if (!vis[nei]) {
                sum += dfs(nei, k, values, count);
            }
        }
        if (sum % k == 0) {
            count++;
            return 0; 
        }
        return sum % k;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.assign(n, {});
        vis.assign(n, 0);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int count = 0;
        dfs(0, k, values, count);
        return count;
    }
};
