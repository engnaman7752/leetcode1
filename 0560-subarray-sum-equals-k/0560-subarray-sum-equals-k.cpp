class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int result=0;
        mp[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            result=result+mp[sum-k];
            mp[sum]++;
        }
       return result; 
    }
};