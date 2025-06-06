class Solution {
public:
    string robotWithString(string s) {
        map<char,int>mp;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        stack<char>st;
        string ans;
        int i=0;
        while (!mp.empty()) {
        auto it = mp.begin();
        char x = it->first;

        while (i < n && s[i] != x) {
            st.push(s[i]);
            mp[s[i]]--;
            if (mp[s[i]] == 0) {
                mp.erase(s[i]);
            }
            
            i++;
        }
        if (i < n && s[i] == x) {
            ans.push_back(x);
            mp[x]--;
            if (mp[x] == 0) {
                mp.erase(x);
            }
            i++;
        }
        while(!st.empty()&&st.top()<=mp.begin()->first)
            {
            ans.push_back(st.top());
            st.pop();
            }
    }

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;}
};