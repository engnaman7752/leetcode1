class Solution {
public:
    int maxFreqSum(string s) {
     int mv=0;
     int mc=0;
     map<char,int>mp;
     for(int i=0;i<s.size();i++){
        mp[s[i]]++;
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            mv=max(mv,mp[s[i]]);
        }
        else{
            mc=max(mc,mp[s[i]]);
     }
     }
     return mv+mc;
    }
};