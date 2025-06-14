class Solution {
private:
    void solve(int index, vector<string>& s, string a, vector<string>& ans,
               string digits) {
        if (index == digits.size()) {
            ans.push_back(a);
            return;
        }

        int digit =((int)digits[index] - '0');
         for (int j = 0; j < s[digit].size(); j++) {
            a.push_back(s[digit][j]);
            solve(index+1,s, a, ans, digits);
            a.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> s{"",    "",    "abc",  "def", "ghi",
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        if(digits.size()==0)
        return ans;
        string a;
        solve(0, s, a, ans, digits);
        return ans;
    }
};