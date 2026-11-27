class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int left=0;
        int cnt=0;
        int n=nums.size();
        for(int right=0;right<n;right++){
            if(nums[right]==0)cnt++;
            if(cnt>k){
                while(left<=right && nums[left]!=0)left++;
                cnt--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};