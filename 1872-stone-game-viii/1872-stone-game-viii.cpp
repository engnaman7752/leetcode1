class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>preSum(n,0);
        preSum[0]=stones[0];
        preSum[1]=preSum[0]+stones[1];
        pair<int,int>p{stones[0]+stones[1],1};
        for(int i=2;i<n;i++){
            preSum[i]+=preSum[i-1]+stones[i];
            //cout<<preSum[i]<<endl;
            if(p.first<=preSum[i]){
                p={preSum[i],i};
            }
        }
       // cout<<p.second<<endl;
        //if(p.second==n-1)return p.first;
        int ans=preSum[n-1];
        for(int i=n-2;i>=1;i--){
            //cout<<(preSum[n-1]-preSum[i])<<endl;
            ans=max(ans,preSum[i]-ans);
        }
        return ans;
    }
};