class Solution {
public:
    int romanToInt(string s) {
         map<char,int>mp{{'M',1000},{'D',500},{'C',100},
        {'L',50},{'X',10},{'V',5},{'I',1}};
        int ans=0;
        for(int i=0;i<s.size();i++){
            int curr=mp[s[i]];
            int next=0;
            if(i!=s.size()-1)next=mp[s[i+1]];
            if(next<=curr)
            ans+=curr;
            else
            ans-=curr;
        }
        return ans;
    }
};