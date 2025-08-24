class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        vector<int>minn(n);
        minn[n-1]=nums[n-1];
        vector<int>ans(n);
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            minn[i]=min(minn[i+1],nums[i]);

        }
        ans[n-1]=pre[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i]=pre[i];
           if(minn[i+1]<pre[i])
           ans[i]=ans[i+1];
           
        }
        return ans;
        
    }
};