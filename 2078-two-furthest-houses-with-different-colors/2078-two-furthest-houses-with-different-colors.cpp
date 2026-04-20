class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(colors[i]!=colors[j]){
                    ans=max(ans,abs(i-j));
                    break;
                }
            }
        }
        return ans;
    }
};