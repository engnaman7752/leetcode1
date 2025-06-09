class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0;
        int n=g.size();int m=s.size();
        for(int i=0,j=0;i<n&&j<m;j++)
        {if(g[i]<=s[j])
        {
            ans++;
            i++;
        }

        }
        return ans;
    }
};