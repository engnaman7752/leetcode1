class Solution {
public:
    bool isValid(string s) {
        stack<char>para;
        int i=0;
        while(i<s.size())
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                para.push(s[i]);
            }
            else if((!para.empty())&&(
            (s[i]==')'&&para.top()=='(')||
            (s[i]==']'&&para.top()=='[')||
            (s[i]=='}'&&para.top()=='{')))
            {
                para.pop();
            }
            else
            return false;
            
            i++;
        }
        if(para.size()==0)
        return true;
        else
        return false;
    }
};