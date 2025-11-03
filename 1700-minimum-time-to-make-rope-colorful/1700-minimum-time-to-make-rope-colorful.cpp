class Solution {
public:
    int minCost(string colors, vector<int>& needTime) {
        int ans=0;
        int i=0;
        int n=colors.size();
        while(i<n){
            int maxx=needTime[i];
            int j=i+1;
            bool flag=false;
            while(j<n&&colors[i]==colors[j]){
                flag=true;
                ans+=needTime[j];
                maxx=max(maxx,needTime[j]);
                j++;
            }
            if(flag)
            {   ans+=needTime[i];
                ans-=maxx;}
            i=j;
        }
        return ans;
    }
};