class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>arr=nums;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<n&&arr[i]==nums[i])i++;
        while(j>=0&&arr[j]==nums[j])j--;
        if(i>j)return 0;
        return j-i+1;
    }
};