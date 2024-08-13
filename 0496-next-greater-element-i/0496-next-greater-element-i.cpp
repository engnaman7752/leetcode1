class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--)
        {while((!st.empty())&&(nums2[i]>st.top()))
        st.pop();
        if(st.empty())
        ans[i]=-1;
        else
        ans[i]=st.top();
        st.push(nums2[i]);


        }
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
           { if(nums1[i]==nums2[j])
            {nums1[i]=ans[j];
            break;}}

        }
        
        return nums1;
    }
};