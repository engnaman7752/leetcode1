class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        int x = (int)(s[s.length() - 1]-'0'); 
        int y = (int)(s[s.length() - 2]-'0'); 
        return x * y;
    }
};