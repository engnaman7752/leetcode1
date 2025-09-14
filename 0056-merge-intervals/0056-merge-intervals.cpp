class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        int start=nums[0][0];
        int end=nums[0][1];
        for(int i=0;i<n-1;i++){
            end=max(end,nums[i][1]);
            if(end<nums[i+1][0]){
                ans.push_back({start,end});
                start=nums[i+1][0];
                end=nums[i+1][1];
        }
        }
         end=max(end,nums[n-1][1]);
        ans.push_back({start,end});
        return ans;
    }
};