class Solution {
public:
    int target;
    vector<string> addOperators(string num, int t) {
        target = t;
        string s = "";
        vector<string> ans;
        solve(0, s, 0, 0, ans, num);
        return ans;
    }
    void solve(int i, string s, long long cur_num, long long last_operand,
               vector<string>& ans, string& num) {
        int n = num.size();
        if (i == n) {
            if (cur_num == target) {
                ans.push_back(s);
            }
        }
        for (int index = i; index < n; index++) {
            string number = num.substr(i, index - i + 1);
            if (number.length() > 1 && number[0] == '0') {
                break;
            }
            long long val = stoll(number);
            if (i == 0) {
                solve(index + 1, s + number, val, val, ans, num);
            } else {
                solve(index + 1, s + "+" + number, cur_num + val, val, ans,
                      num);
                solve(index + 1, s + "-" + number, cur_num - val, -val, ans,
                      num);
                solve(index + 1, s + "*" + number,
                      cur_num - last_operand + last_operand * val,
                      last_operand * val, ans, num);
            }
        }
    }
};