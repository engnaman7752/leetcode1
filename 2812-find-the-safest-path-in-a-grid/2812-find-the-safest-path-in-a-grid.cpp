class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>mat(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        // 1. Mark initial thieves immediately when pushing
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
            q.push({i, j});
            mat[i][j] = 0; // Mark visited!
        }
    }
}

int cur = 0;
vector<int> dr({0, 0, 1, -1});
vector<int> dc({1, -1, 0, 0});

while (!q.empty()) {
    int s = q.size();
    for (int i = 0; i < s; i++) {
        auto [row, col] = q.front();
        q.pop();
        
        // REMOVED: mat[row][col] = cur; (Don't do it on pop!)

        for (int j = 0; j < 4; j++) {
            int r = row + dr[j];
            int c = col + dc[j];
            
            if (r >= 0 && r < n && c < n && c >= 0 && mat[r][c] == -1) {
                mat[r][c] = cur + 1; // Assign safeness immediately!
                q.push({r, c});
            }
        }
    }
    cur++;
}
        vector<vector<int>>dis(n,vector<int>(n,INT_MIN));
        priority_queue<tuple<int,int,int>>pq;
        pq.push({mat[0][0],0,0});
        dis[0][0]=mat[0][0];
        while(!pq.empty()){
            auto [weight,row,col]=pq.top();
            pq.pop();
            for(int i=0;i<4;i++){
                 int r=row+dr[i];
                 int c=col+dc[i];
                    if(r>=0 && r<n && c<n && c>=0 && dis[r][c]<min(weight,mat[r][c])){
                        dis[r][c]=min(weight,mat[r][c]);
                        pq.push({min(weight,mat[r][c]),r,c});
                    }
            }
        }
        return dis[n-1][n-1];
    }
};