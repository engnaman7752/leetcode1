class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int>dr{0,-1,0,1};
        vector<int>dc{1,0,-1,0};
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++)
            {auto [r,c]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
               int row=dr[k]+r;
                int col=dc[k]+c;
                if(row>=0&&row<n&&col<m&&col>=0&&grid[row][col]==1){
                    q.push({row,col});
                    grid[row][col]=2;
                }
            }
            }
             ans++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return max(0,ans-1);
    }
};