class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(auto i:s)
        {
            if(!st.empty()&&(i>='0'&&i<='9'))
            st.pop();
            else
            st.push(i);
        }
        string sk;
        while(!st.empty())
        {
            sk.push_back(st.top());
            st.pop();
        }
        reverse(sk.begin(),sk.end());
        return sk;

    }
};