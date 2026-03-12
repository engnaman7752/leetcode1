class DisjointSet {
public:
    vector<int> parent;
    int comp;
    DisjointSet(int n) {
        parent.resize(n);
        comp = n;
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int ultiPar(int u) {
        if (parent[u] == u) return u;
        return parent[u] = ultiPar(parent[u]);
    }
    bool findUnion(int u, int v) {
        int up = ultiPar(u);
        int vp = ultiPar(v);
        if (up == vp) return false;
        parent[up] = vp;
        comp--;
        return true;
    }
};

class Solution {
public:
    bool solve(int n, vector<vector<int>>& edges, int k, int limit) {
        DisjointSet ds(n);
        int usedK = 0;

        // 1. Mandatory edges MUST be included. 
        // If any mandatory edge is < limit, this limit is impossible.
        for (auto& e : edges) {
            if (e[3] == 1) {
                if (e[2] < limit) return false; 
                ds.findUnion(e[0], e[1]);
            }
        }

        // 2. Add optional edges that are already >= limit (no upgrade needed)
        for (auto& e : edges) {
            if (e[3] == 0 && e[2] >= limit) {
                ds.findUnion(e[0], e[1]);
            }
        }

        // 3. Add optional edges that need an upgrade to reach the limit
        for (auto& e : edges) {
            if (e[3] == 0 && e[2] < limit && e[2] * 2 >= limit) {
                if (ds.ultiPar(e[0]) != ds.ultiPar(e[1])) {
                    if (usedK < k) {
                        ds.findUnion(e[0], e[1]);
                        usedK++;
                    }
                }
            }
        }

        return ds.comp == 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        if (n == 1) return 0;

        // Check if mandatory edges are valid (no cycles)
        DisjointSet check(n);
        for (auto& e : edges) {
            if (e[3] == 1) {
                if (!check.findUnion(e[0], e[1])) return -1;
            }
        }

        vector<int> vals;
        for (auto& e : edges) {
            vals.push_back(e[2]);
            if (e[3] == 0) vals.push_back(e[2] * 2);
        }
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int l = 0, r = vals.size() - 1, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (solve(n, edges, k, vals[mid])) {
                ans = vals[mid];
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};