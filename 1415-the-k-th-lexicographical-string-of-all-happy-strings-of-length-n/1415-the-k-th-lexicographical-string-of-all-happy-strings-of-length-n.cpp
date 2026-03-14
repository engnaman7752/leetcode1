class Solution {
public:
    string getHappyString(int n, int k) {
        string test = "";
        set<string> st;
        solve(n, st, test);
        if (st.size() < k)
            return "";
        auto it = st.begin();
        for (int i = 0; i < k - 1; i++)
            it++;
        return *it;
    }
    void solve(int n, set<string> &st, string test) {
        if (test.size() == n) {
            st.insert(test);
            return;
        }
        for (char i = 'a'; i <= 'c'; i++) {
            if(test.size()!=0&&test.back()!=i)
           { test+=i;
            solve(n, st, test);
            test.pop_back();}
            if(test.size()==0){
                test+=i;
            solve(n, st, test);
            test.pop_back();
            }
        }
    }
};