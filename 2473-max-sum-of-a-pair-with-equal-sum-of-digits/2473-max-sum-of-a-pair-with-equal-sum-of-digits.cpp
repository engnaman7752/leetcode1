class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        map<int,priority_queue<int>>m;
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            int sum=0;
            while(num>=10)
            {
                sum=num%10+sum;
                num=num/10;
            }
            m[sum+num].push(nums[i]);
        }
        int ans=-1;
        for(auto[i,j]:m)
        {
            if(j.size()>1)
            {int k=j.top();
            j.pop();
            ans=max(k+j.top(),ans);
            }
        }
        return ans;
    }
};