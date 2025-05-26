class Solution {
public:
    string resultingString(string s) {
       string ans;
       stack<char>st;
       st.push(s[0]);
       for(int i=1;i<s.size();i++)
       {
        if((abs((int)s[i]-st.top())==1)||(abs((int)s[i]-st.top())==25))
        {
            st.pop();
        }
        else
         st.push(s[i]);
         if((i!=s.size()-1)&&st.empty())
         {st.push(s[i+1]);
         i=i+1;}
       }
       while(!st.empty())
       {
        ans.push_back(st.top());
        st.pop();
       }
       reverse(ans.begin(),ans.end());
       return ans;

    }
};