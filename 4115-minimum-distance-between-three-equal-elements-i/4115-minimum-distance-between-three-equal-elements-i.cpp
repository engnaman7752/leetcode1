class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>>mp;
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto it:mp){
            if(it.second.size()>=3){
                for(int i=0;i<it.second.size()-2;i++){
                    ans=min(ans,abs(it.second[i]-it.second[i+1])+abs(it.second[i+2]-it.second[i+1])+abs(it.second[i]-it.second[i+2]));
                }
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};