class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxx = s;
        string minn = s;
        char x = s[s.size() - 1];
        char y;
        if (s[0] != '1')
            y = s[0];
        else {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    y = s[i];
                    break;
                }
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '9') {
                x = s[i];
                break;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == x)
                maxx[i] = '9';
            if (s[i] == y && y == s[0])
                minn[i] = '1';
            else if (s[i] == y)
                minn[i] = '0';
        }
        return stoi(maxx) - stoi(minn);
    }
};
