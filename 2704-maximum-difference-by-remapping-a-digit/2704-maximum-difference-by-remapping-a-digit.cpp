class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxx = s;
        string minn = s;
        char x;
        char y;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '9') {
                x = s[i];
                break;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                y = s[i];
                break;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == x)
                maxx[i] = '9';
            if (s[i] == y)
                minn[i] = '0';
        }
        return stoi(maxx) - stoi(minn);
    }
};