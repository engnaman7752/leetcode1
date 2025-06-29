class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> pow2(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            pow2[i] = (pow2[i - 1] * 2) % 1000000007;
        }
        int left=0;
        int right=nums.size()-1;
        int ans=0;
        while(left<=right)
        {
            if(nums[left]+nums[right]<=target)
            {ans = (ans + pow2[right - left]) % 1000000007;;
            left++;}
            else if(nums[left]+nums[right]>target)
            right--;
        }
         return ans;
        
    }
};