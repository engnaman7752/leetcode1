class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>fr;
        for(int i=0;i<nums.size();i++)
        {
            fr[nums[i]]++;
        }
        for(auto it:fr)
        {
            if(it.second>nums.size()/2)
            return it.first;
        }
        return -1;
    }
};