class Solution {
public:
    bool possible(int mid,vector<int>&nums,int k){
        int sum=0;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>mid){
            cnt++;
            sum=nums[i];
            }
            if(cnt>k-1)return false;
        }
        return cnt<=k-1;
    }
    int splitArray(vector<int>& nums, int k) {
        int start=*max_element(nums.begin(),nums.end());
        int end=accumulate(nums.begin(),nums.end(),0);
        int ans=end;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(possible(mid,nums,k)){
                ans=min(ans,mid);
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};