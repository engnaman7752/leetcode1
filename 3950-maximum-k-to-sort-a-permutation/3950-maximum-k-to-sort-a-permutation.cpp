class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int>a=nums;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            if(a[i]!=nums[i]){
                if(ans!=-1)ans=ans&a[i];
                else ans=a[i];}
        }
        return max(ans,0);
    }
};