class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        vector<vector<int>>ans;
        int diff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(diff>nums[i]-nums[i-1]){
                ans.clear();
                ans.push_back({nums[i-1],nums[i]});
                diff=nums[i]-nums[i-1];
            }
            else if(diff==nums[i]-nums[i-1]){
                ans.push_back({nums[i-1],nums[i]});
            }
        }
        return ans;
    }
};