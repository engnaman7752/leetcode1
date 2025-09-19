class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> p;
        p.push({0,0,0});
        vector<int>dr{1,0,-1,0};
        vector<int>dc{0,1,0,-1};
        while(!p.empty()){
            auto [dist,r,c]=p.top();
            p.pop();
            for(int i=0;i<4;i++){
                int row=r+dr[i];
                int col=c+dc[i];
                if(row>=0&&row<n&&col>=0&&col<m){
                    if(dis[row][col]>max(abs(heights[r][c]-heights[row][col]),dist))
                    {
                        dis[row][col]=max(abs(heights[r][c]-heights[row][col]),dist);
                        p.push({dis[row][col],row,col});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};