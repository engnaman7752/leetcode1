class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        sum=sum+nums[i];
        int count=0;
        int add=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            add=add+nums[i];
            int two=sum-add;
            if(abs(two-add)%2==0)count++;
        }
        return count;
    }
};