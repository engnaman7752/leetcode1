class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, vector<int>> mp;
        
        // Store all occurrences of each character, just like you did
        for (int i = 0; i < n; i++) {
            mp[s[i]].push_back(i);
        }
        
        vector<string> ans;
        int last_right = -1;
        
        for (int i = 0; i < n; i++) {
            if (i == mp[s[i]].front()) {
                int end = mp[s[i]].back();
                bool isValid = true;
                for (int j = i; j <= end; j++) {
                    if (mp[s[j]].front() < i) {
                        isValid = false;
                        break;
                    }
                    end = max(end, mp[s[j]].back());
                }
                
                if (isValid) {
                    if (i > last_right) {
                        ans.push_back(s.substr(i, end - i + 1));
                    } 
                    else {
                        ans.back() = s.substr(i, end - i + 1);
                    }
                    last_right = end;
                }
            }
        }
        return ans;
    }
};