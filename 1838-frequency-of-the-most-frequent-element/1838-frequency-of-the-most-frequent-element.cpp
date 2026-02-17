class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        int n=nums.size();int left=0;int ans=1;
        for(int right=0;right<n;right++){
            k-=(nums[left]-nums[right]);
            while(k<0){
                k+=(right-left)*(nums[left]-nums[left+1]);
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};