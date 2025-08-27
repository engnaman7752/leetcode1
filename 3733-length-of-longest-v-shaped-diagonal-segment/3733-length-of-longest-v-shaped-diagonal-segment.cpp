class Solution {
    // true clockwise order: (1,1) -> (1,-1) -> (-1,-1) -> (-1,1)
    vector<pair<int,int>> p{{1,1},{1,-1},{-1,-1},{-1,1}};
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // dp[i][j][dir][turn][needBit]  turn: 1=turn available, 0=used; needBit: 1=expect 2, 0=expect 0
        vector<vector<vector<vector<array<int,2>>>>> dp(
            n, vector<vector<vector<array<int,2>>>>(
                   m, vector<vector<array<int,2>>>(4, vector<array<int,2>>(2, {-1,-1}))));
        int ans = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==1){
                    for (int d=0; d<4; d++){
                        ans = max(ans, 1 + solve(i,j,d,1, /*need=*/2, grid, dp));
                    }
                }
            }
        }
        return ans;
    }

    int solve(int i,int j,int dir,int turn,int need,
              vector<vector<int>>& g,
              vector<vector<vector<vector<array<int,2>>>>>& dp) {
        int n=g.size(), m=g[0].size();
        int nb = (need==2)?1:0;                 // need bit for memo
        int &memo = dp[i][j][dir][turn][nb];
        if (memo!=-1) return memo;

        int ni = i + p[dir].first, nj = j + p[dir].second;
        if (ni<0||nj<0||ni>=n||nj>=m||g[ni][nj]!=need) return memo = 0;

        int next = (need==2)?0:2;
        int best = solve(ni,nj,dir,turn,next,g,dp);             // keep direction
        if (turn) {
            int nd = (dir+1)%4;                                 // single clockwise turn
            best = max(best, solve(ni,nj,nd,0,next,g,dp));
        }
        return memo = best + 1;
    }
};
