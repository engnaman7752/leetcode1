class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int start=0;
       int n=nums.size();
       while(start<n && nums[start]!=0){
        start++;
       } 
       if(start==n)return;
       for(int i=start+1;i<nums.size();i++){
        if(nums[i]!=0){
        swap(nums[start],nums[i]);
        start++;}
       }
    }
};