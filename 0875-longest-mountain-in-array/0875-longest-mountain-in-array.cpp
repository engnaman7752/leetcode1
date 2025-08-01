class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int i=1;
        while(i<n-1){
            if((nums[i]>nums[i-1])&&(nums[i]>nums[i+1]))
            {int left=i-1;
            int right=i+1;
            while(right<n&&(nums[right]<nums[right-1]))
            {right++;}
           while(left>=0&&nums[left]<nums[left+1])
           {left--;}
          
           ans=max(ans,right-left-1);
         }
           
           i++;
        }
      return ans;


    }
};