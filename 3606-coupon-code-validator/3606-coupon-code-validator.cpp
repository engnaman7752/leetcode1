class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        map<string, vector<string>> mp;

        for (int i = 0; i < n; i++) {
            if (isActive[i] && isValid(code[i],businessLine[i])) {
                mp[businessLine[i]].push_back(code[i]);
            }
        }

        vector<string> ans;
        for (auto& it : mp) {
            sort(it.second.begin(), it.second.end());
            ans.insert(ans.end(), it.second.begin(), it.second.end());
        }

        return ans;
    }

private:
    bool isValid(string& s,string & p) {
        if(s.size()==0||p=="invalid")return false;
        for (char c : s) {
            if (!(isalnum(c)||c=='_')) {
                return false;
            }
        }
        return true;
    }
};
