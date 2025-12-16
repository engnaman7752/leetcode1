class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<vector<int>>> dp;
    vector<int> pre, fut;
    int n, B;

    vector<int>& dfs(int u, int br) {
        if (!dp[u][br].empty())
            return dp[u][br];

        int cost = br ? pre[u] / 2 : pre[u];

        vector<int> notake(B + 1, 0);
        for (int v : adj[u]) {
            auto &ch = dfs(v, 0);
            for (int b = B; b >= 0; b--)
                for (int x = 0; x <= b; x++)
                    notake[b] = max(notake[b], notake[b - x] + ch[x]);
        }

        vector<int> take(B + 1, -1e9);
        if (cost <= B) {
            take[cost] = fut[u] - cost;
            for (int v : adj[u]) {
                auto &ch = dfs(v, 1);
                vector<int> nt(B + 1, -1e9);
                for (int b = cost; b <= B; b++)
                    for (int x = 0; x <= b - cost; x++)
                        nt[b] = max(nt[b], take[b - x] + ch[x]);
                take.swap(nt);
            }
        }

        dp[u][br].resize(B + 1);
        for (int b = 0; b <= B; b++)
            dp[u][br][b] = max(notake[b], take[b]);

        return dp[u][br];
    }

    int maxProfit(int n_, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {

        n = n_;
        B = budget;
        pre = present;
        fut = future;

        adj.assign(n, {});
        for (auto &e : hierarchy) {
            int u = e[0] - 1;  
            int v = e[1] - 1;
            adj[u].push_back(v);
        }

        dp.assign(n, vector<vector<int>>(2));
        auto &ans = dfs(0, 0);   
        return *max_element(ans.begin(), ans.end());
    }
};
