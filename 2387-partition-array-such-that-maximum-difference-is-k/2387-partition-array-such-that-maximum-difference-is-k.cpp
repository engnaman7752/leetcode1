class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int start=nums[0];
        int count=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]-start>k)
          { count++;
           start=nums[i];}

        }
        return count;
        
    }
};