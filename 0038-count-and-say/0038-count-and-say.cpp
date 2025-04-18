class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int l = 1; l < n; l++) {
            string temp;
            for (int i = 0; i < s.size(); ) {
                char same = s[i];
                int count = 0;
                while (i < s.size() && s[i] == same) {
                    count++;
                    i++;
                }
                temp += to_string(count);
                temp += same;
            }
            s = temp;
        }
        return s;
    }
};
