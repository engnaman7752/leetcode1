class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
    int maxx=0;
    int minn=INT_MAX;
    for(auto p:mp)
    {
        if(p.second>maxx&&p.second%2)
        maxx=p.second;
        if(p.second<minn&&p.second%2==0)
        minn=p.second;
    }
        return maxx-minn;
    }
};