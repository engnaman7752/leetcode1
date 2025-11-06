class Solution {
public:
    vector<int> processQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> comp(n + 1, -1);
        int cid = 0;

        for (int i = 1; i <= n; i++) {
            if (comp[i] == -1) {
                bfs(i, cid, adj, comp);
                cid++;
            }
        }

       
        vector<bool> online(n + 1, true);
        unordered_map<int, set<int>> online_nodes;

        for (int i = 1; i <= n; i++) {
            online_nodes[comp[i]].insert(i);
        }

        vector<int> ans;

        for (auto& q : queries) {
            int type = q[0];
            int x = q[1];
            int group = comp[x];

            if (type == 1) {
                if (online[x]) {
                    ans.push_back(x);
                } else {
                    if (online_nodes[group].empty()) {
                        ans.push_back(-1);
                    } else {
                        ans.push_back(*online_nodes[group].begin()); 
                    }
                }
            } else if (type == 2) {
                if (online[x]) {
                    online[x] = false;
                    online_nodes[group].erase(x);
                }
            }
        }

        return ans;
    }

private:
    void bfs(int start, int cid, vector<vector<int>>& adj, vector<int>& comp) {
        queue<int> q;
        q.push(start);
        comp[start] = cid;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int nei : adj[curr]) {
                if (comp[nei] == -1) {
                    comp[nei] = cid;
                    q.push(nei);
                }
            }
        }
    }
};