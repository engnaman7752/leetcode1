class Solution {
public:
    int minFlips(string s) {
        int diff1 = 0;
        int n = s.size();
        int diff2 = 0;
        s += s;
        int ans = INT_MAX;
        string target1;
        string target2;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                target1.push_back('0');
                target2.push_back('1');
            } else {
                target1.push_back('1');
                target2.push_back('0');
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != target1[i])
                diff1++;
            if (s[i] != target2[i])
                diff2++;
            if (i >= n) {
                if (target1[i - n] != s[i - n])
                    diff1--;
                if (target2[i - n] != s[i - n])
                    diff2--;
            }
            if (i >= n - 1) {
                ans = min({ans, diff1, diff2});
            }
        }
        return ans;
    }
};