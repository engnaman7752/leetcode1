class Solution {
public:
    int maxBuilding(int k, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        sort(restrictions.begin(),restrictions.end());
        int n=restrictions.size();
        for(int i=1;i<n;i++){
            restrictions[i][1]=min(restrictions[i][1],restrictions[i-1][1]+(restrictions[i][0]-restrictions[i-1][0]));
        }
        for(int i=n-2;i>=0;i--){
             restrictions[i][1]=min(restrictions[i][1],restrictions[i+1][1]+(restrictions[i+1][0]-restrictions[i][0]));
        }
        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,(restrictions[i][0]-restrictions[i-1][0] +restrictions[i][1]+restrictions[i-1][1])/2);
        }
        ans=max(ans,k-restrictions[n-1][0]+restrictions[n-1][1]);
        return ans;

    }
};