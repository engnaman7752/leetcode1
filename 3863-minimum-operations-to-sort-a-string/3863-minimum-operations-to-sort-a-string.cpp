class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
       if(n==1)return 0; 
        if(n==2){
            if(s[0]<=s[1])return 0;
            else return -1;
        }
        string t=s;sort(t.begin(),t.end());
        if(s==t)return 0;
        if(t[0]==s[0]||t[n-1]==s[n-1])return 1;
        string l=s.substr(1,n-1);
        sort(l.begin(),l.end());
        if(l[n-2]==t[n-1])return 2;
        l=s.substr(0,n-1);
        sort(l.begin(),l.end());
        if(l[0]==t[0])return 2;
        return 3;
    }
};