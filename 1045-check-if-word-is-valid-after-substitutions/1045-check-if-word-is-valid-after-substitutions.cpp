class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty()&&st.top()=='c')
            {
                int count=3; char curr='c';
                while(count>0&&!st.empty()&&st.top()==curr)
                {
                    st.pop();
                    count--;
                    curr--;
                }
                if(count!=0)
                return false;

            }
            st.push(s[i]);
        }
        if(!st.empty()&&st.top()=='c')
            {
                int count=3; char curr='c';
                while(!st.empty()&&count>0&&st.top()==curr)
                {
                    st.pop();
                    count--;
                    curr--;
                }
                 if(count!=0)
                return false;
            }
                if(st.empty())
                return true;
                else
                return false;
    }
};