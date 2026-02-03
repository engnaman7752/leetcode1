class Solution {
public:
    bool isTrionic(vector<int>& nums) {
       int cnt=0;
       bool flag=true;
       int i=1;
       int n=nums.size();
       if(n<=3)return false;
       if(nums[0]>=nums[1])return false;
       while(i<n-1){
        if(nums[i]>nums[i+1]&&flag){
            flag=false;
            cnt++;
        }
        else if(nums[i]<nums[i+1]&&!flag){
            flag=true;
            cnt++;
        }
        else if(nums[i]==nums[i+1]){
            return false;
        }
        if(cnt>2)return false;
        i++;
       }
       return flag&&cnt==2;
    }
};
