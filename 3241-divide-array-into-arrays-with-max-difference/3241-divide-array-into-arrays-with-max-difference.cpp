class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size()-2;i=i+3)
        {
            if(nums[i+2]-nums[i]<=k)
            {vector<int>temp(nums.begin()+i,nums.begin()+i+3);
                ans.push_back(temp);
            }
            else
            {vector<vector<int>>temp;
            return temp;

            }
        }
        return ans;
        
    }
};