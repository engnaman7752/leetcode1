class Solution {
    private:
   bool isPossible(int newr,int newc,int n,int m){
        if(newr<n&&newr>=0&&newc>=0&&newc<m)return true;
        else return false;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>minCost;
        minCost.push({0,0,0});
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>cost(n,vector<int>(m,INT_MAX));
        cost[0][0]=0;
        vector<int>dr{-5,0,0,1,-1};
        vector<int>dc{-5,1,-1,0,0};
        while(!minCost.empty()){
            auto [c,row,col]=minCost.top();
            minCost.pop();
            for(int i=1;i<5;i++){
                int newr=dr[i]+row;int newc=dc[i]+col;
                if(i==grid[row][col]&&isPossible(newr,newc,n,m)){
                    if(cost[newr][newc]>c)
                   { minCost.push({c,newr,newc});
                        cost[newr][newc]=c ;      
                                }
                }
                else if(isPossible(newr,newc,n,m)){
                    if(cost[newr][newc]>c+1)
                    {minCost.push({c+1,newr,newc});
                     cost[newr][newc]=c+1;}
                }
            }
        }
        return cost[n-1][m-1];
    }
};