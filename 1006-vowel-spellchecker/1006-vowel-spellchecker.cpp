class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> st;
        unordered_map<string,string> l;
        unordered_map<string,string> v;

        for (auto &w : wordlist) {
            st.insert(w);
            string k = lower(w);
            if (l.find(k) == l.end()) l[k] = w;
            string vk = vow(k);
            if (v.find(vk) == v.end()) v[vk] = w;
        }

        vector<string> ans;
        for (auto &q : queries) {
            if (st.find(q) != st.end()) {
                ans.push_back(q);
                continue;
            }
            string k = lower(q);
            if (l.find(k) != l.end()) {
                ans.push_back(l[k]);
                continue;
            }
            string vk = vow(k);
            if (v.find(vk) != v.end()) {
                ans.push_back(v[vk]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }

    string lower(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

    string vow(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                s[i] = '*';
        }
        return s;
    }
};
