class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0;
        int n = s.size();
        vector<string> res;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') count++;
            else count--;
            if (count == 0) {
                res.push_back("1" +  makeLargestSpecial(s.substr(j + 1, i - j - 1))  + "0");
                j = i + 1;
            }
        }
        sort(res.rbegin(), res.rend());

        string result;
        for (auto &str : res)
            result += str;

        return result;
    }
};