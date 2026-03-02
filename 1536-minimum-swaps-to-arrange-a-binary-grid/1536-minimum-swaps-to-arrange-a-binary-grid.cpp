class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int ans=0;int n=grid.size();
        for(int i=0;i<n;i++){
            bool flag=false;
            for(int j=i;j<n;j++){
                bool flag2=true;
                for(int k=n-1;k>i;k--){
                    if(grid[j][k]!=0){
                        flag2=false;
                        break;
                    }
                }
                if(flag2){
                    ans+=j-i;
                    for(int l=i+1;l<=j;l++){
                        swap(grid[l],grid[i]);
                    }
                    flag=true;
                    break;
                }
            }
            if(flag==false)return -1;
        }
        return ans;
    }
};