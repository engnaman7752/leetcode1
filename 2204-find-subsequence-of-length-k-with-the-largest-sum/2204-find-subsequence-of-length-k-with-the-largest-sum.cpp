class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> temp = nums;
        map<int, int> st;
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int i = nums.size() - k;
        while (k--) {
            st[nums[i]]++;
            i++;
        }
        for (int i = 0; i < temp.size(); i++) {
            if (st.find(temp[i]) != st.end() && st[temp[i]] > 0) {
                st[temp[i]]--;
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};