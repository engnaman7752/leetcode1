class Solution {
public:
    set<int> st;
    
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<bool> vis(n, false);
        solve(vis, 0, 0, digits);
        return st.size();
    }
    
    void solve(vector<bool>& vis, int num, int length, vector<int>& digits) {
        if (length == 3) {
            if (num % 2 == 0) {
                st.insert(num);
            }
            return;
        }
        
        for (int i = 0; i < digits.size(); i++) {
            if (!vis[i]) {
                if (length == 0 && digits[i] == 0) continue; 
                
                vis[i] = true;
                solve(vis, num * 10 + digits[i], length + 1, digits);
                vis[i] = false;
            }
        }
    }
};