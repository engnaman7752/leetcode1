class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minimum=min_element(nums.begin(),nums.end())-nums.begin();
        int maximum=max_element(nums.begin(),nums.end())-nums.begin();
        int ans=min(n-minimum+maximum+1,n-maximum+minimum+1);
        ans=min(ans,n-min(minimum,maximum));
        ans=min(ans,max(minimum,maximum)+1);
        return ans;
    }
};