class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 1;
        vector<vector<int>> row(n, vector<int>(m, 0));
        vector<vector<int>> col(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i][j] = grid[i][j] + (j ? row[i][j-1] : 0);
                col[i][j] = grid[i][j] + (i ? col[i-1][j] : 0);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=1;k<=min(n-i,m-j);k++){
                    bool flag = true;
                    int sum = row[i][j+k-1] - (j ? row[i][j-1] : 0);
                    for(int r=i;r<i+k;r++){
                        int rsum = row[r][j+k-1] - (j ? row[r][j-1] : 0);
                        if(rsum != sum){ flag=false; break; }
                    }
                    for(int c=j;c<j+k && flag;c++){
                        int csum = col[i+k-1][c] - (i ? col[i-1][c] : 0);
                        if(csum != sum){ flag=false; break; }
                    }
                    int d1 = 0, d2 = 0;
                    for(int t=0;t<k;t++){
                        d1 += grid[i+t][j+t];
                        d2 += grid[i+t][j+k-1-t];
                    }

                    if(d1 != sum || d2 != sum) flag=false;
                    if(flag) ans = max(ans, k);
                }
            }
        }
        return ans;
    }
};
