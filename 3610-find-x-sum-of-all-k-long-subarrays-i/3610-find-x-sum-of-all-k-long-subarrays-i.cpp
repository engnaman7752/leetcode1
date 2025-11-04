class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int l=0;
        int r=0;
        int n=nums.size();
        vector<int>ans;
        map<int,int>mp;
        while(r<n){
            mp[nums[r]]++;
            if(r-l+1==k){
                vector<pair<int,int>>sum;
                for(auto it:mp){
                    if(it.second!=0)
                    sum.push_back({it.second,it.first});
                }
                 sort(sum.begin(), sum.end(), [&](auto &a, auto &b){
                    if (a.first == b.first) return a.second > b.second; 
                    return a.first > b.first; 
                });
                int i=0;
                int s=0;
                while(i<sum.size()&&i<x){
                    s+=sum[i].first*sum[i].second;
                    i++;
                }
                ans.push_back(s);
                mp[nums[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};