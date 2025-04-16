class Solution {
public:
    string getSmallestString(string s) {
        for(int i=0;i<s.size()-1;i++)
        {if(((s[i]%2==0&&s[i+1]%2==0)||(s[i+1]%2==1&&s[i]%2==1))&&s[i]>s[i+1])
            {char a=s[i];
            s[i]=s[i+1];
            s[i+1]=a;
               break; 
            }
        }
        return s;
    }
};