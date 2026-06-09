class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>tp;
        map<char,char>sp;
        for(int i=0;i<s.size();i++){
            if(tp.find(t[i])!=tp.end()){
                if(tp[t[i]]!=s[i])return false;
            }
             if(sp.find(s[i])!=sp.end()){
                if(sp[s[i]]!=t[i])return false;
            }
            tp[t[i]]=s[i];
            sp[s[i]]=t[i];
        }
        return true;
    }
};