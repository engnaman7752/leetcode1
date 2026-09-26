class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto k : knowledge) {
            mp[k[0]] = k[1];
        }
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                string k = "";
                i++;
                while (s[i] != ')') {
                    k += s[i];
                    i++;
                }
                //cout<<k<<endl;
                if (mp.find(k) == mp.end())
                    ans += '?';
                else
                    ans += mp[k];
            } else
                ans += s[i];
        }
        return ans;
    }
};