class Solution {
public:
    unordered_map<string, int> mp;
    int n;
    const long long INF = 1e15;
    using ll = long long;
    vector<long long> dp;
    set<int> length;
    long long minimumCost(string s, string t, vector<string>& original,vector<string>& changed, vector<int>& cost) {
        n = s.size();
        int id = 0;
        for (auto& x : original)
            if (!mp.count(x))
                mp[x] = id++;
        for (auto& x : changed)
            if (!mp.count(x))
                mp[x] = id++;
        int V = id;
        vector<vector<ll>> dist(V, vector<ll>(V, INF));
        for (int i = 0; i < V; i++)
            dist[i][i] = 0;
        for (int i = 0; i < (int)original.size(); i++) {
            int u = mp[original[i]];
            int v = mp[changed[i]];
            dist[u][v] = min(dist[u][v], (ll)cost[i]);
        }
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        for (int i = 0; i < (int)original.size(); i++) {
            length.insert(original[i].size());
        }
        dp.assign(n, -1);
        long long ans = solve(0, s, t, dist);
        return (ans >= INF ? -1 : ans);
    }
    long long solve(int i, string& s, string& t,vector<vector<long long>>& dist) {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        long long ans = INF;
        if (s[i] == t[i]) {
            ans = solve(i + 1, s, t, dist);
        }
        for (auto len : length) {
            if (i + len > n)
                break;
            string a = s.substr(i, len);
            string b = t.substr(i, len);
            auto it1 = mp.find(a);
            auto it2 = mp.find(b);
            if (it1 == mp.end() || it2 == mp.end())
                continue;
            ll c = dist[it1->second][it2->second];
            if (c < INF) {
                ans = min(ans, c + solve(i + len, s, t, dist));
            }
        }
        return dp[i] = ans;
    }
};
