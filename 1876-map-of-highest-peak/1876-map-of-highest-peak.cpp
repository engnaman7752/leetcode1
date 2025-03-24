class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> ans(isWater.size(), vector<int>(isWater[0].size(), -1));
        vector<vector<bool>> vis(isWater.size(), vector<bool>(isWater[0].size(), false));
        queue<pair<int,int>>q;
        for (int i = 0; i < isWater.size(); i++) {
            for (int j = 0; j < isWater[0].size(); j++) {
               if(isWater[i][j]==1)
              { q.push({i,j});
               vis[i][j]=true;
               ans[i][j]=0;}
            }
        }
        int count=1;
        while(!q.empty())
        {
            int s=q.size();
            
            for(int i=0;i<s;i++)
            {int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row+1<isWater.size()&&(vis[row+1][col]==false)&&isWater[row+1][col]!=1)
               { q.push({row+1,col});
                ans[row+1][col]=count;
                   vis[row+1][col]=true;
               }
            if(col+1<isWater[0].size()&&(vis[row][col+1]==false)&&isWater[row][col+1]!=1)
               { q.push({row,col+1});
                ans[row][col+1]=count;
                   vis[row][col+1]=true;
               }
            if(col-1>=0&&(vis[row][col-1]==false)&&isWater[row][col-1]!=1)
               { q.push({row,col-1});
                ans[row][col-1]=count;
                   vis[row][col-1]=true;
               }
             if(row-1>=0&&(vis[row-1][col]==false)&&isWater[row-1][col]!=1)
               { q.push({row-1,col});
                ans[row-1][col]=count;
                   vis[row-1][col]=true;
               }
                
            }
            count++;
        }
        return ans;
    }
};