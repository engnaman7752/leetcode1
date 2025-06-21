class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<char,int>mp;
        int count=word.size();
        for(int i=0;i<word.size();i++)
        {
            mp[word[i]]++;
        }
        vector<pair<char,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](auto &a,auto &b)
        {
            return a.second<b.second;
        });
        for(int i=v.size()-1;i>=0;i--)
        {int cnt=0;
            for(int j=0;j<=v.size()-1;j++)
            {if(v[i].second>v[j].second)
            cnt=cnt+v[j].second;
            else if(abs(v[i].second-v[j].second)>k)
            cnt=cnt+(abs(v[i].second-v[j].second))-k;
            }
            count=min(cnt,count);
        }
        return count;
    }
};