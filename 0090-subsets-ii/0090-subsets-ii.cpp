class Solution {
    void solve(int index,vector<vector<int>>& ans,vector<int>a,vector<int>& nums)
    {
        ans.push_back(a);
        
        for(int i=index;i<nums.size();i++)
        {
            if(i>index&&nums[i]==nums[i-1])continue;
            a.push_back(nums[i]);
            solve(i+1,ans,a,nums);
            a.pop_back();
        }
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>a;
        sort(nums.begin(),nums.end());
        solve(0,ans,a,nums);
        return ans;
        
    }
};