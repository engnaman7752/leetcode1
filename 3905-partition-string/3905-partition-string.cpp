class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> st;
        string temp;
        vector<string> ans;
        for (int i = 0; i < s.size(); i++) {
            temp.push_back(s[i]);
            if (st.find(temp) == st.end()) {
                st.insert(temp);
                ans.push_back(temp);
                temp = "";
            }
        }
        return ans;
    }
};