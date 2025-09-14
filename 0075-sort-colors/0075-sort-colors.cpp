class Solution {
public:
    void sortColors(vector<int>& nums) {
      int s=0;
      int n=nums.size();
      int e=n-1;  
      for(int i=0;i<=e;){
        if(nums[i]==0){
            swap(nums[i],nums[s]);
            s++;
            i++;
        }
        else if(nums[i]==2){
            swap(nums[i],nums[e]);
            e--;
        }
        else{
            i++;
        }
      }
    }
};