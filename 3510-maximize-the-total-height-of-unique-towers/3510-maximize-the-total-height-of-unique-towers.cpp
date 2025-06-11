class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(),maximumHeight.end());
        long long ans=maximumHeight[maximumHeight.size()-1];
        long long current=maximumHeight[maximumHeight.size()-1];
        for(int i=maximumHeight.size()-2;i>=0;i--)
        {if(maximumHeight[i]>=current)
        current--;
        else
        current=maximumHeight[i];
        if(current<=0)
        return -1;
            ans=ans+current;
        }
        return ans;
    }
};