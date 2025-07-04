class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x=nums.size();
        int count=0;
        vector<int>a;
        a.push_back(nums[0]);
        for(int i=1;i<x;i++)
        {
            if(nums[i]!=nums[i-1])a.push_back(nums[i]);
        }
        nums=a;
        return a.size();
        
    }
};