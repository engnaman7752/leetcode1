class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        map<char,int>m;
        for(int i=0;i<n;i++)
        {
            m[s[i]]=i;
        }
        vector<int>ans;
        int x=0;
        int i=0;
        while(i<n)
        { x=max(x,m[s[i]]);
        for(int j=i;j<x;j++)
        {
            if((x<m[s[j]]))
            x=m[s[j]];
        }
        ans.push_back(x);
        i=x+1;

            
        }
        
        for(int i=ans.size()-1;i>0;i--)
        ans[i]=ans[i]-ans[i-1];
        ans[0]++;
        return ans;

    }
};