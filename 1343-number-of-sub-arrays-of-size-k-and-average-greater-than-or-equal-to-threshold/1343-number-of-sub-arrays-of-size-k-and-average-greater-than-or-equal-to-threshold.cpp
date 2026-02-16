class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int left=0;int n=nums.size();
        int sum=0;int ans=0;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            if(right-left+1==k){
                if(sum/k>=threshold)ans++;
                sum-=nums[left];
                left++;
            }
        }
        return ans;
    }
};