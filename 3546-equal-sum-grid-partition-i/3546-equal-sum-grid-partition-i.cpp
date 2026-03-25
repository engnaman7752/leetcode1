class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum=0;
        for(auto i:grid){
            for(auto j:i)sum+=j;
        }
        if(sum%2)return false;
        long long s=0;int n=grid.size();int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s+=grid[i][j];
            }
            if(s==sum/2)return true;
            if(s>sum/2)break;
        }
        s=0;
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                s+=grid[j][i];
            }
            if(s==sum/2)return true;
            if(s>sum/2)break;
        }
        return false;
    }
};