class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty()&&(st.top()==s[i]))
            st.pop();
            else
            st.push(s[i]);
        }
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        int start=0;
        int end=ans.size()-1;
        while(start<end)
        {swap(ans[start],ans[end]);
        start++;
        end--;}
        return ans;

    }
};