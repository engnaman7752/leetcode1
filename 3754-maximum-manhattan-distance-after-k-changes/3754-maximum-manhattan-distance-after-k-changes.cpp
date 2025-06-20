class Solution {
public:
    int maxDistance(string s, int k) {
        int x=0;
        int y=0;
        int ans=0;
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='N')x++;
            if(s[i]=='S')x--;
            if(s[i]=='W')y--;
            if(s[i]=='E')y++;
            count=abs(x)+abs(y);
            int dis = count + min(2 * k, i + 1 - count);
            ans = max(ans, dis);
            
        }
        return ans;
    }
};