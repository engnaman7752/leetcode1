class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int,vector<int>>mp;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }
        for(auto &[a,b]:mp){
            if(a>=0)
            sort(b.begin(),b.end());
            else
            sort(b.rbegin(),b.rend());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return grid;
    }
};