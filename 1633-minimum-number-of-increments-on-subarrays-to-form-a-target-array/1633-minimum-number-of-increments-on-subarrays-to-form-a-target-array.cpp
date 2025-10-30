class Solution {
public:
    int minNumberOperations(vector<int>& nums) {
        int ans = 0;
        stack<int> st;
        st.push(nums[0]);
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < st.top()) {
                ans += st.top() - nums[i];
                st.pop();
                st.push(nums[i]);
            } else if (nums[i] > st.top()) {
                st.push(nums[i]);
            }
        }
        
        ans += st.top();
        return ans;
    }
};
