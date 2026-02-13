class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;

        unordered_map<char, int> window_mp;
        queue<int> q; 
        
        int l = -1, r = -1; 
        int cnt = 0;        
        int m = t.size();
        int min_len = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            if (mp.count(s[right])) {
                q.push(right);
                window_mp[s[right]]++;
                if (window_mp[s[right]] <= mp[s[right]]) {
                    cnt++;
                }
            }
            while (!q.empty() && window_mp[s[q.front()]] > mp[s[q.front()]]) {
                window_mp[s[q.front()]]--;
                q.pop();
            }
            if (cnt == m) {
                int current_left = q.front();
                if (right - current_left + 1 < min_len) {
                    min_len = right - current_left + 1;
                    l = current_left;
                    r = right;
                }
            }
        }
        if (l == -1) return "";
        return s.substr(l, r - l + 1);
    }
};