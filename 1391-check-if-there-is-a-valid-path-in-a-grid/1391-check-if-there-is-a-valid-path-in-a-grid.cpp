class DSU {
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findPar(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findPar(parent[u]);
    }
    void unite(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv])
            swap(pu, pv);
        size[pu] += size[pv];
        parent[pv] = pu;
    }
};

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DSU d(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if (j + 1 < m &&
                        (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 ||
                         grid[i][j + 1] == 5))
                        d.unite(m * i + j, m * i + (j + 1));
                    if (j - 1 >= 0 &&
                        (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 ||
                         grid[i][j - 1] == 6))
                        d.unite(m * i + j, m * i + (j - 1));
                }
                if (grid[i][j] == 2) {
                    if (i + 1 < n &&
                        (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 ||
                         grid[i + 1][j] == 6))
                        d.unite(m * i + j, m * (i + 1) + j);
                    if (i - 1 >= 0 &&
                        (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 ||
                         grid[i - 1][j] == 4))
                        d.unite(m * i + j, m * (i - 1) + j);
                }
                if (grid[i][j] == 3) {
                    if (j - 1 >= 0 &&
                        (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 ||
                         grid[i][j - 1] == 6))
                        d.unite(m * i + j, m * i + (j - 1));
                    if (i + 1 < n &&
                        (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 ||
                         grid[i + 1][j] == 6))
                        d.unite(m * i + j, m * (i + 1) + j);
                }
                if (grid[i][j] == 4) {
                    if (j + 1 < m &&
                        (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 ||
                         grid[i][j + 1] == 5))
                        d.unite(m * i + j, m * i + (j + 1));
                    if (i + 1 < n &&
                        (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 ||
                         grid[i + 1][j] == 6))
                        d.unite(m * i + j, m * (i + 1) + j);
                }
                if (grid[i][j] == 5) {
                    if (j - 1 >= 0 &&
                        (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 ||
                         grid[i][j - 1] == 6))
                        d.unite(m * i + j, m * i + (j - 1));
                    if (i - 1 >= 0 &&
                        (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 ||
                         grid[i - 1][j] == 4))
                        d.unite(m * i + j, m * (i - 1) + j);
                }
                if (grid[i][j] == 6) {
                    if (j + 1 < m &&
                        (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 ||
                         grid[i][j + 1] == 5))
                        d.unite(m * i + j, m * i + (j + 1));
                    if (i - 1 >= 0 &&
                        (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 ||
                         grid[i - 1][j] == 4))
                        d.unite(m * i + j, m * (i - 1) + j);
                }
            }
        }
        return d.findPar(0) == d.findPar((n * m) - 1);
    }
};