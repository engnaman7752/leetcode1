class Solution {
public:
    using ll = long long;
    const ll INF = 1e18;

    ll minimumCost(string s, string t,
                   vector<string>& original,
                   vector<string>& changed,
                   vector<int>& cost) {

        int n = s.size();

        // Map unique strings to ids
        unordered_map<string, int> mp;
        int id = 0;
        for (auto &x : original)
            if (!mp.count(x)) mp[x] = id++;
        for (auto &x : changed)
            if (!mp.count(x)) mp[x] = id++;

        int V = id;
        vector<vector<ll>> dist(V, vector<ll>(V, INF));
        for (int i = 0; i < V; i++) dist[i][i] = 0;

        // Build graph
        for (int i = 0; i < original.size(); i++) {
            int u = mp[original[i]];
            int v = mp[changed[i]];
            dist[u][v] = min(dist[u][v], (ll)cost[i]);
        }

        // Floyd–Warshall
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // Collect valid substring lengths
        unordered_set<int> st;
        int maxLen = 0;
        for (auto &x : original) {
            st.insert(x.size());
            maxLen = max(maxLen, (int)x.size());
        }
        for (auto &x : changed) {
            st.insert(x.size());
            maxLen = max(maxLen, (int)x.size());
        }

        vector<int> lens(st.begin(), st.end());
        sort(lens.begin(), lens.end());  // ⭐ important

        // dp[i] = min cost to convert s[i..] → t[i..]
        vector<ll> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {

            // Case 1: characters already equal
            if (s[i] == t[i]) {
                dp[i] = dp[i + 1];
            }

            // Case 2: substring replacements
            for (int len : lens) {
                if (len > maxLen || i + len > n) break;

                string a = s.substr(i, len);
                string b = t.substr(i, len);

                auto it1 = mp.find(a);
                auto it2 = mp.find(b);
                if (it1 == mp.end() || it2 == mp.end()) continue;

                ll c = dist[it1->second][it2->second];
                if (c < INF) {
                    dp[i] = min(dp[i], c + dp[i + len]);
                }
            }
        }

        return dp[0] >= INF ? -1 : dp[0];
    }
};
