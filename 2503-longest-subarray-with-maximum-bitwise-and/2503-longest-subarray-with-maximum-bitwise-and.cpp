class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int x=*max_element(nums.begin(), nums.end());
        int ans=0;
        for(int i=0;i<nums.size();){
            if(nums[i]==x){
                int count=0;
                while(i<nums.size()&&nums[i]==x)
               { count++;
                i++;}
                ans=max(ans,count);
                            }
                            else
                            i++;
        }
        return ans;
        
    }
};