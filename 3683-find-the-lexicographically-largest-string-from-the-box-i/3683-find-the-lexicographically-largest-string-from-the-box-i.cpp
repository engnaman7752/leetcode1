class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if (numFriends == 1) return word;
        string temp = word;
        sort(word.begin(), word.end());
        char x = word[n - 1];
        if (n == numFriends) return string(1, x);
        int keepLen = n - numFriends + 1;
        vector<string> s;
        for (int i = 0; i < n; i++) {
            if (temp[i] == x) {
                if (i + keepLen <= n) 
                    s.push_back(temp.substr(i, keepLen));
                else if(i + keepLen > n&&i>=numFriends)
                    s.push_back(temp.substr(i));
                    
                
            }
        }
        if (s.empty()) return string(1, x);
        sort(s.begin(), s.end());
        return s.back();
    }
};
