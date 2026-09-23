class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum=accumulate(nums.begin(),nums.end(),0)-x;
        int n=nums.size();
        if(sum==0)return n;
        int w=-1;
        int left=0; long long k=0;
        for(int right=0;right<n;right++){
            k+=nums[right];
            while(left<=right && k>sum){
                k-=nums[left];
                left++;
            }
             if(k==sum)w=max(w,right-left+1);
        }
        if(w==-1)return -1;
        else return n-w;
    }
};