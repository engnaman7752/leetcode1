class Solution {
public:
    set<string> st;
    map<string, vector<char>> mp;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (int i = 0; i < allowed.size(); i++) {
            string key = allowed[i].substr(0, 2);
            mp[key].push_back(allowed[i][2]);
        }
        return solve(bottom);
    }
    bool solve(string bottom) {
        if (bottom.size() == 1) return true;
        if (st.find(bottom) != st.end()) return false;
        string next = "";
        bool ans = dfs(bottom, 0, next);
        if (!ans) st.insert(bottom);
        return ans;
    }
    bool dfs(string &bottom, int index, string &next) {
        if (next.size() == bottom.size() - 1) {
            return solve(next);
        }
        string key = "";
        key += bottom[index];
        key += bottom[index + 1];
        if (mp.count(key) == 0) return false;
        for (int i = 0; i < mp[key].size(); i++) {
            next.push_back(mp[key][i]);
            if (dfs(bottom, index + 1, next)) return true;
            next.pop_back();   
        }
        return false;
    }
};
