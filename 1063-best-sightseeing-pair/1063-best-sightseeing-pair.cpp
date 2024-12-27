class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxx=INT_MIN;
        int naman=values[0];
        int n=values.size();
        for(int i=1;i<n;i++)
        {
             maxx=max(maxx,naman+values[i]-i);
             naman=max(naman,values[i]+i);



        }
        return maxx;
    }
};