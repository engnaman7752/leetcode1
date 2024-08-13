class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        stack<int>stp;

        vector<int>ans(n);
        for(int i=n-1;i>=0;i--)
        {while((!st.empty())&&(nums[i]>=st.top()))
        st.pop();
        if(st.empty())
        {bool flag=true;
            for(int j=0;j<i;j++)
            {if(nums[i]<nums[j])
            {
            ans[i]=nums[j];
            flag=false;
            break;}}
            if(flag)
            ans[i]=-1;
        }
        
        else
        ans[i]=st.top();
        st.push(nums[i]);


        }
        return ans;
    }
};