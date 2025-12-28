class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            reverse(grid[i].begin(),grid[i].end());
            ans+=upper_bound(grid[i].begin(),grid[i].end(),-1)-grid[i].begin();
        }
        return ans;
    }
};