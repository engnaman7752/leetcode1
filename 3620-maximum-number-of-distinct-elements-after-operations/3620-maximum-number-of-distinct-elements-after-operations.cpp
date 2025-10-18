class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
      int n=nums.size();
      int ans=0;
      long long minn=nums[0]-k-1;
      for(int i=0;i<n;i++){
        if(nums[i]+k<=minn)continue;
        if(nums[i]-k>minn){
            ans++;
            minn=nums[i]-k;
        }
        else if(nums[i]-k<=minn){
            ans++;
            minn++;
        }
      }
      return ans;
    }
};