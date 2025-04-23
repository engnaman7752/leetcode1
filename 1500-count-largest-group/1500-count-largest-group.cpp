class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int>mp;
        int maxf=0;
        for(int i=1;i<=n;i++)
        {
            int sum=0;
            int x=i;
            while(x>0)
            {
                sum=sum+x%10;
                x=x/10;
            }
            mp[sum]++;
            if(mp[sum]>maxf)
            maxf=mp[sum];
        }
        int ans=0;
        for(auto it:mp)
        {
            if(it.second==maxf)
            ans++;
        }
        return ans;
        
    }
};