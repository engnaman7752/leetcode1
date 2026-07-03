class Solution {
public:
    bool isValid(int minCost, vector<vector<pair<int, int>>> &adj, vector<bool> &online, long long k, int n) {
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (cost > dist[u]) continue;
            for (auto &[v, w] : adj[u]) {
                if (w < minCost) continue;
                if (v != n - 1 && !online[v]) continue; 
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        int lo = 0, hi = 1e9, ans = -1;
        vector<vector<pair<int, int>>> check = adj; 

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (isValid(mid, check, online, k, n)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
