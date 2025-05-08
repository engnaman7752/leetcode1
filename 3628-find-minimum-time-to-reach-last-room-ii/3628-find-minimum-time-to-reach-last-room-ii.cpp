class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        vector<int> row{1, 0, -1, 0};
        vector<int> col{0, 1, 0, -1};
        int cnt=0;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int distance = p[0];
            int noder   = p[1];
            int nodec   = p[2];
            cnt++;
            if (distance > dis[noder][nodec])
                continue;

            for (int i = 0; i < 4; ++i) {
                int newr = noder + row[i];
                int newc = nodec + col[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < m) {
                    int newTime = max(distance, moveTime[newr][newc])+1+(noder+nodec)%2;
                if (dis[newr][newc] > newTime) {
                        dis[newr][newc] = newTime;
                        pq.push({newTime, newr, newc});
                    }
                }
            }
        }

        return dis[n-1][m-1];
    }
};