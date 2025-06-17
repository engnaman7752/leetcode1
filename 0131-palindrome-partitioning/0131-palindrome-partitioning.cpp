class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>a;
        solve(0,ans,a,s);
        return ans;
    }
    void solve(int index,vector<vector<string>>& ans,vector<string>& a,string s)
    {
        if(index==s.size())
       { ans.push_back(a);
        return;}
       for (int i = index; i < s.size(); i++) {
        string prefix = s.substr(index, i+1-index);
        if (isPalindrome(prefix)) {
       { a.push_back(prefix);
        solve(i + 1, ans, a, s);
        a.pop_back();}
    }
}

    }
    bool isPalindrome(string s)
    {
        for(int i=0,j=s.size()-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])return false;
        }
        return true;
    }
};