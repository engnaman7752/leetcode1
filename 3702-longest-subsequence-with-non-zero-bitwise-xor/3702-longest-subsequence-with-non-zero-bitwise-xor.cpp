class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
       int xorr=0;
       int n=nums.size();
       bool flag=false;
       for(int i:nums){
        xorr^=i;
        if(xorr>0)flag=true;
       } 
       if(xorr>0)return n;
       if(flag==false)return 0;
       return n-1;
       
    }
};