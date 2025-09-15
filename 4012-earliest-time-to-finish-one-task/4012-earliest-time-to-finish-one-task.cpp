class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int sum=INT_MAX;
        for(auto t:tasks){
            sum=min(sum,t[1]+t[0]);
        }
        return sum;
    }
};