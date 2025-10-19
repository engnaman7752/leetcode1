#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> st;
        st.insert(s);
        string ans = s;
        queue<string> q;
        q.push(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            string newAdd = add(cur, a);
            string newRot = rot(cur, b);

            if (st.find(newAdd) == st.end()) {
                st.insert(newAdd);
                q.push(newAdd);
            }
            if (st.find(newRot) == st.end()) {
                st.insert(newRot);
                q.push(newRot);
            }

            ans = min(ans, min(newAdd, newRot));
        }
        return ans;
    }

    string add(string s, int a) {
        for (int i = 1; i < s.size(); i += 2) { 
            int num = (s[i] - '0' + a) % 10;
            s[i] = char(num + '0');
        }
        return s;
    }

    string rot(string s, int b) {
        rotate(s.begin(), s.begin() + b, s.end());
        return s;
    }
};
