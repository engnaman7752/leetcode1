class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i-1]==nums[i])continue;
            if(nums[i]>0)break;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int curr1=nums[j];
                    int curr=nums[i];
                    while(j<k&&nums[j]==curr1)
                    j++;
                     while(j<k&&nums[k]==curr)
                    k--;
                }
                else if(sum>0){
                    int curr=nums[k];
                    while(j<k&&nums[k]==curr)
                    k--;
                }
                else{
                    int curr=nums[j];
                    while(j<k && nums[j]==curr)
                    j++;
                }
            }
        }
        return ans;
    }
};