class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> st;
        for (auto f : friendships) {
            int u = f[0] - 1;
            int v = f[1] - 1;
            set<int> s(languages[u].begin(), languages[u].end());

            bool talk = false;
            for (int lang : languages[v]) {
                if (s.find(lang) != s.end()) {
                    talk = true;
                    break;
                }
            }

            if (!talk) { 
                st.insert(u);
                st.insert(v);
            }
        }

        if (st.empty()) return 0;

        map<int,int> mp;
        int maxx = 0;
        for (auto it : st) {
            for (int fr : languages[it]) {
                mp[fr]++;
                maxx = max(maxx, mp[fr]);
            }
        }

        return (int)st.size() - maxx;
    }
};
