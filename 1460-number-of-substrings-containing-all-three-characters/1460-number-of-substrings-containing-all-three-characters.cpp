class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        vector<int> pos{-1, -1, -1};

        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'] = i;
            if (find(pos.begin(), pos.end(), -1) == pos.end()) 
                ans = 1 + ans + min(pos[0], min(pos[1], pos[2]));
        }

        return ans;
    }
};