class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int start=0;
        int ans=0;
        for(auto i:gain){
            start+=i;
            ans=max(ans,start);
        }
        return ans;
    }
};