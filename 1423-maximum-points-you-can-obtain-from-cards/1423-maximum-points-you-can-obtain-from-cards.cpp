class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
        int ans=sum;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            sum+=cardPoints[n-1-i];
            sum-=cardPoints[k-1-i];
            ans=max(ans,sum);
        }
        return ans;
    }
};