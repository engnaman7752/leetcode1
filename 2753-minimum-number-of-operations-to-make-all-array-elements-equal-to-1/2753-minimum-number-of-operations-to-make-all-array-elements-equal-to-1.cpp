class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int minLen=INT_MAX;
        int one=count(nums.begin(),nums.end(),1);
        if(one>0){
            return n-one;
        }
        for(int i=0;i<n;i++){
            int a=nums[i];
            for(int j=i+1;j<n;j++){
                a=gcd(a,nums[j]);
                if(a==1){
                    minLen=min(minLen,j-i+1);
                }
            }
        }
        if(minLen==INT_MAX)return -1;
        else 
        return minLen+n-2;
    }
};