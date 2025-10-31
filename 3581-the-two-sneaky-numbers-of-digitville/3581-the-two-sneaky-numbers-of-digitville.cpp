class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;
        for(int i:nums){
            mp[i]++;
        }
        for(auto [a,b]:mp){
            if(b==2){
                ans.push_back(a);
                if(ans.size()==2)return ans;
            }
        }
        return {};
    }
};