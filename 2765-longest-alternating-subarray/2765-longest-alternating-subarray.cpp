class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans=0;int n=nums.size();
        for(int i=0;i<n;i++){
            int j=i;bool flag=true;
            while(j<n-1){
                if(flag&&nums[j]+1==nums[j+1])flag=false;
                else if(!flag&&nums[j]==nums[j+1]+1)flag=true;
                else break;
                j++;
            }
            ans=max(ans,j-i+1);
        }
        if(ans==1)return -1;
        else return ans;
    }
};