class Solution {
public:
    string clearStars(string s) {
    map<char, vector<int>> mp;
    vector<bool> v(s.size(), true);

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c != '*') {
            mp[c].push_back(i);
        } else {
            v[i] = false;

            if (!mp.empty()) {
                auto it = mp.begin();
                if (!it->second.empty()) {
                    v[it->second.back()] = false;
                    it->second.pop_back();
                    if (it->second.empty()) {
                        mp.erase(it);
                    }
                }
            }
        }
    }

    string ans;
    for (int i = 0; i < s.size(); i++) {
        if (v[i])
            ans.push_back(s[i]);
    }
    return ans;
}

};