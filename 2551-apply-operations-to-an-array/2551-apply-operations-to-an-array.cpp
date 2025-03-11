class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size()-1;i++)
        {if(nums[i]!=0)
           { if(nums[i]==nums[i+1])
           { ans.push_back(nums[i]*2);
            nums[i+1]=0;}
            else
           { 
            ans.push_back(nums[i]);}}
        }
        ans.push_back(nums[nums.size()-1]);
        for(int i=ans.size();i<nums.size();i++)
        ans.push_back(0);
        return ans;

    }
};