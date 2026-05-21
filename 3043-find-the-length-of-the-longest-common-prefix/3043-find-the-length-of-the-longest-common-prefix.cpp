class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        int n = arr1.size();
        for (int i = 0; i < n; i++) {
            int val = arr1[i];
            while (val > 0) {
                st.insert(val);
                val /= 10;
            }
        }
        
        int m = arr2.size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int val = arr2[i];
            while (val > 0) {
                if (st.count(val)) {
                    ans = max(ans, (int)to_string(val).size());
                    break;
                }
                val /= 10;
            }
        }
        return ans;
    }
};