class Solution {
    private:
     bool isPossible(int newr,int newc,int n,int m){
        if(newr<n&&newr>=0&&newc>=0&&newc<m)return true;
        else return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>time(n,vector<int>(m,INT_MAX));
        time[0][0]=grid[0][0];
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>minTime;
        minTime.push({time[0][0],0,0});
        vector<int>dr{1,-1,0,0};
        vector<int>dc{0,0,1,-1};
        while(!minTime.empty()){
            auto [t,row,col]=minTime.top();
            minTime.pop();
            for(int i=0;i<4;i++){
                int newr=row+dr[i];
                int newc=col+dc[i];
                if(isPossible(newr,newc,n,m)){
                    if(grid[newr][newc]<grid[row][col]&&time[newr][newc]>t){
                        time[newr][newc]=t;
                        minTime.push({t,newr,newc});
                    }
                    else if(grid[newr][newc]>grid[row][col]&&time[newr][newc]>max(t,grid[newr][newc])){
                        time[newr][newc]=max(t,grid[newr][newc]);
                        minTime.push({time[newr][newc],newr,newc});
                    }

                }
            }
        }
        return time[n-1][m-1];
    }
};