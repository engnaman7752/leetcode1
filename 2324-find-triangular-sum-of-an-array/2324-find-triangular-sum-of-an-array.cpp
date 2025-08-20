class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            vector<int>post;
            int val=n-i;
            for(int j=1;j<val;j++){
                post.push_back((nums[j]+nums[j-1])%10);
            }
            nums=post;
        }
        return nums[0];
    }
};