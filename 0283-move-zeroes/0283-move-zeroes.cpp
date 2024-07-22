class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>a;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            a.push_back(nums[i]);
        }
        for(int i=a.size();i<nums.size();i++)
        a.push_back(0);
        for(int i=0;i<nums.size();i++)
        nums[i]=a[i];
    }
};