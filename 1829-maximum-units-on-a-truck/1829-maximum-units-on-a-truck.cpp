class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b) {
            return a[1] > b[1];
        });
        int ans=0;
        for(int i=0;i<boxTypes.size();i++){
            int x=truckSize-boxTypes[i][0];
            if(x<=0)
            {ans+=boxTypes[i][1]*(truckSize);
            break;}
            else
             ans+=boxTypes[i][1]*boxTypes[i][0];
             truckSize=x;
        }
        return ans;
        
    }
};