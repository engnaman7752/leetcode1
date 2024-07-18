class Solution {
   public:
    vector<int> finalPrices(vector<int>& prices) {
       int n=prices.size();
        stack<int> st;
    vector<int> ans(n);
    st.push(0);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = prices[i];
        while (st.top() > curr)
        {
            st.pop();
        }
        ans[i]=curr-st.top();
        st.push(curr);
    }
    return ans;
    }
};