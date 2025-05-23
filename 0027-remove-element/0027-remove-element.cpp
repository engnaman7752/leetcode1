class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        int i=0;
        int j=0;
        int n=nums.size();
        while(i<n)
        {
            if(nums[i]==val)
            {
                count++;
            }
            else
            nums[j++]=nums[i];
            i++;
        }
        return nums.size()-count;
    }
};