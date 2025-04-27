class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;
            int k=i+2;
            double x=nums[j];
            if((2*(nums[i]+nums[k])==x))
            cnt++;

        }
        return cnt;
        
    }
};