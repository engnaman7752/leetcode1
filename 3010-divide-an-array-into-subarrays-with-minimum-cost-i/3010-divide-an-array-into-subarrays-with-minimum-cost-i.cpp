class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size();
        int index=1;
        for(int i=1;i<n;i++){
            if(nums[index]>nums[i]){
                index=i;
            }
        }
        int index2;
       if(index!=1)index2=1;
       else index2=2;
          for(int i=index2;i<n;i++){
            if((index!=i)&&nums[index2]>nums[i]){
                index2=i;
            }

        }
        ans+=nums[index]+nums[index2];
        return ans;
    }
};