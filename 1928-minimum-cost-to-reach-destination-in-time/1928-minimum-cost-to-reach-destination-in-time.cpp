class Solution {
    using t = tuple<int,int,int>; 
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>> adj(n);
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<vector<int>> mon(n, vector<int>(maxTime + 1, INT_MAX));
        priority_queue<t, vector<t>, greater<t>> pq;
        pq.push({passingFees[0], 0, 0});
        mon[0][0] = passingFees[0];
        while (!pq.empty()) {
            auto [amnt, time, node] = pq.top();
            pq.pop();
            if(node==n-1)return amnt;
            if (amnt > mon[node][time]) continue;
            for (auto [neighbour, nodeTime] : adj[node]) {
                int newTime = time + nodeTime;
                if (newTime <= maxTime) {
                    int newAmnt = amnt + passingFees[neighbour];
                    if (newAmnt < mon[neighbour][newTime]) {
                        mon[neighbour][newTime] = newAmnt;
                        pq.push({newAmnt, newTime, neighbour});
                    }
                }
            }
        }

        return -1;
    }
};
