class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        ans=ans|nums[i];
        return solve(0,nums,ans,0);
    }
    int solve(int index,vector<int>&nums,int ans,int curr){
        if(index==nums.size()){
            if(curr==ans)return 1;
            else return 0;
        };
        return solve(index+1,nums,ans,curr|nums[index])+solve(index+1,nums,ans,curr);
    }
};